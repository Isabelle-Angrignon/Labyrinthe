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
	cout << endl;
	if (Fini())
			if (m_Personnage.EstVivant())
				cout << "Gagne !";
			else
				cout << "Perdu !";
}


void CPartie::Executer(const Commande &c)
{
	if (c == Menu::HAUT)
	{
		CLabyrinthe::disponibiliteCase dispo = m_Lab.LireCase(m_Personnage.Destination(CPersonnage::HAUT));
		if (dispo != CLabyrinthe::disponibiliteCase::MUR)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::HAUT));
			m_Personnage.AvancerUnPas();
		}
	}
	if (c == Menu::BAS)
	{
		CLabyrinthe::disponibiliteCase dispo = m_Lab.LireCase(m_Personnage.Destination(CPersonnage::BAS));
		if (dispo != CLabyrinthe::disponibiliteCase::MUR)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::BAS));
			m_Personnage.AvancerUnPas();
		}
	}
	if (c == Menu::DROITE)
	{
		CLabyrinthe::disponibiliteCase dispo = m_Lab.LireCase(m_Personnage.Destination(CPersonnage::DROITE));
		if (dispo != CLabyrinthe::disponibiliteCase::MUR)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::DROITE));
			m_Personnage.AvancerUnPas();
		}
	}
	if (c == Menu::GAUCHE)	{
		
		if (m_Lab.LireCase(m_Personnage.Destination(CPersonnage::GAUCHE)) != CLabyrinthe::disponibiliteCase::MUR)
		{
			m_Personnage.SetPosition(m_Personnage.Destination(CPersonnage::GAUCHE));
			m_Personnage.AvancerUnPas();
		}
	}
}


bool CPartie::Fini() const
{	
	bool vivant = m_Personnage.EstVivant();
	Pos p = m_Personnage.GetPosition();
	bool sorti = p == m_Sortie;
	bool fini = !vivant || sorti;
  	return fini;
}

