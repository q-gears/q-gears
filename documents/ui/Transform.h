#ifndef __TRANSFORM_H_
#define __TRANSFORM_H_

//////////////////////////////////////////////////////////////////////////////
//
// Created: 31-Mar-2009
// Copyright © 2009, Targem LLC. All rights reserved.
//
//----------------------------------------------------------------------------
// $Id:
//----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////


namespace Puzzle
{
	/**
		@struct st_Transform
		@brief transformation of object
	*/
	struct st_Transform
	{
		f32						v_fRotation;			// object rotation
		Vec2					v_stScale;				// object scale by x, y
		Vec2					v_stPos;				// object position
		Vec2					v_stHotSpot;			// object hot spot
		//
								st_Transform();
		/// make base values
		void					f_Init();
	};


	//
	inline
	st_Transform::st_Transform()
		: v_fRotation		( 0.0f )
		, v_stScale			( 1.0f, 1.0f )
		, v_stPos			( 0.0f, 0.0f )
		, v_stHotSpot		( 0.0f, 0.0f )
	{
	}

	//
	inline
	void	st_Transform::f_Init()
	{
		v_fRotation		= 0.0f;
		v_stScale.Set( 1.0f, 1.0f );
		v_stPos.Set( 0.0f, 0.0f );
		v_stHotSpot.Set( 0.0f, 0.0f );
	}
} // namespace Puzzle

#endif // __TRANSFORM_H_