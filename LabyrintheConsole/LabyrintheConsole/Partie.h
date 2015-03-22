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


class Commande;

class CPartie
{ 
	
public:
	

	CPartie(std::string filePath);
//	void JouerUnePartie();
	void AfficherEtat() const;
	void Executer(const Commande &c);
	bool Fini() const;

	~CPartie() = default;

private:
	CPartie() = delete;

	CLabyrinthe m_Lab;
	CPersonnage m_Personnage;
	const Pos m_Sortie;
	
	std::vector<CItem> m_listeBouffe;
	std::vector<CItem> m_listeTorches;
};

