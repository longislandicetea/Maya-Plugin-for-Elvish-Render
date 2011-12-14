#ifndef _MUserEventMessage
#define _MUserEventMessage
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
// CLASS:    MUserEventMessage
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDED HEADER FILES


#include <maya/MMessage.h>

// ****************************************************************************
// CLASS DECLARATION (MUserEventMessage)

//! \ingroup OpenMaya
//! \brief User defined Message Types 
/*!
	This class is used to register user-defined event types, register
	callbacks with the user-defined event types, and to post user-defined
	messages.

	The registerUserEvent and deregisterUserEvent methods allow user event
	types to be created and destroyed.  User events are identified by a unique
	string identifier.

	The addCallback method registers a function that will be executed
	whenever the specified message occurs. An id is returned and is used
	to remove the callback.

	The postUserEvent notifies all registered callbacks of the occurence of the
	user-defined event.

	To remove a callback use MMessage::removeCallback.
	All callbacks that are registered by a plug-in must be removed by that
	plug-in when it is unloaded. Failure to do so will result in a fatal error.
*/
class OPENMAYA_EXPORT MUserEventMessage : public MMessage
{
public:

	static MStatus		registerUserEvent( const MString& event );
	static bool			isUserEvent( const MString& event );
	static MStatus		deregisterUserEvent( const MString& event );
	static MCallbackId	addUserEventCallback(
								const MString& event,
								MMessage::MBasicFunction func,
								void * clientData = NULL,
								MStatus * ReturnStatus = NULL );
	static MStatus		postUserEvent(
								const MString& event,
								void* clientData = NULL );

	static const char* className();
};

#endif /* __cplusplus */
#endif /* _MUserEventMessage */
