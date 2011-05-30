if(p[0])
{
	u16 result = (p[0] + ch[0xC2]) & 0xffff;

	if(result <= 0)
		ch[0xC4] = 0x01;
	else if(result >= 100)
		ch[0xC4] = 0xFF;
	else
		ch[0xC4] = result;
}
else
	ch[0xC4] = 0x00;
