#pragma once
#include "Labyrinthe.h"
#include "Personnage.h"
#include "Pos.h"
#include "Item.h"
#include "Evenements.h"

#include <vector>
#include <string>
#include <iostream>
#include <memory>
#include <Windows.h>


class CCommande;

class CPartie
{ 
	
public:	

	CPartie(std::string filePath);
	void AfficherEtat() const;
	void Executer(const CCommande &c);
	bool Fini() const;

	~CPartie() = default;

private:
	CPartie() = delete;

	CLabyrinthe m_Lab;
	CPersonnage m_Personnage;
	CEvenements m_Evenements;
	void TraiterDirection(CPersonnage::e_Direction d, CPersonnage & p);
	const std::string MESSAGEGAGNANT = "Bravo! Vous avez trouve la sortie !";
	const std::string MESSAGEPERDANT = "Trop long! Vous avez perdu !";
	
	void GereFin() const;
};

