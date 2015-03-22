#include "Menu.h"
#include "Commande.h"

const Commande
Menu::HAUT    = Commande(VK_UP),
Menu::BAS     = Commande(VK_DOWN),
Menu::GAUCHE  = Commande(VK_LEFT),
Menu::DROITE  = Commande(VK_RIGHT),
Menu::QUITTER = Commande(VK_ESCAPE);

Commande Menu::LireCommande()
{
	// On cherche à connaitre la valeur du plus gros bit ! 
	int taille = sizeof(short) * CHAR_BIT;
	short PlusGrosBit = pow(2, taille - 1);
	bool ToucheAppuyer = false;
	while (!ToucheAppuyer)
	{
		short VirtualKey;
		VirtualKey = GetAsyncKeyState(VK_UP);
		if (VirtualKey == PlusGrosBit + 1) return Menu::HAUT;
		VirtualKey = GetAsyncKeyState(VK_RIGHT);
		if (VirtualKey == PlusGrosBit + 1) return Menu::DROITE;
		VirtualKey = GetAsyncKeyState(VK_DOWN);
		if (VirtualKey == PlusGrosBit + 1) return Menu::BAS;
		VirtualKey = GetAsyncKeyState(VK_LEFT);
		if (VirtualKey == PlusGrosBit + 1) return Menu::GAUCHE;
		VirtualKey = GetAsyncKeyState(VK_ESCAPE);
		if (VirtualKey == PlusGrosBit + 1) return Menu::QUITTER;
		Sleep(10);
	}
}