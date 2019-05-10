#pragma once
#include "Trenchcoat.h"


template <typename TElement>
class DynamicVector
{
private:
	TElement * elems;
	int size;
	int capacity;

public:
	// default constructor
	DynamicVector(int capacity = 10);

	//constructor with parameters
	DynamicVector(const DynamicVector& v);
	
	//destructor
	~DynamicVector();

	/*function which overloads the "=" function and makes it work for dynamic vectors
	IN: a dynamic vector
	*/
	DynamicVector& operator=(const DynamicVector& v);


	/*adds an element in the vector
	IN: the element t be added
	OUT: -
	*/
	void add(const TElement& e);

	/*
	deletes an element from the vector
	IN: the position of the element to be deleted
	OUT: value 1 if the deleted was successful, 0 otherwise
	*/
	int deleteElem(int i);

	/*
	updates an element from the vector
	IN: the position of the vector to be updated, the size, colour,quantity and photograph of the new element
	OUT:value 1 if the deleted was successful, 0 otherwise
	*/
	int updateElem(int i, TrenchCoat& trenchc);

	/*
	searches the vector and finds an element which has the given colour and photograph
	IN: colour, photograph
	OUT: the position of the element (if it was found), -1 otherwise
	*/
	int getTrenchCoatPosition(string photograph,string colour);

	/*
	returns the size of the dynamic array
	*/
	int getSize() const;

	/*
	returns all the elements from the dynamic array
	*/
	TElement* getAllElems() const;

	/*
	returns all the elements which have a certain size
	*/
	DynamicVector<TElement>* getElemsBySize(int size);

	friend DynamicVector& operator+(TElement& e, DynamicVector& v);
	friend DynamicVector& operator+( DynamicVector& v , TElement& e);

private:
	void resizeUp(double factor = 2);
	void resizeDown(double factor = 2);
};

template <typename TElement>
DynamicVector<TElement>::DynamicVector(int capacity) {
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}

template <typename TElement>
DynamicVector<TElement>::DynamicVector(const DynamicVector& v) {
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename TElement>
DynamicVector<TElement>::~DynamicVector()
{
	delete[] this->elems;
}

template <typename TElement>
DynamicVector<TElement>& DynamicVector<TElement>::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new TElement[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename TElement>
void DynamicVector<TElement>::add(const TElement& e)
{
	if (this->size == this->capacity)
		this->resizeUp();

	this->elems[this->size++] = e;
}

template <typename TElement>
void DynamicVector<TElement>::resizeUp(double factor)
{
	this->capacity *= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename TElement>
void DynamicVector<TElement>::resizeDown(double factor)
{
	this->capacity /= static_cast<int>(factor);

	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		els[i] = this->elems[i];

	delete[] this->elems;
	this->elems = els;
}

template <typename TElement>
int DynamicVector<TElement>::getSize() const { return this->size; }

template <typename TElement>
TElement* DynamicVector<TElement>::getAllElems() const { return this->elems; }

template <typename TElement>
int DynamicVector<TElement>::getTrenchCoatPosition(string photo, string colour)
{
	std::string clr2 = colour;
	const char * c2 = clr2.c_str();
	std::string pht2 = photo;
	const char * p2 = pht2.c_str();
	for (int i = 0; i < this->size; i++)
	{
		std::string clr = this->elems[i].getColour();
		const char * c = clr.c_str();

		std::string pht = this->elems[i].getPhoto();
		const char * p = pht.c_str();

		if (strcmp(c, c2) == 0 && strcmp(p, p2) == 0) return i;

	}
	return -1;
}

template <typename TElement>
int DynamicVector<TElement>::deleteElem(int i)
{
	if (this->size == 0)
	{
		return 0;
	}

	if (i<0 || i>this->getSize()) return 0;

	else
	{
		TrenchCoat oldElem = this->elems[i];

		for (int index = i; index < this->getSize() - 1; index++)
		{
			this->elems[index] = this->elems[index + 1];
		}
		this->size = this->size - 1;
		if (this->size <= this->capacity / 4)
			resizeDown();
		return 1;
	}
}

template <typename TElement>
int DynamicVector<TElement>::updateElem(int i, TrenchCoat& trenchc)
{
	if (this->size == 0)
	{
		return 0;
	}

	if (i<0 || i>this->getSize()) return 0;
	else this->elems[i] = trenchc;
	return 1;

}

template <typename TElement>
DynamicVector<TElement>& operator+(TElement& e, DynamicVector<TElement>& v)
{
	v.add(e);
	return v;
}

template <typename TElement>
DynamicVector<TElement>& operator+(DynamicVector<TElement>& v, TElement& e)
{
	v.add(e);
	return v;
}

template<typename TElement>
DynamicVector<TElement>* DynamicVector<TElement>::getElemsBySize(int size)
{
	DynamicVector<TElement>* da = new DynamicVector<TElement>{};
	for (int i = 0; i < this->getSize(); i++)
		if (this->getAllElems()[i].getSize() == size)
			da->add(this->getAllElems()[i]);
	return da;
}

