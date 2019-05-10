#pragma once
#include "Repository.h"
#include "ShoppingBasket.h"
#include <iostream>


class Controller
{
private:
	Repository repo;
	ShoppingBasket shopb;

public:
	Controller(const Repository& repo) : repo(repo) {}

	Repository getRepo()const { return this->repo; }

	ShoppingBasket getShoppingBasket() {
		return this->shopb;
	}

	int addTrenchCoatCtrl(const int& size, const string& colour, const int& quantity, const int& price,const string& photograph);

	int addTrenchCoatShopBasket(TrenchCoat& tr);

	int deleteTrenchCoatCtrl(const int& size,const string& colour,const int& quantity, const int& price,const string& photograph);

	int updateTrenchCoatCtrl(string& oldcolour, string& oldphotograph, int& newsize, string& newcolour, int& newquantity, int& newprice, string& newphotograph);

	void startShow(int _size);

	void nextTrench(ShoppingBasket* da);

	int getCurrentPos();
	
	DynamicVector<TrenchCoat>* getElemsBySize(int _size);

	int getSumShoppingBasket() { return this->shopb.getSum(); }

	void growSum(const TrenchCoat & t)
	{
		this->shopb.growSum(t);
	}
};
