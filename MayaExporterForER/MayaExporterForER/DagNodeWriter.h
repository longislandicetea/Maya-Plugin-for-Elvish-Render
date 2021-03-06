#pragma once

#include <iostream>
#include <maya/MIOStream.h>
#include <maya/MGlobal.h>
#include <maya/MDagPath.h>
#include <maya/MItDependencyGraph.h>
#include <maya/MMatrix.h>
#include <maya/MTransformationMatrix.h>
#include <maya/MVector.h>

#include <eiAPI\ei.h>


class DagNodeWriter
{
public:
	DagNodeWriter(MDagPath dagPath, MStatus status);
	virtual ~DagNodeWriter();

	virtual MStatus			ExtractInfo() = 0;
	//virtual MStatus			WriteToFile(ostream& os) = 0;
	virtual MStatus         render() = 0;

	//virtual void			outputInstance(ostream& os, MString instName);
	virtual void            render_instance(MString instName);

	void					openPhoton();
	
	MString					GetInstName();

protected:
	//helpers
	//static void				outputTabs (ostream & os, int tabCount);
	//void					outputTransform(ostream& os);
          

	//render
	void                    render_transform();

	//Dagnode info
	MDagPath*				fpath;
	MString					fname;
	MString					fInstName;
	MTransformationMatrix   fTransmatOrigin;
	MMatrix					fTransMat;
	MVector					fTranslation;

	//photon mapping config
	bool					isPhotonOpen;
};