#include <iostream>
#include <Windows.h>
#include <string>
#include <bitset>
#include <cmath>
#include "Menu.h"
#include "Commande.h"
using namespace std;

int ReadInput()
{
	// On cherche à connaitre la valeur du plus gros bit ! 
	int taille = sizeof(short) * CHAR_BIT;
	short PlusGrosBit = pow(2, taille - 1);
	bool ToucheAppuyer = false;
	while (!ToucheAppuyer)
	{
		short VirtualKey; 
		VirtualKey = GetAsyncKeyState(VK_UP);
		if (VirtualKey == PlusGrosBit +1) return VK_UP; 
		VirtualKey = GetAsyncKeyState(VK_RIGHT);
		if (VirtualKey == PlusGrosBit +1) return VK_RIGHT;
		VirtualKey = GetAsyncKeyState(VK_DOWN);
		if (VirtualKey == PlusGrosBit +1) return VK_DOWN;
		VirtualKey = GetAsyncKeyState(VK_LEFT);
		if (VirtualKey == PlusGrosBit +1) return VK_LEFT;
		VirtualKey = GetAsyncKeyState(VK_ESCAPE);
		if (VirtualKey == PlusGrosBit +1) return VK_ESCAPE;
		Sleep(10);
	}
}

bool WriteInput(int Arrow)
{
	switch (Arrow)
	{
	case VK_UP:
		cout << "Up" << endl;
		break;
	case VK_RIGHT:
		cout << "Right" << endl;
		break;
	case VK_DOWN:
		cout << "Down" << endl;
		break;
	case VK_LEFT:
		cout << "Left" << endl;
		break;
	case VK_ESCAPE:
		return false;
		break;
	default:
		break;
	}
	return true;
}
bool WriteInput(Commande c)
{
	if (c == Menu::HAUT) cout << "^" << endl;
	if (c == Menu::BAS) cout << "V" << endl;
	if (c == Menu::GAUCHE) cout << "<" << endl;
	if (c == Menu::DROITE) cout << ">" << endl;
	if (c == Menu::QUITTER) return false;
	return true;
}

int main()
{
	/*bool IsNotEnd = true;
	while (IsNotEnd)
	{
		int Arrows = ReadInput();
		IsNotEnd = WriteInput(Arrows);
	}*/
	bool IsNotEnd = true;
	while (IsNotEnd)
	{
		Commande c = Menu::LireCommande();
		IsNotEnd = WriteInput(c);
	}

}



