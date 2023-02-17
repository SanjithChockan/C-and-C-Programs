#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "sortandsearch.h"

using namespace std;

//function prototype
void menu(string[], string[], string[], int);

void performSort(string fNames[], string lNames[], string dateofBirths[], int arraySize, int sortChoice){

	string sorted_LNames[arraySize];
	string sorted_FNames[arraySize];
	string sorted_DOBs[arraySize];

	//sorting by Last Name
	if(sortChoice == 1){

		for(int k=0; k<arraySize; k++){
			//inserting values from original array to another array to sort
			sorted_LNames[k] = lNames[k];

			sorted_FNames[k] = fNames[k];

			sorted_DOBs[k] = dateofBirths[k];
		}

		cout << endl;

		string lowestVal = sorted_LNames[0];

		string temp;

		//bubble sort
		for(int i=0; i<=arraySize-2; i++){

			for(int k=i+1; k<=arraySize-1; k++){

				if(sorted_LNames[i] > sorted_LNames[k]){

					//Swapping and Sorting Last Names
					temp = sorted_LNames[i];
					sorted_LNames[i] = sorted_LNames[k];
					sorted_LNames[k] = temp;

					//Swapping and Sorting First Names
					temp = sorted_FNames[i];
					sorted_FNames[i] = sorted_FNames[k];
					sorted_FNames[k] = temp;

					//Swapping and Sorting date of births
					temp = sorted_DOBs[i];
					sorted_DOBs[i] = sorted_DOBs[k];
					sorted_DOBs[k] = temp;

				}

			}

		}

		for(int k=0; k<arraySize; k++){
			cout << "Last Name: " << left << setw(15) << sorted_LNames[k] << setw(15) << " First Name: "<< setw(15) << sorted_FNames[k] << setw(15) << " Date of Birth: " << sorted_DOBs[k];
			cout << endl;
		}

		menu(fNames, lNames, dateofBirths, arraySize);

	}

	//sort by First Name
	if(sortChoice == 2){
		for(int k=0; k<arraySize; k++){
			//inserting values from original array to another array to sort
			sorted_LNames[k] = lNames[k];

			sorted_FNames[k] = fNames[k];

			sorted_DOBs[k] = dateofBirths[k];
		}

		cout << endl;

		string lowestVal = sorted_LNames[0];

		string temp;

		//bubble sort
		for(int i=0; i<=arraySize-2; i++){

			for(int k=i+1; k<=arraySize-1; k++){

				if(sorted_FNames[i] > sorted_FNames[k]){

					//Swapping and Sorting Last Names
					temp = sorted_LNames[i];
					sorted_LNames[i] = sorted_LNames[k];
					sorted_LNames[k] = temp;

					//Swapping and Sorting First Names
					temp = sorted_FNames[i];
					sorted_FNames[i] = sorted_FNames[k];
					sorted_FNames[k] = temp;

					//Swapping and Sorting date of births
					temp = sorted_DOBs[i];
					sorted_DOBs[i] = sorted_DOBs[k];
					sorted_DOBs[k] = temp;

				}

			}

		}

		for(int k=0; k<arraySize; k++){
			cout << "Last Name: " << left << setw(15) << sorted_LNames[k] << setw(15) << " First Name: "<< setw(15) << sorted_FNames[k] << setw(15) << " Date of Birth: " << sorted_DOBs[k];
			cout << endl;
		}

		menu(fNames, lNames, dateofBirths, arraySize);

	}



}
