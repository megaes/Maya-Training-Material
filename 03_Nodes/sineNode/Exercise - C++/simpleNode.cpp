//
// Copyright (C) 
// 
// File: simpleNode.cpp
//
// Dependency Graph Node: simpleNode
//
// Author: Maya Plug-in Wizard 2.0
//

#include "simpleNode.h"
#include <maya/MGlobal.h>

//- Assigning a unique node ID to your new node class.
//- Ask ADN or Autodesk product support to reserve IDs for your company. You can
//- reserve ID by block of 64, 128, 256, or 512 consecutive ID.
//-
//- In the solution project, 0x00001 is a temporary ID for reserved for development. Never use that ID in a
//- production environment.

//- TODO: Define here your unique node ID
//...

//- Instantiate the static attributes of your node class.
/*static*/ MObject simpleNode::input;        
/*static*/ MObject simpleNode::output;        
/*static*/ MObject simpleNode::descString;		 

//- The initialize method is called to create and initialize all of the 
//- attributes and attribute dependencies for this node type. This is 
//- only called once when the node type is registered with Maya.
//- Return Values: MS::kSuccess / MS::kFailure
//-
MStatus simpleNode::initialize()
{
	//- Initialize a float input attribute using the MFnNumericAttribute
	//- class. Make that attribute definition saved into Maya file (setStorable),
	//- and selectable in the channel box (setKeyable).

	//- Create a generic attribute using MFnNumericAttribute
	MFnNumericAttribute nAttr;
	input = nAttr.create( "input", "in", MFnNumericData::kFloat, 0.0 );
	//- Attribute will be written to files when this type of node is stored
 	nAttr.setStorable(true);
	//- Attribute is keyable and will show up in the channel box
 	nAttr.setKeyable(true);

	//- TODO: Initialize a float output attribute using the MFnNumericAttribute
	//- class. Make that attribute definition not saved into Maya file.
	//...
	//- TODO: Attribute will not be written to files when this type of node is stored
	//...
	
	//- Initialize a string output attribute using the MFnTypedAttribute
	//- class. Make that attribute definition saved into Maya file.
	//- In order to specify the attribute default value, you will need to 
	//- use the MFnStringData class, before creating the attribute itself.


	//- Use MFnStringData to implement default value first
	MFnStringData fnStringData;
	MString defaultString("description string for current node");
	MObject defaultStringObj = fnStringData.create(defaultString);

	//- TODO: create a string attribute using the MFnTypedAttribute
	//- and use the above MObject as a default value for your string attribute
	//...

	//- Attribute will be written to files when this type of node is stored
	typedAttr.setStorable(true);

	//- Now add the attribute to your node definition using the addAttribute()
	//- method.

	//- Add the attributes we have created to the node
	addAttribute( input );	
	//- TODO: Add the output attribute to the node type definition
	//...
	addAttribute(descString);
	
	//- Finally tell Maya how the information should flow through your node.
	//- This will also tell Maya how the dirty flag is propagated in your node
	//- and ultimately in the Maya DG. To do this, use the attributeAffects()
	//- method to link your node' attributes together.

	//- TODO: Set up a dependency between the input and the output. This will cause
	//- the output to be marked dirty when the input changes. The output will
	//- then be recomputed the next time the value of the output is requested.
	//...

	//- Return success to Maya
	return MS::kSuccess;
}

//- This method computes the value of the given output plug based
//- on the values of the input attributes.
//- Arguments:
//- 	plug - the plug to compute
//- 	data - object that provides access to the attributes for this node
MStatus simpleNode::compute( const MPlug& plug, MDataBlock& data )
{
	MStatus returnStatus;
 
	//- Check which output attribute we have been asked to compute. If this 
	//- node doesn't know how to compute it, you must return MS::kUnknownParameter.

	if( plug == output )
	{
		//- Get a handle to the input attribute that we will need for the
		//- computation. If the value is being supplied via a connection 
		//- in the dependency graph, then this call will cause all upstream  
		//- connections to be evaluated so that the correct value is supplied.
		MDataHandle inputData = data.inputValue( input, &returnStatus );

		//- Read the input value from the handle.
		float result = inputData.asFloat();

		//- Get a handle to the output attribute. Use "outputValue", which 
		//- is similar to the "inputValue" call above except that no 
		//- dependency graph computation will be done as a result of this call.
		//- ToDO: Get a handle on the aOutput attribute
		//...

		//- TODO: Set the new output value to the handle.
		//...

		//- Mark the destination plug as being clean. This will prevent the
		//- dependency graph from repeating this calculation until an input 
		//- attribute of this node which affects this output attribute changes.

		//- TODO: Tell Maya the plug is now clean
		//...

		//- Return success to Maya
		return MS::kSuccess;
	}

	//- Tell Maya that we do not know how to handle this plug, but let give a chance
	//- to our parent class to evaluate it.
	return MS::kUnknownParameter;
}
