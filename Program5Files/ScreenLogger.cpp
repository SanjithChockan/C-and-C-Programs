//============================================================================
// Name			: ScreenLogger.cpp
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// The goal of this class is to display the given log message to the console
// when called.It also overrides the displayMessage from the abstract class,
// CS1337Logger.cpp
//
//============================================================================

#include <iostream>

#include "ScreenLogger.h"

using namespace std;

ScreenLogger::ScreenLogger() {
	// TODO Auto-generated constructor stub

}

void ScreenLogger::displayMessage(const char* str){
	cout << str << endl;
}

ScreenLogger::~ScreenLogger() {
	// TODO Auto-generated destructor stub
}

