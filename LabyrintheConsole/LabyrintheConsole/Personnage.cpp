#include "Personnage.h"

CPersonnage::CPersonnage(Pos depart ,CLabyrinthe * Lab)
{
	m_position.x = depart.x;
	m_position.y = depart.y;
	m_nbrDePas = nbrDePasDefaut;
	m_vision = visionDefaut;
	m_labyrinthe = Lab;
}

void CPersonnage::Bouger(int virtualKey)
{
	switch (virtualKey)
	{
	case VK_UP:
		EssayerDeplacement(m_position.x -1, m_position.y);
		break;
	case VK_RIGHT:
		EssayerDeplacement(m_position.x, m_position.y +1);
		break;
	case VK_DOWN:
		EssayerDeplacement(m_position.x + 1, m_position.y);
		break;
	case VK_LEFT:
		EssayerDeplacement(m_position.x , m_position.y -1);
		break;
	default:
		break;
	}
}

void CPersonnage::EssayerDeplacement(int NouvellePosX, int NouvellePosY)
{
	if (m_labyrinthe->LireCase(NouvellePosX, NouvellePosY) != CLabyrinthe::caractereAafficher::MUR)
	{
		m_position.x = NouvellePosX;
		m_position.y = NouvellePosY;
	}
}