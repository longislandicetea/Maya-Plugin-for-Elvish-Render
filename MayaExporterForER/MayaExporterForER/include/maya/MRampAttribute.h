#ifndef _MRampAttribute
#define _MRampAttribute
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
// CLASS:    MRampAttribute
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MRampAttribute)
//
// This class is used to manipulate ramp attributes.  You can add,
// delete, and set entries in both color and curve ramps.  You can't
// create a ramp attribute from this class, you can only modifying
// existing ramps.
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MTypes.h>
#include <maya/MDGContext.h>

// ****************************************************************************
// DECLARATIONS

class MString;
class MStatus;
class MPlug;
class MColor;
class MFloatArray;
class MColorArray;
class MIntArray;
class MObject;

// ****************************************************************************
// CLASS DECLARATION (MRampAttribute)

//! \ingroup OpenMaya
//! \brief Create and manipulate ramp attributes.
/*!
	A ramp attribute consists of a set of entries describing a curve which
	is used to map an input value onto an output value. Each entry consists
	of an input \b position ranging from 0 to 1, an output \b value that
	that position maps onto, and an enumerator indicating the type of
	interpolation to use between that position and the next.

	Currently two types of output values are a supported: a float, in which
	case the attribute is displayed as a curve in the Attribute Editor, or
	a color, in which case the attribute is displayed as a color gradient,
	similar to how a ramp texture node is displayed.

	A ramp must always have at least one entry. A newly-created ramp attribute will
	automatically be given a default entry at position 0.0 with a value of
	0.0 or black, depending upon the ramp type.

	Any attempt to delete the last of a ramp's entries will fail.  This
	means that if you want to initialize a newly-created ramp attribute
	with a specific set of entries you must add at least one of your
	new entries first before deleting the default entry. Alternatively, you can
	modify the default entry to match one of your new entries and then add your
	remaining entries.
*/
class OPENMAYA_EXPORT MRampAttribute
{
public:

	MRampAttribute ();
	MRampAttribute (const MRampAttribute& other);

	MRampAttribute (const MPlug& obj, MStatus* ReturnStatus = NULL);

	MRampAttribute (const MObject& node, const MObject& attr, MStatus* ReturnStatus = NULL);

	MRampAttribute&    operator =( const MRampAttribute & other );

	~MRampAttribute ();

	//! Interpolation methods.
	enum MInterpolation	{
		kNone = 0,	//!< \nop
		kLinear = 1,	//!< \nop
		kSmooth = 2,	//!< \nop
		kSpline = 3	//!< \nop
	};

	unsigned int getNumEntries (MStatus * returnStatus = NULL);
	void getEntries (MIntArray& indexes,
		MFloatArray& positions,
		MFloatArray& values,
		MIntArray& interps,
		MStatus * returnStatus = NULL);
	void getEntries (MIntArray& indexes,
		MFloatArray& positions,
		MColorArray& colors,
		MIntArray& interps,
		MStatus * returnStatus = NULL);
	void addEntries (MFloatArray& positions,
		MColorArray& values,
		MIntArray& interps,
		MStatus * returnStatus = NULL);
	void addEntries (MFloatArray& positions,
		MFloatArray& values,
		MIntArray& interps,
		MStatus * returnStatus = NULL);
	void deleteEntries (MIntArray& indexes,
		MStatus * returnStatus = NULL);
	void setColorAtIndex (MColor& color, unsigned int index, MStatus * returnStatus = NULL);
	void setValueAtIndex (float value, unsigned int index, MStatus * returnStatus = NULL);
	void setPositionAtIndex (float position, unsigned int index, MStatus * returnStatus = NULL);
	void setInterpolationAtIndex (MRampAttribute::MInterpolation interp, unsigned int index, MStatus * returnStatus = NULL);
	bool isColorRamp(MStatus * returnStatus = NULL);
	bool isCurveRamp(MStatus * returnStatus = NULL);
	void getColorAtPosition (float position, MColor& color, MStatus * returnStatus = NULL, MDGContext& = MDGContext::fsNormal);
	void getValueAtPosition (float position, float& value, MStatus * returnStatus = NULL, MDGContext& = MDGContext::fsNormal);

	static MObject createCurveRamp(const MString& attrLongName, const MString& attrShortName, MStatus* ReturnStatus = NULL);
	static MObject createColorRamp(const MString& attrLongName, const MString& attrShortName, MStatus* ReturnStatus = NULL);

	static const char* className();

protected:
// No protected members

private:
	const void * fData;
	bool fOwn;
};

#endif /* __cplusplus */
#endif /* _MFnRampDataAttribute */



