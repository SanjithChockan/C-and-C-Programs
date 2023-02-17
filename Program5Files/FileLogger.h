//============================================================================
// Name			: FileLogger.h
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This header file contains the public and private declarations of variables
// and methods to successfully write log messages to an output file in
// FileLogger.cpp
//
//============================================================================

#ifndef FILELOGGER_H_
#define FILELOGGER_H_

#include <fstream>
#include "CS1337Logger.h"

using namespace std;

class FileLogger: public CS1337Logger {

private:
	ofstream outputFile;
public:

	FileLogger();
	void displayMessage(const char*);
	virtual ~FileLogger();
};

#endif /* FILELOGGER_H_ */
