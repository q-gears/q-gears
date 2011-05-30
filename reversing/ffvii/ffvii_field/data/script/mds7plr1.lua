-- created by Tori

entity = {
};



tempd = 0; -- we set this if we try to leave during pillar event. number specify direction.
tempe = 0; -- we talk to guardR



entity["tobira"] = {
    on_start = function(self)
        --BGCLR(0,1)
        --BGON(0,1,0)

        return 0;
    end;

    script1 = function(self)
--727:	bgoff(0,1,0)
--72b:	bgon(0,1,1)

        return 0;
    end;

    script2 = function(self)
--730:	bgoff(0,1,1)
--734:	bgon(0,1,0)

        return 0;
    end;
};



entity["produce"] = {
    on_start = function(self)
        --MPNAM(0)

        local progress = game:variable_get("progress_game");

        if progress >= 212 then
            --MUSIC(0)
        elseif progress >= 108 then
            --MUSIC(1)
        elseif progress >= 69 then
            --MUSIC(2)
        else
            --MUSIC(3)
        end;

        if progress == 221 then
            script:request_start_wait("stagedr", "script6", 2);
            script:request_start_wait("AD", "script2", 6);
        elseif progress == 218 then
            -- after we see gunfire on pillar and Wedge fall down
            --CharMovable(Off)
            --MenuAccess(Off)
            --MENU(0,11,3)
            script:request_start_wait("stagedr", "script5", 2);
            script:request_start_wait("AD", "script2", 6);
        elseif progress == 212 then
            -- start of pillar bombing event
            game:variable_set("progress_game", 215);
            --CharMovable(Off)
            --MenuAccess(Off)
            script:request_start_wait("stagedr", "script4", 2);
            script:request_start_wait("AD", "script2", 6);
            --PMJMP(9D,0)
        else
            local flags = game:variable_get("bank3[208]")
            if bit.band(flags, hex.to_dec('0x08')) then
                -- load without man1
                script:request_start_wait("stagedr", "script3", 2);
            elseif bit.band(flags, hex.to_dec('0x02')) then
                -- load leftover talk to man1
                game:variable_set("bank3[208]", bit.bor(flags, hex.to_dec('0x08')));
                script:request_start_wait("stagedr", "script2", 2);
            elseif bit.band(flags, hex.to_dec('0x01')) then
                -- everyone already runned
                script:request_start_wait("stagedr", "script3", 2);
            else
                -- everyone run to hideout
                game:variable_set("bank3[208]", bit.bor(flags, hex.to_dec('0x01')));
                script:request_start_wait("stagedr", "script1", 2);
            end;
        end;

        return 0;
    end;
};



entity["direct"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["AD"] = {
    on_start = function(self)
        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--7e2:	akao(0,0,0,a2,40,0,0,0,0,0,0,0,0)

        while true do
--7f0:	akao(0,0,0,2a,7f,f,0,0,0,0,0,0,0)
--7fe:	wait(3c,0)
--801:	akao(0,0,0,2a,0,f,0,0,0,0,0,0,0)
--80f:	wait(3c,0)
--812:	wait(3c,0)
--815:	akao(0,0,0,2a,7f,10,0,0,0,0,0,0,0)
--823:	wait(a,0)
--826:	akao(0,0,0,2a,7f,10,0,0,0,0,0,0,0)
--834:	wait(a,0)
--837:	akao(0,0,0,2a,0,14,0,0,0,0,0,0,0)
--845:	wait(1e,0)
--848:	akao(0,0,0,2a,0,31,0,0,0,0,0,0,0)
--856:	wait(3c,0)
--859:	akao(0,0,0,2a,7f,31,0,0,0,0,0,0,0)
--867:	wait(3c,0)
        end;

        return 0;
    end;
};



entity["stagedr"] = {
    on_start = function(self)
        --IDLCK(4,1,1)

        return 0;
    end;

    script1 = function(self)
        script:request_start_wait("avaf", "script3", 6);
        script:request_start_wait("avaw", "script3", 6);
        script:request_start_wait("aval", "script3", 6);
        script:request_start_wait("ballet", "script3", 6);
        script:request_start_wait("man1", "script3", 6);

        return 0;
    end;

    script2 = function(self)
        local flags = game:variable_get("bankD[208]");
        flags = bit.band(flags, hex.to_dec('0xFD'));
        game:variable_set("bankD[208]", flags);

        script:request_start_wait("ballet", "script4", 6);
        script:request_start_wait("aval", "script4", 6);
        script:request_start_wait("avaw", "script4", 6);
        script:request_start_wait("avaf", "script4", 6);

        script:request_start_wait("cloud", "script3", 6);

        if bit.band(flags, hex.to_dec('0x04')) then
            script:request_start_wait("man1", "script5", 2);
        else
            script:request_start_wait("man1", "script4", 2);
        end;

        return 0;
    end;

    script3 = function(self)
        script:request_start_wait("ballet", "script4", 6);
        script:request_start_wait("aval", "script4", 6);
        script:request_start_wait("avaw", "script4", 6);
        script:request_start_wait("avaf", "script4", 6);

        local flags = game:variable_get("bank3[208]")
        if bit.band(flags, hex.to_dec('0x08')) then
            script:request_start_wait("man1", "script5", 6);
        else
            script:request_start_wait("man1", "script3", 6);
        end;

        return 0;
    end;

    script4 = function(self)
        script:request_start_wait("ballet", "script4", 6);
        script:request_start_wait("aval",   "script4", 6);
        script:request_start_wait("avaw",   "script4", 6);
        script:request_start_wait("avaf",   "script4", 6);
        script:request_start_wait("tifa",   "script3", 6);
        script:request_start_wait("earith", "script3", 6);
        script:request_start_wait("man1",   "script6", 6);
        script:request_start_wait("man2",   "script3", 6);
        script:request_start_wait("woman1", "script3", 6);
        script:request_start_wait("guardR", "script5", 6);
        script:request_start_wait("guardL", "script7", 6);
        script:request_start_wait("cloud", "script5", 6);

        return 0;
    end;

    script5 = function(self)
        script:request_start_wait("ballet", "script4", 6);
        script:request_start_wait("aval",   "script4", 6);
        script:request_start_wait("avaw",   "script4", 6);
        script:request_start_wait("avaf",   "script5", 6);
        script:request_start_wait("tifa",   "script6", 6);
        script:request_start_wait("earith", "script5", 6);
        script:request_start_wait("man1",   "script6", 6);
        script:request_start_wait("man2",   "script3", 6);
        script:request_start_wait("woman1", "script3", 6);
        script:request_start_wait("guardR", "script5", 6);
        script:request_start_wait("guardL", "script7", 6);
        script:request_start_wait("cloud", "script6", 6);

        return 0;
    end;

    script6 = function(self)
        script:request_start_wait("ballet", "script4", 6);
        script:request_start_wait("aval", "script4", 6);
        script:request_start_wait("avaw", "script4", 6);
        script:request_start_wait("avaf", "script9", 6);
        script:request_start_wait("man1", "script6", 6);
        script:request_start_wait("man2", "script3", 6);
        script:request_start_wait("woman1", "script3", 6);
        script:request_start_wait("guardR", "script5", 6);
        script:request_start_wait("guardL", "script7", 6);
        script:request_start_wait("border1", "script8", 6);
        script:request_start_wait("border2", "script8", 6);
        script:request_start_wait("border3", "script8", 6);
        tempe = 1;

        return 0;
    end;
};



entity["timekp"] = {
    on_start = function(self)
        return 0;
    end;
};



entity["BGanim"] = {
    on_start = function(self)
        script:request_start_wait("tobira", "script2", 6);

        return 0;
    end;
};



entity["border1"] = {
    on_start = function(self)
--93c:	line(77,fe,31,ff,0,0,8,ff,d7,fd,0,0)
--94a:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--94e:	uc(1)
--950:	menu2(1)
        script:request_start_wait("cloud", "script7", 6);
        tempd = 1;
        script:request_end_wait("tifa", "script10", 6);
        tempd = 0;

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
--968:	linon(1)

        return 0;
    end;
};



entity["border2"] = {
    on_start = function(self)
--96b:	line(64,ff,76,fd,0,0,f0,0,7b,fd,0,0)
--979:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--97d:	uc(1)
--97f:	menu2(1)
        script:request_start_wait("cloud", "script7", 6);
        tempd = 2;
        script:request_end_wait("tifa", "script10", 6);
        tempd = 0;

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
--997:	linon(1)

        return 0;
    end;
};



entity["border3"] = {
    on_start = function(self)
--99a:	line(3e,1,72,ff,0,0,77,1,26,fe,0,0)
--9a8:	linon(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
--9ac:	uc(1)
--9ae:	menu2(1)
        script:request_start_wait("cloud", "script7", 6);
        tempd = 3;
        script:request_end_wait("tifa", "script10", 6);
        tempd = 0;

        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
--9c6:	linon(1)

        return 0;
    end;
};



entity["cloud"] = {
    on_start = function(self)
        --CHAR(0)
        --PC(0)
        --SLIDR(0,22)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--9d3:	xyzi(0,0,3,ff,e1,3,0,0,1,1)
--9de:	dir(0,0)

        return 0;
    end;

    script4 = function(self)
--9e2:	turngen(0,60,2,4,1)
--9e8:	canm!2(3,0,e,1)
--9ed:	wait(f,0)

        return 0;
    end;

    script5 = function(self)
--9f1:	solid(1)
--9f3:	scr2d(0,0,0,f,0)
--9f9:	scr2dc(0,0,0,0,78,0,50,0)
--a02:	msped(0,0,8)
--a06:	dfanm(2,1)
--a09:	fmove(0,ae,0,e9,fe)
--a0f:	fmove(0,39,0,e6,ff)
--a15:	fmove(0,39,0,86,0)
--a1b:	dfanm(4,1)
--a1e:	dir(0,80)
        script:request_end_wait("tifa", "script4", 6);
--a24:	dfanm(2,1)
--a27:	fmove(0,13,0,db,0)
--a2d:	dir(0,80)
--a30:	dfanm(4,1)
--a33:	wait(1e,0)
--a36:	canm!2(5,0,e,1)
--a3b:	window(2,82,0,3a,0,e8,0,39,0)
--a45:	message(2,4)
        script:request_end_wait("earith", "script4", 6);
        script:request_start_wait("tifa", "script5", 6);

        return 0;
    end;

    script6 = function(self)
--a4f:	solid(1)
--a51:	uc(1)
--a53:	menu2(1)
--a55:	xyzi(0,0,13,0,db,0,0,0,ae,0)
--a60:	dir(0,80)
--a63:	anime2(6,1)
--a66:	turngen(0,0,2,a,1)
--a6c:	msped(0,0,c)
--a70:	move(0,c,0,92,ff)
--a76:	dir(0,40)
        script:request_start_wait("man1", "script7", 5);
        script:request_start_wait("guardR", "script6", 5);
        script:request_start_wait("woman1", "script4", 5);
        script:request_start_wait("tifa", "script8", 6);
        script:request_start_wait("man2", "script4", 5);
        script:request_end_wait("guardL", "script8", 5);
--a8b:	msped(0,0,c)
--a8f:	move(0,c,0,92,ff)
--a95:	dir(0,40)
--a98:	anim!2(7,1)
--a9b:	window(2,8,0,a0,0,ae,0,39,0)
--aa5:	message(2,d)
        script:request_end_wait("avaf", "script7", 6);
--aab:	anim!2(8,1)
        script:request_end_wait("avaf", "script8", 6);
--ab1:	anim!2(8,1)
--ab4:	anim!2(9,1)
--ab7:	asped(0,20,0)
--abb:	anime2(a,1)
--abe:	turngen(0,80,2,a,1)
--ac4:	canm!2(5,0,e,1)
--ac9:	message(2,7)
--acc:	canm!2(5,e,1d,1)
--ad1:	dir(0,a0)
--ad4:	message(2,8)
        script:request_end_wait("earith", "script9", 6);
        script:request_end_wait("tifa", "script9", 6);
--add:	dfanm(0,1)
--ae0:	asped(0,10,0)
--ae4:	wrest(2)
--ae6:	wrest(1)
        game:variable_set("progress_game", 221);

        script:request_start_wait("border1", "script8", 6);
        script:request_start_wait("border2", "script8", 6);
        script:request_start_wait("border3", "script8", 6);
--af6:	slidr(0,22)
--af9:	solid(0)

        return 0;
    end;

    script7 = function(self)
--afc:	solid(1)
--afe:	dira(d)

        return 0;
    end;

    script8 = function(self)
--b01:	msped(0,0,8)
--b05:	mova(d)

        return 0;
    end;
};



entity["earith"] = {
    on_start = function(self)
        --CHAR(1)
        --PC(3)
        --TalkSwitch(Off)
        --SolidObject(Off)
        --VISI(Off)

        return 0;
    end;

    script1 = function(self)
--b14:	uc(1)
--b16:	menu2(1)
--b18:	window(0,be,0,8,0,ae,0,39,0)
--b22:	message(0,2c)
--b25:	uc(0)
--b27:	menu2(0)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--b2b:	getaxy(66,a,2,4)
--b30:	getai(6,a,0)
--b34:	xyi(66,60,2,0,4,0,0,0)
--b3d:	dir(0,c0)
--b40:	solid(1)
--b42:	tlkon(0)
--b44:	solid(0)
--b46:	visi(1)
--b48:	msped(0,0,b)
--b4c:	dfanm(2,1)
--b4f:	fmove(0,b7,ff,4,0)
--b55:	dir(0,80)
--b58:	anime1(3,1)
--b5b:	dfanm(0,1)

        return 0;
    end;

    script4 = function(self)
--b5f:	move(0,89,ff,98,0)
--b65:	dir(0,60)
--b68:	anime1(4,1)
--b6b:	message(1,5)

        return 0;
    end;

    script5 = function(self)
--b6f:	xyzi(0,0,b7,ff,4,0,0,0,8f,0)
--b7a:	dir(0,20)
--b7d:	tlkon(0)
--b7f:	solid(0)
--b81:	visi(1)
--b83:	wait(3c,0)
--b86:	dfanm(2,1)
--b89:	msped(0,0,8)
--b8d:	fmove(0,91,ff,cb,ff)
--b93:	dir(0,20)

        return 0;
    end;

    script6 = function(self)
--b97:	anim!2(5,1)

        return 0;
    end;

    script7 = function(self)
--b9b:	anim!2(6,1)

        return 0;
    end;

    script8 = function(self)
--b9f:	anime2(7,1)
--ba2:	turngen(0,60,2,a,1)
--ba8:	anim!2(8,1)
--bab:	window(1,be,0,8,0,ce,0,39,0)
--bb5:	message(1,b)

        return 0;
    end;

    script9 = function(self)
--bb9:	anim!2(8,1)

        return 0;
    end;

    script10 = function(self)
--bbd:	msped(0,0,10)
--bc1:	move(0,f2,ff,23,ff)
--bc7:	move(0,80,0,60,ff)
--bcd:	uc(0)
--bcf:	menu2(0)
--bd1:	dir(0,a0)
--bd4:	asped(0,20,0)
--bd8:	anim!2(9,1)
--bdb:	asped(0,10,0)
        while true do
--bdf:	anim!2(a,1)
--be2:	wait(3c,0)
        end;

        return 0;
    end;
};



entity["ballet"] = {
    on_start = function(self)
        --CHAR(2)
        --PC(1)
        --SLIDR(0,30)
        --TALKR(0,46)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--bfb:	xyzi(0,0,98,ff,2f,ff,0,0,68,0)
--c06:	dfanm(2,1)
--c09:	msped(0,0,d)
--c0d:	fmove(0,f8,fe,28,ff)
--c13:	fmove(0,2a,fe,b5,fe)
--c19:	tlkon(1)
--c1b:	solid(1)
--c1d:	visi(0)

        return 0;
    end;

    script4 = function(self)
--c20:	tlkon(1)
--c22:	solid(1)
--c24:	visi(0)
--c26:	slidr(0,0)
--c29:	talkr(0,0)

        return 0;
    end;

    script5 = function(self)
        local flags = game:variable_get("bank3[209]")
        if bit.band(flags, hex.to_dec('0x01')) == 0 then
            local flags1 = game:variable_get("bank3[208]")
            game:variable_set("bank3[208]", bit.bor(flags1, hex.to_dec('0x04')));
            --Wait(1E)
            --XYZI(0,-167,-144,0,64)
            --TalkSwitch(On)
            --SolidObject(On)
            --VISI(On)
            --DFANM(2,1)
            --MSPED(0,0,8)
            --FMOVE(0,14,FF,FE,FE)
            --ANIM!2(3,1)
            --CreateWindow(0,8,64,B2,39)
            --Dialog(0,2)
            --MSPED(0,0,E)
            --DFANM(2,1)
            --FMOVE(0,2A,FE,B5,FE)
            --TalkSwitch(Off)
            --SolidObject(Off)
            --VISI(Off)
        end;

        return 0;
    end;
};



entity["tifa"] = {
    on_start = function(self)
--c7e:	char(3)
--c80:	pc(2)
--c82:	slidr(0,1e)
--c85:	talkr(0,0)
--c88:	tlkon(1)
--c8a:	solid(1)
--c8c:	visi(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--c91:	getaxy(66,a,2,4)
--c96:	getai(6,a,0)
--c9a:	xyi(66,60,2,0,4,0,0,0)
--ca3:	dir(0,c0)
--ca6:	tlkon(0)
--ca8:	solid(0)
--caa:	visi(1)
--cac:	solid(1)
--cae:	msped(0,0,c)
--cb2:	dfanm(2,1)
--cb5:	move(0,52,0,d7,fe)
--cbb:	move(0,fc,ff,6e,0)
--cc1:	move(0,c5,ff,26,1)
--cc7:	dir(0,80)
--cca:	dfanm(0,1)

        return 0;
    end;

    script4 = function(self)
--cce:	move(0,c2,ff,7f,1)
--cd4:	anim!2(3,1)
--cd7:	window(1,8,0,3a,0,a3,0,39,0)
--ce1:	message(1,3)

        return 0;
    end;

    script5 = function(self)
--ce5:	dir(0,0)
--ce8:	anim!2(3,1)
--ceb:	mapjump(9d,0,0,0,0,0,0,0,0) -- mds7plr2

        return 0;
    end;

    script6 = function(self)
--cf6:	xyzi(0,0,c2,ff,7f,1,0,0,be,0)
--d01:	dir(0,80)
--d04:	tlkon(0)
--d06:	solid(0)
--d08:	visi(1)
--d0a:	wait(a,0)
--d0d:	dfanm(2,1)
--d10:	msped(0,0,8)
--d14:	fmove(0,ff,ff,c0,0)
--d1a:	dir(0,0)
--d1d:	canm!2(4,0,e,1)

        return 0;
    end;

    script7 = function(self)
        return 0;
    end;

    script8 = function(self)
--d29:	move(0,56,0,3e,0)
--d2f:	dfanm(0,1)
--d32:	dir(0,0)

        return 0;
    end;

    script9 = function(self)
--d36:	move(0,e3,ff,e,0)
        script:request_start_wait("earith", "script7", 6);
--d3f:	window(2,8,0,a0,0,f8,0,39,0)
--d49:	message(2,9)
--d4c:	message(2,a)
        script:request_end_wait("earith", "script8", 6);
--d52:	move(0,e9,ff,19,0)
--d58:	dir(0,80)
--d5b:	anime1(5,1)
--d5e:	anime1(6,1)
        script:request_start_wait("man1", "script8", 4);
        script:request_start_wait("guardL", "script9", 5);
--d67:	window(2,8,0,a0,0,20,1,39,0)
--d71:	message(2,c)
        script:request_start_wait("man1", "script9", 4);
        script:request_start_wait("guardL", "script10", 4);
        script:request_start_wait("woman1", "script5", 4);
        script:request_start_wait("guardR", "script7", 4);
        script:request_start_wait("man2", "script5", 4);
--d83:	solid(1)
--d85:	mova(a)
--d87:	tlkon(1)
--d89:	solid(1)
--d8b:	visi(0)
--d8d:	hmpmax3
--d8e:	prtye(0,2,fe)
--d92:	prtym(3)
--d94:	talkr(0,0)
        script:request_start_wait("earith", "script10", 6);

        return 0;
    end;

    script10 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --AXYZI(66,66,A,2,4,6,0)
        --XYI(66,60,2,0,4,0,0,0)
        --DIR(0,40)
        --TalkSwitch(On)
        --SolidObject(On)
        --VISI(On)
        --SolidObject(Off)
        --MSPED(0,0,C)

        if tempd == 1 then
            --MOVE(0,63,FF,21,FF)
            --DIR(0,C0)
        elseif tempd == 2 then
            --MOVE(0,40,0,21,FE)
            --DIR(0,0)
        elseif tempd == 3 then
            --MOVE(0,BE,0,C3,FE)
            --DIR(0,40)
        end;

        --CreateWindow(1,8,8,C0,39)
        --Dialog(1,12)
        script:request_end_wait("cloud", "script8", 6);
        --TalkSwitch(Off)
        --SolidObject(Off)
        --VISI(Off)
        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;
};



entity["aval"] = {
    on_start = function(self)
--e0b:	char(4)
--e0d:	slidr(0,22)
--e10:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--e16:	solid(1)
--e18:	xyzi(0,0,e8,0,dd,fe,0,0,42,0)
--e23:	dfanm(2,1)
--e26:	msped(0,0,e)
--e2a:	fmove(0,1,0,15,0)
--e30:	dir(0,0)
--e33:	dfanm(3,1)
--e36:	wait(1e,0)
--e39:	dfanm(2,1)
--e3c:	msped(0,0,10)
--e40:	fmove(0,10,ff,7d,ff)
--e46:	dir(0,0)
--e49:	dfanm(3,1)
--e4c:	wait(1e,0)
--e4f:	dfanm(2,1)
--e52:	fmove(0,2d,fe,a1,fe)
--e58:	tlkon(1)
--e5a:	solid(1)
--e5c:	visi(0)

        return 0;
    end;

    script4 = function(self)
--e5f:	tlkon(1)
--e61:	solid(1)
--e63:	visi(0)
--e65:	talkr(0,0)

        return 0;
    end;

    script5 = function(self)
--e69:	xyzi(0,0,4b,0,90,ff,0,0,7b,0)
--e74:	solid(0)
--e76:	slidr(0,30)

        return 0;
    end;
};



entity["avaf"] = {
    on_start = function(self)
--e7a:	char(5)
--e7c:	slidr(0,22)
--e7f:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--e86:	solid(1)
--e88:	xyzi(0,0,61,0,af,fd,0,0,29,0)
--e93:	dir(0,0)
--e96:	dfanm(3,1)
--e99:	wait(1e,0)
--e9c:	dfanm(2,1)
--e9f:	msped(0,0,8)
--ea3:	fmove(0,73,ff,10,ff)
--ea9:	dfanm(3,1)
--eac:	wait(1e,0)
--eaf:	msped(0,0,c)
--eb3:	dfanm(2,1)
--eb6:	fmove(0,2d,fe,a1,fe)
--ebc:	tlkon(1)
--ebe:	solid(1)
--ec0:	visi(0)

        return 0;
    end;

    script4 = function(self)
--ec3:	tlkon(1)
--ec5:	solid(1)
--ec7:	visi(0)
--ec9:	talkr(0,0)

        return 0;
    end;

    script5 = function(self)
--ecd:	xyzi(0,0,59,0,e8,ff,0,0,8c,0)
--ed8:	dir(0,40)
--edb:	canm!2(4,1d,1d,1)
--ee0:	blink(1)
        script:request_start_wait("guard", "script6", 6);
--ee5:	tlkon(0)
--ee7:	solid(0)
--ee9:	visi(1)
--eeb:	solid(1)
--eed:	slidr(0,0)

        return 0;
    end;

    script6 = function(self)
        return 0;
    end;

    script7 = function(self)
--ef7:	canm!2(5,0,e,1)
--efc:	blink(0)
--efe:	wait(1e,0)
--f01:	window(1,5a,0,a0,0,d8,0,39,0)
--f0b:	message(1,e)

        return 0;
    end;

    script8 = function(self)
--f0f:	canm!2(4,1b,1d,1)
--f14:	canm!2(5,e,e,1)
--f19:	window(1,5a,0,a0,0,cb,0,39,0)
--f23:	message(1,f)
--f26:	blink(1)
--f28:	canm!2(5,e,1d,1)
--f2d:	window(1,5a,0,a0,0,bd,0,39,0)
--f37:	message(1,10)
        script:request_start_wait("aval", "script5", 6);
--f3d:	kawai(7)

        return 0;
    end;

    script9 = function(self)
--f4a:	xyzi(0,0,59,0,e8,ff,0,0,8c,0)
--f55:	dir(0,40)
--f58:	kawai(7)

        return 0;
    end;
};



entity["avaw"] = {
    on_start = function(self)
--f63:	char(6)
--f65:	slidr(0,22)
--f68:	talkr(0,46)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--f6e:	solid(1)
--f70:	xyzi(0,0,5a,ff,54,fe,0,0,49,0)
--f7b:	dfanm(3,1)
--f7e:	dir(0,0)
--f81:	wait(3c,0)
--f84:	wait(3c,0)
--f87:	msped(0,0,10)
--f8b:	dfanm(2,1)
--f8e:	fmove(0,2d,fe,a1,fe)
--f94:	tlkon(1)
--f96:	solid(1)
--f98:	visi(0)

        return 0;
    end;

    script4 = function(self)
--f9b:	tlkon(1)
--f9d:	solid(1)
--f9f:	visi(0)
--fa1:	talkr(0,0)

        return 0;
    end;
};



entity["guardR"] = {
    on_start = function(self)
--fa5:	char(7)
--fa7:	slidr(0,22)
--faa:	talkr(0,46)
--fad:	dir(0,80)
--fb0:	xyzi(0,0,ba,ff,92,fc,0,0,c,0)

        return 0;
    end;

    script1 = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 221 then
            --CharMovable(Off)
            --MenuAccess(Off)
            if tempe == 0 then
                --CreateWindow(2,8,8,D8,39)
                --Dialog(2,30)
                --CreateWindow(3,BE,A0,FD,39)
                --Dialog(3,31)
            else
                --CreateWindow(2,BE,A0,113,29)
                --Dialog(2,32)
                --CreateWindow(3,8,A0,FB,39)
                --Dialog(3,33)
            end;
            --CharMovable(On)
            --MenuAccess(On)
        elseif progress == 108 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --CANM!2(3,E,16,1)

            local flags = game:variable_get("bank3[208]")
            if bit.band(flags, hex.to_dec('0x10')) then
                --CreateWindow(2,8,8,CA,39)
                --Dialog(2,29)
            else
                if tempe == 1 then
                    --CreateWindow(2,8,8,11E,39)
                    --Dialog(2,26)
                    script:request_end_wait("guardL", "script6", 1);
                    --Dialog(2,28)
                    game:variable_set("bank3[208]", bit.bor(flags, hex.to_dec('0x10')));
                else
                    --CreateWindow(2,8,8,E2,39)
                    --Dialog(2,21)
                    script:request_end_wait("guardL", "script4", 1);
                    --CreateWindow(2,8,8,EC,39)
                    --Dialog(2,23)
                    script:request_end_wait("guardL", "script5", 1);
                    --CreateWindow(2,8,8,126,39)
                    --Dialog(2,25)
                    tempe = 1;
                end;
            end;

            --CANM!2(3,16,1D,1)
            --CharMovable(On)
            --MenuAccess(On)
        elseif progress >= 63 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --CreateWindow(2,8,8,D6,39)
            --Dialog(2,18)
            --CANM!2(3,E,16,1)
            --CreateWindow(2,8,8,A8,39)
            --Dialog(2,19)
            script:request_end_wait("guardL", "script3", 1);
            --CreateWindow(2,8,8,6F,39)
            --Dialog(2,1B)
            --CANM!2(3,16,1D,1)
            --CharMovable(On)
            --MenuAccess(On)
        end;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--10d2:	canm!2(3,e,16,1)
--10d7:	window(2,8,0,8,0,b9,0,39,0)
--10e1:	message(2,1c)

        return 0;
    end;

    script4 = function(self)
--10e5:	window(2,8,0,8,0,6f,0,39,0)
--10ef:	message(2,1b)
--10f2:	canm!2(3,16,1d,1)

        return 0;
    end;

    script5 = function(self)
--10f8:	xyzi(0,0,6b,0,e7,2,0,0,d0,0)
--1103:	dir(0,60)
--1106:	talkr(0,96)

        while true do
--1109:	canm!2(4,0,13,1)
--110e:	wait(3c,0)
--1111:	canm!2(4,14,1d,1)
--1116:	wait(3c,0)
        end;

        return 0;
    end;

    script6 = function(self)
--111c:	solid(1)
--111e:	wait(a,0)
--1121:	talkr(0,c8)
--1124:	msped(0,0,8)
--1128:	move(0,d,0,d0,0)
--112e:	dir(0,0)
--1131:	dfanm(0,1)

        while true do
--1134:	canm!2(4,9,13,1)
--1139:	wait(3c,0)
--113c:	canm!2(4,14,1d,1)
--1141:	wait(3c,0)
        end;

        return 0;
    end;

    script7 = function(self)
--1147:	move(0,b6,0,df,0)
--114d:	dir(0,0)
        tempe = 0;
--1154:	solid(0)
        while true do
--1156:	canm!2(4,9,13,1)
--115b:	wait(3c,0)
--115e:	canm!2(4,14,1d,1)
--1163:	wait(3c,0)
        end;

        return 0;
    end;
};



entity["guardL"] = {
    on_start = function(self)
--1169:	char(8)
--116b:	slidr(0,22)
--116e:	talkr(0,46)
--1171:	dir(0,80)
--1174:	xyzi(0,0,7,0,93,fc,0,0,5f,0)

        return 0;
    end;

    script1 = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 221 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --ASPED(0,20,0)
            --ANIME2(5,1)
            --TURA(A,A,2)
            --CreateWindow(1,64,A0,128,39)
            --Dialog(1,34)
            --ASPED(0,10,0)
            --CharMovable(On)
            --MenuAccess(On)
        elseif progress == 108 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --ASPED(0,20,0)
            --ANIME2(5,1)
            --CreateWindow(1,64,8,C4,39)
            --Dialog(1,2A)
            --ASPED(0,10,0)
            --CharMovable(On)
            --MenuAccess(On)
        elseif progress >= 63 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --ASPED(0,20,0)
            --ANIME2(5,1)
            --CreateWindow(1,64,8,BB,39)
            --Dialog(1,1E)
            --CreateWindow(1,64,8,11D,39)
            --Dialog(1,1F)
            script:request_end_wait("guardR", "script3", 1);
            --ANIMW
            --ASPED(0,10,0)
            --CANM!2(3,0,7,1)
            --Dialog(1,1D)
            script:request_end_wait("guardR", "script4", 1);
            --CANM!2(3,7,E,1)
            --CharMovable(On)
            --MenuAccess(On)
        end;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1224:	canm!2(3,0,7,1)
--1229:	window(1,64,0,8,0,e5,0,39,0)
--1233:	message(1,1a)
--1236:	canm!2(3,7,e,1)

        return 0;
    end;

    script4 = function(self)
--123c:	canm!2(3,0,7,1)
--1241:	window(1,64,0,8,0,e7,0,39,0)
--124b:	message(1,22)

        return 0;
    end;

    script5 = function(self)
--124f:	window(1,64,0,8,0,d8,0,39,0)
--1259:	message(1,24)
--125c:	canm!2(3,7,e,1)

        return 0;
    end;

    script6 = function(self)
--1262:	canm!2(3,0,7,1)
--1267:	window(1,64,0,8,0,ce,0,39,0)
--1271:	message(1,27)
--1274:	canm!2(3,7,e,1)

        return 0;
    end;

    script7 = function(self)
--127a:	xyzi(0,0,39,0,74,2,0,0,be,0)
--1285:	dir(0,80)

        return 0;
    end;

    script8 = function(self)
--1289:	msped(0,0,c)
--128d:	move(0,d9,ff,6f,0)
--1293:	dir(0,0)
--1296:	dfanm(0,1)
--1299:	talkr(0,c8)

        return 0;
    end;

    script9 = function(self)
--129d:	dfanm(3,1)

        return 0;
    end;

    script10 = function(self)
--12a1:	msped(0,0,c)
--12a5:	move(0,75,0,e4,2)
--12ab:	dir(0,0)
--12ae:	dfanm(0,1)
        script:request_start_wait("tobira", "script1", 6);
--12b4:	akao(0,0,0,28,40,c1,0,0,0,0,0,0,0)
--12c2:	idlck(4,1,0)

        return 0;
    end;
};



entity["man2"] = {
    on_start = function(self)
--12c7:	char(9)
--12c9:	tlkon(1)
--12cb:	solid(1)
--12cd:	visi(0)

        return 0;
    end;

    script1 = function(self)
        --CharMovable(Off)
        --MenuAccess(Off)
        --TURA(A,A,2)
        --CreateWindow(0,8,A0,C7,39)
        --Dialog(0,2D)
        --Wait(4)
        --MENU(0,8,9)
        --CreateWindow(0,8,A0,F5,39)
        --Dialog(0,2E)
        --CharMovable(On)
        --MenuAccess(On)

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1300:	xyzi(0,0,d9,ff,3e,3,0,0,f6,0)
--130b:	dir(0,60)
--130e:	talkr(0,c8)
--1311:	dfanm(3,1)
--1314:	tlkon(0)
--1316:	solid(0)
--1318:	visi(1)

        return 0;
    end;

    script4 = function(self)
--131b:	wait(1e,0)
--131e:	msped(0,0,c)
--1322:	move(0,b1,ff,b2,0)
--1328:	dir(0,0)
--132b:	dir(0,0)
        while true do
--132e:	anim!2(3,1)
--1331:	wait(3c,0)
        end;

        return 0;
    end;

    script5 = function(self)
--1337:	move(0,42,ff,3e,1)
--133d:	move(0,2b,ff,bd,1)
--1343:	move(0,c8,fe,9c,1)
--1349:	dir(0,0)
        while true do
--134c:	dir(0,0)
--134f:	anim!2(3,1)
--1352:	wait(3c,0)
--1355:	wait(3c,0)
        end;

        return 0;
    end;
};



entity["man1"] = {
    on_start = function(self)
        --CHAR(A)
        --SLIDR(0,22)
        --TALKR(0,46)

        local progress = game:variable_get("progress_game");
        if progress == 108 then
            --TalkSwitch(Off)
            --SolidObject(Off)
            --VISI(Off)
        end;

        --DFANM(3,1)
        --DIR(0,80)

        return 0;
    end;

    script1 = function(self)
        local progress = game:variable_get("progress_game");
        if progress == 221 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --TURA(A,A,2)
            --CreateWindow(0,8,64,106,29)
            --Dialog(0,2F)
            --TURNGEN(0,80,2,A,1)
            --CharMovable(On)
            --MenuAccess(On)
        elseif progress >= 63 then
            local flags = game:variable_get("bank3[208]")
            if bit.band(flags, hex.to_dec('0x08')) == 0 then
                --CharMovable(Off)
                --MenuAccess(Off)
                --PMJMP(9D,0)
                --CANM!2(4,0,E,1)
                --DIRA(A)
                --CANM!2(4,E,1D,1)
                --DFANM(0,1)
                --DIR(0,20)
                --CreateWindow(3,8,A0,112,39)
                --Dialog(3,13)
                --Dialog(3,14)
                --Dialog(3,15)
                --DIR(0,60)
                --CANM!2(5,0,E,1)
                --CreateWindow(3,8,A0,9A,39)
                --Dialog(3,16)
                script:request_end_wait("cloud", "script4", 2);
                --Wait(1)
                game:variable_set("bank3[208]", bit.bor(flags, hex.to_dec('0x02')));
                --ChangeField(9D,0,A5,3,89,F8,1,0,40) -- mds7plr2
            end;
        end;

        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--1407:	xyzi(0,0,bf,fe,15,4,0,0,2,1)

        return 0;
    end;

    script4 = function(self)
--1413:	uc(1)
--1415:	menu2(1)
--1417:	xyzi(0,0,f,ff,95,3,0,0,ff,0)
--1422:	dir(0,80)
--1425:	dfanm(3,1)
--1428:	window(3,8,0,a0,0,6,1,39,0)
--1432:	message(3,17)
--1435:	uc(0)
--1437:	menu2(0)
        script:request_start_wait("ballet", "script5", 3);
--143c:	asped(0,30,0)
--1440:	msped(0,0,10)
--1444:	move(0,73,0,d,ff)
--144a:	move(0,ce,1,0,ff)
--1450:	tlkon(1)
--1452:	solid(1)
--1454:	visi(0)

        return 0;
    end;

    script5 = function(self)
--1457:	tlkon(1)
--1459:	solid(1)
--145b:	visi(0)
--145d:	talkr(0,0)

        return 0;
    end;

    script6 = function(self)
--1461:	xyzi(0,0,bf,fe,15,4,0,0,2,1)
--146c:	talkr(0,96)

        while true do
--146f:	msped(0,0,8)
--1473:	move(0,9a,ff,84,3)
--1479:	dfanm(6,1)
--147c:	dir(0,60)
--147f:	wait(3c,0)
--1482:	move(0,bf,fe,15,4)
--1488:	dfanm(6,1)
--148b:	dir(0,60)
--148e:	wait(3c,0)
        end;

        return 0;
    end;

    script7 = function(self)
--1494:	wait(a,0)
--1497:	msped(0,0,c)
--149b:	move(0,85,ff,63,0)
--14a1:	dir(0,20)
--14a4:	talkr(0,c8)
--14a7:	dfanm(0,1)

        return 0;
    end;

    script8 = function(self)
--14ad:	dfanm(7,1)

        return 0;
    end;

    script9 = function(self)
--14b1:	move(0,2d,ff,80,0)
--14b7:	move(0,43,ff,a8,3)
--14bd:	move(0,be,fe,12,4)
--14c3:	dir(0,80)
--14c6:	dfanm(3,1)

        return 0;
    end;
};



entity["woman1"] = {
    on_start = function(self)
--14ca:	char(11)
--14cc:	tlkon(1)
--14ce:	solid(1)
--14d0:	visi(0)

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
--14d6:	xyzi(0,0,42,0,12,3,0,0,f5,0)
--14e1:	solid(1)
--14e3:	tlkon(0)
--14e5:	solid(0)
--14e7:	visi(1)

        while true do
--14e9:	turngen(0,80,2,a,1)
--14ef:	wait(1e,0)
--14f2:	turngen(0,60,2,a,1)
--14f8:	wait(3c,0)
        end;

        return 0;
    end;

    script4 = function(self)
--14fe:	wait(1e,0)
--1501:	msped(0,0,c)
--1505:	move(0,31,0,b1,0)
--150b:	dir(0,0)
--150e:	dfanm(0,1)]
        while true do
--1511:	turngen(0,0,2,a,1)
--1517:	wait(1e,0)
--151a:	turngen(0,e0,2,a,1)
--1520:	wait(3c,0)
        end;

        return 0;
    end;

    script5 = function(self)
--1526:	solid(1)
--1528:	move(0,cb,0,b3,0)
--152e:	solid(0)
        while true do
--1530:	turngen(0,80,2,a,1)
--1536:	wait(1e,0)
--1539:	turngen(0,a0,2,a,1)
--153f:	wait(3c,0)
        end;

        return 0;
    end;
};



entity["save"] = {
    on_start = function(self)
        CHAR(C)

        local progress = game:variable_get("progress_game");
        if progress >= 212 then
            --XYZI(0,179,446,0,10C)
            --SolidObject(Off)
        else
            --XYZI(0,-163,296,0,E7)
            --SolidObject(Off)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;
};



entity["savel0"] = {
    on_start = function(self)
        --LineSet(-181,2A2,0,-14E,27B,0)

        local progress = game:variable_get("progress_game");
        if progress >= 212 then
            --SLINE(0,0,0,79,1,B2,4,0,0,7F,1,C9,3,0,0)
        end;

        return 0;
    end;

    script1 = function(self)
        return 0;
    end;

    script2 = function(self)
        return 0;
    end;

    script3 = function(self)
        return 0;
    end;

    script4 = function(self)
        return 0;
    end;

    script5 = function(self)
        --SOUND(0,67,1,40)
        local flags = game:variable_get("bankD[ 91]")
        if bit.band(flags, hex.to_dec('0x02')) == 0x00 then
            --CharMovable(Off)
            --MenuAccess(Off)
            --WSIZW(3,3E,0,A,0,B4,0,39,0)
            --Dialog(3,2B)
            --CharMovable(On)
            --MenuAccess(On)
        end;

        local flags = game:variable_get("bankD[ 91]");
        game:variable_set("bankD[ 91]", bit.bor(flags, hex.to_dec('0xFD')));

        local flags = game:variable_get("bank2[ 28]");
        game:variable_set("bank2[ 28]", hex.to_dec('0x0100'));

        return 0;
    end;

    script6 = function(self)
        local flags = game:variable_get("bankD[ 91]");
        game:variable_set("bankD[ 91]", bit.band(flags, hex.to_dec('0xFD')));

        local flags = game:variable_get("bank2[ 28]");
        game:variable_set("bank2[ 28]", bit.bor(flags, hex.to_dec('0x0300')));

        return 0;
    end;
};
