#ifndef _MConditionMessage
#define _MConditionMessage
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
// CLASS:    MConditionMessage
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MMessage.h>
#include <maya/MString.h>
#include <maya/MStringArray.h>

// ****************************************************************************
// CLASS DECLARATION (MConditionMessage)

//! \ingroup OpenMaya
//! \brief Condition change messages.
/*!
	This class is used to register callbacks for changes to specific
    conditions.

	The addConditionCallback method will add callback a callback for
    condition changed messages.

	The first parameter passed to the addConditionCallback method is
	the name of the condition that will trigger the callback.  The
	list of available condition names can be retrieved by calling the
	getConditionNames method or by using the -listConditions flag on
	the <a href="../Commands/scriptJob.html">scriptJob</a> command.

    Callbacks that are registered for conditions will be passed a
    bool value as a parameter.  This value indicates the new state of
    the condition.

	The addConditionCallback method returns an id which is used to
	remove the callback.

    To remove a callback use MMessage::removeCallback.

	All callbacks that are registered by a plug-in must be removed by
	that plug-in when it is unloaded. Failure to do so will result in
	a fatal error.

	The getConditionState method is used to return the current state
	of the specified condition.
*/
class OPENMAYA_EXPORT MConditionMessage : public MMessage
{
public:
	static MCallbackId	addConditionCallback(
								const MString& conditionName,
								MMessage::MStateFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );

	static MStatus		getConditionNames( MStringArray & names );

	static bool			getConditionState( const MString& name,
										   MStatus * ReturnStatus = NULL );

	static const char* className();
};

#endif /* __cplusplus */
#endif /* _MConditionMessage */
