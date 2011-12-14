#ifndef _MGeometry
#define _MGeometry
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
// CLASS:    MGeometry
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MGeometryData.h>
#include <maya/MGeometryPrimitive.h>
#include <maya/MString.h>

// ****************************************************************************
// CLASS DECLARATION (MGeometry)

//! \ingroup OpenMayaRender
//! \brief Geometric data cache.
/*!
MGeometry stores the collection of MGeometryData arrays which describe
a Maya surface, including per-component data such as UV mapping and colour.

Various methods are provided for returning MGeometryData containing the
data for different properties of the geometry: the position() method
returns position data, the normal() method returns normals, and so on.

The primitiveArray() method returns MGeometryPrimitive's which provide
indexing into those property arrays for each primitive to be drawn.
*/
class OPENMAYARENDER_EXPORT MGeometry
{
public:
	~MGeometry();
	MGeometry( const MGeometry & geom);
	MGeometry& operator = (const MGeometry &rhs);
	unsigned int primitiveArrayCount() const;
	const MGeometryPrimitive primitiveArray(unsigned int arrayNumber) const;
	const MGeometryData position();
	const MGeometryData normal();
	const MGeometryData componentId();
	const MGeometryData texCoord( const MString& name);
	const MGeometryData color( const MString& name);
	const MGeometryData tangent( const MString& name);
	const MGeometryData binormal( const MString& name);
	const MGeometryData data( MGeometryData::DataType what, const MString &name );

protected:
	// Default constructor is protected
	MGeometry();
	MGeometry( void *_pGeometry, void * _pIndexing );
	void set( void *_pGeometry, void * _pIndexing );

	void *_pGeometry;
	MGeometryPrimitive _pIndexing;

private:
// No private members

	friend class MGeometryManager;
	friend class MGeometryList;
	friend class MVaryingParameter;

};

#endif
#endif // _MGeometry
