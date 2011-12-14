#ifndef _MDrawProcedureBase
#define _MDrawProcedureBase
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
// CLASS:    MDrawProcedureBase
//
// ****************************************************************************
//
// CLASS DESCRIPTION (MDrawProcedureBase)
//
// This class provides an interface through which a plugin can
// implement a class to provide custom hardware drawing effects.
//
// The derived class needs to be registered with using <to be completed>
// Please refer to documentation of <> for more details.
//
// Each procedure has a user defined string name and can be enabled or
// disabled.  There is also a logical "call location" which defines
// when within a rendering loop that the draw procedure will be
// called. Name, enabling and call location must be defined.
//
// Additionally, the procedure can define a desired sequence
// number. All draw procedures are sorted by sequence
// number. Procedures with lower sequence number will be invoked
// first. The number 0 is the lowest supported sequence number and is
// the default.  When more than one procedure has a sequence number,
// the order of registration will determine the invocation order.
//
// All derived classes must over the execute() method. This is the
// method that will be called by the hardware renderer to which the
// procedure is attached.  The call will only be made if the procedure
// is enabled.
//
// ****************************************************************************

#if defined __cplusplus

// ****************************************************************************
// INCLUDES


#include <maya/MString.h>

// ****************************************************************************
// CLASS DECLARATION (MDrawProcedureBase)

//! \ingroup OpenMayaRender
//! \brief Base user draw procedure class
/*!
This class provides an interface through which a plug-in can be writen
to implement a class to provide custom hardware drawing effects.

The derived class can be added, removed, or reordered in a list of
draw procedures used by the hardware renderer.  Please refer to
documentation for MhardwareRenderer for more details.

Each procedure has a user defined string name and can be enabled or
disabled. Name, and enabling methods must be defined.

All derived classes must over the execute() method. This is the method
that will be called by the hardware renderer to which the procedure is
attached. The call will only be made if the procedure is enabled.
*/
class OPENMAYARENDER_EXPORT MDrawProcedureBase
{
public:
	// constructor
	MDrawProcedureBase(const MString &name);

	// destructor
	virtual	~MDrawProcedureBase();

	// Method called to perform drawing effect. Derived classes must implement this.
	virtual bool execute() = 0;

	// Set the procedure to be enabled or not.
	void		setEnabled(bool value);

	// Returns if the procedure is enabled.
	bool		enabled() const ;

	//	Set the name of the procedure
	void		setName( const MString &name );

	// Get the name of the procedure
	const MString &name() const;

protected :
	// Protected default constructor
	MDrawProcedureBase();

	// Name of the procedure
	MString		fName;

	// Enable / disable toggle
	bool		fEnabled;

private:
	// No private members
};

#endif /* __cplusplus */
#endif /* _MDrawProcedureBase */
