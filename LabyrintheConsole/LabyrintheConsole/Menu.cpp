#include "Menu.h"
#include "Commande.h"

const Commande
Menu::HAUT    = Commande(VK_UP),
Menu::BAS     = Commande(VK_DOWN),
Menu::GAUCHE  = Commande(VK_LEFT),
Menu::DROITE  = Commande(VK_RIGHT),
Menu::QUITTER = Commande(VK_ESCAPE);


//Lecture du clavier en continu tant qu'aucune des 5 touches n'est appuy�e.
Commande Menu::LireCommande()
{
	// On cherche � connaitre la valeur du plus gros bit ! 
	int taille = sizeof(short) * CHAR_BIT;		//Taille de short varie selon l'OS (32 vs 64 bits)
	short PlusGrosBit = pow(2, taille - 1);		//Touche d�j� appuy�e durant le "Sleep"... Bit le plus � gauche est � 1
	short toucheEnCours = PlusGrosBit + 1;		//Appuis de la touche en cours, bit le plus � droite est � 1
	bool toucheAppuyee = false;
	while (!toucheAppuyee)
	{
		short VirtualKey;
		VirtualKey = GetAsyncKeyState(VK_UP);
		if (VirtualKey == toucheEnCours) return Menu::HAUT;
		VirtualKey = GetAsyncKeyState(VK_RIGHT);
		if (VirtualKey == toucheEnCours) return Menu::DROITE;
		VirtualKey = GetAsyncKeyState(VK_DOWN);
		if (VirtualKey == toucheEnCours) return Menu::BAS;
		VirtualKey = GetAsyncKeyState(VK_LEFT);
		if (VirtualKey == toucheEnCours) return Menu::GAUCHE;
		VirtualKey = GetAsyncKeyState(VK_ESCAPE);
		if (VirtualKey == toucheEnCours) return Menu::QUITTER;
		Sleep(10);// D�lais pour laisser le CPU se reposer...
	}
}