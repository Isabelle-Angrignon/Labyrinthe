#pragma once
#include <vector>
#include "Evenement.h"

class CEvenements
{
private:
	std::vector<CEvenement> m_Evenements;

	int m_Temps = 0;

public:
	CEvenements() = default;
	~CEvenements() = default;

	void AjouterEvenement(int delais, ACTION_EVENEMENT f);
	void ExecuterEvenements();
};

/*Class CEvenements
{

std::make_pair(Temps + combienDetemps, i);
}
Execute ()
{
for( auto & Pairs; Events)
	{	
		if(Pairs.first() == temps) 
		Pairs.second()();
	}
}

}

setEvent(Item.getDuree, [&Personnage](){Personnage.Annuler(Effet);}->void);
*/
