#include "DagNodeWriter.h"

#include <maya/MFnDagNode.h>

DagNodeWriter::DagNodeWriter(MDagPath dagPath, MStatus status)
{
	fpath = new MDagPath(dagPath);
	MFnDagNode node(dagPath);
	fTransMat = node.transformationMatrix();
}

DagNodeWriter::~DagNodeWriter()
{
	if(fpath!=NULL) delete fpath;
}

void DagNodeWriter::outputTabs( ostream& os, int tabCount )
{
	for (int i = 0; i < tabCount; i++) {
		os << "\t";
	}
}

void DagNodeWriter::outputInstance( ostream& os, MString instName )
{
	os<<"instance "<<"\""<<instName.asChar()<<"\"\n";
	outputTabs(os,1); os<<"element "<<"\""<<fname.asChar()<<"\"\n";
	outputTabs(os,1); outputTransform(os);
	os<<"end instance"<<"\n";
	os<<"\n";
}

MString DagNodeWriter::GetInstName()
{
	return fInstName;
}

void DagNodeWriter::outputTransform( ostream& os )
{
	os<<"transform ";
	for(int i = 0;i<4;++i)
	{
		for(int j = 0;j<4;++j)
		{
			os<<fTransMat(i,j)<<" ";
		}
	}
	os<<"\n";
}
