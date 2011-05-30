// channel number counting from 0
if(!ch[0x54])
{
	gl[0x04] &= ~(1 << <channel_number>);

	if(!gl[0x04])
		gl[0x4a] = 0x00;

	gl[0x2c] &= ~(1 << <channel_number>);
	gl[0x34] &= ~(1 << <channel_number>);
	gl[0x30] &= ~(1 << <channel_number>);

	if(ch[0x38] & 0x100)
		gl[0x24] &= ~(1 << ((0x80062f04)) ? ch[0x24] - 0x18 : ch[0x24]);

	if(ch[0x38] & 0x200)
		gl[0x28] &= ~(1 << ch[0x28]);
}
else
{
	u32 a3 = (1 << <channel_number>) xor 0xff0000;
	(0x80099fcc) &= a3; // 32-bit
	(0x80099fec) &= a3; // 32-bit
	(0x80099ff0) &= a3; // 32-bit
	(0x80099ff4) &= a3; // 32-bit

	gl[0x08] &= ~(1 << <channel_number>);
	gl[0x0c] &= ~(1 << <channel_number>);
	gl[0x10] &= ~(1 << <channel_number>);

	ch<ch[0x28]>[0xe0] |= 0x1ff80;
}

ch[0x38] = 0x00;
gl[0x38] |= 0x10;

call(0x8002ff4c);
call(0x80030038);
call(0x80030148);
