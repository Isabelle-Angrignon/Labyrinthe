﻿#pragma once
#include "Pos.h"
#include "Labyrinthe.h"
#include <memory>
#include <Windows.h>
class CPersonnage
{
public:
	static const char m_avatar = 'Q';//'☺';
	static enum controle { HAUT, DROITE, BAS, GAUCHE, QUITTER };
	static const int NBREDEPASDEFAUT = 30;
	static const int VISIONDEFAUT = 3;
	
	int GetNbreDePas() const { return m_nbrDePas; }
	int GetVision() const { return m_vision; }
	Pos GetPosition() const { return m_position; }	
	
	Pos Destination(controle direction);
	void SetPosition(Pos p);
	void SetPosition(const int x, const int y);

	CPersonnage(Pos position);
	CPersonnage() = delete;
	~CPersonnage() = default;

private:
	int m_nbrDePas;
	int m_vision;
	Pos m_position;
	
	
};

