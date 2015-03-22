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


Pos CPersonnage::Destination(controle direction)
{	
	Pos destination(CPersonnage::GetPosition());

	switch (direction)
	{
	case HAUT:
		SetPosition(m_position.x -1, m_position.y);
		break;
	case DROITE:
		SetPosition(m_position.x, m_position.y + 1);
		break;
	case BAS:
		SetPosition(m_position.x + 1, m_position.y);
		break;
	case GAUCHE:
		SetPosition(m_position.x, m_position.y - 1);
		break;
	default:
		break; 
	}
	return destination;
}
