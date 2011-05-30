ch[0x38] |= 0x04;
ch[0x98] = p[0] ? p[0] : 0x100;
ch[0x9c] = p[1];
ch[0x9A] = 0x01;
// (calculation of real file offset: <asm_offset> - 8000f800)
// table from 0x3adcc
$at = 0x8004a5cc;
$at += p[1] << 2;
ch[0x20] = ($at);
