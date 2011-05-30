// void sub_80031820(a0: <channel structure pointer>, a1: <instrument number>);
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
