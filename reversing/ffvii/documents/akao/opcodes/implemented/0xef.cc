if(gl[0x4e] && gl[0x4e] >= p[0])
{
	// channel_position already points to next opcode
	ch[0x00] += (s16)(p[1] | (p[2] << 8));
	gl[0x4c] = p[0];
}
