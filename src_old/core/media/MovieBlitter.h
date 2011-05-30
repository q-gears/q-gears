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



#ifndef MOVIE_BLITTER_HH__
#define MOVIE_BLITTER_HH__



class MovieBlitter
{
public:
	template <typename T>
	static MovieBlitter *Create() {return static_cast<MovieBlitter *>(new T);};
	
	virtual void Init(int arg_frame_width, int arg_frame_height) = 0;
	virtual void Blit(void *arg_frame, void *arg_custom, int arg_custom_size) = 0;
};



#endif
