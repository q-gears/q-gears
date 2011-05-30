if(ch[0x38] & 0x100)
{
	gl[0x24] &= ~(1 << ch[0x24]);
	ch[0x38] &= ~0x100;
}

if(!ch[0x54] && !($a2 & gl[0x0C] & dword_80099FCC))
{
	// set flag, that we changed pitch
	ch[0xE0] |= 0x10;
	
	v0 = ch[0x30] mult m_InstrumentIndex[p[0]].pitch[0];
	
	ch[0x30] = $v0 / m_InstrumentIndex[ch[0x58]].pitch[0];
}

// if loaded adsr release rate, load rest
if(ch[0x38] & 0x200)
{
	ch[0x58] = p[0];
	ch[0xE4] = m_InstrumentIndex[p[0]].start_offset;
	ch[0xE8] = m_InstrumentIndex[p[0]].loop_offset;
	ch[0xFA] = m_InstrumentIndex[p[0]].attack_rate;
	ch[0xFC] = m_InstrumentIndex[p[0]].decay_rate;
	ch[0xFE] = m_InstrumentIndex[p[0]].sustain_level;
	ch[0x100] = m_InstrumentIndex[p[0]].sustain_rate;
	ch[0xEC] = m_InstrumentIndex[p[0]].attack_mode;
	ch[0xF0] = m_InstrumentIndex[p[0]].sustain_mode;

	// set flags, that we changed instrument addresses and adsr settings
	ch[0xE0] |= 0x1bb80;
}
// else load everything
else
{
	akao_load_adsr_to_memory(ch, p[0]);
}

void akao_load_adsr_to_memory(u8* ch, u8 a1)
{
	ch[0x58] = a1;
	ch[0xE4] = m_InstrumentIndex[a1].attack_offset;
	ch[0xE8] = m_InstrumentIndex[a1].loop_offset;
	ch[0xEC] = m_InstrumentIndex[a1].attack_mode;
	ch[0xF0] = m_InstrumentIndex[a1].sustain_mode;
	ch[0xF4] = m_InstrumentIndex[a1].release_mode;
	ch[0xFA] = m_InstrumentIndex[a1].attack_rate;
	ch[0xFC] = m_InstrumentIndex[a1].decay_rate;
	ch[0xFE] = m_InstrumentIndex[a1].sustain_level;
	ch[0x100] = m_InstrumentIndex[a1].sustain_rate;
	ch[0x102] = m_InstrumentIndex[a1].release_rate;
	
	ch[0xE0] |= 0x1ff80;
}

