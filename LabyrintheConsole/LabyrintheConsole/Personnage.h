#pragma once
#include "Pos.h"
#include "Labyrinthe.h"
#include <memory>
#include <Windows.h>
class CPersonnage
{
public:
	static const char m_avatar = '☺';
	static const int nbrDePasDefaut = 30;
	static const int visionDefaut = 3;
	CPersonnage(Pos position, CLabyrinthe * Lab);
	void Bouger(int virtualKeyDirection);
	int GetNbreDePas(){ return m_nbrDePas; }
	int GetVision(){ return m_vision; }
	Pos GetPosition(){ return m_position; }
	CPersonnage() = delete;
	~CPersonnage() = default;
private:
	int m_nbrDePas;
	int m_vision;
	Pos m_position;
	CLabyrinthe* m_labyrinthe;
	void EssayerDeplacement(int NouvellePosX, int NouvellePosY);
};

