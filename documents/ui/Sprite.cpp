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
#include "Precompiled.h"
#include "Sprite.h"
#include "Texture.h"
#include "Core.h"

//
namespace Puzzle
{
	cl_Sprite::cl_Sprite( f32 fX, f32 fY, f32 fWidth, f32 fHeight, cl_Texture* pTex )
		: v_pTexture		( pTex )
		, v_pData			( NULL )
		, v_stTexRect		( 0.0f, 0.0f, 0.0f, 0.0f )

		, v_stQuad			()
				
		, v_bXFlip			( false )
		, v_bYFlip			( false )
		, v_bHSFlip			( false )
		
		, v_nType			( RENDER_XY )

		, v_stTransform		()
		, v_bNeedValidate	( true )
		, v_stHotSpot		( 0.0f, 0.0f )

		, v_fWidth			( fWidth )
		, v_fHeight			( fHeight )
	{
		v_stTransform.v_stPos.Set( fX, fY );
		f_CreateSprite();
	}


	//
	cl_Sprite::cl_Sprite( cl_Texture* pTex, const st_SpriteData* pData )
		: v_pTexture		( pTex )
		, v_pData			( pData )
		, v_stTexRect		( 0.0f, 0.0f, 0.0f, 0.0f )

		, v_stQuad			()
				
		, v_bXFlip			( false )
		, v_bYFlip			( false )
		, v_bHSFlip			( false )
		
		, v_nType			( RENDER_XY )

		, v_stTransform		()
		, v_stHotSpot		( 0.0f, 0.0f )

		, v_fWidth			( 0.0f )
		, v_fHeight			( 0.0f )
	{
		M3D_ASSERT_MSG( "FiloXSee", v_pTexture.get() != NULL, "Texture can not be invalide!" );
		M3D_ASSERT_MSG( "FiloXSee", v_pData != NULL, "Sprite data can not be invalide!" );

		v_stTexRect = v_pData->v_stRect;
		f_CreateSprite();
	}
	
	
	//
	cl_Sprite::~cl_Sprite()
	{
	}


	//
	void	cl_Sprite::f_CreateSprite( bool bFullInit )
	{
		v_stQuad.tex = NULL;
		if( v_pTexture )
		{
			if( v_pTexture->f_IsRenderTarget() )
				v_stQuad.tex = g_pHGE->Target_GetTexture( (HTARGET)v_pTexture->f_GetTexture() );
			else
				v_stQuad.tex = v_pTexture->f_GetTexture();
		}

		if( v_pData )
		{
			v_fWidth	= v_stTexRect.v_Width;
			v_fHeight	= v_stTexRect.v_Height;
		}

		f32 fTexWidth, fTexHeight;
		f32 fX1, fX2, fY1, fY2;
		if( v_pTexture )
		{
			v_pTexture->f_GetDims( fTexWidth, fTexHeight, false );

			if( v_stTexRect.v_Width == 0.0f || v_stTexRect.v_Height == 0.0f )
			{
				v_stTexRect.v_Width = v_fWidth;
				v_stTexRect.v_Height = v_fHeight;
			}

			fX1 = v_stTexRect.v_X / fTexWidth;
			fY1 = v_stTexRect.v_Y / fTexHeight;
			fX2 = (v_stTexRect.v_X + v_stTexRect.v_Width) / fTexWidth;
			fY2 = (v_stTexRect.v_Y + v_stTexRect.v_Height) / fTexHeight;
		}
		else
		{
			fX1 = 0.0f;
			fY1 = 0.0f;
			fX2 = 1.0f;
			fY2 = 1.0f;
		}

		v_stQuad.v[ 0 ].tx = fX1; v_stQuad.v[ 0 ].ty = fY1;
		v_stQuad.v[ 1 ].tx = fX2; v_stQuad.v[ 1 ].ty = fY1;
		v_stQuad.v[ 2 ].tx = fX2; v_stQuad.v[ 2 ].ty = fY2;
		v_stQuad.v[ 3 ].tx = fX1; v_stQuad.v[ 3 ].ty = fY2;

		if( bFullInit )
		{
			v_stQuad.v[ 0 ].z = 
			v_stQuad.v[ 1 ].z = 
			v_stQuad.v[ 2 ].z = 
			v_stQuad.v[ 3 ].z = 0.5f;
			
			v_stQuad.v[ 0 ].col = 
			v_stQuad.v[ 1 ].col = 
			v_stQuad.v[ 2 ].col = 
			v_stQuad.v[ 3 ].col = 0xffffffff;

			v_stQuad.blend=BLEND_DEFAULT;
		}
	}


	//
	void	cl_Sprite::f_Render() const
	{
		M3D_ASSERT( "FiloXSee", !v_bNeedValidate );
		g_pHGE->Gfx_RenderQuad( &v_stQuad );
	}


	//
	void	cl_Sprite::f_RenderEx( f32 fX, f32 fY, f32 fRot, f32 fScaleX, f32 fScaleY )
	{
		f32 fX1 = -v_stHotSpot.v_fX * fScaleX;
		f32 fY1 = -v_stHotSpot.v_fY * fScaleY;
		f32 fX2 = (v_fWidth - v_stHotSpot.v_fX) * fScaleX;
		f32 fY2 = (v_fHeight - v_stHotSpot.v_fY) * (fScaleY == 0.0f ? fScaleX : fScaleY);

		if( fRot != 0.0f )
		{
			f32 fCos = Cos( fRot );
			f32 fSin = Sin( fRot );
				
			v_stQuad.v[ 0 ].x  = fX1 * fCos - fY1 * fSin + fX;
			v_stQuad.v[ 0 ].y  = fX1 * fSin + fY1 * fCos + fY;	

			v_stQuad.v[ 1 ].x  = fX2 * fCos - fY1 * fSin + fX;
			v_stQuad.v[ 1 ].y  = fX2 * fSin + fY1 * fCos + fY;	

			v_stQuad.v[ 2 ].x  = fX2 * fCos - fY2 * fSin + fX;
			v_stQuad.v[ 2 ].y  = fX2 * fSin + fY2 * fCos + fY;	

			v_stQuad.v[ 3 ].x  = fX1 * fCos - fY2 * fSin + fX;
			v_stQuad.v[ 3 ].y  = fX1 * fSin + fY2 * fCos + fY;	
		}
		else
		{
			v_stQuad.v[ 0 ].x = fX1 + fX; v_stQuad.v[ 0 ].y = fY1 + fY;
			v_stQuad.v[ 1 ].x = fX2 + fX; v_stQuad.v[ 1 ].y = fY1 + fY;
			v_stQuad.v[ 2 ].x = fX2 + fX; v_stQuad.v[ 2 ].y = fY2 + fY;
			v_stQuad.v[ 3 ].x = fX1 + fX; v_stQuad.v[ 3 ].y = fY2 + fY;
		}
		g_pHGE->Gfx_RenderQuad( &v_stQuad );
	}


	//
	void	cl_Sprite::f_Validation()
	{
		switch( v_nType )
		{
			case RENDER_XY:
				{
					f32 fX1 = v_stTransform.v_stPos.v_fX - v_stHotSpot.v_fX;
					f32 fY1 = v_stTransform.v_stPos.v_fY - v_stHotSpot.v_fY;
					f32 fX2 = v_stTransform.v_stPos.v_fX + v_fWidth - v_stHotSpot.v_fX;
					f32 fY2 = v_stTransform.v_stPos.v_fY + v_fHeight - v_stHotSpot.v_fY;

					v_stQuad.v[ 0 ].x = fX1; v_stQuad.v[ 0 ].y = fY1;
					v_stQuad.v[ 1 ].x = fX2; v_stQuad.v[ 1 ].y = fY1;
					v_stQuad.v[ 2 ].x = fX2; v_stQuad.v[ 2 ].y = fY2;
					v_stQuad.v[ 3 ].x = fX1; v_stQuad.v[ 3 ].y = fY2;
				} break;

			case RENDER_XYROTSCALE:
				{
					f32 fX1 = -v_stHotSpot.v_fX * v_stTransform.v_stScale.v_fX;
					f32 fY1 = -v_stHotSpot.v_fY * v_stTransform.v_stScale.v_fY;
					f32 fX2 = (v_fWidth - v_stHotSpot.v_fX) * v_stTransform.v_stScale.v_fX;
					f32 fY2 = (v_fHeight - v_stHotSpot.v_fY) * v_stTransform.v_stScale.v_fY;

					if( v_stTransform.v_fRotation != 0.0f )
					{
						f32 fCos = Cos( v_stTransform.v_fRotation );
						f32 fSin = Sin( v_stTransform.v_fRotation );
							
						v_stQuad.v[ 0 ].x  = fX1 * fCos - fY1 * fSin + v_stTransform.v_stPos.v_fX;
						v_stQuad.v[ 0 ].y  = fX1 * fSin + fY1 * fCos + v_stTransform.v_stPos.v_fY;	

						v_stQuad.v[ 1 ].x  = fX2 * fCos - fY1 * fSin + v_stTransform.v_stPos.v_fX;
						v_stQuad.v[ 1 ].y  = fX2 * fSin + fY1 * fCos + v_stTransform.v_stPos.v_fY;	

						v_stQuad.v[ 2 ].x  = fX2 * fCos - fY2 * fSin + v_stTransform.v_stPos.v_fX;
						v_stQuad.v[ 2 ].y  = fX2 * fSin + fY2 * fCos + v_stTransform.v_stPos.v_fY;	

						v_stQuad.v[ 3 ].x  = fX1 * fCos - fY2 * fSin + v_stTransform.v_stPos.v_fX;
						v_stQuad.v[ 3 ].y  = fX1 * fSin + fY2 * fCos + v_stTransform.v_stPos.v_fY;	
					}
					else
					{
						v_stQuad.v[ 0 ].x = fX1 + v_stTransform.v_stPos.v_fX; v_stQuad.v[ 0 ].y = fY1 + v_stTransform.v_stPos.v_fY;
						v_stQuad.v[ 1 ].x = fX2 + v_stTransform.v_stPos.v_fX; v_stQuad.v[ 1 ].y = fY1 + v_stTransform.v_stPos.v_fY;
						v_stQuad.v[ 2 ].x = fX2 + v_stTransform.v_stPos.v_fX; v_stQuad.v[ 2 ].y = fY2 + v_stTransform.v_stPos.v_fY;
						v_stQuad.v[ 3 ].x = fX1 + v_stTransform.v_stPos.v_fX; v_stQuad.v[ 3 ].y = fY2 + v_stTransform.v_stPos.v_fY;
					}
				} break;
			case RENDER_STRETCH:
			case RENDER_V4:
				break;
		};

		v_bNeedValidate = false;
	}


	//
	hgeQuad&		cl_Sprite::f_GetQuad( f32 fX, f32 fY, f32 fScale )
	{

		f32 fSize = 0.5f * fScale;

		v_stQuad.v[ 0 ].x = -fSize + fX;	v_stQuad.v[ 0 ].y = -fSize + fY;
		v_stQuad.v[ 1 ].x = fSize + fX;		v_stQuad.v[ 1 ].y = -fSize + fY;
		v_stQuad.v[ 2 ].x = fSize + fX;		v_stQuad.v[ 2 ].y = fSize + fY;
		v_stQuad.v[ 3 ].x = -fSize + fX;	v_stQuad.v[ 3 ].y = fSize + fY;
		
		return v_stQuad;
	}


	//
	hgeQuad&		cl_Sprite::f_GetQuad( f32 fX, f32 fY, f32 fScaleX, f32 fScaleY )
	{
		f32 fX2 = 0.5f * fScaleX;
		f32 fY2 = 0.5f * fScaleY;
		f32 fX1 = -fX2;
		f32 fY1 = -fY2;
		
		v_stQuad.v[ 0 ].x = fX1 + fX; v_stQuad.v[ 0 ].y = fY1 + fY;
		v_stQuad.v[ 1 ].x = fX2 + fX; v_stQuad.v[ 1 ].y = fY1 + fY;
		v_stQuad.v[ 2 ].x = fX2 + fX; v_stQuad.v[ 2 ].y = fY2 + fY;
		v_stQuad.v[ 3 ].x = fX1 + fX; v_stQuad.v[ 3 ].y = fY2 + fY;
		
		return v_stQuad;
	}


	//
	hgeQuad&	cl_Sprite::f_GetQuadRot( f32 fX, f32 fY, f32 fRot, f32 fScale )
	{
		f32 fSize = 0.5f * fScale;

		f32 fCos = Cos( fRot );
		f32 fSin = Sin( fRot );
			
		v_stQuad.v[ 0 ].x  = -fSize * fCos - (-fSize) * fSin + fX;
		v_stQuad.v[ 0 ].y  = -fSize * fSin + (-fSize) * fCos + fY;	

		v_stQuad.v[ 1 ].x  = fSize * fCos - (-fSize) * fSin + fX;
		v_stQuad.v[ 1 ].y  = fSize * fSin + (-fSize) * fCos + fY;	

		v_stQuad.v[ 2 ].x  = fSize * fCos - fSize * fSin + fX;
		v_stQuad.v[ 2 ].y  = fSize * fSin + fSize * fCos + fY;	

		v_stQuad.v[ 3 ].x  = -fSize * fCos - fSize * fSin + fX;
		v_stQuad.v[ 3 ].y  = -fSize * fSin + fSize * fCos + fY;	

		return v_stQuad;
	}


	//
	hgeQuad&	cl_Sprite::f_GetQuadRot( f32 fX, f32 fY, f32 fRot, f32 fScaleX, f32 fScaleY )
	{
		f32 fX2 = 0.5f * fScaleX;
		f32 fY2 = 0.5f * fScaleY;
		f32 fX1 = -fX2;
		f32 fY1 = -fY2;

		f32 fCos = Cos( fRot );
		f32 fSin = Sin( fRot );
			
		v_stQuad.v[ 0 ].x  = fX1 * fCos - fY1 * fSin + fX;
		v_stQuad.v[ 0 ].y  = fX1 * fSin + fY1 * fCos + fY;	

		v_stQuad.v[ 1 ].x  = fX2 * fCos - fY1 * fSin + fX;
		v_stQuad.v[ 1 ].y  = fX2 * fSin + fY1 * fCos + fY;	

		v_stQuad.v[ 2 ].x  = fX2 * fCos - fY2 * fSin + fX;
		v_stQuad.v[ 2 ].y  = fX2 * fSin + fY2 * fCos + fY;	

		v_stQuad.v[ 3 ].x  = fX1 * fCos - fY2 * fSin + fX;
		v_stQuad.v[ 3 ].y  = fX1 * fSin + fY2 * fCos + fY;

		return v_stQuad;
	}


	//
	void	cl_Sprite::f_SetPosition( f32 fX1, f32 fY1, f32 fX2, f32 fY2 )
	{
		v_stQuad.v[ 0 ].x = fX1; v_stQuad.v[ 0 ].y = fY1;
		v_stQuad.v[ 1 ].x = fX2; v_stQuad.v[ 1 ].y = fY1;
		v_stQuad.v[ 2 ].x = fX2; v_stQuad.v[ 2 ].y = fY2;
		v_stQuad.v[ 3 ].x = fX1; v_stQuad.v[ 3 ].y = fY2;
	}


	//
	void	cl_Sprite::f_SetPosition( f32 fX0, f32 fY0, f32 fX1, f32 fY1, f32 fX2, f32 fY2, f32 fX3, f32 fY3 )
	{
		v_stQuad.v[ 0 ].x = fX0; v_stQuad.v[ 0 ].y = fY0;
		v_stQuad.v[ 1 ].x = fX1; v_stQuad.v[ 1 ].y = fY1;
		v_stQuad.v[ 2 ].x = fX2; v_stQuad.v[ 2 ].y = fY2;
		v_stQuad.v[ 3 ].x = fX3; v_stQuad.v[ 3 ].y = fY3;
	}

	
	//
	void	cl_Sprite::f_SetFlip( bool bX, bool bY, bool bHotSpot )
	{
		f32 tx, ty;

		M3D_ASSERT_MSG( "FiloXSee", !(bHotSpot && RENDER_XY != v_nType), "Flip hot spot can be only in RenderXY mode!" );

		if( v_bHSFlip && v_bXFlip ) v_stHotSpot.v_fX = v_fWidth - v_stHotSpot.v_fX;
		if( v_bHSFlip && v_bYFlip ) v_stHotSpot.v_fY = v_fHeight - v_stHotSpot.v_fY;

		v_bHSFlip = bHotSpot;
		
		if( v_bHSFlip && v_bXFlip ) v_stHotSpot.v_fX = v_fWidth - v_stHotSpot.v_fX;
		if( v_bHSFlip && v_bYFlip ) v_stHotSpot.v_fY = v_fHeight - v_stHotSpot.v_fY;

		if( bX != v_bXFlip )
		{
			tx = v_stQuad.v[0].tx; v_stQuad.v[0].tx = v_stQuad.v[1].tx; v_stQuad.v[1].tx = tx;
			ty = v_stQuad.v[0].ty; v_stQuad.v[0].ty = v_stQuad.v[1].ty; v_stQuad.v[1].ty = ty;
			tx = v_stQuad.v[3].tx; v_stQuad.v[3].tx = v_stQuad.v[2].tx; v_stQuad.v[2].tx = tx;
			ty = v_stQuad.v[3].ty; v_stQuad.v[3].ty = v_stQuad.v[2].ty; v_stQuad.v[2].ty = ty;

			v_bXFlip = !v_bXFlip;
		}

		if( bY != v_bYFlip )
		{
			tx = v_stQuad.v[0].tx; v_stQuad.v[0].tx = v_stQuad.v[3].tx; v_stQuad.v[3].tx = tx;
			ty = v_stQuad.v[0].ty; v_stQuad.v[0].ty = v_stQuad.v[3].ty; v_stQuad.v[3].ty = ty;
			tx = v_stQuad.v[1].tx; v_stQuad.v[1].tx = v_stQuad.v[2].tx; v_stQuad.v[2].tx = tx;
			ty = v_stQuad.v[1].ty; v_stQuad.v[1].ty = v_stQuad.v[2].ty; v_stQuad.v[2].ty = ty;

			v_bYFlip = !v_bYFlip;
		}

		v_bNeedValidate = true;
	}


	//
	void	cl_Sprite::f_SetColor( u32 iCol, i32 iVert )
	{
		if( iVert != -1 )
			v_stQuad.v[ iVert ].col = iCol;
		else
			v_stQuad.v[ 0 ].col = v_stQuad.v[ 1 ].col = v_stQuad.v[ 2 ].col = v_stQuad.v[ 3 ].col = iCol;
	}


	//
	void	cl_Sprite::f_SetZ( f32 fZ, i32 iVert )
	{
		if( iVert != -1 )
			v_stQuad.v[ iVert ].z = fZ;
		else
			v_stQuad.v[ 0 ].z = v_stQuad.v[ 1 ].z = v_stQuad.v[ 2 ].z = v_stQuad.v[ 3 ].z = fZ;
	}


	namespace Internal
	{
		int arrBlendFactors[][ 2 ] = { { 0, BLEND_DEFAULT }, // BLEND_COLORMUL | BLEND_ALPHABLEND | BLEND_NOZWRITE
									{ 1, BLEND_COLORMYMUL | BLEND_ALPHABLEND | BLEND_NOZWRITE },
									{ 2, BLEND_COLORMUL | BLEND_ALPHAADD | BLEND_NOZWRITE },
									{ 3, BLEND_COLORADD | BLEND_ALPHAADD | BLEND_NOZWRITE } };
	}


	//
	void	cl_Sprite::f_SetBlendIndex( i32 iBlend )
	{
		for( int i = 0; i < M3D_ARR_SZ( Internal::arrBlendFactors ); ++i )
			if( Internal::arrBlendFactors[ i ][ 0 ] == iBlend )
				f_SetBlendMode( Internal::arrBlendFactors[ i ][ 1 ] );
	}


	//
	void	cl_Sprite::f_SetTextureRect( f32 fX, f32 fY, f32 fW, f32 fH )
	{
		M3D_ASSERT( "FiloXSee", v_pData );
		v_stTexRect.v_X			= fX;
		v_stTexRect.v_Y			= fY;
		v_stTexRect.v_Width		= fW;
		v_stTexRect.v_Height	= fH;

		f_CreateSprite( false );
	}


	//
	void	cl_Sprite::f_RestoreRenderTargetTexture()
	{
		v_stQuad.tex = NULL;
		if( v_pTexture )
		{
			if( v_pTexture->f_IsRenderTarget() )
				v_stQuad.tex = g_pHGE->Target_GetTexture( (HTARGET)v_pTexture->f_GetTexture() );
			else
				v_stQuad.tex = v_pTexture->f_GetTexture();
		}
	}


	//
	const char*		cl_Sprite::f_GetTexName() const
	{
		return v_pTexture->f_GetName();
	}
}	// namespace Puzzle
