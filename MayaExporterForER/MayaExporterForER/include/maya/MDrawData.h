#ifndef _MDrawData
#define _MDrawData
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
// CLASS:    MDrawData
//
// ****************************************************************************
//
#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MStatus.h>
#include <maya/MTypes.h>
#include <maya/MObject.h>
#include <maya/M3dView.h>

// ****************************************************************************
// DECLARATIONS

class MDagPath;
class MVector;

// ****************************************************************************
// CLASS DECLARATION (MDrawData)

//! \ingroup OpenMayaUI
//! \brief Draw data used in the draw methods of MPxSurfaceShapeUI 
/*!
The MDrawData class holds geometry specific information for user
defined shapes which maya does not intrinsicly know about.

This class is used in the draw methods of MPxSurfaceShapeUI
For each draw request you must create and add a draw data object
which will contain geometry specific information that you will need
in the subsequent call to MPxSurfaceShapeUI::draw.

MDrawData contains one void* member which is a pointer to an
object that you define. This object is the geometry needed to draw
your shape.

To create draw data use the function MPxSurfaceShapeUI::getDrawData.
This function takes two arguments, the first is a pointer to your
geometry object, the second is the draw data being created.
To add the data to a request use MDrawRequest::setDrawData.

Draw data is also used to carry texture information to your draw method.
For materials with texture you must call MMaterial::evaluateTexture
from your MPxSurfaceShapeUI::getDrawRequests method.
Then in your draw method use MMaterial::applyTexture to set up the
viewport to draw using the textured material.
*/
class OPENMAYAUI_EXPORT MDrawData
{
public:
	MDrawData();
	MDrawData( const MDrawData& in );
	~MDrawData();

public:
	void *		geometry();

	static const char*	className();

protected:
	MDrawData& operator=(const MDrawData& other);

private:
    friend class MMaterial;
    friend class MPxSurfaceShapeUI;
	friend class MDrawRequest;

    MDrawData( void* in );
	void*	 fDrawData;
};

#endif /* __cplusplus */
#endif /* _MDrawData */
