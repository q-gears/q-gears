// channel number counting from 0

$t0 = p[0] * 64 + 0x80075F28;

if(ch[0x54] && !((1 << <channel number>) & gl[0x0C] & (0x80099FCC)))
{
	ch[0xE0] |= 0x10;
	ch[0x30] = (((ch[0x30] * m_InstrumentIndex[p[0]].pitch[0]) & 0xffffffff) /
			(m_InstrumentIndex[ch[0x58]].pitch[0])) & 0xffffffff;
}

ch[0x58] = p[0];
ch[0xE4] = 0x76fe0;
ch[0xE8] = m_InstrumentIndex[p[0]].loop_offset;
ch[0xFA] = m_InstrumentIndex[p[0]].attack_rate;
ch[0xFC] = m_InstrumentIndex[p[0]].decay_rate;
ch[0xFE] = m_InstrumentIndex[p[0]].sustain_level;
ch[0x100] = m_InstrumentIndex[p[0]].sustain_rate;
ch[0xEC] = m_InstrumentIndex[p[0]].attack_mode;
ch[0xF0] = m_InstrumentIndex[p[0]].sustain_mode;

if(ch[0x38] & 0x200)
	ch[0xE0] |= 0x1bb80;
else
{
	ch[0x102] = m_InstrumentIndex[p[0]].release_rate;
	ch[0xF4] = m_InstrumentIndex[p[0]].release_mode;
	ch[0xE0] |= 0x1ff80;
}

