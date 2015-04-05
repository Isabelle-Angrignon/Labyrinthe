#pragma once
#include <Windows.h>
#include "Commande.h"
#include <cmath>

class CMenu
{
public:
	static const CCommande HAUT, GAUCHE, DROITE, BAS, QUITTER;
	static CCommande LireCommande();
};

