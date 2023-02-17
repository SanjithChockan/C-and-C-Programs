//============================================================================
// Name			: cs1337F19p1-main.cpp
// Author		: Sanjithkarthikesh Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
//		This file contains the main function. This is where the input and
//      output files are opened. The first integer is taken from the input file
//		and it is used in a for loop to go through different test cases. The function
//		perform_calculations is called in this loop. After the loop ends, both the
//		input and the output files are closed.
//
//
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "cs1337F19p1.h"
using namespace std;

//function prototype
void perform_calculations(double, double, double, ofstream&);

int main() {

	ifstream inputFile;
	string fileName;

	ofstream outputFile;
	string outfileName;

	string firstNum;
	int fNum;


	cout << "Enter your input file name: ";
	cin >> fileName;							 //User inputs input file name
	cout << endl;

	inputFile.open(fileName);					 //opens input file to access data in it

	cout << "Enter your output file name: ";
	cin >> outfileName;						     //User inputs output file name
	cout << endl;
	outputFile.open(outfileName);                //opens output file to access data in it

	//checking if file opens without error

	/*if(inputFile){
		cout << "Success" << endl;
	}
	else{
		cout << "Error in opening the file. \n";
	}*/

	getline(inputFile, firstNum);               //getting the first number(number of test cases) as string
	stringstream stoint(firstNum);              //converts the string stored in firstNum to an int
	stoint >> fNum;                        //the string from firstNum is stored as an int in variable fNum

	//cout << fNum << endl; //print the first number on the file as a string

	double input1, input2, input3;

	for(int i=0; i<fNum; i++){
		inputFile >> input1;                                       //Getting the first number from a case
		outputFile << "Starting Balance: $" << input1 << endl;	   //Prints first number to the output file

		inputFile >> input2;									   //Getting the second number from a case
		outputFile << "Interest Rate: " << input2 << endl;         //Prints second number to the output file

		inputFile >> input3;									   //Getting the third number from a case
		outputFile << "Monthly Payment: $" << input3 << endl;      //Prints third number to the output file
		outputFile << endl;

		cout << "" << endl;
		perform_calculations(input1, input2, input3, outputFile);  //calling function perform_calculations

		outputFile << "" << endl;
	}

	inputFile.close();
	outputFile.close();

	return 0;
}



