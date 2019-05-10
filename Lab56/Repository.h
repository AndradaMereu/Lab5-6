#pragma once
#include "DynamicVector.h"

class Repository
{
private:
	DynamicVector<TrenchCoat>  TrenchRepo;

public:
	//default constructor
	Repository() {}

	/*
	The function adds a new trench coat in the repository;
	IN: an element of type trench coat
	OUT: value 1 if it was successfully added, 0 otherwise
	*/
	int add(const TrenchCoat& trenchc);

	/*
	The function returns all the trenchcoats from the repository
	*/
	DynamicVector<TrenchCoat> getTrenchCoats()  { return this->TrenchRepo; }

	/*
	The function deletes a trench coat from the repository;
	IN: an element of type trench coat
	OUT: value 1 if it was successfully deleted, 0 otherwise
	*/
	int deleteTrench(TrenchCoat& trenchc);

	/*
	returns the position of the trench coat which has the given photo and colour or -1 if such a trench coat was not found
	*/
	int getTrenchCoatPosition(string photo,string colour);

	/*
	returns the size of the repository
	*/
	int getSize() const;

	/*
	The function updates a trench coat from the repository;
	IN: the colour and the photo link of the element to be updated, an element of type trench coat
	OUT: value 1 if it was successfully updated, 0 otherwise
	*/
	int update(string colour, string photo, TrenchCoat& newtrenchc);

	/*
	The function gets all the trench coats which have a certain size
	IN: an integer representing the size
	OUT: a dynamic vector with trench coats
	*/
	DynamicVector<TrenchCoat>* getTrenchCoatsBySize(int size);

};

