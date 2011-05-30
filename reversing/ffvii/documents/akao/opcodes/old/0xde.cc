// "/" is mips div instruction
ch[0x92] = p[0] ? p[0] : 0x100;
ch[0x94] = ((p[1] * 256 - ch[0x90]) /
		(p[0] ? p[0] : 0x100)) & 0xffffffff;
