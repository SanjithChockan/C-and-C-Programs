//============================================================================
// Name			: FactoryDesign.cpp
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This class has the implementation of the factory method design pattern.
// The ultimate goal of this class is to return a new FileLogger() or new ScreenLogger()
//
//============================================================================

#include "FactoryDesign.h"
#include "CS1337Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

FactoryDesign::FactoryDesign() {
	// TODO Auto-generated constructor stub

}

CS1337Logger *FactoryDesign::getLogger_Factory(int x){
	if(x == 1)
		return new ScreenLogger();

	return new FileLogger();
}

FactoryDesign::~FactoryDesign() {
	// TODO Auto-generated destructor stub
}

