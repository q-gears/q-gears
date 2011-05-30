u16 some_channel_number;
u32 some_channel_mask;
if(ch[0x38] & 0x100)
{
	some_channel_number = (u16)ch[0x24];
	some_channel_mask = 1 << (ch[0x24] < 0x18 ? ch[0x24] : ch[0x24] - 0x18);
}
else
{
	some_global_mask = gl[0x04] | gl[0x24] | gl[0x28];
	some_channel_number = ((0x80062f04)) ? 0x18 : 0x00;
	
	some_channel_mask = 1;
	candidate_mask = some_global_mask & some_channel_mask;
	while(candidate_mask)
	{
		some_channel_mask = some_channel_mask << 1;
		++some_channel_number;
		if(!(some_channel_mask & 0xffffff))
			return;
		candidate_mask = some_global_mask & some_channel_mask;
	}
}

if(!(some_channel_mask & 0xffffff))
	return;

gl[0x24] |= some_channel_mask;
ch[0x24] = some_channel_number;
ch[0x38] |= 0x100;

call(0x80031820)(ch, p[0]);
call(0x80031820)(ch<some_channel_number>, p[1]);
