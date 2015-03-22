#pragma once
#include "Labyrinthe.h"
#include "Personnage.h"
#include "Pos.h"
#include "Item.h"

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <Windows.h>
class CPartie
{ 
	
public:
	CPartie(std::string filePath);
//	void JouerUnePartie();
	void AfficherEtat() const;
	void Executer();
	bool Fini() const;

	~CPartie() = default;

private:
	CPartie() = delete;
//	void afficher();
//	int LireTouche();

	CLabyrinthe m_Lab;
	CPersonnage m_Personnage;
	std::vector<CItem> m_listeBouffe;
	std::vector<CItem> m_listeTorches;
};

