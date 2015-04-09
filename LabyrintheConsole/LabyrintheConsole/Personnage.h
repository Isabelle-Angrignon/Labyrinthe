#pragma once
#include "Pos.h"
#include "Labyrinthe.h"
#include <memory>
#include <Windows.h>
#include "Item.h"

class CPersonnage
{
public:
	static const char m_avatar = 'Q';
	static enum e_Direction { HAUT, DROITE, BAS, GAUCHE };
	static const int NBREDEPASDEFAUT = 50;
	static const int VISIONDEFAUT = 2;
	
	int GetNbreDePas() const { return m_nbrDePas; }
	int GetVision() const { return m_vision; }
	CPos GetPosition() const { return m_position; }	
	bool EstVivant() const { return GetNbreDePas() > 0; }

	void RamasserItem(std::pair<int, CItem::e_TypeBonus>);
	void AnnulerEffetItem(std::pair<int, CItem::e_TypeBonus>);
	
	CPos Destination(e_Direction d);
	void SetPosition(CPos p);
	void SetPosition(const int x, const int y);
	void AvancerUnPas() { --m_nbrDePas; }

	CPersonnage(CPos position);
	CPersonnage() = delete;
	~CPersonnage() = default;

private:
	int m_nbrDePas;
	int m_vision;
	CPos m_position;
	
	
};

