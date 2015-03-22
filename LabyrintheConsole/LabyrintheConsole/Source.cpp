#include <iostream>
#include <Windows.h>
#include <string>
#include <bitset>
#include <cmath>
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

int main()
{
	bool IsNotEnd = true;
	while (IsNotEnd)
	{
		int Arrows = ReadInput();
		IsNotEnd = WriteInput(Arrows);
	}
}



