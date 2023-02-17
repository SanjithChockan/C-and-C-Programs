//============================================================================
// Name			: FileLogger.cpp
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// This class logs the log message to an output file when called
//
//============================================================================


#include <iostream>
#include <fstream>
#include "FileLogger.h"

using namespace std;

FileLogger::FileLogger() {
	// TODO Auto-generated constructor stub
	outputFile.open("Log.txt");

}

void FileLogger::displayMessage(const char* str){
	outputFile << str << endl;

}

FileLogger::~FileLogger() {
	// TODO Auto-generated destructor stub
	outputFile.close();
}

