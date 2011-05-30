// channel number counting from 0
if(!ch[0x54])
	gl[0x34] |= (1 << <channel_number>);
else if(!((1 << <channel_number>) & 0x555555))
	(0x80099ff4) |= (1 << <channel_number>);

call(0x80030148);
