#pragma once
#include "DynamicVector.h"
#include"Trenchcoat.h"
class ShoppingBasket
{
public:
	// default constructor for shopping bag
	ShoppingBasket() { this->currentPos = 0; }

	// constructor of shopping bag with parameters
	ShoppingBasket(DynamicVector<TrenchCoat> da);
	
	//destructor
	~ShoppingBasket();

	// adds an element in the shopping bag
	int add(const TrenchCoat& t);

	//gets the number of elements from the shopping bag
	int getSize() { return this->da.getSize(); }

	// returns the current position
	int getCurrentPos() { return this->currentPos; }

	// modifies the current position by 1
	void growCurrentPos() { this->currentPos++; }
	
	//checks whether the shopping bag is empty or not
	bool isEmpty();

	/*a function which modifies the sum of the shopping bag by adding the price of a new element
	IN: an element t 
	*/
	void growSum(const TrenchCoat& t);

	// returns the sum of all the prices of the elements from the shopping bag
	int getSum() { return this->sum; }

	DynamicVector<TrenchCoat> getTrenchCoats();

private:
	DynamicVector<TrenchCoat> da;
	int currentPos=0;
	int sum=0;
};

