//============================================================================
// Name			: LogSingleton.h
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This header file declares all the public and private variables and members
// to successfully implement the singleton design pattern in LogSingleton.cpp
//
//============================================================================

#ifndef LOGSINGLETON_H_
#define LOGSINGLETON_H_

#include "CS1337Logger.h"

class LogSingleton {

private:
	static CS1337Logger* theInstance;
	static int instanceCount;
	LogSingleton();
public:

	virtual ~LogSingleton();
	int getInstanceCount();
	static CS1337Logger* getLogger();
};

#endif /* LOGSINGLETON_H_ */
