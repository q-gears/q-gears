// increment pos_num[ch[0xb8]]
++ch[ch[0xb8] * 2 + 0xba];

// set stream position to save_pos[ch[0xb8]]
ch[0x00] = ch[ch[0xb8] * 4 + 4];
