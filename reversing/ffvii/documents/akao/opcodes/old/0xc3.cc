// channel number counting from 0
if(ch[0x54])
	(0x80099ff1) &= ~(1 << <channel_number>);
else
	gl[0x30] &= ~(1 << <channel_number>);

call(0x80030038);
