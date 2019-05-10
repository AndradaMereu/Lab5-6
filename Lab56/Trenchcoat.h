#pragma once
#include <iostream>

using namespace std;

class TrenchCoat
{
private:
	// a size, a colour, a price, a quantity and a photo
	int size;
	string colour;
	int quantity;
	string photo;
	int price;
public:
	//default constructor
	TrenchCoat();
	
	//constructor with parameters
	TrenchCoat(const int& size,const string& colour,const int& quantity,const int& price, const string& photo);

	//returns the size of the Trench coat
	int getSize() const { return this->size; }

	//returns the colour of the trench coat
	string getColour() const { return this->colour; }

	//returns the quantity of trench coats
	int getQuantity() const { return this->quantity; }
	
	//returns a string (a link to the photo of the trench coat
	string getPhoto() const { return this->photo; }

	//returns the price of the trench coat
	int getPrice() const { return this->price; }

	//modifies the price of a trench coat
	void setPrice(int price) { this->price = price; }

	//modifies the size of the trench coat
	void setSize(int size) { this->size = size; }

	//modifies the quantity of the trench coats
	void setQuantity(int quantity) { this->quantity = quantity; }

	//modifies the colour of the trench coat
	void setColour(string colour) { this->colour = colour; }

	//modifies the link of the trench coat
	void setPhotograph(string photograph) { this->photo = photograph; }

	void play();

	//function which gives all the information about a trench coat
	void toString();



};