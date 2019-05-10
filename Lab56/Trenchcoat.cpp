#include <iostream>
#include <string>
#include "Trenchcoat.h"
#include <Windows.h>
#include <shellapi.h>

using namespace std;

TrenchCoat::TrenchCoat():size(0), colour(""), quantity(0), price(0), photo("") {}


TrenchCoat::TrenchCoat(const int& size, const string& colour, const int& quantity, const int& price, const string& photograph)
{
	this->size = size;
	this->colour = colour;
	this->quantity = quantity;
	this->price = price;
	this->photo = photograph;

}

void TrenchCoat::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void TrenchCoat::toString()
{
	cout << "The coat has the size: " << this->size << ", the colour: " << this->colour << "; the quantity is: " << this->quantity
		<<"and the price is : "<<this->price<< endl;
}