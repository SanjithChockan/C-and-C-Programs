//============================================================================
// Name			: drinkmachine.c
// Author		: Sanjithkarthikesh Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
//		This file contains the main function. This is where all the functions,
//		create(), destroy(), firstDrink(), nextDrink(), items(), available(),
//		cost(), purchase and dumpDrinkMachine() are written. All of this serves
//		to simulate a drink machine.
//============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int INVALID_INDEX = -1;

#define NUM_TYPES 128

const int STRING_BUFFER_SIZE = 128;

const char * INPUT_FILE_NAME = "drink_machine.txt";

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



//function prototypes
dMachine * create(void);

FileData * readFile(void);

void destroy(struct DrinkMachine*);

struct DrinkItem *firstDrink(struct DrinkMachine*);

struct DrinkItem *nextDrink(struct DrinkMachine*);

int items(struct DrinkMachine*);

int available(struct DrinkMachine*, int);

double cost(struct DrinkMachine*, int);

int purchase(struct DrinkMachine*, int, double, double*);

void dumpDrinkMachine(struct DrinkMachine*);


typedef enum{AVAILABLE, VALID_SELECTION_BUT_OUT, INVALID_SELECTION}DrinkAvailability;

typedef enum{PURCHASED,INVALID,NOT_AVAILABLE,INSUFFICIENT_FUNDS}Purchase;

//main function where create() is called
int main(void) {

	struct DrinkMachine b;


	dMachine *dm_fileData;

	dm_fileData = create();



	FileData *myFileData;
	//myFileData = readFile();

	//items(&b);
	//printf("%d",items(&b));

	return EXIT_SUCCESS;
}

//sets structure drinkitem's variables to data from file
dMachine * create(void){

	dMachine dM_Stuff;


	dM_Stuff.version = 1;
	dM_Stuff.location = INVALID_INDEX;

	FILE *pToFile= fopen(INPUT_FILE_NAME,"r");
	dMachine *fileData;
	fileData = calloc(1, sizeof(FileData));

	fscanf(pToFile, "%d", &(fileData->numOfDrinkItems));
	printf("FIRST INT: %d\n", fileData->numOfDrinkItems);
	fflush(stdout);
	//assigning numofDrinkItems to the first number on file
	dM_Stuff.numOfDrinkItems = fileData->numOfDrinkItems;

	printf("Version Checkpoint: %d \n", dM_Stuff.version);

	printf("numofdrinkitems : %d\n", dM_Stuff.numOfDrinkItems);



	fileData ->DrinkItemsArray = calloc(fileData->numOfDrinkItems,sizeof(int));

	char tempBuffer[STRING_BUFFER_SIZE];


	for(int i=0; i<fileData->numOfDrinkItems;i++){
		fileData->DrinkItemsArray[i].id = i+1;
		fscanf(pToFile, "%s", tempBuffer);
		strcpy(fileData->DrinkItemsArray[i].name, tempBuffer);

		fscanf(pToFile, "%lf", &fileData->DrinkItemsArray[i].price);

		fscanf(pToFile, "%d", &fileData->DrinkItemsArray[i].numOfDrinks);

		printf("%d           %s           %lf           %d \n",fileData->DrinkItemsArray[i].id,fileData->DrinkItemsArray[i].name, fileData->DrinkItemsArray[i].price,fileData->DrinkItemsArray[i].numOfDrinks);
		fflush(stdout);
	}
	fflush(stdout);

	int Z;
	printf("%s \n", "Enter a drink id for the drink you want to purchase or 0 to quit.");
	fflush(stdout);
	scanf("%d",&Z);

	fflush(stdout);

	printf("%d\n", Z);

	if(Z==0){
		printf("%s", "Thank you for using the drink machine.");
		exit(1);
	}

	if(Z>0 && Z<=dM_Stuff.numOfDrinkItems){
		printf("%s \n", "Enter your payment(Up to 2.00 dollars)");
		fflush(stdout);
		double payment;
		scanf("%lf \n",&payment);
		printf("%lf \n",payment);
		fflush(stdout);

		if(payment>= fileData->DrinkItemsArray[Z].price && payment <= 2.00){
			printf("%s\n", "Payment was successful");
			fflush(stdout);
		}
		else{
			printf("%s", "Payment too low or too high");
			fflush(stdout);
		}


	}

	fclose(pToFile);
	return fileData;
}

//this function frees up the memory
void destroy(struct DrinkMachine *d_Machine){

	for(int i=0; i<d_Machine->numOfDrinkItems;i++){
		if(d_Machine->DrinkItemsArray[i].name!= NULL){
			free(d_Machine->DrinkItemsArray[i].name);
			free(&d_Machine->DrinkItemsArray[i].price);
			free(&d_Machine->DrinkItemsArray[i].numOfDrinks);
			free(&d_Machine->DrinkItemsArray[i].id);
		}
	}
	free(d_Machine);

	printf("Everything is freed/destroyed");
	fflush(stdout);

}

//set location to 1 if it was INVALID_INDEX
struct DrinkItem *firstDrink(struct DrinkMachine* d_Machine){
	struct DrinkItem* returnFirstDrink;
	if(d_Machine->location==INVALID_INDEX){
		d_Machine->location = 0;
	}
	returnFirstDrink = &d_Machine->DrinkItemsArray[d_Machine->location];
	return returnFirstDrink;
}

//goes to the next location is structures exists
struct DrinkItem *nextDrink(struct DrinkMachine* d_Machine){
	struct DrinkItem* returnFirstDrink;

	if(d_Machine->location ==INVALID_INDEX){
		return NULL;
	}
	if(d_Machine->location<sizeof(d_Machine)){
		d_Machine->location+=1;
	}

	if(d_Machine->location>=sizeof(d_Machine)){
		d_Machine->location=INVALID_INDEX;
		return NULL;
	}

	returnFirstDrink = &d_Machine->DrinkItemsArray[d_Machine->location];
	return returnFirstDrink;
}

//return the number of DrinkItem structures
int items(struct DrinkMachine* d_Machine){
	return d_Machine->numOfDrinkItems;
}


//this function tells if a drink is available, not available or invalid input
int available(struct DrinkMachine *d_Machine, int id){

	if(id<1 && id>d_Machine->numOfDrinkItems){
		return INVALID_SELECTION;
	}

	if(d_Machine->DrinkItemsArray[id-1].numOfDrinks==0){
		return VALID_SELECTION_BUT_OUT;
	}

	return AVAILABLE;
}

//returns the cost of the selected[id] drink
double cost(struct DrinkMachine *d_Machine, int id){

	if(id<1 && id>d_Machine->numOfDrinkItems){
		return -1.0;
	}

	return d_Machine->DrinkItemsArray[id-1].price;
}

int purchase(struct DrinkMachine *d_Machine, int id, double payment, double *change){

	if(id<1 && id>d_Machine->numOfDrinkItems){
		return INVALID;
	}

	if(d_Machine->DrinkItemsArray[id-1].numOfDrinks==0){
		return NOT_AVAILABLE;
	}

	if(payment < d_Machine->DrinkItemsArray[id-1].price){
		return INSUFFICIENT_FUNDS;
	}

	*change = payment - d_Machine->DrinkItemsArray[id-1].price;
	return PURCHASED;

}

//prints all the output to the screen
void dumpDrinkMachine(struct DrinkMachine *d_Machine){


	//create();
}




/*
 * END
 */













FileData * readFile(void){

	FILE* inFile;

	FileData *fileData;


	int i, stringLen;

	char tmpBuffer[STRING_BUFFER_SIZE];

	inFile = fopen(INPUT_FILE_NAME, "r");

	if(!inFile){

		puts("Error opening file");
		return NULL;
	}

	fileData = calloc(1, sizeof(FileData));

	if(fileData == NULL)	// Check that the calloc was successful
		return NULL;

	fscanf(inFile, "%d", &(fileData->myInt));
	printf("DEBUG readFile int: %d\n", fileData->myInt); //prints first statement; debugging
	fflush(stdout);   // Guarantee that above printf statements reach the screen


	fileData->sodaTypes = calloc(fileData->myInt, sizeof(char *));

	if (fileData->sodaTypes == NULL){
		puts("ERROR: Failed to allocate sodaTypes array in function readFile");
		return NULL;
	}

	// Dynamically create an array of floats that is the correct size
	fileData->priceArray = calloc(fileData->myInt, sizeof(float));

	if (fileData->priceArray == NULL){

		puts("ERROR: Failed to allocate float array in function readFile");
		return NULL;
	}

	// Dynamically create an array of floats that is the correct size
	fileData->quantityArray = calloc(fileData->myInt, sizeof(int));

	if (fileData->quantityArray == NULL){

		puts("ERROR: Failed to allocate int array in function readFile");
		return NULL;
	}

	for(i=0; i < fileData->myInt; ++i){
		fscanf(inFile, "%s %f %d", tmpBuffer,&(fileData->priceArray[i]), &(fileData->quantityArray[i]));



		stringLen = strlen(tmpBuffer);

		printf("DEBUG String %d is '%s' \n", i, tmpBuffer);

		printf("DEBUG Float %d is: %f\n", i, fileData->priceArray[i]);

		printf("DEBUG Int %d is: %d\n", i, fileData->quantityArray[i]);
		fflush(stdout);   // Guarantee that above printf statements reach the screen

		// Allocate memory to hold the string plus the NULL character
		fileData->sodaTypes[i] = malloc(stringLen + 1);  	// +1 for the NULL terminator that makes it a C-Style string

		if(fileData->sodaTypes[i] == NULL){
			printf("ERROR: Failed to allocate string memory for string %d in function readFile", i);
			return NULL;
		}

		// Copy the string from the tmpBuffer to the newly allocated space
		memcpy(fileData->sodaTypes[i], tmpBuffer, stringLen + 1);		// destination, source, size

	}

	//prints out all the elements
	/*for(int k=0; k < fileData->myInt;k++){
		printf("%s\n", fileData->sodaTypes[k]);
	}*/


	fclose(inFile);

	// Make sure we force any output to screen
	puts("DEBUG readFile Success!");
	fflush(stdout);

	return fileData;
}




