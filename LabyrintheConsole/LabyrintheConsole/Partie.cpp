#pragma once
#include "Partie.h"
#include "Pos.h"
#include "Menu.h"
#include "Commande.h"




CPartie::CPartie(std::string filePath) 
	: m_Lab(filePath), m_Personnage(m_Lab.GetDebut())
{
	
}

void CPartie::AfficherEtat() const
{
	using namespace std;
	
	CLabyrinthe::VECTEUR_INFOCASE CaseVisible = m_Lab.LireCasesVisibles(m_Personnage.GetPosition(), m_Personnage.GetVision());
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
				{
					if (CaseVisible[ParcourirCaseVisible].second == CLabyrinthe::ITEM)
						cout << *CaseVisible[ParcourirCaseVisible].second.GetItem();
					else
						cout << CaseVisible[ParcourirCaseVisible].second;
				}
					
				if (ParcourirCaseVisible + 1 < (int)CaseVisible.size())
					++ParcourirCaseVisible;
			}
			else
				cout << ' '; // si extérieur de la zone visible
		}
		cout << endl;
		
	}
	cout << endl;
	cout << "Nombre de pas restant: " << m_Personnage.GetNbreDePas() << endl;
	if (Fini())
		GereFin();

}

void CPartie::GereFin() const
{
	if (m_Personnage.EstVivant())
	{
		std::cout << MESSAGEGAGNANT;
		system("pause");
	}
	else
	{
		std::cout << MESSAGEPERDANT;
		system("pause");
	}
}

void CPartie::Executer(const Commande &c)
{
	if (c == Menu::HAUT)
		TraiterDirection(CPersonnage::HAUT, m_Personnage);
	
	else if (c == Menu::BAS)
		TraiterDirection(CPersonnage::BAS, m_Personnage);
	
	else if (c == Menu::DROITE)
		TraiterDirection(CPersonnage::DROITE, m_Personnage);
	
	else if (c == Menu::GAUCHE)	
		TraiterDirection(CPersonnage::GAUCHE, m_Personnage);
	
}


bool CPartie::Fini() const
{	
	bool vivant = m_Personnage.EstVivant();
	Pos p = m_Personnage.GetPosition();
	bool sorti = m_Lab.LireCase(p) == CLabyrinthe::SORTIE;
	bool fini = !vivant || sorti;
  	return fini;
}

void CPartie::TraiterDirection(CPersonnage::direction d, CPersonnage & p)
{
	CLabyrinthe::contenuCase dispo = m_Lab.LireCase(p.Destination(d));
	if (dispo != CLabyrinthe::MUR)
	{
		p.SetPosition(p.Destination(d));
		p.AvancerUnPas();
		if (dispo == CLabyrinthe::ITEM)
		{
			p.RamasserItem(dispo.GetItem()->Consommer());
			m_Lab.enleverItemCase(dispo.GetItem()->GetPosition());
		}
	}
}