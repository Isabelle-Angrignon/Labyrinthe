#pragma once
#include "Labyrinthe.h"
#include "Personnage.h"
#include "Pos.h"
#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <Windows.h>
class CPartie
{
public:
	CPartie(string filePath);
	void JouerUnePartie();
	~CPartie();
private:
	void afficher();
	int LireTouche();
	CLabyrinthe m_Lab;
	CPersonnage* m_Personnage;
};

