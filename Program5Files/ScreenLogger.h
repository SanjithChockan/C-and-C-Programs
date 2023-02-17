//============================================================================
// Name			: ScreenLogger.h
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This header file has all the necessary private and public variables and
// methods to successfully define in ScreenLogger.cpp to print the log message
// to the console
//
//============================================================================

#ifndef SCREENLOGGER_H_
#define SCREENLOGGER_H_

#include "CS1337Logger.h"

class ScreenLogger: public CS1337Logger {
public:
	ScreenLogger();
	void displayMessage(const char*);
	virtual ~ScreenLogger();
};

#endif /* SCREENLOGGER_H_ */
