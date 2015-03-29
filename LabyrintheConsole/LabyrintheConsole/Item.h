#pragma once
#include "Pos.h"
#include <utility>
#include <iostream>

class CItem
{
public:
	static enum TypeBonus{ PAS, VISION };

private:
	const Pos m_POSITITON;
	int m_Bonus;  //valeur du bonus a ajouter ou soustraire si négatif...  peut changer en cour de jeu si désiré, ajouter un SetBonus
	const char m_SYMBOLE;
	const TypeBonus m_TYPE;
	int m_Duree;//////////////////////not used yet...

public:
	const char GetSymbole() const { return m_SYMBOLE; };
	const Pos GetPosition() const { return m_POSITITON; };	

	std::pair<int, TypeBonus> Consommer(){ return std::make_pair(m_Bonus, m_TYPE); };

	friend std::ostream& operator<<(std::ostream &os, const CItem& i){ return os << i.m_SYMBOLE; }

	CItem(const Pos p, const char symbole, const TypeBonus t, const int bonus = 0) 
		: m_POSITITON{ p }, m_SYMBOLE{ symbole }, m_TYPE{ t }, m_Bonus{ bonus } {};

	CItem(const CItem& i)
		: m_POSITITON{ i.m_POSITITON }, m_SYMBOLE{ i.m_SYMBOLE }, m_TYPE{ i.m_TYPE }, m_Bonus{ i.m_Bonus } {};
	CItem() = delete;	
	~CItem() = default;
};

