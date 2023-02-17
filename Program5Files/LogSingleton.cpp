//============================================================================
// Name			: LogSingleton.cpp
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This class implements the Singleton design pattern, which only
// uses one instance from several different classes. In this case,
// it is used by FileLogger and ScreenLogger.
//
//============================================================================

#include "LogSingleton.h"
#include "CS1337Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"

CS1337Logger* LogSingleton::theInstance = nullptr;
int LogSingleton::instanceCount = 0;

//private constructor
LogSingleton::LogSingleton() {
	// TODO Auto-generated constructor stub

	++LogSingleton::instanceCount;

}

int LogSingleton::getInstanceCount(){

	return instanceCount;

}

CS1337Logger* LogSingleton::getLogger(){
	if(theInstance == nullptr){
		theInstance = new FileLogger();
	}

	return theInstance;
}

LogSingleton::~LogSingleton() {
	// TODO Auto-generated destructor stub
}

