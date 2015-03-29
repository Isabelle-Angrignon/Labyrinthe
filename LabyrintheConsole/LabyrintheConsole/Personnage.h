﻿#pragma once
#include "Pos.h"
#include "Labyrinthe.h"
#include <memory>
#include <Windows.h>
#include "Item.h"

class CPersonnage
{
public:
	static const char m_avatar = 'Q';//'☺';
	static enum direction { HAUT, DROITE, BAS, GAUCHE };
	static const int NBREDEPASDEFAUT = 15000;
	static const int VISIONDEFAUT = 2;
	
	int GetNbreDePas() const { return m_nbrDePas; }
	int GetVision() const { return m_vision; }
	Pos GetPosition() const { return m_position; }	
	bool EstVivant() const { return GetNbreDePas() > 0; }

	void RamasserItem(std::pair<int, CItem::TypeBonus>);/////todo
	
	Pos Destination(direction d);
	void SetPosition(Pos p);
	void SetPosition(const int x, const int y);
	void AvancerUnPas() { --m_nbrDePas; }

	CPersonnage(Pos position);
	CPersonnage() = delete;
	~CPersonnage() = default;

private:
	int m_nbrDePas;
	int m_vision;
	Pos m_position;
	
	
};

