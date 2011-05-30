// channel number counting from 0
if(!ch[0x54])
	gl[0x34] &= ~(1 << <channel_number>);
else
	(0x80099ff4) &= ch[0x54];

call(0x80030148);
ch[0xA6] = 0x00;
