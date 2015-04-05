#include "Menu.h"
#include "Commande.h"


const Commande
CMenu::HAUT    = Commande(VK_UP),
CMenu::BAS     = Commande(VK_DOWN),
CMenu::GAUCHE  = Commande(VK_LEFT),
CMenu::DROITE  = Commande(VK_RIGHT),
CMenu::QUITTER = Commande(VK_ESCAPE);


//Lecture du clavier en continu tant qu'aucune des 5 touches n'est appuyée.
Commande CMenu::LireCommande()
{
	// On cherche à connaitre la valeur du plus gros bit ! 
	int taille = sizeof(short) * CHAR_BIT;		//Taille de short varie selon l'OS (32 vs 64 bits)
	short plusGrosBit = (short)pow(2, taille - 1);		//Touche déjà appuyée durant le "Sleep"... Bit le plus à gauche est à 1
	short toucheEnCours = plusGrosBit + 1;		//Appuis de la touche en cours, bit le plus à droite est à 1
	bool toucheAppuyee = false;
	while (!toucheAppuyee)
	{
		short VirtualKey;
		VirtualKey = GetAsyncKeyState(VK_UP);
		if (VirtualKey == toucheEnCours) return CMenu::HAUT;
		VirtualKey = GetAsyncKeyState(VK_RIGHT);
		if (VirtualKey == toucheEnCours) return CMenu::DROITE;
		VirtualKey = GetAsyncKeyState(VK_DOWN);
		if (VirtualKey == toucheEnCours) return CMenu::BAS;
		VirtualKey = GetAsyncKeyState(VK_LEFT);
		if (VirtualKey == toucheEnCours) return CMenu::GAUCHE;
		VirtualKey = GetAsyncKeyState(VK_ESCAPE);
		if (VirtualKey == toucheEnCours) return CMenu::QUITTER;
		Sleep(10);// Délais pour laisser le CPU se reposer...
	}
}