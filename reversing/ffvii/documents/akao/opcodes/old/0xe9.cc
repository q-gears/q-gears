gl[0x48] = p[0] ? p[0] : 0x100;

// "/" is mips div instruction
gl[0x18] &= 0xffff0000;
gl[0x1C] = (((p[1] << 16 | p[2] << 24)
		- gl[0x18]) / gl[0x48]) & 0xffffffff;
