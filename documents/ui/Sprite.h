#ifndef __SPRITE_H_
#define __SPRITE_H_

//////////////////////////////////////////////////////////////////////////////
//
// Created: 27-Feb-2009
// Copyright © 2009, Targem LLC. All rights reserved.
//
//----------------------------------------------------------------------------
// $Id:
//----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////

//
namespace Puzzle
{ 
	// fwd
	class cl_Texture;
	struct st_SpriteData;


	/// type of sprite render
	enum e_SpriteType
	{
		RENDER_XY = 0,
		RENDER_XYROTSCALE,
		RENDER_STRETCH,
		RENDER_V4,
	};

	
	/**
		@class	cl_Texture
		@brief	texture working unit
	 */
	class cl_Sprite
	{
	public:
								cl_Sprite( f32 fX, f32 fY, f32 fWidth, f32 fHeight, cl_Texture* pTex = NULL );
								cl_Sprite( cl_Texture* pTex, const st_SpriteData* pData );
		virtual					~cl_Sprite();
		

	public:
		///	render sprite
		void					f_Render() const;
		void					f_RenderEx( f32 fX, f32 fY, f32 fRot = 0.0f, f32 fScaleX = 1.0f, f32 fScaleY = 0.0f );
		
		/**
			All sprite settings will apply after sprite validating!!!
		*/
		void					f_Validation();

		//////////////////////////////////////////////////////////////////////////
		// Quad functions
		/// return quad, to sprite by position and scale
		hgeQuad&				f_GetQuad( f32 fX, f32 fY, f32 fScale );
		hgeQuad&				f_GetQuad( f32 fX, f32 fY, f32 fScaleX, f32 fScaleY );
		hgeQuad&				f_GetQuadRot( f32 fX, f32 fY, f32 fRot, f32 fScale );
		hgeQuad&				f_GetQuadRot( f32 fX, f32 fY, f32 fRot, f32 fScaleX, f32 fScaleY );


		//////////////////////////////////////////////////////////////////////////
		// Set functions

		/// Set sprite scale
		void					f_SetScale( f32 fXScale, f32 fYScale = -1.0f );
		/// Set sprite rotation
		void					f_SetRotation( f32 fRot );
		/// Set size of sprite
		void					f_SetSize( f32 fWidth, f32 fHeight );
		/// Set position of sprite on screen coordinates. Apply immediately.
		void					f_SetPosition( f32 fX1, f32 fY1, f32 fX2, f32 fY2 );
		/// Set position of each sprite vertices on screen coordinates. Apply immediately.
		void					f_SetPosition( f32 fX0, f32 fY0, f32 fX1, f32 fY1, f32 fX2, f32 fY2, f32 fX3, f32 fY3 );
		/// Set position of sprite
		void					f_SetPosition( f32 fX, f32 fY );
		/// Set sprite hot spot (piVot of sprite)
		void					f_SetHotSpot( f32 fX, f32 fY );
		/// set sprite render type
		void					f_SetType( e_SpriteType nType );
		/// Set render blend mode
		void					f_SetBlendMode( i32 iBlend );
		/// Set blend index
		void					f_SetBlendIndex( i32 iBlend );
		/// Set sprite texture uv rect
		void					f_SetTextureRect( f32 fX, f32 fY, f32 fW, f32 fH );
		/// update render target texture
		void					f_RestoreRenderTargetTexture();


		/// Flip texture image in the sprite. Apply immediately.
		void					f_SetFlip( bool bX, bool bY, bool bHotSpot = false );
		/// Set color of sprite or some vertex of sprite
		void					f_SetColor( u32 iCol, i32 iVert = -1 );
		/// Set Z of sprite or some vertex of sprite
		void					f_SetZ( f32 fZ, i32 iVert = -1 );
		
		
		//////////////////////////////////////////////////////////////////////////
		// Add functions
		void					f_AddScale( f32 fXScale, f32 fYScale = -1.0f );
		void					f_AddRotation( f32 fRot );
		void					f_AddSize( f32 fWidth, f32 fHeight );
		void					f_AddPosition( f32 fX, f32 fY );

		//////////////////////////////////////////////////////////////////////////
		// Get functions
		const Vec2&				f_GetScale() const;
		f32						f_GetRotation() const;
		void					f_GetSize( f32& fWidth, f32& fHeight ) const;
		const Vec2&				f_GetPosition() const;
		const Vec2&				f_GetHotSpot() const;
		e_SpriteType			f_GetType() const;
		i32						f_GetBlendMode() const;

		u32						f_GetColor( i32 iVert = 0 ) const;
		f32						f_GetZ( i32 iVert = 0 ) const;
		void					f_GetFlip( bool& bX, bool& bY ) const;

		cl_Texture*				f_GetTexture();
		const st_SpriteData*	f_GetBaseSprite()const;
		const char*				f_GetTexName() const;
		Boundsf					f_GetTextureRect() const;

	private:
		// no realization
								cl_Sprite( const cl_Sprite& );
		const cl_Sprite&		operator = ( const cl_Sprite& );

		/// create sprite quad
		void					f_CreateSprite( bool bFullInit = true );

	private:
		intrusive_ptr< cl_Texture >	v_pTexture;		// sprite texture
		const st_SpriteData*	v_pData;			// base sprite data
		Boundsf					v_stTexRect;		// current texture rect

		hgeQuad					v_stQuad;			// sprite geometry
				
		bool					v_bXFlip;			// flip sprite by x axis
		bool					v_bYFlip;			// flip sprite by y axis
		bool					v_bHSFlip;			// flip hot spot
		
		e_SpriteType			v_nType;			// type of sprite

		
		//////////////////////////////////////////////////////////////////////////
		// sprite configuration data

		st_Transform			v_stTransform;		// pos / rot / scale
		bool					v_bNeedValidate;	// need validate of transformation
		Vec2					v_stHotSpot;		// sprite hot spot
		
		f32						v_fWidth;			// width of sprite on the screen
		f32						v_fHeight;			// height of sprite on the screen
	};


	//////////////////////////////////////////////////////////////////////////
	// Set functions

	//
	inline
	void	cl_Sprite::f_SetScale( f32 fXScale, f32 fYScale )
	{
		v_stTransform.v_stScale.v_fX = fXScale;
		v_stTransform.v_stScale.v_fY = fYScale < 0.0f ? fXScale : fYScale;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_SetRotation( f32 fRot )
	{
		v_stTransform.v_fRotation = fRot;
		v_bNeedValidate = true;
	}
	
	
	//
	inline
	void	cl_Sprite::f_SetSize( f32 fWidth, f32 fHeight )
	{
		v_fWidth	= fWidth;
		v_fHeight	= fHeight;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_SetPosition( f32 fX, f32 fY )
	{
		v_stTransform.v_stPos.Set( fX, fY );
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_SetHotSpot( f32 fX, f32 fY )
	{
		v_stHotSpot.v_fX = fX;
		v_stHotSpot.v_fY = fY;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_SetType( e_SpriteType nType )
	{
		v_nType = nType;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_SetBlendMode( i32 iBlend )
	{ 
		v_stQuad.blend = iBlend; 
	}


	//////////////////////////////////////////////////////////////////////////
	// Add functions

	//
	inline
	void	cl_Sprite::f_AddScale( f32 fXScale, f32 fYScale )
	{
		v_stTransform.v_stScale.v_fX += fXScale;
		v_stTransform.v_stScale.v_fY += fYScale < 0.0f ? fXScale : fYScale;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_AddRotation( f32 fRot )
	{
		v_stTransform.v_fRotation += fRot;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_AddSize( f32 fWidth, f32 fHeight )
	{
		v_fWidth	+= fWidth;
		v_fHeight	+= fHeight;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_Sprite::f_AddPosition( f32 fX, f32 fY )
	{
		v_stTransform.v_stPos += Vec2( fX, fY );
		v_bNeedValidate = true;
	}

	//////////////////////////////////////////////////////////////////////////
	// Get functions
	//
	inline
	const Vec2&		cl_Sprite::f_GetScale() const
	{
		return v_stTransform.v_stScale;
	}


	//
	inline
	f32		cl_Sprite::f_GetRotation() const
	{
		return v_stTransform.v_fRotation;
	}
	

	//
	inline
	void	cl_Sprite::f_GetSize( f32& fWidth, f32& fHeight ) const
	{
		fWidth	= v_fWidth;
		fHeight = v_fHeight;
	}
	

	//
	inline
	const Vec2&		cl_Sprite::f_GetPosition() const
	{
		return v_stTransform.v_stPos;
	}
	

	//
	inline
	const Vec2&		cl_Sprite::f_GetHotSpot() const
	{
		return v_stHotSpot;
	}
	

	//
	inline
	e_SpriteType	cl_Sprite::f_GetType() const
	{
		return v_nType;
	}
	

	//
	inline
	i32		cl_Sprite::f_GetBlendMode() const
	{
		return v_stQuad.blend;
	}
	

	//
	inline
	u32		cl_Sprite::f_GetColor( i32 iVert ) const
	{
		return v_stQuad.v[ iVert ].col;
	}
	

	//
	inline
	f32		cl_Sprite::f_GetZ( i32 iVert ) const
	{
		return v_stQuad.v[ iVert ].z;
	}
	

	//
	inline
	void	cl_Sprite::f_GetFlip( bool& bX, bool& bY ) const
	{
		bX = v_bXFlip;
		bY = v_bYFlip;
	}


	//
	inline
	const st_SpriteData*	cl_Sprite::f_GetBaseSprite() const
	{
		return v_pData;
	}


	//
	inline
	Boundsf		cl_Sprite::f_GetTextureRect() const
	{
		return v_stTexRect;
	}


	//
	inline
	cl_Texture*		cl_Sprite::f_GetTexture()
	{
		return v_pTexture.get();
	}
}	// namespace Puzzle



#endif	// __SPRITE_H_
