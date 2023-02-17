//============================================================================
// Name			: FactoryDesign.h
// Author		: Sanjith Chockan
// Course		: UTDallas CS 1337.504 F19
// Version		: 1.0
// Copyright	: 2019
//
// Description :
//
// Header file that contains the declaration of private and public variables
// and methods to implement the factory method design pattern.
//
//============================================================================

#ifndef FACTORYDESIGN_H_
#define FACTORYDESIGN_H_

#include "CS1337Logger.h"

class FactoryDesign {

private:
	static CS1337Logger *factoryInstance;

public:
	FactoryDesign();
	static CS1337Logger *getLogger_Factory(int);
	virtual ~FactoryDesign();
};

#endif /* FACTORYDESIGN_H_ */
