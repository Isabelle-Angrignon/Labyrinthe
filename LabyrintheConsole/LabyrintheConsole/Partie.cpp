#pragma once
#include "Partie.h"
#include "Pos.h"
#include "Menu.h"
#include "Commande.h"

CPartie::CPartie(std::string filePath) 
	: m_Lab(filePath), m_Personnage(m_Lab.GetDebut()), m_Sortie(m_Lab.GetFin())
{
	//std::cout << m_Personnage.GetPosition().x << " " << m_Personnage.GetPosition().y << std::endl;
}

void CPartie::AfficherEtat() const
{
	using namespace std;
	vector<pair<Pos, CLabyrinthe::disponibiliteCase>> CaseVisible = m_Lab.LireCasesVisibles(m_Personnage.GetPosition(), m_Personnage.GetVision());
	int ParcourirCaseVisible = 0;
	system("cls");
	for (int i = 0; i < m_Lab.GetHauteur(); ++i)
	{ 
		for (int j = 0; j < m_Lab.GetLargeur(); ++j)
		{
			if (i == CaseVisible[ParcourirCaseVisible].first.y && j == CaseVisible[ParcourirCaseVisible].first.x)
			{
				if (m_Personnage.GetPosition().x == j && m_Personnage.GetPosition().y == i)
					cout << m_Personnage.m_avatar;
				else
					cout << CaseVisible[ParcourirCaseVisible].second;
				if (ParcourirCaseVisible + 1 < (int)CaseVisible.size())
					++ParcourirCaseVisible;
			}
			else
				cout << ' ';
		}
		cout << endl;
	}
}


void CPartie::Executer(const Commande &c)
{
	if (c == Menu::HAUT)
	{
		//valider jouer.destin est valide
		if (m_Lab.LireCase(m_Personnage.Destination(CPersonnage::HAUT)) == CLabyrinthe::disponibiliteCase::LIBRE)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::HAUT));
		}
	}
	if (c == Menu::BAS)
	{
		//valider jouer.destin est valide
		if (m_Lab.LireCase(m_Personnage.Destination(CPersonnage::BAS)) == CLabyrinthe::disponibiliteCase::LIBRE)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::BAS));
		}
	}
	if (c == Menu::DROITE)
	{
		//valider jouer.destin est valide
		if (m_Lab.LireCase(m_Personnage.Destination(CPersonnage::DROITE)) == CLabyrinthe::disponibiliteCase::LIBRE)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::DROITE));
		}
	}
	if (c == Menu::GAUCHE)
	{
		//valider jouer.destin est valide
		if (m_Lab.LireCase(m_Personnage.Destination(CPersonnage::GAUCHE)) == CLabyrinthe::disponibiliteCase::LIBRE)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::GAUCHE));
		}
	}

}


bool CPartie::Fini() const
{	
	return !m_Personnage.EstVivant() || m_Personnage.GetPosition() == m_Sortie;
}

