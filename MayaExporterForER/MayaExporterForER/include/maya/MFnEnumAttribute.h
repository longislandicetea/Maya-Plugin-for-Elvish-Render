#ifndef _MFnEnumAttribute
#define _MFnEnumAttribute
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
// CLASS:    MFnEnumAttribute
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnAttribute.h>

// ****************************************************************************
// DECLARATIONS

class MString;

// ****************************************************************************
// CLASS DECLARATION (MFnEnumAttribute)

//! \ingroup OpenMaya MFn
//! \brief Enumerated attribute function set. 
/*!
  Function set for enumerated attributes.  These attributes accept
  fields as input. Each field consists of a short and its associated
  string, which is a descriptive name for the field.
*/
class OPENMAYA_EXPORT MFnEnumAttribute : public MFnAttribute
{
	declareMFn(MFnEnumAttribute, MFnAttribute);

public:

	MObject     create( const MString& fullName,
					    const MString& briefName,
						short defaultValue = 0,
					    MStatus* ReturnStatus = NULL );
	MStatus		addField( const MString & fieldString, short index);
	MString     fieldName( short index, MStatus *ReturnStatus = NULL ) const;
	short       fieldIndex( const MString & fieldString,
							MStatus *ReturnStatus = NULL ) const;
	MStatus		getMin ( short& minValue ) const;
	MStatus		getMax ( short& maxValue ) const;

	MStatus 	setDefault( short index );
	MStatus 	setDefault( const MString &fieldString );

	MStatus		getDefault( short &index ) const;
	MString		defaultValue( MStatus * ReturnStatus = NULL ) const;

BEGIN_NO_SCRIPT_SUPPORT:

 	declareMFnConstConstructor( MFnEnumAttribute, MFnAttribute );
	//!     NO SCRIPT SUPPORT
	MStatus		getDefault( MString &fieldString ) const;

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:

	MStatus		commonGetDefault( short &index ) const;
	MStatus		commonSetDefault( short index ) const;
};

#endif /* __cplusplus */
#endif /* _MFnEnumAttribute */
