//============================================================================
// Name			: CS1337Logger.h
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This header file contains all the declarations of private and public variables,
// constructors, and methods. This is an abstract class because displayMessage is
// set to 0.
//
//============================================================================

#ifndef CS1337LOGGER_H_
#define CS1337LOGGER_H_

class CS1337Logger {

private:
	bool loggingEnabled;
public:
	CS1337Logger();
	virtual ~CS1337Logger();
	void setValue(bool);
	virtual void displayMessage(const char*)=0;
	void logMessage(const char*);
};

#endif /* CS1337LOGGER_H_ */
