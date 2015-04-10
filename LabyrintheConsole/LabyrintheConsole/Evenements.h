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



