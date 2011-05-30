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



#include <fstream>
#include <OgreRoot.h>
#include <OgreTextureManager.h>
#include <OgreMaterialManager.h>
#include <OgreHardwarePixelBuffer.h>

#include "RootMovieBlitter.h"



void RootMovieBlitter::Init(int arg_frame_width, int arg_frame_height)
{
	m_FrameWidth = arg_frame_width;
	m_FrameHeight = arg_frame_height;
	
	m_Texture = Ogre::TextureManager::getSingleton().createManual("movie_texture",
		Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
		Ogre::TEX_TYPE_2D, m_FrameWidth, m_FrameHeight,
		1, 0, Ogre::PF_BYTE_RGBA, Ogre::TU_DYNAMIC_WRITE_ONLY);
	
	// get material for texture
	Ogre::MaterialPtr material = Ogre::MaterialManager::getSingleton().getByName(m_USE_SHADERS ? "movie_shader" : "movie_software");
	material->getTechnique(0)->getPass(0)->createTextureUnitState("movie_texture");

	// create background rectangle covering the whole screen
	Ogre::Rectangle2D *rectangle = new Ogre::Rectangle2D(true);
	rectangle->setCorners(-1.0, 1.0, 1.0, -1.0);
	rectangle->setMaterial(m_USE_SHADERS ? "movie_shader" : "movie_software");

	// render the background before everything else
	rectangle->setRenderQueueGroup(Ogre::RENDER_QUEUE_BACKGROUND);

	// use infinite AAB to always stay visible
	Ogre::AxisAlignedBox aab_inf;
	aab_inf.setInfinite();
	rectangle->setBoundingBox(aab_inf);

	// attach background to the scene
	Ogre::SceneNode* node = Ogre::Root::getSingleton().getSceneManager("Scene")->getRootSceneNode()->createChildSceneNode("BackgroundMovie");
	node->attachObject(rectangle);
}


RootMovieBlitter::~RootMovieBlitter()
{
	//TODO: perform cleanup :)
}


void RootMovieBlitter::Blit(void *arg_frame, void *arg_custom, int arg_custom_size)
{
/*
	if(arg_custom_size)
	{
		std::ofstream oF;
		oF.open("camera.dump", std::ios::binary | std::ios::app);
		oF.write(static_cast<char *>(arg_custom), arg_custom_size);
		oF.close();
	}
*/
	
	Ogre::HardwarePixelBufferSharedPtr pixel_buffer = m_Texture->getBuffer();
	pixel_buffer->lock(Ogre::HardwareBuffer::HBL_NORMAL);
	const Ogre::PixelBox& pixel_box = pixel_buffer->getCurrentLock();
	
	// do software YCbCr2RGB
	if(m_USE_SHADERS)
	{
		memcpy(pixel_box.data, arg_frame, m_FrameWidth * m_FrameHeight * sizeof(uint32_t));
	}
	// do YCbCr2RGB using shader
	else
	{
		uint32_t *write_ptr = (uint32_t *)pixel_box.data;
		uint32_t *write_end = write_ptr + m_FrameWidth * m_FrameHeight;
		uint32_t *read_ptr = (uint32_t *)arg_frame;
		
		while(write_ptr != write_end)
			*write_ptr++ = YCbCr2RGBA(*read_ptr++);
	}
	
	pixel_buffer->unlock();
}


uint32_t RootMovieBlitter::YCbCr2RGBA(uint32_t arg_yuv)
{
	uint32_t result;
	
	uint8_t *yuv = (uint8_t *)&arg_yuv;
	
	int OY = 298 * (yuv[2] - 16);
	int U = yuv[1] - 128;
	int V = yuv[0] - 128;
	
	uint8_t *rgb = (uint8_t *)&result;
	
	rgb[3] = 0xff;                                         // A
	rgb[2] = ClampU8((OY + 409 * V + 128) >> 8);           // R
	rgb[1] = ClampU8((OY - 100 * U - 208 * V + 128) >> 8); // G
	rgb[0] = ClampU8((OY + 516 * U + 128) >> 8);           // B
	
	return result;
}


uint8_t RootMovieBlitter::ClampU8(const int x)
{
	return x < 0x00 ? 0x00 : (x > 0xff ? 0xff : (uint8_t)x);
}
