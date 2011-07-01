//////////////////////////////////////////////////////////////////////////////
//
// Created: 11-Mar-2009
// Copyright © 2009, Targem LLC. All rights reserved.
//
//----------------------------------------------------------------------------
// $Id:
//----------------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////////////

//
#include "Precompiled.h"
#include "ActionQueue.h"
#include "BehaviorSpawns.h"
#include "InteractiveEntity.h"
#include "EntityFactory.h"

#include "InnerObject.h"
#include "ValueStorageEntity.h"
#include "GlobalEntity.h"
#include "Animation/ObjectAnimEffectInst.h"

#include "ActionEvent.h"
#include "BehaviorSpawns.h"
#include "InteractiveEntity.h"
#include "Cursor.h"

//
namespace Puzzle
{
	namespace Internal
	{
		//
		void	f_DeleteNode( std::pair< u32, cl_BaseEntity* > pObj )
		{
			M3D_ASSERT( "FiloXSee", pObj.second );
			M3D_SAFE_DELETE( pObj.second );
		}
	}



	const u32		OBJECT_HASH_SEED		= 0xf1f2f3f4;


	//
	cl_BaseEntity*			f_GetObjectByName( cl_BaseEntity* pRoot, const char* szName )
	{
		M3D_PROFILE_FUNCTION();

		M3D_ASSERT( "FiloXSee", pRoot );
		M3D_ASSERT( "FiloXSee", !StrEmpty( szName ) );
		M3D_ASSERT( "FiloXSee", g_pGlobalEntity );

		// send message to itself screen
		if( StrEq_u( szName, "screen" ) )
			return f_GetParentScreen( pRoot );

		//
		if( StrEq_u( szName, "global" ) )
			return g_pGlobalEntity;

		//
		if( StrEq_u( szName, "parent" ) )
			return pRoot->f_GetParent();

		//
		/*if( StrEq_u( szName, "root" ) )
			return pRoot->f_FindRoot();*/

		//
		if( StrEq_u( szName, "this" ) )
			return pRoot;

		cl_BaseEntity* pObj = pRoot->f_FindInnerObjectByName( szName );
		if( pObj )
			return pObj;
		return pRoot->f_FindByName( szName );
	}


	//
	cl_BaseEntity*			f_GetObjectIntoHierarchy( cl_BaseEntity* pRoot, const char* szName )
	{
		M3D_ASSERT( "FiloXSee", pRoot );
		M3D_ASSERT( "FiloXSee", szName );
		M3D_ASSERT( "FiloXSee", g_pGlobalEntity );
				
		// if name of object is empty, then return this object
		if( !szName || StrEmpty( szName ) || StrEq( szName, "this" ) )
			return pRoot;
		

		StrTokenizer<> toks( "." );
		toks.Parse( szName );
		cl_BaseEntity* pObj = pRoot;
		for( m3dSize iArg = 0; iArg < toks.Argc(); ++iArg )
		{
			if( StrEmpty( toks.Argv( iArg ) ) )
				continue;

			// find next object into name
			pObj = f_GetObjectByName( pObj, toks.Argv( iArg ) );
			if( !pObj )
			{
				M3D_LOG_ERR( "Can not find object '%s'", szName );
				return NULL;
			}
		}
		return pObj;
	}


	//
	cl_BaseEntity*	f_GetParentScreen( cl_BaseEntity* pEntity )
	{
		while( pEntity )
		{
			if( cl_EntityFactory::f_IsScreen( pEntity->f_GetType() ) )
				return pEntity;
			pEntity = pEntity->f_GetParent();
		}

		return NULL;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////
	////
	////	class cl_BaseEntity
	////
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//
	M3D_IMPLEMENT_CLASS( cl_BaseEntity, cl_Unk );
	
	
	//
	M3D_BEGIN_DATADESC_NO_BASE( cl_BaseEntity )
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_stPos.v_fX,		FT_FLOAT,			"x" ),
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_stPos.v_fY,		FT_FLOAT,			"y" ),
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_fRotation,		FT_FLOAT,			"rot" ),
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_stScale.v_fX,	FT_FLOAT,			"scaleX" ),
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_stScale.v_fY,	FT_FLOAT,			"scaleY" ),
		
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_stHotSpot.v_fX,	FT_FLOAT,			"hsX" ),
		M3D_DEFINE_KEYFIELD(	v_stSelfTransform.v_stHotSpot.v_fY,	FT_FLOAT,			"hsY" ),

		M3D_DEFINE_KEYFIELD(	v_iSelfColor,						FT_COLOR,			"color" ),
		
		M3D_DEFINE_KEYFIELD(	v_bVisible,							FT_BOOL,			"visible" ),
		M3D_DEFINE_KEYFIELD(	v_bEnabled,							FT_BOOL,			"enable" ),
		M3D_DEFINE_KEYFIELD(	v_bImpulsed,						FT_BOOL,			"impulsed" ),
		
		M3D_DEFINE_KEYFIELD(	v_clName,							FT_ENTITY_NAME,		"name" ),

		M3D_DEFINE_ACTION(		FT_VOID,							"Show",				f_ActionShow ),
		M3D_DEFINE_ACTION(		FT_VOID,							"Hide",				f_ActionHide ),

		M3D_DEFINE_ACTION(		FT_VOID,							"Set",				f_ActionSet ),
		M3D_DEFINE_ACTION(		FT_VOID,							"SetChildAll",		f_ActionSetToChild ),
		M3D_DEFINE_ACTION(		FT_VOID,							"Validation",		f_ActionValidation ),
		M3D_DEFINE_ACTION(		FT_VOID,							"SetSkin",			f_ActionSetSkin ),

		M3D_DEFINE_ACTION(		FT_VOID,							"StartAnimation",	f_ActionStartAnimation ),
		M3D_DEFINE_ACTION(		FT_VOID,							"RestartAnimation",	f_ActionRestartAnimation ),
		M3D_DEFINE_ACTION(		FT_VOID,							"StopAnimation",	f_ActionStopAnimation ),
		M3D_DEFINE_ACTION(		FT_VOID,							"PauseAnimation",	f_ActionPauseAnimation ),

	M3D_END_DATADESC()



	//
	cl_BaseEntity::cl_BaseEntity( const char* szType )
		: v_clName				( "" )
		, v_clPrototype			( "" )
		, v_szType				( szType )
		, v_szProtExt			( "iof" )

		, v_bVisible			( true )
		, v_bEnabled			( true )
		, v_bImpulsed			( true )

		, v_arrChildren			()
		, v_mapChildren			()
		, v_iChildrenCount		( 0 )
		, v_pInnerHierarchy		( NULL )
		, v_pParent				( NULL )

		, v_iSkinCount			( 0 )
		, v_pCurrentSkin		( NULL )
		, v_szSkinName			( "" )

		, v_pCurrentAnimation	( NULL )

		, v_stSelfTransform		()
		, v_stCurrTransform		()
		, v_stLastTransform		()
		, v_stDirection			( 0.0f, 0.0f )

		, v_iSelfColor			( 0xffffffff )
		, v_iCurrColor			( 0xffffffff )

		, v_bNeedValidate		( true )
	{
		M3D_ASSERT( "FiloXSee", !v_szType.empty() );
	}


	//
	cl_BaseEntity::~cl_BaseEntity()
	{
		f_Destroy();
	}
	

	//
	bool	cl_BaseEntity::f_LoadPrototype( const char* szFilename )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szFilename ) );
		M3D_ASSERT( "FiloXSee", StrEmpty( v_clName.c_str() ) );
		
		// delete old data
		//f_Destroy();

		FilePath clPath = szFilename;//g_pFileStorage->f_GetFullFileName( szFilename );
		clPath.UnifySelf();
		clPath.SetExt( v_szProtExt.c_str() );

		/// open file for read
		TiXmlElement* pRoot = g_pXmlStorage->f_LoadXml( clPath.c_str() );
		if( !pRoot )
		{
			M3D_LOG_ERR( "Failed loading prototype '%s'.", clPath.c_str() );
			return false;
		}
		v_clPrototype = szFilename;

		
		// check prototype type
		if( StrCompare( pRoot->Value(), v_szType.c_str() ) != 0 )
		{
			M3D_LOG_ERR( "File '%s' has bad root tag name.", v_clPrototype.c_str() );
			return false;
		}


		/// load prototype base information
		for( TiXmlElement* pNode = pRoot->FirstChildElement(); pNode != NULL; pNode = pNode->NextSiblingElement() )
		{
			if( StrCompare( pNode->Value(), "params" ) == 0 )
			{
				// read parameters
				f_LoadProperties( pNode );
			}
			else if( StrCompare( pNode->Value(), "object" ) == 0 )
			{
				M3D_ASSERT_MSG( "FiloXSee", !v_pInnerHierarchy, "There can be only one children root in prototype '%s'!", szFilename );
				// build inner hierarchy
				v_pInnerHierarchy = cl_EntityFactory::f_CreateObject( pNode->Attribute( "type", "objects" ) );
				v_pInnerHierarchy->v_pParent = this;
				v_pInnerHierarchy->f_BuildHierarchy( pNode );
			}
			// load skins
			else if( StrCompare( pNode->Value(), "skins" ) == 0 )
			{
				for( TiXmlElement* pSkin = pNode->FirstChildElement(); pSkin != NULL; pSkin = pSkin->NextSiblingElement() )
				{
					if( StrCompare( pSkin->Value(), "skin" ) == 0 )
					{
						// take skin name
						const char* szSkinName = pSkin->Attribute( "name" );
						if( StrEmpty( szSkinName ) )
							continue;

						for( TiXmlElement* pObj = pSkin->FirstChildElement(); pObj != NULL; pObj = pObj->NextSiblingElement() )
						{
							if( StrCompare( pObj->Value(), "object" ) == 0 )
							{
								// create new skin
								cl_BaseEntity*	v_pSkinHierarchy = cl_EntityFactory::f_CreateObject( pObj->Attribute( "type", "objects" ) );
								v_pSkinHierarchy->v_pParent = this;
								v_pSkinHierarchy->f_BuildHierarchy( pObj );

								// add skin into map
								f_AddSkin( v_pSkinHierarchy, szSkinName );

								// set first skin as default
								if( NULL == v_pCurrentSkin )
								{
									v_pCurrentSkin	= v_pSkinHierarchy;
									v_szSkinName	= szSkinName;
								}
								break;
							}
						}
					}
				}
			}
		}

		// set first skin as default
		if( 0 == v_iSkinCount )
			v_pCurrentSkin = v_pInnerHierarchy;

		// read special data
		return f_ReadDescription( pRoot );
	}


	//
	void	cl_BaseEntity::f_BuildHierarchy( TiXmlElement* pNode )
	{
		M3D_ASSERT( "FiloXSee", pNode );

		// read params of this object
		f_LoadProperties( pNode );

		// make children objects
		for( TiXmlElement* pChild = pNode->FirstChildElement(); pChild != NULL; pChild = pChild->NextSiblingElement() )
		{
			if( StrCompare( pChild->Value(), "object" ) != 0 )
				continue;

			// get type of object
			const char* szType		= pChild->Attribute( "type" );
			const char* szPrototype = pChild->Attribute( "prototype" );
			if( StrEmpty( szType ) )
			{
				M3D_LOG_ERR( "Object '%s' has children with bad type", v_clName.c_str() );
				continue;
			}


			// build object and add it to hierarchy
			cl_BaseEntity* pObj = cl_EntityFactory::f_CreateObject( szType );
			pObj->v_pParent		= this;

			// load prototype
			if( !StrEmpty( szPrototype ) )
			{
				if( !pObj->f_LoadPrototype( szPrototype ) )
				{
					M3D_SAFE_DELETE( pObj );
					continue;
				}
			}

			// make children hierarchy
			pObj->f_BuildHierarchy( pChild );

			if( !f_AddChild( pObj ) )
				M3D_SAFE_DELETE( pObj );
		}
	}


	//
	bool	cl_BaseEntity::f_AddChild( cl_BaseEntity* pObj )
	{
		M3D_ASSERT( "FiloXSee", pObj );

		u32 iHash = MurmurHash::CalcHash( pObj->f_GetName(), StrLen( pObj->f_GetName() ), OBJECT_HASH_SEED );
		td_ObjectMapItor iter = v_mapChildren.find( iHash );

		// check object exists
		if( iter != v_mapChildren.end() )
		{
			M3D_LOG_ERR( "Can not add children '%s' into object '%s'. Object with this name is already exists.", pObj->f_GetName(), v_clName.c_str() );
			return false;
		}

		if( v_arrChildren.size() >= MAX_CHILD_OBJECT )
		{
			M3D_LOG_ERR( "Object '%s' has overflow by children objects. Can't add new object '%s'.", v_clName.c_str(), pObj->f_GetName() );
			return false;
		}

		// set parent
		pObj->v_pParent = this;

		// add to children list
		v_mapChildren[ iHash ] = pObj;
		v_arrChildren.push_back( pObj );
		++v_iChildrenCount;

		return true;
	}


	//
	bool	cl_BaseEntity::f_AddInnerChildren( cl_BaseEntity* pObj )
	{
		M3D_ASSERT( "FiloXSee", 0 == v_iSkinCount );

		// create inner object
		if( NULL == v_pInnerHierarchy )
		{
			// build inner hierarchy
			v_pInnerHierarchy = cl_EntityFactory::f_CreateObject( "objects" );
			v_pInnerHierarchy->v_pParent = this;
			v_pCurrentSkin = v_pInnerHierarchy;
		}

		// add children to inner hierarchy
		return v_pInnerHierarchy->f_AddChild( pObj );
	}


	//
	bool	cl_BaseEntity::f_RemoveChild( cl_BaseEntity* pObj )
	{
		M3D_ASSERT( "FiloXSee", pObj );

		// find object into array by pointer
		td_ObjectArrayItor iter = std::find( v_arrChildren.begin(), v_arrChildren.end(), pObj );
		M3D_ASSERT( "FiloXSee", iter != v_arrChildren.end() );
		v_arrChildren.erase( iter );
		
		// find object into map
		u32 iHash = MurmurHash::CalcHash( pObj->f_GetName(), StrLen( pObj->f_GetName() ), OBJECT_HASH_SEED );
		td_ObjectMapItor iterMap = v_mapChildren.find( iHash );
		M3D_ASSERT( "FiloXSee", iterMap != v_mapChildren.end() );

		// remove it
		v_mapChildren.erase( iterMap );
		--v_iChildrenCount;

		// delte object
		M3D_SAFE_DELETE( pObj );

		return true;
	}


	//
	cl_BaseEntity*	cl_BaseEntity::f_FindRoot()
	{
		if( v_pParent )
			return v_pParent->f_FindRoot();
		return this;
	}


	//
	cl_BaseEntity*		cl_BaseEntity::f_FindByName( const char* szName, u32 iHash )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szName ) );

		// check this entity
		if( StrCompare( v_clName.c_str(), szName ) == 0 )
			return this;

		u32 iSaveHash = iHash;

		// find new hash code
		if( iHash == ~0u )
			iHash = MurmurHash::CalcHash( szName, StrLen( szName ), OBJECT_HASH_SEED );
		td_ObjectMapItor iter = v_mapChildren.find( iHash );

		// check object exists
		if( iter != v_mapChildren.end() )
			return iter->second;

		// find object in children hierarchy
		for( td_ObjectMapItor iter = v_mapChildren.begin(); iter != v_mapChildren.end(); ++iter )
		{
			cl_BaseEntity* pObj = iter->second->f_FindByName( szName, iHash );
			if( pObj )
				return pObj;
		}

		// write error
		if( iSaveHash == ~0u )
		{
			M3D_LOG_ERR( "Can not find object with name '%s'.", szName );
		}

		return NULL;
	}


	//
	cl_BaseEntity*		cl_BaseEntity::f_GetObjectByIndex( m3dSize iIndex )
	{
		M3D_ASSERT( "FiloXSee", iIndex >= 0 && iIndex < v_arrChildren.size() );
		return v_arrChildren[ iIndex ];
	}


	//
	cl_BaseEntity*		cl_BaseEntity::f_FindInnerObjectByName( const char* szName )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szName ) );

		// check this entity
		if( StrCompare( v_clName.c_str(), szName ) == 0 )
			return this;

		//M3D_ASSERT( "FiloXSee", v_pCurrentSkin );
		return v_pCurrentSkin ? v_pCurrentSkin->f_FindByName( szName ) : NULL;
	}


	//
	cl_BaseEntity*		cl_BaseEntity::f_GetInnerObjectByIndex( m3dSize iIndex )
	{		
		M3D_ASSERT( "FiloXSee", v_pCurrentSkin );
		return v_pCurrentSkin ? v_pCurrentSkin->f_GetObjectByIndex( iIndex ) : NULL;
	}


	//
	m3dSize		cl_BaseEntity::f_GetInnerObjectCount() const
	{
		M3D_ASSERT( "FiloXSee", v_pCurrentSkin );
		return v_pCurrentSkin ? v_pCurrentSkin->v_iChildrenCount : 0;
	}


	//
	void	cl_BaseEntity::f_Render()
	{
		if( !v_bVisible )
			return;

		// render inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_Render();

		// render children objects
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_Render();
	}


	//
	void	cl_BaseEntity::f_Update()
	{
		if( !v_bEnabled )
			return;

		// update inner object
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_Update();

		// update children objects
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_Update();
	}

	
	//
	void	cl_BaseEntity::f_Validation()
	{
		// find parent parameters
		Vec2 stPos( 0.0f, 0.0f );
		Vec2 stScale( 1.0f, 1.0f );
		f32 fRot = 0.0f;

		if( v_pParent )
		{
			//M3D_ASSERT( "FiloXSee", !v_pParent->v_bNeedValidate );
			stPos	= v_pParent->v_stCurrTransform.v_stPos;
			stScale = v_pParent->v_stCurrTransform.v_stScale;
			fRot	= v_pParent->v_stCurrTransform.v_fRotation;
		}

		// save last transformation
		v_stLastTransform.v_stPos		= v_stCurrTransform.v_stPos;
		v_stLastTransform.v_fRotation	= v_stCurrTransform.v_fRotation;
		v_stLastTransform.v_stScale		= v_stCurrTransform.v_stScale;
		v_stLastTransform.v_stHotSpot	= v_stCurrTransform.v_stHotSpot;

		//
		v_stCurrTransform.v_stScale.v_fX	= stScale.v_fX * v_stSelfTransform.v_stScale.v_fX;
		v_stCurrTransform.v_stScale.v_fY	= stScale.v_fY * v_stSelfTransform.v_stScale.v_fY;
		
		v_stCurrTransform.v_stHotSpot.v_fX	= v_stSelfTransform.v_stHotSpot.v_fX * v_stSelfTransform.v_stScale.v_fX;
		v_stCurrTransform.v_stHotSpot.v_fY	= v_stSelfTransform.v_stHotSpot.v_fY * v_stSelfTransform.v_stScale.v_fY;

		v_stCurrTransform.v_stPos.v_fX		= stPos.v_fX + v_stSelfTransform.v_stPos.v_fX * stScale.v_fX - v_stCurrTransform.v_stHotSpot.v_fX;
		v_stCurrTransform.v_stPos.v_fY		= stPos.v_fY + v_stSelfTransform.v_stPos.v_fY * stScale.v_fY - v_stCurrTransform.v_stHotSpot.v_fY;

		v_stCurrTransform.v_fRotation		= fRot + v_stSelfTransform.v_fRotation;
		v_bNeedValidate	= false;

		Vec2 stDir = v_stCurrTransform.v_stPos - v_stLastTransform.v_stPos;
		if( stDir.LengthSq() >= 0.0001f )
		{
			v_stDirection = stDir.normalize();
		}

		// validate children objects by current transformation
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_Validation();

		// validate inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_Validation();

		// validate color
		f_ValidationColor();
	}

	
	//
	void	cl_BaseEntity::f_ValidationPos()
	{
		f_ValidationSelfPos();		

		// validate children objects by current transformation
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_ValidationPos();

		// validate inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_ValidationPos();
	}


	//
	void	cl_BaseEntity::f_ValidationSelfPos()
	{
		M3D_ASSERT( "FiloXSee", !v_bNeedValidate );
		
		// find parent parameters
		Vec2 stPos( 0.0f, 0.0f );
		Vec2 stScale( 1.0f, 1.0f );

		if( v_pParent )
		{
			M3D_ASSERT( "FiloXSee", !v_pParent->v_bNeedValidate );
			stPos	= v_pParent->v_stCurrTransform.v_stPos;
			stScale = v_pParent->v_stCurrTransform.v_stScale;
		}

		// save last transformation
		v_stLastTransform.v_stPos = v_stCurrTransform.v_stPos;

		//
		v_stCurrTransform.v_stPos.v_fX		= stPos.v_fX + v_stSelfTransform.v_stPos.v_fX * stScale.v_fX - v_stCurrTransform.v_stHotSpot.v_fX;
		v_stCurrTransform.v_stPos.v_fY		= stPos.v_fY + v_stSelfTransform.v_stPos.v_fY * stScale.v_fY - v_stCurrTransform.v_stHotSpot.v_fY;

		// update direction
		Vec2 stDir = v_stCurrTransform.v_stPos - v_stLastTransform.v_stPos;
		if( stDir.LengthSq() >= 1.0f )
			v_stDirection = stDir.normalize();

		// validate inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_ValidationSelfPos();
	}


	//
	void	cl_BaseEntity::f_ValidationScale()
	{
		// find parent parameters
		Vec2 stPos( 0.0f, 0.0f );
		Vec2 stScale( 1.0f, 1.0f );

		if( v_pParent )
		{
			M3D_ASSERT( "FiloXSee", !v_pParent->v_bNeedValidate );
			stPos	= v_pParent->v_stCurrTransform.v_stPos;
			stScale = v_pParent->v_stCurrTransform.v_stScale;
		}

		// save last transformation
		v_stLastTransform.v_stPos		= v_stCurrTransform.v_stPos;
		v_stLastTransform.v_stScale		= v_stCurrTransform.v_stScale;
		

		//
		v_stCurrTransform.v_stScale.v_fX	= stScale.v_fX * v_stSelfTransform.v_stScale.v_fX;
		v_stCurrTransform.v_stScale.v_fY	= stScale.v_fY * v_stSelfTransform.v_stScale.v_fY;
		
		v_stCurrTransform.v_stPos.v_fX		= stPos.v_fX + v_stSelfTransform.v_stPos.v_fX * stScale.v_fX - v_stCurrTransform.v_stHotSpot.v_fX;
		v_stCurrTransform.v_stPos.v_fY		= stPos.v_fY + v_stSelfTransform.v_stPos.v_fY * stScale.v_fY - v_stCurrTransform.v_stHotSpot.v_fY;

		// update direction
		Vec2 stDir = v_stCurrTransform.v_stPos - v_stLastTransform.v_stPos;
		if( stDir.LengthSq() >= 1.0f )
			v_stDirection = stDir.normalize();

		// validate children objects by current transformation
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_ValidationScale();

		// validate inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_ValidationScale();
	}


	//
	void	cl_BaseEntity::f_ValidationColor()
	{
		u32 iParentColor = 0xffffffff;
		if( v_pParent )
		{
			//M3D_ASSERT( "FiloXSee", !v_pParent->v_bNeedValidate );
			iParentColor = v_pParent->v_iCurrColor;
		}

		i32 iA = M3D_A( iParentColor ) * M3D_A( v_iSelfColor ) / 255;
		i32 iR = M3D_R( iParentColor ) * M3D_R( v_iSelfColor ) / 255;
		i32 iG = M3D_G( iParentColor ) * M3D_G( v_iSelfColor ) / 255;
		i32 iB = M3D_B( iParentColor ) * M3D_B( v_iSelfColor ) / 255;
		v_iCurrColor = M3D_ARGB( iA, iR, iG, iB );

		// validate children objects by current transformation
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_ValidationColor();

		// validate inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_ValidationColor();
	}


	//
	void	cl_BaseEntity::f_ValidationOpacity()
	{
		u32 iParentColor = 0xffffffff;
		if( v_pParent )
		{
			//M3D_ASSERT( "FiloXSee", !v_pParent->v_bNeedValidate );
			iParentColor = v_pParent->v_iCurrColor;
		}

		i32 iA = M3D_A( iParentColor ) * M3D_A( v_iSelfColor ) / 255;
		v_iCurrColor = M3D_SET_A( v_iCurrColor, iA );

		// validate children objects by current transformation
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_ValidationOpacity();

		// validate inner objects
		if( v_pCurrentSkin )
			v_pCurrentSkin->f_ValidationOpacity();
	}


	//
	void	cl_BaseEntity::f_Destroy()
	{
		std::for_each( v_mapChildren.begin(), v_mapChildren.end(), Internal::f_DeleteNode );	
		v_mapChildren.clear();
		v_arrChildren.clear();
		v_iChildrenCount = 0;

		M3D_SAFE_DELETE( v_pInnerHierarchy );
		v_pParent = NULL;

		// delete all skins
		for( td_SkinMapItor iter = v_mapSkins.begin(); iter != v_mapSkins.end(); ++iter )
			M3D_SAFE_DELETE( iter->second );
		v_mapSkins.clear();
		v_iSkinCount	= 0;
		v_pCurrentSkin	= NULL;
		v_szSkinName	= "";

		v_clName		= "";
		v_clPrototype	= "";
		//v_szType		= "";

		v_bVisible = true;
		v_bEnabled = true;

		v_stSelfTransform.f_Init();
		v_stCurrTransform.f_Init();
	}


	//
	bool	cl_BaseEntity::f_Impulse( const st_ImpulseInfo& szImp )
	{
		if( !v_bImpulsed )
			return false;

		// set impulse to inner object
		if( v_pCurrentSkin && v_pCurrentSkin->f_Impulse( szImp ) )
			return true;

		// set impulse to children objects
		for( i32 iInd = v_iChildrenCount - 1; iInd >= 0; --iInd )
		{
			if( v_arrChildren[ (m3dSize)iInd ]->f_Impulse( szImp ) )
				return true;
		}
		return false;
	}


	//
	bool	cl_BaseEntity::f_AcceptEvent( const char* szActionName, cl_BaseEntity* pActivator, cl_BaseEntity* pSender, Variant clParam )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szActionName ) );
		M3D_PROFILE_CODE( "Accept All Event" );

		//
		for( const st_ClassDataMap* dm = f_GetDataMap(); dm != 0; dm = dm->v_pBaseClassMap )
		{
			for( m3dSize ii = 0; ii < dm->v_iNumFields; ++ii )
			{
				const st_FieldDesc& fieldDesc = dm->v_pFields[ ii ];
				if( !StrEmpty( fieldDesc.v_szEditorName ) && StrEq( fieldDesc.v_szEditorName, szActionName ) )
				{
					if( !( fieldDesc.v_iFlags & FF_DESC_ACTION ) )
					{
						M3D_LOG_ERR( "f_AcceptEvent: bad action name '%s' into object '%s'", szActionName, v_clName.c_str() );
						return false;
					}

					// call action
					f_pActionFunc fpHandler = fieldDesc.v_pfActionFunc;
					M3D_ASSERT( "FiloXSee", fpHandler );

					// get value of sender object, if needed
					if( pSender && clParam.GetValueType() != Variant::VALUE_UNDEFINED && !StrEmpty( clParam.GetAsString() ) )
					{
						// for
						// <do object = "global" command = "SetSoundVolume" param = "value this value" />
						StrTokenizer<> clTok( " " );
						clTok.Parse( clParam.GetAsString() );
						if( clTok.Argc() == 3 && !StrEq( clTok.Argv( 1 ), "=" ) && StrEq( clTok.Argv( 0 ), "value" ) )
						{
							// get value of object
							cl_BaseEntity* pObj = st_Entity( pSender, clTok.Argv( 1 ) ).f_GetEntity();
							if( pObj )
								clParam = pObj->f_GetValue( clTok.Argv( 2 ) );
						}
					}

					// create event
					st_InputEvent stEv;
					stEv.v_pSender		= pSender;
					stEv.v_pActivator	= pActivator;
					stEv.v_clParam		= clParam;

					(this->*fpHandler)( stEv );

					return true;
				}
			}
		}

		M3D_LOG_ERR( "Object '%s' with type '%s' has no command '%s'", v_clName.c_str(), v_szType.c_str(), szActionName );

		return false;
	}


	//
	const char*		cl_BaseEntity::f_GetValue( const char* szParam )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szParam ) );
		Variant clVal;
		if( !f_GetProperty( szParam, &clVal ) )
			return NULL;

		//
		if( clVal.GetValueType() == Variant::VALUE_UNDEFINED )
		{
			M3D_LOG_ERR( "Can not find param '%s' into object '%d'", szParam, v_clPrototype.c_str() );
			return NULL;
		}

		//
		return StrFormat( "%s", clVal.GetAsString() );
	}


	//
	void	cl_BaseEntity::f_ActionShow( st_InputEvent& )
	{
		f_SetShow( true );
	}


	//
	void	cl_BaseEntity::f_ActionHide( st_InputEvent& )
	{
		f_SetShow( false );
	}


	//
	void	cl_BaseEntity::f_ActionSet( st_InputEvent& stEv )
	{
		M3D_ASSERT( "FiloXSee", stEv.v_clParam.GetValueType() == Variant::VALUE_STRING );

		// string in format 'param = value'
		const char* szStr = stEv.v_clParam.GetAsString();

		StrTokenizer<> clBaseTok( "=" );
		clBaseTok.Parse( szStr );
		if( clBaseTok.Argc() != 2 )
		{
			M3D_LOG_ERR( "Cannot convert Variant from string to 'param = value'" );
			return;
		}

		// first token
		StrTokenizer<> clTok1( " " );
		clTok1.Parse( clBaseTok.Argv( 0 ) );

		// second token
		StrTokenizer<> clTok2( " " );
		clTok2.Parse( clBaseTok.Argv( 1 ) );
		
		// set property
		if( clTok2.Argc() == 1 )
			f_SetProperty( clTok1.Argv( 0 ), clTok2.Argv( 0 ) );
		else if( clTok2.Argc() == 2 )
		{
			// get object value
			cl_BaseEntity* pObj = st_Entity( this, clTok2.Argv( 0 ) ).f_GetEntity();
			M3D_ASSERT( "FiloXSee", pObj );
			if( pObj )
			{
				if( !f_SetProperty( clTok1.Argv( 0 ), pObj->f_GetValue( clTok2.Argv( 1 ) ) ) )
				{
					M3D_LOG_ERR( "Can not change property '%s' of object '%s'", clTok1.Argv( 0 ), v_clPrototype.c_str() );
				}
			}
			else
			{
				M3D_LOG_ERR( "Cannot convert Variant from string to 'param = object value'" );
			}
		}
		else if( clTok2.Argc() > 2 )
			f_SetProperty( clTok1.Argv( 0 ), clBaseTok.Argv( 1 ) );
		else
		{
			M3D_LOG_ERR( "Cannot find value '%s' of object '%s'", clTok2.Argv( 1 ), clTok2.Argv( 0 ) );
			return;
		}
	}


	//
	void	cl_BaseEntity::f_ActionSetToChild( st_InputEvent& stEv )
	{
		// can not set to itself
		//f_ActionSet( stEv );

		// set impulse to children objects
		for( m3dSize iInd = 0; iInd < v_iChildrenCount; ++iInd )
			v_arrChildren[ iInd ]->f_ActionSet( stEv );
	}


	//
	void	cl_BaseEntity::f_ActionValidation( st_InputEvent& )
	{
		f_Validation();
	}

	
	//
	void	cl_BaseEntity::f_ActionSetSkin( st_InputEvent& stEv )
	{
		M3D_ASSERT( "FiloXSee", stEv.v_clParam.GetValueType() == Variant::VALUE_STRING );
		f_SetCurrentSkin( stEv.v_clParam.GetAsString() );
	}


	//
	void	cl_BaseEntity::f_ActionStartAnimation( st_InputEvent& )
	{
		if( v_pCurrentAnimation )
			v_pCurrentAnimation->f_Start();
	}


	//
	void	cl_BaseEntity::f_ActionRestartAnimation( st_InputEvent& )
	{
		if( v_pCurrentAnimation )
			v_pCurrentAnimation->f_Restart();
	}


	//
	void	cl_BaseEntity::f_ActionStopAnimation( st_InputEvent& )
	{
		if( v_pCurrentAnimation )
			v_pCurrentAnimation->f_Stop();
	}


	//
	void	cl_BaseEntity::f_ActionPauseAnimation( st_InputEvent& )
	{
		if( v_pCurrentAnimation )
			v_pCurrentAnimation->f_Pause();
	}


	//
	M3D_PROPERTY_SET_IMPL( cl_BaseEntity )
	{
		// search data map properties
		for( st_ClassDataMap* dm = f_GetDataMap(); dm != 0; dm = dm->v_pBaseClassMap )
		{
			for( m3dSize ii = 0; ii < dm->v_iNumFields; ++ii )
			{
				st_FieldDesc& field = dm->v_pFields[ ii ];
				if( ( field.v_iFlags & FF_DESC_PROPERTY ) && StrEq( szKey, field.v_szEditorName ) )
				{
					u8* ptr = ( ( u8* )this + field.v_iOffset );
					switch( field.v_nType )
					{
						default:
							M3D_ASSERT( "FiloXSee", !"This property type should be used manually" );
							return false;

						case FT_INT:
							*( i32* )ptr = Strtoi( szVal );
							return true;

						case FT_FLOAT:
							*( f32* )ptr = Strtof( szVal );
							return true;

						case FT_BOOL:
							*( bool* )ptr = Strtob( szVal );
							return true;

						case FT_COLOR:
						{
							u32 col;
							//if( !StrToRGBA( szVal, col ) )StrToUint
							if( !StrToUint( szVal, col ) )
								return false;
							*( u32* )ptr = col;
							return true;
						}
						case FT_STD_STRING:
							*( m3dString* )ptr = szVal;
							return true;

						case FT_FILE_PATH:
							*( FilePath* )ptr = szVal;
							return true;

						case FT_ENTITY_NAME:
							*( td_EntityName* )ptr = szVal;
							return true;

						case FT_VEC2:
							StrToVec2( szVal, *( Vec2* )ptr );
							return true;
						
						case FT_BOUNDF:
							StrToBoundf( szVal, *( Boundsf* )ptr );
							return true;
					}
				}
			}
		}

		return false;
	}


	//
	M3D_PROPERTY_GET_IMPL( cl_BaseEntity )
	{
		// search data map
		for( st_ClassDataMap* dm = f_GetDataMap(); dm != 0; dm = dm->v_pBaseClassMap )
		{
			for( m3dSize ii = 0; ii < dm->v_iNumFields; ++ii )
			{
				st_FieldDesc& field = dm->v_pFields[ ii ];
				if( ( field.v_iFlags & FF_DESC_PROPERTY ) && StrEq( szKey, field.v_szEditorName ) )
				{
					u8* ptr = ( ( u8* )this + field.v_iOffset );
					switch( field.v_nType )
					{
						default:
							M3D_ASSERT( "FiloXSee", !"This property type should be used manually" );
							return false;

						case FT_INT:
							pVal->Set( *( i32* )ptr );
							return true;

						case FT_FLOAT:
							pVal->Set( *( f32* )ptr );
							return true;

						case FT_BOOL:
							pVal->Set( *( bool* )ptr );
							return true;

						case FT_COLOR:
							pVal->Set( *( u32* )ptr );
							return true;

						case FT_STD_STRING:
							pVal->Set( *( m3dString* )ptr );
							return true;

						case FT_FILE_PATH:
							pVal->Set( ( ( FilePath* )ptr )->c_str() );
							return true;							

						case FT_ENTITY_NAME:
							pVal->Set( ( ( td_EntityName* )ptr )->c_str() );
							return true;

						case FT_VEC2:
							pVal->Set( *( Vec2* )ptr );
							return true;
						
						case FT_BOUNDF:
							pVal->Set( *( Boundsf* )ptr );
							return true;
					}
				}
			}
		}

		return false;
	}


	// load/save public properties
	bool	cl_BaseEntity::f_SaveProperties( TiXmlElement* pNode )
	{
		// NOTE: [FiloXSee] some default values are not saved to reduce scene size
		//
		// default values are:
		//		FT_INT = 0
		//		FT_FLOAT = 0.0
		//		FT_BOOL = false
		//		FT_COLOR = 0xffffffff (white)
		//		FT_STD_STRING = "" (empty one)
		//		FT_BOUNDF = 0 0 0 0

		// save data map properties
		for( st_ClassDataMap* dm = f_GetDataMap(); dm != 0; dm = dm->v_pBaseClassMap )
		{
			for( m3dSize ii = 0; ii < dm->v_iNumFields; ++ii )
			{
				st_FieldDesc& field = dm->v_pFields[ ii ];
				if( field.v_iFlags & FF_DESC_PROPERTY )
				{
					u8* ptr = ( ( u8* )this + field.v_iOffset );
					const char* val = "";
					bool skipSave = false;
					switch( field.v_nType )
					{
						default:
							continue;

						case FT_INT:
						{
							i32 v = *( i32* )ptr;
							skipSave = ( v == 0 );
							if( !skipSave )
								val = StrFormat( "%d", *( i32* )ptr );
							break;
						}
							
						case FT_FLOAT:
						{
							f32 v = *( f32* )ptr;
							skipSave = ( v == 0.0f );
							if( !skipSave )
								val = StrFormat( "%.3f", v );
							break;
						}

						case FT_BOOL:
						{
							bool v = *( bool* )ptr;
							skipSave = ( v == false );
							val = v ? "1" : "0";
							break;
						}

						case FT_COLOR:
						{
							u32 v = *( u32* )ptr;
							skipSave = ( v == 0xffffffff );
							if( !skipSave )
								val = StrFormat( "0x%X", v );
							break;
						}
							
						case FT_STD_STRING:
						{
							m3dString& v = *( m3dString* )ptr;
							skipSave = ( v.empty() );
							if( !skipSave )
								val = v.c_str();
							break;
						}

						case FT_FILE_PATH:
						{
							FilePath& v = *( FilePath* )ptr;
							skipSave = ( v.empty() );
							if( !skipSave )
								val = v.c_str();
							break;
						}

						case FT_ENTITY_NAME:
						{
							td_EntityName& v = *( td_EntityName* )ptr;
							skipSave = ( v.empty() );
							if( !skipSave )
								val = v.c_str();
							break;
						}

						case FT_VEC2:
							val = Vec2ToStr( *( Vec2* )ptr );
							break;

						case FT_BOUNDF:
							val = BoundfToStr( *( Boundsf* )ptr );
							break;
					}

					if( !skipSave )
						pNode->SetAttribute( field.v_szEditorName, val );
				}

				// save spawners
				/*if( field.v_iFlags & FF_DESC_SPAWNER )
				{
					const cl_ActionEventSpawner* ptr = ( cl_ActionEventSpawner* )( ( u8* )this + field.v_iOffset );
					if( ptr->f_GetNum() )
					{
						TiXmlElement* pChild = m3d_new( TiXmlElement( "ActionList" ) );
						pChild->SetAttribute( "Name", field.v_szName );
						pNode->LinkEndChild( pChild );
						ptr->Save( pNode );
					}
				}*/
			}
		}

		return true;
	}


	//
	bool	cl_BaseEntity::f_LoadProperties( TiXmlElement* pNode )
	{
		// load data map properties
		for( st_ClassDataMap* dm = f_GetDataMap(); dm != 0; dm = dm->v_pBaseClassMap )
		{
			for( m3dSize ii = 0; ii < dm->v_iNumFields; ++ii )
			{
				st_FieldDesc& field = dm->v_pFields[ ii ];
				if( field.v_iFlags & FF_DESC_PROPERTY )
				{
					u8* ptr = ( ( u8* )this + field.v_iOffset );
					const char* name = field.v_szEditorName;
					switch( field.v_nType )
					{
						default:
							continue;

						case FT_INT:
							pNode->Attribute( name, ( i32* )ptr, *( i32* )ptr );
							break;

						case FT_FLOAT:
							pNode->Attribute( name, ( f32* )ptr, *( f32* )ptr );
							break;

						case FT_BOOL:
							pNode->Attribute( name, ( bool* )ptr, *( bool* )ptr );
							break;

						case FT_COLOR:
							pNode->Attribute( name, ( u32* )ptr, *( u32* )ptr );
							break;

						case FT_STD_STRING:
						{
							*( m3dString* )ptr = pNode->Attribute( name, ( *( m3dString* )ptr ).c_str() );
							break;
						}

						case FT_FILE_PATH:
						{
							*( FilePath* )ptr = pNode->Attribute( name, ( *( FilePath* )ptr ).c_str() );
							break;
						}

						case FT_ENTITY_NAME:
						{
							*( td_EntityName* )ptr = pNode->Attribute( name, ( *( td_EntityName* )ptr ).c_str() );
							break;
						}

						case FT_VEC2:
						{
							const char* pValue = pNode->Attribute( name );
							if( pValue )
								StrToVec2( pValue, *( Vec2* )ptr );
						} break;

						case FT_BOUNDF:
						{
							const char* pValue = pNode->Attribute( name );
							if( pValue )
								StrToBoundf( pValue, *( Boundsf* )ptr );
						} break;
					}
				}

				// load spawners
				/*if( field.v_iFlags & FF_DESC_SPAWNER )
				{
					cl_ActionEventSpawner* ptr = ( cl_ActionEventSpawner* )( ( u8* )this + field.v_iOffset );

					for( TiXmlElement* pChild = pNode->FirstChild( "ActionList" ); pChild != NULL; pChild = pChild->NextSiblingElement() )
					{
						if( StrEq( pChild->Attribute( "Name", "" ), field.v_szName ) )
						{
							if( !ptr->Load( pChild ) )
							{
								M3D_LOG_ERR( "Failed to load action spawner '%s' for entity '%s'", field.name, GetName() );
							}
							break;
						}
					}
				}*/
			}
		}

		return true;
	}

	
	//
	void	cl_BaseEntity::f_AddSkin( cl_BaseEntity* pObj, const char* szName )
	{
		M3D_ASSERT( "FiloXSee", pObj );
		M3D_ASSERT( "FiloXSee", !StrEmpty( szName ) );

		// find skin with same name
		u32 iHash = MurmurHash::CalcHash( szName, StrLen( szName ), OBJECT_HASH_SEED );
		td_SkinMapItorConst iter = v_mapSkins.find( iHash );

		// check 
		if( iter != v_mapSkins.end() )
		{
			M3D_LOG_ERR( "Skin with name '%s' of object '%s' is already exists.", szName, v_clPrototype.c_str() );
			return;
		}

		// add new skin into map
		v_mapSkins[ iHash ] = pObj;
		++v_iSkinCount;
	}

	
	//
	cl_BaseEntity*		cl_BaseEntity::f_GetSkin( const char* szName )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szName ) );

		u32 iHash = MurmurHash::CalcHash( szName, StrLen( szName ), OBJECT_HASH_SEED );
		td_SkinMapItor iter = v_mapSkins.find( iHash );

		// check 
		if( iter == v_mapSkins.end() )
		{
			M3D_LOG_ERR( "Skin with name '%s' of object '%s' is NOT exists.", szName, v_clPrototype.c_str() );

			// return default skin
			return v_pInnerHierarchy;
		}

		M3D_ASSERT( "FiloXSee", iter->second );
		return iter->second;
	}

	
	//
	void	cl_BaseEntity::f_SetCurrentSkin( const char* szName )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty( szName ) );

		// check name of new skin with current skin name
		if( v_szSkinName.compare( szName ) == 0 )
			return;

		// set new skin as default
		cl_BaseEntity* pSkin = f_GetSkin( szName );
		if( pSkin )
		{
			v_pCurrentSkin	= pSkin;
			v_pCurrentSkin->f_Validation();
			v_szSkinName	= szName;
		}
		else
		{
			v_pCurrentSkin = v_pInnerHierarchy;
		}
	}


	//
	void	cl_BaseEntity::f_SetAnimation( cl_ObjectAnimationEffectInst* pAnim )
	{
		v_pCurrentAnimation = pAnim;
	}
}	// namespace Puzzle
