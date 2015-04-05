#include <iostream>
#include <string>
#include "Labyrinthe.h"
#include "Partie.h"
#include "Menu.h"

using namespace std;

int main()
{
	CPartie MonJeu("Labyrinthe.csv");
	MonJeu.AfficherEtat();
	Commande c;

	while (!MonJeu.Fini() && (c = CMenu::LireCommande(), c != CMenu::QUITTER))
	{
		MonJeu.Executer(c);
		MonJeu.AfficherEtat();
	}
	
	
	return 0;
}