#pragma once
#include "Pos.h"

class CItem
{
	const Pos m_POSITITON;
	int m_Bonus;  //valeur du bonus a ajouter ou soustraire si négatif...  peut changer en cour de jeu si désiré, ajouter un SetBonus
	const char m_SYMBOLE;

public:
	const Pos GetPosition() const { return m_POSITITON; };
	const int GetBonus() const { return m_Bonus; };
	const char GetSymbole() const { return m_SYMBOLE; };
	
	CItem(const Pos p, const char symbole, const int bonus = 0) 
		: m_POSITITON{ p }, m_SYMBOLE{ symbole }, m_Bonus{ bonus } {};
	CItem() = delete;	
	~CItem() = default;
};

