//============================================================================
// Name			: CS1337Logger.cpp
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This class defines all the variables and methods labeled.
// This is also an abstract class because of how displayMessage is
// defined in the header file.
//
//============================================================================

#include "CS1337Logger.h"

CS1337Logger::CS1337Logger() {

	loggingEnabled = false;

}

void CS1337Logger::setValue(bool boolValue){
	loggingEnabled = boolValue;
}

void CS1337Logger::displayMessage(const char* str){
	if(loggingEnabled==true){
		CS1337Logger::displayMessage(str);
	}
}

void CS1337Logger::logMessage(const char* str){
	if(loggingEnabled==true){
		displayMessage(str);
	}
}

CS1337Logger::~CS1337Logger() {
	// TODO Auto-generated destructor stub
}

