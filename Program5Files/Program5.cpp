//============================================================================
// Name			: Program5.cpp
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// The main function which calls the singleton function and factory design
// function.
//
//============================================================================

#include <iostream>
#include "LogSingleton.h"
#include "CS1337Logger.h"
#include "ScreenLogger.h"
#include "FileLogger.h"
#include "FactoryDesign.h"

//function prototypes
void Singleton();
void FactoryDesign();

using namespace std;

const int MAX_LENGTH = 1000;

int main() {

	int SingOrFac;
	cout << "Singleton(1) or Factory Design Method(2)" << endl;
	cin >> SingOrFac;
	cout << endl;

	if(SingOrFac == 1){
		Singleton();
	}

	if(SingOrFac == 2){
		FactoryDesign();
	}

	return 0;
}

//function to perform singleton design pattern
void Singleton(){
	string YorN;
	CS1337Logger* onlyInstance;


	bool keepLogging = true;
	while(keepLogging){

		char* inputLog = new char[MAX_LENGTH];
		cout << "Log something" << endl;
		cin >> inputLog;

		onlyInstance = LogSingleton::getLogger();
		cout << "Do you want to log this? Y/N: ";
		cin >> YorN;
		cout << endl;
		if(YorN == "Y"){
			onlyInstance->setValue(true);
			onlyInstance->logMessage(inputLog);
		}
		else{
			cout << "You're not logging anything" << endl;
		}

		cout << "Would you like to continue logging? Y/N: " <<endl;
		cin >> YorN;
		cout << endl;

		if(YorN == "N"){
			keepLogging = false;
		}
		else{
			keepLogging = true;
		}

	}
}

//function to perform factory design pattern
void FactoryDesign(){

	CS1337Logger* factoryInstance;
	int SorF;
	string YorN;

	cout << "Do you want to log to screen(1) or log to file(2)" << endl;
	cin >> SorF;
	cout << endl;

	bool keepLogging = true;
	while(keepLogging){
		char* inputLog = new char[MAX_LENGTH];
		cout << "Log something" << endl;
		cin >> inputLog;

		if(SorF == 1){
			factoryInstance = FactoryDesign::getLogger_Factory(1);
			cout << "Do you want to log this? Y/N: ";
			cin >> YorN;
			cout << endl;
			if(YorN == "Y"){
				factoryInstance->setValue(true);
				factoryInstance->logMessage(inputLog);
			}
			else{
				cout << "You're not logging anything" << endl;
			}

		}

		if(SorF == 2){
			factoryInstance = FactoryDesign::getLogger_Factory(2);
			cout << "Do you want to log this? Y/N: ";
			cin >> YorN;
			cout << endl;
			if(YorN == "Y"){
				factoryInstance->setValue(true);
				factoryInstance->logMessage(inputLog);
			}
			else{
				cout << "You're not logging anything" << endl;
			}

		}

		cout << "Would you like to continue logging? Y/N: " <<endl;
		cin >> YorN;
		cout << endl;

		if(YorN == "N"){
			keepLogging = false;
		}
		else{
			keepLogging = true;
		}
	}

}


