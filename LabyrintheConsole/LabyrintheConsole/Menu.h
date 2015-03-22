#pragma once
#include <Windows.h>
#include "Commande.h"
#include <cmath>
class Menu
{
public:
	static const Commande HAUT, GAUCHE, DROITE, BAS, QUITTER;
	static Commande LireCommande();
};

