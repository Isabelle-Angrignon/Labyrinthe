#pragma once
#include "Pos.h"
#include <utility>
#include <iostream>



class CItem
{
public:
	static enum e_TypeBonus{ PAS, VISION };

private:
	 CPos m_Position;
	int m_Bonus;  //valeur du bonus a ajouter ou soustraire si négatif...  peut changer en cour de jeu si désiré, ajouter un SetBonus
	const char m_SYMBOLE;
	const e_TypeBonus m_TYPE;
	int m_Duree;

public:
	const char GetSymbole() const { return m_SYMBOLE; };
	const CPos GetPosition() const { return m_Position; };	
	const int GetDuree() const { return m_Duree; };

	void SetPosition(CPos p){ m_Position = p;  };

	std::pair<int, e_TypeBonus> Consommer(){ return std::make_pair(m_Bonus, m_TYPE); };	

	friend std::ostream& operator<<(std::ostream &os, const CItem& i){ return os << i.m_SYMBOLE; }

	CItem(const CPos p, const char symbole, const e_TypeBonus t, const int duree, const int bonus = 0)
		: m_Position{ p }, m_SYMBOLE{ symbole }, m_TYPE{ t }, m_Bonus{ bonus }, m_Duree{ duree } {};

	CItem(const CItem& i)
		: m_Position{ i.m_Position }, m_SYMBOLE{ i.m_SYMBOLE }, 
		m_TYPE{ i.m_TYPE }, m_Bonus{ i.m_Bonus }, m_Duree{ i.m_Duree } {};
	CItem() = delete;	
	~CItem() = default;
};

