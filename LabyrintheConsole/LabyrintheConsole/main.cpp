#include <iostream>
#include <string>
#include "Labyrinthe.h"

using namespace std;

int main()
{
	CLabyrinthe monLaby("Labyrinthe.csv");

	const CLabyrinthe::disponibiliteCase *grille = monLaby.GetGrille();
	if (grille)
		monLaby.afficher();
	else
		cout << "pas recupere la grille" << endl;

	return 0;
}