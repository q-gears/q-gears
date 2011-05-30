// current position is set on next opcode
ch[0x38] |= (1 << 3);
ch[0x14] = <current_position> + ((p[1] << 8) | p[0]);
