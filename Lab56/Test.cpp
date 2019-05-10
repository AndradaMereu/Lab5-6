#include "Test.h"
#include<assert.h>

void Test::testAdd()
{
	Repository r{};
	TrenchCoat t1{ 12,"red",23,21,"photo1" };
	TrenchCoat t2{};
	TrenchCoat t3{ 4,"black",25,140,"photo2" };
	TrenchCoat t4{ 12,"gree ",23,21,"photo3" };
	TrenchCoat t5{};
	TrenchCoat t6{ 4,"black",25,140,"photo6" };
	TrenchCoat t7{ 12,"red",23,21,"photo7" };
	TrenchCoat t8{ 4,"black",25,140,"photo8" };
	TrenchCoat t9{ 12,"red",23,21,"photo9" };
	TrenchCoat t10{ 4,"black",25,140,"photo10" };
	TrenchCoat t11{ 12,"red",23,21,"photo11" };
	TrenchCoat t12{ 4,"black",25,140,"photo12" };
	TrenchCoat t13{ 12,"red",23,21,"photo13" };
	r.add(t1);
	assert(r.getSize() == 1);
	r.add(t2);
	r.add(t3);
	assert(r.getSize() == 3);
	//TrenchCoat t4{ 5,"bleu",25,90,"photo3" };
	//r.getTrenchCoats() = r.getTrenchCoats() + t4;
	//assert(r.getSize() == 4);
	//TrenchCoat t5{ 5,"orange",25,120,"photo5" };
	////r.getTrenchCoats() = t5 + r.getTrenchCoats();

	r.add(t4);
	r.add(t5);
	r.add(t6);
	r.add(t7);
	r.add(t8);
	r.add(t9);
	r.add(t10);
	r.add(t11);
	r.add(t12);
	r.add(t13);
	assert(r.getSize() == 12);
	Controller c{ r };
	assert(c.addTrenchCoatCtrl(14, "red", 20, 21, "photo1") == 0);
	assert(c.addTrenchCoatCtrl(14, "green", 20, 21, "photo1") != 0);


	
}

void Test::testDelete()
{
	Repository r{};
	TrenchCoat t1{ 12,"red",0,21,"photo1" };
	TrenchCoat t2{};
	TrenchCoat t3{ 4,"black",25,40,"photo2" };
	r.add(t1);
	assert(r.getSize() == 1);
	r.add(t2);
	r.add(t3);
	assert(r.getSize() == 3);
	assert(r.deleteTrench(t1)!=0);
	assert(r.getSize() == 2);
	assert(r.deleteTrench(t1) == 0);
	Controller c{ r };
	DynamicVector<TrenchCoat> d = r.getTrenchCoats();
	assert(d.getSize() == 2);
	assert(d.deleteElem(-2) == 0);
	assert(d.deleteElem(0) == 1);
	DynamicVector<TrenchCoat>* d2 = r.getTrenchCoatsBySize(4);
	assert(d2->getSize() == 1);
	DynamicVector<TrenchCoat>* d3 = r.getTrenchCoatsBySize(3);
	assert(d3->deleteElem(0) == 0);
	//assert(c.deleteTrenchCoatCtrl(4, "black", 25, 40, "photo2") == 1);

}

void Test::testUpdate()
{
	Repository r{};
	TrenchCoat t1{ 12,"red",23,21,"photo1" };
	TrenchCoat t2{};
	TrenchCoat t3{ 4,"black",25,40,"photo2" };
	DynamicVector<TrenchCoat> d = r.getTrenchCoats();
	assert(d.updateElem(1, t3) == 0);
	r.add(t1);
	assert(r.update("red", "photo1", t3) != 0);

	
}

void Test::testGetTrenchCoatBySize()
{
	Repository r{};
	TrenchCoat t1{ 4,"red",23,21,"photo1" };
	TrenchCoat t2{};
	TrenchCoat t3{ 4,"black",25,40,"photo2" };
	TrenchCoat t4{ 4,"green",23,21,"photo4" };
	TrenchCoat t5{};
	r.add(t1);
	r.add(t2);
	r.add(t3);
	r.add(t4);
	r.add(t5);
	DynamicVector<TrenchCoat>* t = r.getTrenchCoatsBySize(4);
	assert(t->getSize() == 3);

}

void Test::testShoppingBasket()
{
	Repository r{};
	ShoppingBasket b{};
	TrenchCoat t1{ 12,"red",0,21,"photo1" };
	TrenchCoat t2{};
	TrenchCoat t3{ 4,"black",25,40,"photo2" };
	r.add(t1); r.add(t3);
	assert(b.isEmpty() == 1);
	assert(b.add(t1) == 1);
	assert(b.add(t1) == 1);
	assert(b.add(t2) == 1);
	assert(b.isEmpty() == 0);
	assert(b.getSum() == 42);
	ShoppingBasket br(r.getTrenchCoats());
	assert(br.isEmpty() == 0);


}

void Test::testTrenchCoat()
{
	TrenchCoat t1{ 12,"red",0,21,"photo1" };
	TrenchCoat t2{};
	TrenchCoat t3{ 4,"black",25,40,"photo2" };
	assert(t1.getColour() == "red");
	assert(t1.getPhoto() == "photo1");
	assert(t2.getPrice() == 0);
	assert(t2.getQuantity() == 0);
	assert(t3.getSize() == 4);
	t3.setColour("black");
	assert(t3.getColour() == "black");
	t2.setPhotograph("photo");
	assert(t2.getColour() == "");
	assert(t2.getPhoto() == "photo");
	
}
