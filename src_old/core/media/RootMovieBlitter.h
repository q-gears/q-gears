/*
	This file is part of Q-Gears.

	Copyright 2008,2009 Gennadiy Brich

	Q-Gears is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Q-Gears is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with Q-Gears.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef ROOT_MOVIE_BLITTER_HH__
#define ROOT_MOVIE_BLITTER_HH__



#include "MovieBlitter.h"



class RootMovieBlitter : public MovieBlitter
{
private:
	static const bool m_USE_SHADERS = true;
	
	int m_FrameWidth;
	int m_FrameHeight;
	
	Ogre::TexturePtr m_Texture;
	uint32_t YCbCr2RGBA(uint32_t arg_yuv);
	uint8_t ClampU8(const int x);
	
public:
	~RootMovieBlitter();
	
	virtual void Init(int arg_frame_width, int arg_frame_height);
	virtual void Blit(void *arg_frame, void *arg_custom, int arg_custom_size);
};



#endif
