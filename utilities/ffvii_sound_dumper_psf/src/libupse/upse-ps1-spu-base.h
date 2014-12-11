int SPUinit(void);
int SPUopen(void);
void SPUsetlength(s32 stop, s32 fade);
int SPUclose(void);
void SPUendflush(void);

// External, called by SPU code.
void SPUirq(void);

extern u32 sampcount;
extern upse_breakpoint_callback_func_t _upse_breakpoint_callback_f;
extern void *_upse_breakpoint_cb_user_data;
extern u32 _upse_breakpoint_address;
