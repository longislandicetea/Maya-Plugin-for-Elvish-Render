#ifndef _MItSurfaceCV
#define _MItSurfaceCV
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
// CLASS:    MItSurfaceCV
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnDagNode.h>
#include <maya/MObject.h>
#include <maya/MPoint.h>
#include <maya/MVector.h>

// ****************************************************************************
// DECLARATIONS

class MPointArray;
class MDoubleArray;
class MPoint;
class MVector;
class MDagPath;
class MPtrBase;
class TsurfaceCVComponent;
class TcomponentList;

// ****************************************************************************
// CLASS DECLARATION (MItSurfaceCV)

//! \ingroup OpenMaya
//! \brief NURBS surface CV iterator. 
/*!
Iterator class for NURBS surface CVs.

<b>Example:</b> Translates the CVs for a surface in the X direction (world space).

\code
    MItSurfaceCV cvIter( surface, true, &stat );
    MVector vector(1.0,0.0,0.0);

    if ( MStatus::kSuccess == stat ) {
        for ( ; !cvIter.isDone(); cvIter.nextRow() )
        {
            for ( ; !cvIter.isRowDone(); cvIter.next() )
            {
                cvIter.translateBy( vector, MSpace::kWorld );
            }
        }
        cvIter.updateSurface();    // Tell surface is has been changed
    }
    else {
        cerr << "Error creating iterator!" << endl;
    }
\endcode
*/
class OPENMAYA_EXPORT MItSurfaceCV
{
public:
	MItSurfaceCV( MObject & surface, bool useURows = true,
				  MStatus * ReturnStatus = NULL );
	MItSurfaceCV( const MDagPath & surface,
				  MObject & component = MObject::kNullObj,
				  bool useURows = true,
				  MStatus * ReturnStatus = NULL );
	virtual ~MItSurfaceCV();
	bool     isDone( MStatus * ReturnStatus = NULL ) const;
	bool     isRowDone( MStatus * ReturnStatus = NULL ) const;
	MStatus  next();
	MStatus  nextRow();
	MStatus  reset();
	MStatus  reset( MObject & surface, bool useURows = true );
	MStatus  reset( const MDagPath & surface, MObject & component,
					bool useURows = true );
	MPoint   position( MSpace::Space space = MSpace::kObject,
					      MStatus * ReturnStatus = NULL ) const;
	MStatus  setPosition( const MPoint & point,
						  MSpace::Space space = MSpace::kObject );
	MStatus  translateBy( const MVector & vector,
						  MSpace::Space space = MSpace::kObject );
	int     index(	MStatus * ReturnStatus = NULL ) const;
	MStatus  getIndex( int& indexU, int& indexV ) const;
	// Obsolete
	MObject  cv( MStatus * ReturnStatus = NULL ) const;
	MObject  currentItem( MStatus * ReturnStatus = NULL ) const;

	bool     hasHistoryOnCreate( MStatus * ReturnStatus = NULL ) const;
	MStatus  updateSurface();

	static const char* 	className();

protected:
// No protected members

private:
	inline void * updateGeomPtr() const;
	MPtrBase *		f_shape;
	MPtrBase *		f_geom;
	void *			f_path;
	unsigned int		f_uindex;
	unsigned int		f_vindex;
	bool			f_in_u;
	void *			f_it;

	TcomponentList *      fCompList;
	TsurfaceCVComponent * fcvComp;
};

#endif /* __cplusplus */
#endif /* _MItSurfaceCV */
