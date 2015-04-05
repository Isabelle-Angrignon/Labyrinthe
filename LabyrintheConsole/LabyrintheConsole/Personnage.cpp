#pragma once
#include "Personnage.h"

CPersonnage::CPersonnage(CPos depart) 
	: m_position{ depart }, m_nbrDePas{ NBREDEPASDEFAUT }, m_vision{ VISIONDEFAUT }
{
		
}

void CPersonnage::SetPosition(CPos p)
{
	m_position = p;
}
void CPersonnage::SetPosition(const int x, const int y)
{
	m_position.x = x;
	m_position.y = y;
}


CPos CPersonnage::Destination(e_Direction d)
{	
	CPos destination(GetPosition());

	switch (d)
	{
	case HAUT:
		destination = CPos(m_position.x, m_position.y - 1);
		break;
	case DROITE:
		destination = CPos(m_position.x + 1, m_position.y);
		break;
	case BAS:
		destination = CPos(m_position.x, m_position.y + 1);
		break;
	case GAUCHE:
		destination = CPos(m_position.x - 1, m_position.y);
		break;
	default:
		break; 
	}
	return destination;
}


void CPersonnage::RamasserItem(std::pair<int, CItem::e_TypeBonus> i)
{
	switch (i.second)
	{
		case CItem::PAS:
			m_nbrDePas += i.first;
			break;
		case CItem::VISION:
			m_vision += i.first;
			break;
		default:
			break;
	}

}