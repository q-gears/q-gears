// get opcode parameter
u32 a1 = p[0] ? p[0] : 0x100;

// increment stream position
++ch[0x00];

// if parameter not equal saved pos_number[ch[0xb8]]
if(ch[ch[0xb8] * 2 + 0xba] != $a1)
{
	// set stream position to save_pos[ch[0xb8]]
	ch[0x00] = ch[ch[0xb8] * 4 + 4];
}
// if parameter equal pos_number[ch[0xb8]]
else
{
	// cyclic decrement ch[0xb8] by one
	ch[0xb8] = (ch[0xb8] + 3) & 3;
}

// increment pos_number[ch[0xb8]]
++ch[ch[0xb8] * 2 + 0xba];
