gl[0x50] = p[0] ? p[0] : 0x100;

// "/" is mips div instruction
gl[0x40] &= 0xffff0000;
gl[0x44] = (((p[1] << 16 | p[2] << 24)
		- gl[0x40]) / gl[0x50]) & 0xffffffff;
