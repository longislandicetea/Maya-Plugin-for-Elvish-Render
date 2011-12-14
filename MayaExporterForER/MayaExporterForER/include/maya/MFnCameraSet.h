
#ifndef _MFnCameraSet
#define _MFnCameraSet
//
//-
// ==========================================================================
// Copyright (C) 1995 - 2006 Autodesk, Inc., and/or its licensors.  All 
// rights reserved.
// 
// The coded instructions, statements, computer programs, and/or related 
// material (collectively the "Data") in these files contain unpublished 
// information proprietary to Autodesk, Inc. ("Autodesk") and/or its 
// licensors,  which is protected by U.S. and Canadian federal copyright law 
// and by international treaties.
// 
// The Data may not be disclosed or distributed to third parties or be 
// copied or duplicated, in whole or in part, without the prior written 
// consent of Autodesk.
// 
// The copyright notices in the Software and this entire statement, 
// including the above license grant, this restriction and the following 
// disclaimer, must be included in all copies of the Software, in whole 
// or in part, and all derivative works of the Software, unless such copies 
// or derivative works are solely in the form of machine-executable object 
// code generated by a source language processor.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND. 
// AUTODESK DOES NOT MAKE AND HEREBY DISCLAIMS ANY EXPRESS OR IMPLIED 
// WARRANTIES INCLUDING, BUT NOT LIMITED TO, THE WARRANTIES OF 
// NON-INFRINGEMENT, MERCHANTABILITY OR FITNESS FOR A PARTICULAR PURPOSE, 
// OR ARISING FROM A COURSE OF DEALING, USAGE, OR TRADE PRACTICE. IN NO 
// EVENT WILL AUTODESK AND/OR ITS LICENSORS BE LIABLE FOR ANY LOST 
// REVENUES, DATA, OR PROFITS, OR SPECIAL, DIRECT, INDIRECT, OR 
// CONSEQUENTIAL DAMAGES, EVEN IF AUTODESK AND/OR ITS LICENSORS HAS 
// BEEN ADVISED OF THE POSSIBILITY OR PROBABILITY OF SUCH DAMAGES. 
// ==========================================================================
//+
//
// CLASS:    MFnCameraSet
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnDependencyNode.h>
#include <maya/MString.h>
#include <maya/MObject.h>

// *****************************************************************************
// DECLARATIONS

class MDagPathArray;
class MObjectArray;
class MUintArray;

#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

// *****************************************************************************
// CLASS DECLARATION (MFnCameraSet)

//! \ingroup OpenMaya MFn
//! \brief Camera set node function set.
/*!
	MFnCameraSet is the function set that is used for manipulating cameraSet
	nodes.

	A cameraSet node defines a list of camera layeres to be processed in order,
	defining a multi-layer viewing of the scene.  A camera layer consists of an
	object set to be used by the layer, and a camera through which the set is
	viewed. Individual layers may be marked active or inactive and ordered
	arbitrarily.
*/
class OPENMAYA_EXPORT MFnCameraSet : public MFnDependencyNode 
{

	declareMFn(MFnCameraSet, MFnDependencyNode);

public:
	
	MObject     	create( MStatus * ReturnStatus = NULL );
	MObject     	create( const MDagPathArray &camList, MStatus *returnStatus = NULL );
	MObject     	create( const MString &name, MStatus * ReturnStatus = NULL );
	MObject     	create( const MDagPathArray &camList, const MObjectArray &setList, MStatus *returnStatus = NULL );
	MObject     	create( const MString &name, const MDagPathArray &camList, const MObjectArray &setList, MStatus *returnStatus = NULL );
	MStatus     	appendLayer( const MDagPath &camera, const MObject &set );
	MStatus     	appendLayer( const MDagPath &camera );
	MStatus     	insertLayer( unsigned int index, const MDagPath &camera, const MObject &set );
	MStatus     	insertLayer( unsigned int index, const MDagPath &camera );
	MStatus     	deleteLayer( unsigned int index );
	MStatus     	clear();
	unsigned int    getNumLayers( MStatus *returnStatus = NULL );
	MStatus     	setLayerCamera( unsigned int index, const MDagPath &camera );
	MStatus 		getLayerCamera( unsigned int index, MDagPath & camera );
	MStatus     	setLayerSceneData( unsigned int index, const MObject &set );
	MStatus 		getLayerSceneData( unsigned int index, MObject &set );
	MStatus     	setLayerActive( unsigned int index, bool isActive );
	bool			isLayerActive( unsigned int index, MStatus *returnStatus = NULL );
	MStatus     	setLayerOrder( unsigned int index, int order );
	MStatus			getLayerOrder( unsigned int index, int &order );
	MStatus			getSortedIndices( MUintArray &sortedIndices );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnCameraSet, MFnDependencyNode );

END_NO_SCRIPT_SUPPORT:

private:
	void			updateAttributeEditor();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnCameraSet */
