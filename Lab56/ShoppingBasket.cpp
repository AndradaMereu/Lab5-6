#include "ShoppingBasket.h"



ShoppingBasket::ShoppingBasket(DynamicVector<TrenchCoat> da)
{
	this->da = da;
	this->currentPos = 0;

}


ShoppingBasket::~ShoppingBasket()
{
}


int ShoppingBasket::add(const TrenchCoat & t)
{
	
		this->da.add(t);
		this->growSum(t);
		return 1;
}

bool ShoppingBasket::isEmpty()
{
	return this->da.getSize() == 0;
}

void ShoppingBasket::growSum(const TrenchCoat & t)
{
	this->sum = this->sum + t.getPrice();
}

DynamicVector<TrenchCoat> ShoppingBasket::getTrenchCoats()
{
	return this->da;
}


