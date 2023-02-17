//============================================================================
// Name			: cs1337F19p1-amortize.cpp
// Author		: Sanjithkarthikesh Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
//		This file holds the function perform_calculations,
//      that calculates the number of payments, the amount that
//      is due every month, the amount of the total payment that
//      is allocated to interest and principal, and the balance after
//		every payment.
//
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include "cs1337F19p1.h"

using namespace std;


void perform_calculations(double val1, double val2, double val3, ofstream &outputFile){

	int payment;
	double amount, interest, principal, balance;

	double totalInterest = 0;

	cout << "Starting Balance: $" <<val1 << endl; //printing out val 1 to the console
	cout << "Interest Rate: " <<val2 << endl;     //printing out val 2 to the console
	cout << "Monthly Payment: $" <<val3 << endl;  //printing out val 3 to the console
	cout << endl;

	//Printing out the title for each column for the table for both the output file and console using setw to space them out
	cout << "Payment"  << setw(10)<<"     " << setw(10)<< "Amount" << "            " << setw(10)<<"Interest" << "    " << setw(10)<<"Principal" <<"         "<< setw(10)<<"Balance" << endl;
	outputFile << "Payment"  << setw(10)<< "     " << setw(10)<<"Amount" << "            " << setw(10)<<"Interest" << "    " << setw(10)<<"Principal" <<"         "<< setw(10)<<"Balance" << endl;

	payment = 1;
	amount = val3;
	balance = val1;

	//a do while loop to calculate the # of payments, amount, interest, principal, and balance
	do{
		interest = (balance*val2)/12.0;             //dividing it by 12 because interest on loan is annual
		interest = floor(100*interest)/100;         //floors the value interest to get rid of the decimals

		totalInterest+= interest;					//calculates total interest
		principal = val3 - interest;
		balance-=principal;

		//setprecision(2) adds two decimals values to Interest. Prints the values for all the columns
		cout <<fixed << setprecision(2) <<payment << setw(10)<< "           "<<setw(10)<<amount <<"               "<<setw(10)<< fixed << setprecision(2) <<interest << "      " <<setw(10)<<principal<<"         "<< setw(10)<<balance <<endl;
		outputFile <<fixed << setprecision(2) <<payment << setw(10)<< "           "<<setw(10)<<amount <<"               "<<setw(10)<< fixed << setprecision(2) <<interest << "      " <<setw(10)<<principal<<"         "<< setw(10)<<balance <<endl;

		payment++;  //increases payment by one after each payment

		//if statement for when the balance goes below the monthly dues
		//necessary to print the last payment and to make sure that the amount
		//does not end up being a negative number
		if(balance<val3){
			interest = (balance*val2)/12.0;
			interest = floor(100*interest)/100;

			totalInterest+= interest;

			principal = val3 - interest;

			if(balance < amount){
				principal = balance; // setting principal to balance so that interest + balance will be the amount
				amount = balance + interest;
			}

			balance-=principal; // since balance and principal are now equal, output will be zero at the end


			cout << fixed << setprecision(2) <<payment << setw(10)<< "           "<<setw(10)<<amount <<"               "<<setw(10)<< fixed << setprecision(2) <<interest << "      " <<setw(10)<<principal<<"         "<< setw(10)<<balance <<endl;
			outputFile <<payment << setw(10)<< "           "<<setw(10)<<amount <<"               "<<setw(10)<< fixed << setprecision(2) <<interest << "      " <<setw(10)<<principal<<"         "<< setw(10)<<balance <<endl;
		}

	}while((interest+principal == amount) && balance >= val3); //true till while+principal still equals to amount
															   //and balance is more than or equal to monthly dues.
															   //the first if statement inside the loop is necessary
															   //because the loop won't continue to the last payment!


	cout << "" << endl;
	cout << "Total Payments Made: " << payment << endl;			//prints out the total payments made
	cout << "Total Interest Paid: $" << totalInterest << endl;  //and the total interest paid to the console

	outputFile << "" << endl;
	outputFile << "Total Payments Made: " << payment << endl;        //prints out the total payments made
	outputFile << "Total Interest Paid: $" << totalInterest << endl; //and the total interest paid to the output file

}
