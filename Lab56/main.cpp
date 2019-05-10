#include "UI.h"
#include "Trenchcoat.h"
#include <Windows.h>
#include "Repository.h"
#include "Test.h"

using namespace std;

int main()
{
	Repository repo{};
	DynamicVector<TrenchCoat> da;
	//ShoppingBasket shopb(da);
	//add some trench coats
	TrenchCoat t1{ 8,"blue",200,199,"https://www.wardrobemag.com/wp-content/uploads/2017/03/Blue-Trench-Coat.jpg" };
	TrenchCoat t2{ 10,"blue",300,150,"https://cdna.lystit.com/photos/2012/11/28/burberry-blue-carbon-midlength-technical-cotton-trench-coat-product-1-5639645-112125451.jpeg" };
	TrenchCoat t3{ 6,"red",150,200,"https://cdnd.lystit.com/photos/2012/11/30/burberry-military-red-midlength-technical-cotton-double-gun-flap-trench-coat-product-1-5674605-921708368.jpeg" };
	TrenchCoat t4{ 8,"beige",130,180,"https://www.google.ro/search?q=beige+trench+coat&source=lnms&tbm=isch&sa=X&ved=0ahUKEwjO24Cf0NfhAhW8kcMKHdR1DTgQ_AUIDigB&biw=1366&bih=651#imgrc=g0OZCt5TEOLV-M:" };
	TrenchCoat t5{ 12,"blue",300,400,"https://cdna.lystit.com/photos/2012/11/28/burberry-blue-carbon-midlength-technical-cotton-trench-coat-product-1-5639645-112125451.jpeg" };
	TrenchCoat t6{ 8,"green",150,215,"https://lookastic.com/women/olive-trenchcoat/shop/easy-rider-olive-green-trench-coat-1159803" };
	repo.add(t1);
	repo.add(t2); 
	repo.add(t3);
	repo.add(t4);
	repo.add(t5);
	repo.add(t6);
	/*shopb.add(t1);
	shopb.add(t3);*/


	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	Test::testAdd();
	Test::testDelete();
	Test::testUpdate();
	Test::testGetTrenchCoatBySize();
	Test::testShoppingBasket();
	Test::testTrenchCoat();

	return 0;
}

