// channel number counting from 0
$v0 = ch[0x54];

if(!$v0)
	gl[0x2C] |= (1 << <channel_number>);
else
	(0x80099fec) |= (1 << <channel_number>);

(0x8009a13c) |= 0x10;

call(0x8002FF4C)(0x80096608, 0x8009A104, 0x00000001, 0x80096608);
