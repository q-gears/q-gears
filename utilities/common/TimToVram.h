#ifndef TIM_FILE_H
#define TIM_FILE_H

#include "Vram.h"

class File;

void LoadTimFileToVram( File* file, int tim_offset, Vram* vram );



#endif
