//============================================================================
// Name        : Program2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "sortandsearch.h"

using namespace std;

//function prototype
void menu(string[], string[], string[], int);

int main() {

	ifstream inputFile;
	string inputFileName;

	string f_Name;
	string l_Name;
	string dateofbirth;

	string firstStr = "Hello";
	string secondStr = "H";
	int pos;

	pos = firstStr.find(secondStr);

	cout << pos << endl;

	cout << "Enter input File name: ";
	cin >> inputFileName;
	cout << endl;

	inputFile.open(inputFileName);

	if(inputFile){
		cout << "Input File has opened successfully!"<< endl;
	}
	else{
		cout << "Error in opening input file..." << endl;
	}


	int firstNum;

	inputFile >> firstNum;  //first number from input file
	cout << firstNum << endl;

	//declaring arrays this way for dynamic memory allocation
	string *firstNames = new string[firstNum];
	string *lastNames = new string[firstNum];
	string *DOBs = new string[firstNum];

	//writing data from input files to arrays
	for(int k=0; k<firstNum; k++){
		inputFile >> l_Name;
		lastNames[k] = l_Name;

		inputFile >> f_Name;
		firstNames[k] = f_Name;

		inputFile >> dateofbirth;
		DOBs[k] = dateofbirth;
	}

	menu(firstNames, lastNames, DOBs, firstNum);

	delete []firstNames;
	delete []lastNames;
	delete []DOBs;


	inputFile.close();
	return 0;
}
