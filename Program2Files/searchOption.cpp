#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "sortandsearch.h"

using namespace std;

void menu(string[], string[], string[], int);


void performSearch(string fNames[], string lNames[], string dateofBirths[], int arraySize, string searchWord){

	int pos;
	string UCLastName;
	string UCFirstName;


	for(int k=0; k<arraySize; k++){

		UCLastName = lNames[k];
		//converting string in lNames array to upper case
		for(int i=0; (unsigned)i<UCLastName.length();i++){
			UCLastName[i] = toupper(UCLastName[i]);
		}

		//converting string searchword to upper case
		for(int i=0; (unsigned)i<searchWord.length();i++){
			searchWord[i] = toupper(searchWord[i]);
		}

		pos = lNames[k].find(searchWord); //stores position of searchword of the original string

		if(pos!=-1){  //will execute if searchWord exists within string of an array

			cout << "Last Name: " << left << setw(15) << lNames[k] << setw(15) << " First Name: "<< setw(15) << fNames[k] << setw(15) << " Date of Birth: " << dateofBirths[k];
			cout << endl;

		}

		UCFirstName = fNames[k];
		//converting string in fName to upper case
		for(int i=0; (unsigned)i<UCFirstName.length();i++){

			UCFirstName[i] = toupper(UCFirstName[i]);
		}

		pos = fNames[k].find(searchWord);
		if(pos!=-1){

			cout << "Last Name: " << left << setw(15) << lNames[k] << setw(15) << " First Name: "<< setw(15) << fNames[k] << setw(15) << " Date of Birth: " << dateofBirths[k];
			cout << endl;

		}

		pos = dateofBirths[k].find(searchWord);
		if(pos!=-1){

			cout << "Last Name: " << left << setw(15) << lNames[k] << setw(15) << " First Name: "<< setw(15) << fNames[k] << setw(15) << " Date of Birth: " << dateofBirths[k];
			cout << endl;

		}

	}
	menu(fNames, lNames, dateofBirths, arraySize);
}
