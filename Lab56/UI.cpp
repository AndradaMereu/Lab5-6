#include "UI.h"
#include <string>

using namespace std;

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "The menu is: " << endl;
	cout << "\t 1. Add trench coat." << endl;
	cout << "\t 2. List all trenchcoats." << endl;
	cout << "\t 3. Delete trench coat." << endl;
	cout << "\t 4. Update trenchcoat." << endl;
	cout << "\t 0. Exit." << endl;
}

void UI::printMenu()
{
	cout << endl;
	cout << "Choose the mode: 1. Administrator; 2. User." << endl;
}

void UI::printUserMenu()
{
	cout << endl;
	cout << "The menu is: \n";
	cout << "\t 1. See all the trench coats having a given size" << endl;
	cout << "\t 0. Return." << endl;
}

int UI::validTrench(TrenchCoat & tr)
{
	string colours[]{ "red","green","blue","black","white","yellow","pink","purple","beige","grey" };
	std::string clr = tr.getColour();
	const char * c = clr.c_str();
	bool ok = 0;
	for (auto m: colours)
	{
		std::string clr2 = m;
		const char * c2 = clr2.c_str();
		if (strcmp(c, c2) == 0) ok = 1;
	}
	if (ok == 0) return 0;
	if (tr.getQuantity() < 0) return 0;
	if (tr.getPrice() < 0) return 0;
	if (tr.getSize() < 0 || tr.getSize() > 16 || tr.getSize() % 2 != 0) return 0;
	return 1;
}

void UI::readTrench()
{
	cout << "Enter the size: ";
	int size;
	cin >> size;
	cin.ignore();
	cout << "Enter the colour: ";
	string colour;
	getline(cin, colour);
	cout << "Enter the quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Enter the price: ";
	int price;
	cin >> price;
	cin.ignore();
	cout << "Enter the photo link: ";
	string photograph;
	getline(cin, photograph);
	TrenchCoat*  t= new TrenchCoat{ size, colour, quantity,price, photograph };
}

void UI::addTrench()
{
	cout << "Enter the size: ";
	int size;
	cin >> size;
	cin.ignore();
	cout << "Enter the colour: ";
	string colour;
	getline(cin, colour);
	cout << "Enter the quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Enter the price: ";
	int price;
	cin >> price;
	cin.ignore();
	cout << "Enter the photo link: ";
	string photograph;
	getline(cin, photograph);
	TrenchCoat t{ size, colour, quantity,price, photograph };
	while (validTrench(t) == 0) {
		cout << "The trench is not valid. Please try again \n";
		cout << "Enter the size: ";
		int size;
		cin >> size;
		cin.ignore();
		cout << "Enter the colour: ";
		string colour;
		getline(cin, colour);
		cout << "Enter the quantity: ";
		int quantity;
		cin >> quantity;
		cin.ignore();
		cout << "Enter the price: ";
		int price;
		cin >> price;
		cin.ignore();
		cout << "Enter the photo link: ";
		string photograph;
		getline(cin, photograph);
		t.setColour(colour);
		t.setPhotograph(photograph);
		t.setPrice(price);
		t.setQuantity(quantity);
		t.setSize(size);
	}

	if(this->ctrl.addTrenchCoatCtrl(size, colour, quantity,price, photograph)==1) cout<<"Added successfully \n";
}

void UI::deleteTrench()
{
	cout << "Enter the size: ";
	int size;
	cin >> size;
	cin.ignore();
	cout << "Enter the colour: ";
	string colour;
	getline(cin, colour);
	cout << "Enter the quantity: ";
	int quantity;
	cin >> quantity;
	cin.ignore();
	cout << "Enter the price: ";
	int price;
	cin >> price;
	cin.ignore();
	cout << "Enter the photo link: ";
	string photograph;
	getline(cin, photograph);
	/*int t = 0;
	t = this->ctrl.deleteTrenchCoatCtrl(size, colour, quantity, photograph);
	cout << t;*/

	if (this->ctrl.deleteTrenchCoatCtrl(size, colour, quantity,price, photograph) != 0) cout << "Deleted successfully \n";
	else cout << "Trench coat not deleted";

}

void UI::updateTrench()
{
	
	cout << "Enter the old colour: ";
	string oldcolour;
	getline(cin, oldcolour);
	cout << "Enter the photo old link: ";
	string oldphotograph;
	getline(cin, oldphotograph);
	cout << "Enter the new size: ";
	int newsize;
	cin >> newsize;
	cin.ignore();
	cout << "Enter the new colour: ";
	string newcolour;
	getline(cin, newcolour);
	cout << "Enter the new quantity: ";
	int newquantity;
	cin >> newquantity;
	cin.ignore();
	cout << "Enter the new price: ";
	int newprice;
	cin >> newprice;
	cin.ignore();
	cout << "Enter the photo new link: ";
	string newphotograph;
	getline(cin, newphotograph);

	int u = this->ctrl.updateTrenchCoatCtrl(oldcolour, oldphotograph, newsize, newcolour, newquantity, newprice,newphotograph);
	if (u != 0) cout << "Updated successfully.";
	else cout << "Could not be updated";
}

void UI::displayAll()
{
	DynamicVector<TrenchCoat> v = this->ctrl.getRepo().getTrenchCoats();
	TrenchCoat* trenchc = v.getAllElems();

	if (trenchc == NULL)
		return;

	if (v.getSize() == 0) {
		cout << "There are no songs to display." << endl;
		return;
	}

	for (int i = 0; i < v.getSize(); i++)
	{
		TrenchCoat t = trenchc[i];
		cout << "Trench coat has size " << t.getSize() << " , colour " << t.getColour() << ", quantity " << t.getQuantity() << "; the link is: " << t.getPhoto() << endl;
	}
}

void UI::addTrenchCoatShopBasket(TrenchCoat& trc)
{
	if(int tr = this->ctrl.addTrenchCoatShopBasket(trc)==1) cout<<"Added successfully \n" ;
	else cout << "not added";

}

int UI::validCommand(int command)
{
	if(command<0 || command >4)
		return 0;
	return 1;
}

void UI::displayAllBasket()
{
	DynamicVector<TrenchCoat> sb = this->ctrl.getShoppingBasket().getTrenchCoats();

	TrenchCoat* trenchc = sb.getAllElems();

	if (trenchc == NULL)
		return;

	if (sb.getSize() == 0) {
		cout << "There are no songs to display." << endl;
		return;
	}

	for (int i = 0; i < sb.getSize(); i++)
	{
		TrenchCoat t = trenchc[i];
		cout << "Trench coat has size " << t.getSize() << " , colour " << t.getColour() << ", quantity " << t.getQuantity() << "; the link is: " << t.getPhoto() << endl;
}}



//void UI::startShow(int _size)
//{
//	//if (this->ctrl.getShoppingBasket().isEmpty()) cout << "Nothing to show" << endl;
//	this->ctrl.startShow(_size);
//}

//void UI::nextTrench()
//{
//	this->ctrl.nextTrench()
//}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		while (command < 0 || command>2) {
			cout << "Command not valid \n"; cout << "Input the command: ";
			cin >> command;
			cin.ignore();
		}
		if (command == 0)
			break;
		if (command == 1)
		{
			cout << "Administrator mode chosen. "<< endl;
			while (true)
			{
				UI::printRepositoryMenu();
				cout << "Input the command: ";
				cin >> command;
				cin.ignore();
				while (validCommand(command) == 0) {
					cout << "Command is not valid \n";
					cout << "Input the command: ";
					cin >> command;
					cin.ignore();
				}
				switch (command)
				{
				case 1:
					this->addTrench();
					break;
				case 2:
					this->displayAll();
					break;
				case 3:
					this->deleteTrench();
					break;
				case 4:
					this->updateTrench();
					break;
				default:
					break;
				}
			}
		}
		else if (command == 2)
		{
			cout << "User mode chosen.";
			while (true)
			{
				UI::printUserMenu();
				cout << "Choose an option: ";
				int commandUser{ 0 };
				cin >> commandUser;
				cin.ignore();
				while (commandUser < 0 || commandUser>1) {
					cout << "Command not valid \n";
					cout << "Choose an option: ";
					cin >> commandUser;
					cin.ignore();
				}
				if (commandUser == 0) break;
				switch (commandUser)
				{
					
				case 1:
					int _size;
					cout << "Enter the size: ";
					cin >> _size;
		
					DynamicVector<TrenchCoat>* da = this->ctrl.getElemsBySize(_size);
					bool ok = 1; int i = 0;
					while (ok == 1 && i <= da->getSize())
					{
						TrenchCoat t = da->getAllElems()[i];
						t.toString();
						t.play();
						///*cout << "Do you want to add this to the basket? \n";
						//char answer;
						//cin >> answer;
						//if (strcmp(&answer, "yes") == 0)*/ this->ctrl.addTrenchCoatShopBasket(t);
						////da->growCurrentPos();
						cout << "\n Do you want to add it to the shopping basket? \n Input answer(0 if not, 1 otherwise): ";
						int answer1;
						cin >> answer1;
						if (answer1 == 1)
						{
							this->addTrenchCoatShopBasket(t); 
						}
						cout << "\n Do you want to continue? \n Input answer(0 if not, 1 otherwise): ";
						int answer2;
						cin >> answer2;
						if (answer2 == 0) break;
						i++;
						if (i == da->getSize()) i = 0;


					}
					cout << " \n \n The shopping basket is: \n";
					this->displayAllBasket();
					cout << "\n \n The price of your purchase is: " << this->ctrl.getSumShoppingBasket();
					break;


					
				}
			}
		}
	}
}
