#pragma once
#include "Controller.h"

class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}

	void run();

private:
	// prints a general menu
	void printMenu();

	// prints the repository menu
	void printRepositoryMenu();

	// prints the user menu
	void printUserMenu();

	//a function which adds a trench coat to the repository
	void addTrench();

	//a function which deletes a trench coat from the repository
	void deleteTrench();

	//a function which updates a trench coat from the repository
	void updateTrench();

	// a function which displays all trench coats from the repository
	void displayAll();

	// function which adds a new trench coat in the shopping basket
	void addTrenchCoatShopBasket(TrenchCoat& trc);

	int validCommand(int command);

	void displayAllBasket();

	int validTrench(TrenchCoat& tr);

	void readTrench();


	/*void startShow(int _size);
	void nextTrench();*/
};