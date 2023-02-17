#include <iostream>
#include <string>
#include <iomanip>
#include "sortandsearch.h"

using namespace std;

void performSearch(string [], string [], string [], int, string);
void performSort(string [], string [], string [], int, int);

void menu(string firstNames[], string lastNames[], string DOBs[], int firstNum){

	cout << "Do you want search Search, Sort, or Quit? \n" << endl;

	cout << "Type in 1 to Search" << endl;
	cout << "Type in 2 to Sort" << endl;
	cout << "Type in 3 to Quit" << endl;

	int typedNum;
	cin >> typedNum;
	cout << endl;

	if(typedNum==1){

		string searchWord;
		cout << "Enter last name, first name, or date of birth: ";
		cin >> searchWord;
		performSearch(firstNames,lastNames,DOBs, firstNum, searchWord);
	}

	if(typedNum==2){

		int sortChoice;

		cout << "Type 1 to sort array by last name" << endl;
		cout << "Type 2 to sort array by first name" << endl;


		cout << "Your choice is: ";
		cin >> sortChoice;
		cout << endl;

		performSort(firstNames, lastNames, DOBs, firstNum, sortChoice);
	}

	if(typedNum==3){
		exit(1);
	}
}
