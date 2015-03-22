#pragma once
#include "Personnage.h"

CPersonnage::CPersonnage(Pos depart) 
	: m_position{ depart }, m_nbrDePas{ NBREDEPASDEFAUT }, m_vision{ VISIONDEFAUT }
{
		
}

void CPersonnage::SetPosition(Pos p)
{
	m_position = p;
}
void CPersonnage::SetPosition(const int x, const int y)
{
	m_position.x = x;
	m_position.y = y;
}


Pos CPersonnage::Destination(direction d)
{	
	Pos destination(GetPosition());

	switch (d)
	{
	case HAUT:
		destination = Pos(m_position.x, m_position.y - 1);
		break;
	case DROITE:
		destination = Pos(m_position.x + 1, m_position.y);
		break;
	case BAS:
		destination = Pos(m_position.x, m_position.y + 1);
		break;
	case GAUCHE:
		destination = Pos(m_position.x - 1, m_position.y);
		break;
	default:
		break; 
	}
	return destination;
}
