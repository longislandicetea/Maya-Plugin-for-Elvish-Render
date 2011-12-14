#ifndef _MFnIkEffector
#define _MFnIkEffector
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
// CLASS:    MFnIkEffector
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MFnTransform.h>
#include <maya/MObject.h>

// ****************************************************************************
// CLASS DECLARATION (MFnIkEffector)

//! \ingroup OpenMayaAnim MFn
//! \brief Inverse kinematics end effector function set 
/*!
MFnIkEffector is the function set for inverse kinematic end effectors.  An end
effector is a point on the skeleton, usually the last bone.  When an IK system
solves, it is trying to calculate the rotations on the joints necessary to get the
end effector to the target point.

The methods of the parent class MFnTransform used to position the end effector.
*/
class OPENMAYAANIM_EXPORT MFnIkEffector : public MFnTransform
{
	declareDagMFn( MFnIkEffector, MFn::kEffector );

public:
	MObject create( MObject parent = MObject::kNullObj,
					MStatus * ReturnStatus = NULL );

BEGIN_NO_SCRIPT_SUPPORT:

 	declareDagMFnConstConstructor( MFnIkEffector, MFn::kEffector );

END_NO_SCRIPT_SUPPORT:

protected:
// No protected members

private:
// No private members
};

#endif /* __cplusplus */
#endif /* _MFnIkEffector */
