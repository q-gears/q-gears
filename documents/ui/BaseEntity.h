#ifndef __BASE_ENTITY_H_
#define __BASE_ENTITY_H_

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
namespace Puzzle
{
	/// fwd
	class cl_ObjectAnimationEffectInst;

	/// return pointer to object into hierarchy, by name
	cl_BaseEntity*			f_GetObjectIntoHierarchy( cl_BaseEntity* pRoot, const char* szName );
	// return pointer to parent screen
	cl_BaseEntity*			f_GetParentScreen( cl_BaseEntity* pEntity );

	/**
		@class	cl_BaseEntity
		@brief	base class for all resource. All objects,
		locating on the screen, and description in the xml file,
		represent the tree of this objects.
	 */
	class cl_BaseEntity : public cl_Unk
	{
		M3D_DECLARE_CLASS( cl_BaseEntity, cl_Unk );

	public:
		///
		M3D_DECLARE_DATADESC();
		///
		M3D_DECLARE_PROPERTY_CONTROL;


								/// make entity and set type name
								cl_BaseEntity( const char* szType = NULL );
		virtual					~cl_BaseEntity();
	
	public:
		/// load prototype from file
		bool					f_LoadPrototype( const char* szFilename );
		/// Build objects hierarchy by xml 'object' node
		void					f_BuildHierarchy( TiXmlElement* pNode );
		/// Add children into object hierarchy
		bool					f_AddChild( cl_BaseEntity* pObj ); 
		/// add children to inner object
		bool					f_AddInnerChildren( cl_BaseEntity* pObj ); 
		/// remove child
		bool					f_RemoveChild( cl_BaseEntity* pObj );
		/// Get hierarchy root object
		cl_BaseEntity*			f_FindRoot();
		/// Get object of hierarchy by name
		cl_BaseEntity*			f_FindByName( const char* szName, u32 iHash = ~0u );
		/// Get object of hierarchy by name
		cl_BaseEntity*			f_GetObjectByIndex( m3dSize iIndex );
		/// Get inner object by name
		virtual cl_BaseEntity*	f_FindInnerObjectByName( const char* szName );
		/// Get inner object by index
		virtual cl_BaseEntity*	f_GetInnerObjectByIndex( m3dSize iIndex );
		/// return count of inner objects
		virtual m3dSize			f_GetInnerObjectCount() const;

	public:
		/// render this item
		virtual void			f_Render();
		/// update some inside variables
		virtual	void			f_Update();
		/// object coordinate validation
		virtual void			f_Validation();
		/// object hierarchy position validation
		virtual void			f_ValidationPos();
		/// self object position validation
		virtual void			f_ValidationSelfPos();
		/// object scale validation
		virtual void			f_ValidationScale();
		/// object color validation (rgb)
		virtual void			f_ValidationColor();
		/// object opacity validation
		virtual void			f_ValidationOpacity();
		/// destroy all hierarchy
		virtual void			f_Destroy();
		/// object impulse reaction
		virtual bool			f_Impulse( const st_ImpulseInfo& szImp );
		/// return true, if object executing last command
		virtual bool			f_IsAction() const;

		/**
			@brief accept event by name
			@param szActionName name of action
			@param pActivator object witch activate this action
			@param pSender object witch send this action
			@param clParam event parameter

		*/
		virtual	bool			f_AcceptEvent( const char* szActionName, cl_BaseEntity* pActivator, cl_BaseEntity* pSender, Variant clParam );
		/// return string value, according with param
		virtual const char*		f_GetValue( const char* szParam );
		/// Set effect time
		virtual void			f_SetTime( f32 fTime );
		
		
		/// Set some param
		void					f_ActionShow( st_InputEvent& );
		void					f_ActionHide( st_InputEvent& );
		void					f_ActionSet( st_InputEvent& stEv );
		void					f_ActionSetToChild( st_InputEvent& stEv );
		void					f_ActionValidation( st_InputEvent& );
		/// start behavior by name
		void					f_ActionSetSkin( st_InputEvent& stEv );
		/// work with object animation
		void					f_ActionStartAnimation( st_InputEvent& );
		void					f_ActionRestartAnimation( st_InputEvent& );
		void					f_ActionStopAnimation( st_InputEvent& );
		void					f_ActionPauseAnimation( st_InputEvent& );


	protected:
		/// Make class by description from root xml node
		virtual bool			f_ReadDescription( TiXmlElement* pRoot );
		
		// load/save public properties
		virtual	bool			f_SaveProperties( TiXmlElement* pNode );
		virtual	bool			f_LoadProperties( TiXmlElement* pNode );

	public:
		//////////////////////////////////////////////////////////////////////////
		// Work with skins

		/// add new skin object
		void					f_AddSkin( cl_BaseEntity* pObj, const char* szName );
		/// return skin hierarchy by name
		cl_BaseEntity*			f_GetSkin( const char* szName );
		/// set current skin
		void					f_SetCurrentSkin( const char* szName );

		//////////////////////////////////////////////////////////////////////////
		// Work with animation
		/// execute this function when start/stop object animation
		void					f_SetAnimation( cl_ObjectAnimationEffectInst* pAnim );

		//////////////////////////////////////////////////////////////////////////
		// Work with object params

		/// Set sprite hot spot (piVot of sprite)
		void					f_SetHotSpot( f32 fX, f32 fY );
		/// Set self object scale
		void					f_SetScale( f32 fXScale, f32 fYScale = -1.0f );
		/// Set self object rotation
		void					f_SetRotation( f32 fRot );
		/// Set self position of object
		void					f_SetPosition( f32 fX, f32 fY );
		/// Set object visibility
		void					f_SetVisible( bool bVisible );
		/// Set object enable
		void					f_SetEnable( bool bEnabled );
		/// Set flag to catch impulsed
		void					f_SetImpulsed( bool bImpulsed );
		/// Set object name
		void					f_SetName( const char* szName );
		/// set enable, visible and impulsed flag into some state
		void					f_SetShow( bool bShow );
		/// set object color
		void					f_SetColor( u32 iColor = 0xffffffff );
		/// set object alpha
		void					f_SetOpacity( u8 iAlpha = 0xff );

		// Get functions

		/// Get inner object by name
		cl_BaseEntity*			f_GetParent() const;
		/// Get parent of parent
		cl_BaseEntity*			f_GetGrandParent() const;
		/// Get type of this entity
		const char*				f_GetType() const;

		// Get self transformation
		const Vec2&				f_GetHotSpot() const;
		const Vec2&				f_GetScale() const;
		f32						f_GetRotation() const;
		const Vec2&				f_GetPosition() const;
		const st_Transform&		f_GetSelfTransform() const;

		/// Get name of object
		const char*				f_GetName() const;
		/// Get relative name of object file description
		const char*				f_GetPrototyle() const;
		///
		bool					f_IsVisible() const;
		///
		bool					f_IsEnabled() const;
		///
		bool					f_IsImpulsed() const;

	
	protected:
		enum { MAX_CHILD_OBJECT = 400 };
		typedef	FixedArray< cl_BaseEntity*, MAX_CHILD_OBJECT >	td_ObjectArray;
		typedef	td_ObjectArray::iterator				td_ObjectArrayItor;
		typedef	td_ObjectArray::const_iterator			td_ObjectArrayItorConst;


		typedef	m3dmap< u32, cl_BaseEntity* >			td_ObjectMap;				// map, for first finding objects
		typedef	td_ObjectMap::iterator					td_ObjectMapItor;
		typedef	td_ObjectMap::const_iterator			td_ObjectMapItorConst;

		typedef	m3dmap< u32, cl_BaseEntity* >			td_SkinMap;
		typedef	td_SkinMap::iterator					td_SkinMapItor;
		typedef	td_SkinMap::const_iterator				td_SkinMapItorConst;

		//
		td_EntityName							v_clName;				// name object in hierarchy
		FilePath								v_clPrototype;			// name of object file description
		td_EntityName							v_szType;				// name of type of this object
		td_SystemName							v_szProtExt;			// extension of prototype

		bool									v_bVisible;				// visibility of this object
		bool									v_bEnabled;				// enable of this object
		bool									v_bImpulsed;			// if true, then object catch impulses

		// children data
		td_ObjectArray							v_arrChildren;			// children array, for non shuffle objects when render

		td_ObjectMap							v_mapChildren;			// map of children for fast finding objects
		m3dSize									v_iChildrenCount;		// count of children objects
		cl_BaseEntity*							v_pInnerHierarchy;		// inner object hierarchy
		cl_BaseEntity*							v_pParent;				// parent entity

		// skin data
		td_SkinMap								v_mapSkins;				// object skins
		m3dSize									v_iSkinCount;			// count of object skins
		cl_BaseEntity*							v_pCurrentSkin;			// pointer to current skin
		td_EntityName							v_szSkinName;			// name of current skin

		// animation data
		cl_ObjectAnimationEffectInst*			v_pCurrentAnimation;	// pointer to current object animation

		// dinamic parameters

		// transform data
		st_Transform							v_stSelfTransform;		// transform of this object
		st_Transform							v_stCurrTransform;		// current object transform into hierarchy
		st_Transform							v_stLastTransform;		// last object transform into hierarchy
		Vec2									v_stDirection;			// object moving direction

		//
		u32										v_iSelfColor;			// self color
		u32										v_iCurrColor;			// current object color

		bool									v_bNeedValidate;		// need validate of parameters
	};


	//
	inline
	bool	cl_BaseEntity::f_ReadDescription( TiXmlElement* /*pRoot*/ )
	{ 
		return true; 
	}


	//
	inline
	bool	cl_BaseEntity::f_IsAction() const
	{
		return false;
	}


	//
	inline
	void	cl_BaseEntity::f_SetTime( f32 /*fTime*/ )
	{
	}


	//////////////////////////////////////////////////////////////////////////
	// Set functions

	//
	inline
	void	cl_BaseEntity::f_SetHotSpot( f32 fX, f32 fY )
	{
		v_stSelfTransform.v_stHotSpot.v_fX = fX;
		v_stSelfTransform.v_stHotSpot.v_fY = fY;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_BaseEntity::f_SetScale( f32 fXScale, f32 fYScale )
	{
		v_stSelfTransform.v_stScale.v_fX = fXScale;
		v_stSelfTransform.v_stScale.v_fY = fYScale < 0.0f ? fXScale : fYScale;
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_BaseEntity::f_SetRotation( f32 fRot )
	{
		v_stSelfTransform.v_fRotation = fRot;
		v_bNeedValidate = true;
	}
	
	
	//
	inline
	void	cl_BaseEntity::f_SetPosition( f32 fX, f32 fY )
	{
		v_stSelfTransform.v_stPos.Set( fX, fY );
		v_bNeedValidate = true;
	}


	//
	inline
	void	cl_BaseEntity::f_SetVisible( bool bVisible )
	{
		v_bVisible = bVisible;
	}


	//
	inline
	void	cl_BaseEntity::f_SetEnable( bool bEnabled )
	{
		v_bEnabled = bEnabled;
	}

	
	//
	inline
	void	cl_BaseEntity::f_SetImpulsed( bool bImpulsed )
	{
		v_bImpulsed = bImpulsed;
	}


	//
	inline
	void	cl_BaseEntity::f_SetName( const char* szName )
	{
		M3D_ASSERT( "FiloXSee", !StrEmpty(szName) );
		v_clName = szName;
	}


	//
	inline
	void	cl_BaseEntity::f_SetShow( bool bShow )
	{
		v_bVisible = bShow;
		v_bEnabled = bShow;
		v_bImpulsed = bShow;
	}

	//
	inline
	void	cl_BaseEntity::f_SetColor( u32 iColor )
	{
		v_iSelfColor = M3D_SET_A( iColor, M3D_A( v_iSelfColor ) );
		f_ValidationColor();
	}


	//
	inline
	void	cl_BaseEntity::f_SetOpacity( u8 iAlpha )
	{
		v_iSelfColor = M3D_SET_A( v_iSelfColor, iAlpha );
		f_ValidationOpacity();
	}

	//////////////////////////////////////////////////////////////////////////
	// Get functions

	//
	inline
	cl_BaseEntity*	cl_BaseEntity::f_GetParent() const
	{
		return v_pParent;
	}

	
	//
	inline
	cl_BaseEntity*	cl_BaseEntity::f_GetGrandParent() const
	{
		return v_pParent == NULL ? NULL : v_pParent->f_GetParent();
	}


	//
	inline
	const char*		cl_BaseEntity::f_GetType() const
	{
		return v_szType.c_str();
	}


	//
	inline
	const Vec2&		cl_BaseEntity::f_GetHotSpot() const
	{
		return v_stCurrTransform.v_stHotSpot;
	}


	//
	inline
	const Vec2&		cl_BaseEntity::f_GetScale() const
	{
		return v_stCurrTransform.v_stScale;
	}
	

	//
	inline
	f32		cl_BaseEntity::f_GetRotation() const
	{
		return v_stCurrTransform.v_fRotation;
	}
	

	//
	inline
	const Vec2&		cl_BaseEntity::f_GetPosition() const
	{
		return v_stCurrTransform.v_stPos;
	}


	//
	inline
	const st_Transform&		cl_BaseEntity::f_GetSelfTransform() const
	{
		return v_stSelfTransform;
	}


	//
	inline
	const char*		cl_BaseEntity::f_GetName() const
	{
		return v_clName.c_str();
	}


	//
	inline
	const char*		cl_BaseEntity::f_GetPrototyle() const
	{
		return v_clPrototype.c_str();
	}


	//
	inline
	bool		cl_BaseEntity::f_IsVisible() const
	{
		return v_bVisible;
	}


	//
	inline
	bool		cl_BaseEntity::f_IsEnabled() const
	{
		return v_bEnabled;
	}


	//
	inline
	bool		cl_BaseEntity::f_IsImpulsed() const
	{
		return v_bImpulsed;
	}

}	// namespace Puzzle



#endif	// __BASE_ENTITY_H_
