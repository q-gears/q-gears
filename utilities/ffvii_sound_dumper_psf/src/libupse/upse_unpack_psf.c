/*
 * UPSE: the unix playstation sound emulator.
 *
 * Filename: upse_unpack_psf.c
 * Purpose: libupse: PSF/MiniPSF/PSF2/MiniPSF2 unpacker
 *
 * Copyright (c) 2007 William Pitcock <nenolod@sacredspiral.co.uk>
 *
 * UPSE is free software, released under the GNU General Public License,
 * version 2.
 *
 * A copy of the GNU General Public License, version 2, is included in
 * the UPSE source kit as COPYING.
 *
 * UPSE is offered without any warranty of any kind, explicit or implicit.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "upse-internal.h"
#include "upse.h"
#include "upse-string.h"

// LOAD STUFF

typedef struct
{
    unsigned char id[8];
    u32 text;
    u32 data;
    u32 pc0;
    u32 gp0;
    u32 t_addr;
    u32 t_size;
    u32 d_addr;
    u32 d_size;
    u32 b_addr;
    u32 b_size;
    u32 s_addr;
    u32 s_size;
    u32 SavedSP;
    u32 SavedFP;
    u32 SavedGP;
    u32 SavedRA;
    u32 SavedS0;
} upse_packed_t upse_exe_header_t;

static long _upse_time_to_ms(const char *str)
{
    int x, c = 0;
    int acc = 0;
    char s[100];

    strncpy(s, str, 100);
    s[99] = 0;

    for (x = strlen(s); x >= 0; x--)
	if (s[x] == '.' || s[x] == ',')
	{
	    acc = atoi(s + x + 1);
	    s[x] = 0;
	}
	else if (s[x] == ':')
	{
	    if (c == 0)
		acc += atoi(s + x + 1) * 10;
	    else if (c == 1)
		acc += atoi(s + x + (x ? 1 : 0)) * 10 * 60;
	    c++;
	    s[x] = 0;
	}
	else if (x == 0)
	{
	    if (c == 0)
		acc += atoi(s + x) * 10;
	    else if (c == 1)
		acc += atoi(s + x) * 10 * 60;
	    else if (c == 2)
		acc += atoi(s + x) * 10 * 60 * 60;
	}
    acc *= 100;			// To milliseconds.
    return (acc);
}

static char *_upse_resolve_path(char *f, char *newfile)
{
    static char *ret;
    char *tp1;

#if PSS_STYLE==1
    tp1 = ((char *) strrchr(f, '/'));
#else
    tp1 = ((char *) strrchr(f, '\\'));
#if PSS_STYLE!=3
    {
	char *tp3;

	tp3 = ((char *) strrchr(f, '/'));
	if (tp1 < tp3)
	    tp1 = tp3;
    }
#endif
#endif
    if (!tp1)
    {
	ret = malloc(strlen(newfile) + 1);
	strcpy(ret, newfile);
    }
    else
    {
	ret = malloc(tp1 - f + 2 + strlen(newfile));	// 1(NULL), 1(/).
	memcpy(ret, f, tp1 - f);
	ret[tp1 - f] = '/';
	ret[tp1 - f + 1] = 0;
	strcat(ret, newfile);
    }
    return (ret);
}

static int _upse_psf_get_tag(char *buf, char **key, char **val)
{
    char *tmp;

    tmp = buf;

    /* First, convert any weirdo ASCII characters to spaces. */
    while (*tmp++)
	if (*tmp > 0 && *tmp < 0x20)
	    *tmp = 0x20;

    /* Strip off white space off end of string(which should be the "value"). */
    for (tmp = buf + strlen(buf) - 1; tmp >= buf; tmp--)
    {
	if (*tmp != 0x20)
	    break;
	*tmp = 0;
    }

    /* Now, search for the first non-whitespace character. */
    while (*buf == 0x20)
	buf++;

    tmp = buf;
    while ((*buf != 0x20) && (*buf != '='))
    {
	if (!*buf)
	    return (0);		/* Null character. */
	buf++;
    }

    /* Allocate memory, copy string, and terminate string. */
    if (!(*key = malloc(buf - tmp + 1)))
	return (0);
    strncpy(*key, tmp, buf - tmp);
    (*key)[(buf - tmp)] = 0;

    /* Search for "=" character. */
    while (*buf != '=')
    {
	if (!*buf)
	    return (0);		/* Null character. */
	buf++;
    }

    buf++;			/* Skip over equals character. */

    /* Remove leading whitespace on value. */
    while (*buf == 0x20)
    {
	if (!*buf)
	    return (0);		/* Null character. */
	buf++;
    }

    /* Allocate memory, and copy string over.  Trailing whitespace was eliminated
       earlier.
     */

    if (!(*val = malloc(strlen(buf) + 1)))
	return (0);
    strcpy(*val, buf);

    //puts(*key);
    //puts(*val);

    return (1);
}

static void _upse_psf_free_tags(upse_psftag_t * tags)
{
    while (tags)
    {
	upse_psftag_t *tmp = tags->next;

	free(tags->key);
	free(tags->value);
	free(tags);

	tags = tmp;
    }
}

static void _upse_psf_add_tag(upse_psftag_t ** tag, const char *key, const char *val)
{
    upse_psftag_t *tmp;

    tmp = malloc(sizeof(upse_psftag_t));
    memset(tmp, 0, sizeof(upse_psftag_t));

    tmp->key = strdup(key);
    tmp->value = strdup(val);
    tmp->next = NULL;

    if (!*tag)
	*tag = tmp;
    else
    {
	upse_psftag_t *rec;
	rec = *tag;
	while (rec->next)
	    rec = rec->next;
	rec->next = tmp;
    }

}

typedef struct
{
    int num;
    char *value;
} upse_libcache_slot_t;

static int ccomp(const void *v1, const void *v2)
{
    const upse_libcache_slot_t *a1, *a2;
    a1 = v1;
    a2 = v2;

    return (a1->num - a2->num);
}

static upse_psf_t *_upse_load(char *path, int level, int type, upse_iofuncs_t *_upse_iofuncs)	// Type==1 for just info load.
{
    void *fp;
    upse_exe_header_t tmpHead;
    tmpHead.t_addr = 0;
    tmpHead.t_size = 0;
    unsigned char *in, *out = 0;
    u8 head[4];
    u32 reserved;
    u32 complen;
    u32 crc32;
    uLongf outlen;
    upse_psf_t *psfi;
    upse_psf_t *tmpi;

    _ENTER;

    if (!(fp = _upse_iofuncs->open_impl(path, "rb")))
    {
	_ERROR("path %s failed to load\n", path);
	return NULL;
    }

    _upse_iofuncs->read_impl(head, 1, 4, fp);
    if (memcmp(head, "PSF\x01", 4))
	return NULL;

    psfi = calloc(sizeof(upse_psf_t), 1);
    psfi->stop = ~0;
    psfi->fade = 0;

    _upse_iofuncs->read_impl(&reserved, 1, 4, fp);
    _upse_iofuncs->read_impl(&complen, 1, 4, fp);
    complen = BFLIP32(complen);

    _upse_iofuncs->read_impl(&crc32, 1, 4, fp);
    crc32 = BFLIP32(crc32);

    _upse_iofuncs->seek_impl(fp, reserved, SEEK_CUR);

    if (type)
	_upse_iofuncs->seek_impl(fp, complen, SEEK_CUR);
    else
    {
	in = malloc(complen);
	out = malloc(1024 * 1024 * 2 + 0x800);
	_upse_iofuncs->read_impl(in, 1, complen, fp);
	outlen = 1024 * 1024 * 2;
	uncompress(out, &outlen, in, complen);
	free(in);
	memcpy(&tmpHead, out, sizeof(upse_exe_header_t));
	upse_r3000_cpu_regs.pc = BFLIP32(tmpHead.pc0);
	upse_r3000_cpu_regs.GPR.n.gp = BFLIP32(tmpHead.gp0);
	upse_r3000_cpu_regs.GPR.n.sp = BFLIP32(tmpHead.s_addr);
	if (upse_r3000_cpu_regs.GPR.n.sp == 0)
	    upse_r3000_cpu_regs.GPR.n.sp = 0x801fff00;

	if (level)
	{
	    LoadPSXMem(BFLIP32(tmpHead.t_addr), BFLIP32(tmpHead.t_size), out + 0x800);
	    free(out);
	}
    }

    {
	u8 tagdata[5];
	if (_upse_iofuncs->read_impl(tagdata, 1, 5, fp) == 5)
	{
	    if (!memcmp(tagdata, "[TAG]", 5))
	    {
		char linebuf[1024];

		while (upse_io_fgets(linebuf, 1024, fp, _upse_iofuncs))
		{
		    int x;
		    char *key = NULL, *value = NULL;

		    if (!_upse_psf_get_tag(linebuf, &key, &value))
		    {
			if (key)
			    free(key);
			if (value)
			    free(value);
			continue;
		    }

		    _upse_psf_add_tag(&psfi->taglist, key, value);

		    if (!level)
		    {
			static char *yoinks[8] = { "title", "artist", "game", "year", "genre",
			    "copyright", "psfby", "comment"
			};
			char **yoinks2[8] = { &psfi->title, &psfi->artist, &psfi->game, &psfi->year, &psfi->genre,
			    &psfi->copyright, &psfi->psfby, &psfi->comment
			};
			for (x = 0; x < 8; x++)
			    if (!strcasecmp(key, yoinks[x]))
				*yoinks2[x] = value;
			if (!strcasecmp(key, "length"))
			    psfi->stop = _upse_time_to_ms(value);
			else if (!strcasecmp(key, "fade"))
			    psfi->fade = _upse_time_to_ms(value);
		    }

		    if (!strcasecmp(key, "_lib") && !type)
		    {
			char *tmpfn;
			/* Load file name "value" from the directory specified in
			   the full path(directory + file name) "path"
			 */
			tmpfn = _upse_resolve_path(path, value);
			if (!(tmpi = _upse_load(tmpfn, level + 1, 0, _upse_iofuncs)))
			{
			    free(key);
			    free(value);
			    free(tmpfn);
			    if (!level)
				free(out);
			    _upse_iofuncs->close_impl(fp);
			    _upse_psf_free_tags(psfi->taglist);
			    free(psfi);
			    return NULL;
			}
			_upse_psf_free_tags(tmpi->taglist);
			free(tmpi);
			free(tmpfn);
		    }

		    if (key)
		        free(key);
		}
	    }
	}
    }

    _upse_iofuncs->close_impl(fp);

    /* Now, if we're at level 0(main PSF), load the main executable, and any libN stuff */
    if (!level && !type)
    {
	LoadPSXMem(BFLIP32(tmpHead.t_addr), BFLIP32(tmpHead.t_size), out + 0x800);
	free(out);
    }

    if (!type)			/* Load libN */
    {
	upse_libcache_slot_t *cache;
	upse_psftag_t *tag;
	unsigned int libncount = 0;
	unsigned int cur = 0;

	tag = psfi->taglist;
	while (tag)
	{
	    if (!strncasecmp(tag->key, "_lib", 4) && tag->key[4])
		libncount++;
	    tag = tag->next;
	}

	if (libncount)
	{
	    cache = malloc(sizeof(upse_libcache_slot_t) * libncount);

	    tag = psfi->taglist;
	    while (tag)
	    {
		if (!strncasecmp(tag->key, "_lib", 4) && tag->key[4])
		{
		    cache[cur].num = atoi(&tag->key[4]);
		    cache[cur].value = tag->value;
		    cur++;
		}
		tag = tag->next;
	    }
	    qsort(cache, libncount, sizeof(upse_libcache_slot_t), ccomp);
	    for (cur = 0; cur < libncount; cur++)
	    {
		u32 ba[3];
		char *tmpfn;

		if (cache[cur].num < 2)
		    continue;

		ba[0] = upse_r3000_cpu_regs.pc;
		ba[1] = upse_r3000_cpu_regs.GPR.n.gp;
		ba[2] = upse_r3000_cpu_regs.GPR.n.sp;

		/* Load file name "value" from the directory specified in
		   the full path(directory + file name) "path"
		 */
		tmpfn = _upse_resolve_path(path, cache[cur].value);
		if (!(tmpi = _upse_load(tmpfn, level + 1, 0, _upse_iofuncs)))
		{
		    //free(key);
		    //free(value);
		    //free(tmpfn);
		    //_upse_iofuncs->close_impl(fp);
		    //return(0);
		}
		free(tmpfn);
		_upse_psf_free_tags(tmpi->taglist);
		free(tmpi);

		upse_r3000_cpu_regs.pc = ba[0];
		upse_r3000_cpu_regs.GPR.n.gp = ba[1];
		upse_r3000_cpu_regs.GPR.n.sp = ba[2];
	    }
	    free(cache);

	}			// if(libncount)

    }				// if(!type)

    _LEAVE;
    return psfi;
}

void upse_free_psf_metadata(upse_psf_t * info)
{
    _upse_psf_free_tags(info->taglist);
    free(info);
}

upse_psf_t *upse_get_psf_metadata(char *path, upse_iofuncs_t * iofuncs)
{
    upse_psf_t *ret;

    _ENTER;

    if (!(ret = _upse_load(path, 0, 1, iofuncs)))
	return NULL;

    if (ret->stop == (u32) ~ 0)
	ret->fade = 0;

    ret->length = ret->stop + ret->fade;

    _LEAVE;
    return ret;
}

upse_psf_t *upse_load(char *path, upse_iofuncs_t * iofuncs)
{
    upse_psf_t *ret;

    _ENTER;

    psxInit();
    psxReset();

    SPUinit();
    SPUopen();

    if (!(ret = _upse_load(path, 0, 0, iofuncs)))
    {
	psxShutdown();

	return NULL;
    }

    if (ret->stop == (u32) ~ 0)
	ret->fade = 0;

    SPUsetlength(ret->stop, ret->fade);
    ret->length = ret->stop + ret->fade;

    _LEAVE;
    return ret;
}
