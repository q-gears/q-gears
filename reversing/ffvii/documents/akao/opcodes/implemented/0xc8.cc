// cyclic increment ch[0xb8] by one
ch[0xb8] = (ch[0xb8] + 1) & 3;

// save stream position to save_pos[ch[0xb8]]
ch[ch[0xb8] * 4 + 4] = ch[0x00];

// clear pos_num[ch[0xb8]]
ch[ch[0xb8] * 2 + 0xba] = 0;
