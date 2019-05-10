#include "Repository.h"
#include <assert.h>

int Repository::add(const TrenchCoat& trenchc)
{
	int i= getTrenchCoatPosition(trenchc.getPhoto(), trenchc.getColour());
	if (i == -1)
	{
		this->TrenchRepo.add(trenchc);
		return 1;
	}
	else return 0;
}

int Repository::getTrenchCoatPosition(string photo, string colour)
{
	int i = this->TrenchRepo.getTrenchCoatPosition(photo, colour);
	return i;
}

int Repository::deleteTrench(TrenchCoat& trenchc)
{
	int i = getTrenchCoatPosition(trenchc.getPhoto(), trenchc.getColour());
	if (this->TrenchRepo.getAllElems()[i].getQuantity() == 0)
	{
		int d = this->TrenchRepo.deleteElem(i);
		return d;
	}
	else return 0;
}

int Repository::update(string colour, string photo, TrenchCoat& newtrenchc)
{
	int i = getTrenchCoatPosition(photo, colour);
	int u = this->TrenchRepo.updateElem(i, newtrenchc);
	return u;

}

DynamicVector<TrenchCoat>* Repository::getTrenchCoatsBySize(int size)
{
	return this->TrenchRepo.getElemsBySize(size); 
}

int Repository::getSize() const { return this->TrenchRepo.getSize(); }



