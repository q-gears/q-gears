ch[0x102] = p[0];

if(!(ch[0x38] & 0x200))
{
	u32 some_global_mask = gl[0x04] | gl[0x24] | gl[0x28];

	int i = 0;
	u8 channel_mask = 0x01;
	do
	{
		if(!(some_global_mask & channel_mask))
			break;

		channel_mask <<= 1;
		++i;
	}while(channel_mask & 0xffffff);

	if(channel_mask & 0xffffff)
	{
		gl[0x28] |= channel_mask;
		ch[0x28] = i & 0xffff;
		ch[0x38] |= 0x200;
	}
}
