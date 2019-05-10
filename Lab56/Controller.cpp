#include "Controller.h"

int Controller::addTrenchCoatCtrl(const int & size, const string & colour, const int & quantity,const int& price, const string & photograph)
{
	TrenchCoat trc{ size,colour,quantity,price,photograph };
	int t=this->repo.add(trc);
	return t;
}

int Controller::addTrenchCoatShopBasket(TrenchCoat& tr)
{
	if (int t = this->shopb.add(tr) == 1) return 1;
	return 0;
}

int Controller::deleteTrenchCoatCtrl(const int& size, const string& colour, const int& quantity,const int& price, const string& photograph)
{
	
	TrenchCoat trc{ size,colour,quantity,price,photograph };
	int t = this->repo.deleteTrench(trc);
	return t;
}

int Controller::updateTrenchCoatCtrl(string& oldcolour, string& oldphoto, int& newsize, string& newcolour, int& newquantity, int& newprice, string& newphotograph)
{
	TrenchCoat newt{ newsize,newcolour,newquantity,newprice,newphotograph };
	int u = this->repo.update(oldcolour, oldphoto, newt);
	return u;
}



//void Controller::startShow(int _size)
//{
//	ShoppingBasket* da = new ShoppingBasket(this->repo.getTrenchCoatsBySize(_size));
//	cout << da->getSize();
//	if (da->getSize()==0)
//		return;
//	int currentPos = 0;	
//	//TrenchCoat currentTrench = da->getCurrentElem();
//	currentTrench.toString();
//	currentTrench.play();
//	
//}

DynamicVector<TrenchCoat>* Controller::getElemsBySize(int _size)
{
	DynamicVector<TrenchCoat>* da = this->repo.getTrenchCoatsBySize(_size);
	return da;
}



//void Controller::nextTrench(ShoppingBasket* da)
//{
//	if (da->getSize()==0)
//		return;
//	da->growCurrentPos();
//	TrenchCoat currentTrench = da->getCurrentElem(da->getCurrentPos());
//	currentTrench.play();
//}