//============================================================================
// Name			: drinkmachine.h
// Author		: Sanjithkarthikesh Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
//		This file contains all the function prototypes and the structures.
//		Reason for this is to include it into the include gaurd, and
//		organize all of it in one file.
//============================================================================

#ifndef DRINKMACHINE_H_
#define DRINKMACHINE_H_
#define NUM_TYPES 128
typedef struct _FileData
{
	int myInt;					// No Dynamic Memory Allocation Necessary

	char **sodaTypes;
	float *priceArray;				// Dynamic Memory Allocation will be necessary;
	int *quantityArray;
	//char **cStyleStringArray; 	// Dynamic Memory Allocation will be necessary.  See readFile() for why there are 2 stars.
} FileData;

typedef struct DrinkItem{
	int id;
	char name[NUM_TYPES];
	double price;
	int numOfDrinks;
	int drinksPurchased;
}dItems;

typedef struct DrinkMachine{

	int version;
	int numOfDrinkItems;
	struct DrinkItem *DrinkItemsArray;
	int location;

}dMachine;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
dMachine * create(void);
FileData * readFile(void);
void destroy(struct DrinkMachine *p);


#endif /* DRINKMACHINE_H_ */
