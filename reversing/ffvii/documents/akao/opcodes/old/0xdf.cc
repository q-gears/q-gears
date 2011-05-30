// "/" is mips div instruction
ch[0xA0] = p[0] ? p[0] : 0x100;
ch[0xA2] = ((p[1] * 128 - ch[0x9E]) /
		(p[0] ? p[0] : 0x100)) & 0xffffffff;
