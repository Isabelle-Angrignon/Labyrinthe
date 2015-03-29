#include "Labyrinthe.h"

#include <iostream>
#include <fstream>
#include <regex>
#include <algorithm>




// hors contexte, utilitaire

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems)
{
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems; 
}

std::vector<std::string> split(const std::string &s, char delim)
{
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

/// fin hors contexte


void CLabyrinthe::SetLargeur(int l)
{
	if (l <= LARGEURMAX)
		m_largeur = l;
	else
		m_largeur = 0;
}

void CLabyrinthe::SetHauteur(int h)
{
	if (h <= HAUTEURMAX)
		m_hauteur = h;
	else
		m_hauteur = 0;
}

int CLabyrinthe::GetLargeur() const
{
	return m_largeur;
}

int CLabyrinthe::GetHauteur() const
{
	return m_hauteur;
}

void CLabyrinthe::initialiserGrille()
{
	for (int i = 0; i < HAUTEURMAX; ++i)
		for (int j = 0; j < LARGEURMAX; ++j)
			m_grille[i][j] = CLabyrinthe::MUR;
}
bool CLabyrinthe::chargerLabyrinthe(std::string fichier)/// retourne faux ou throw exception si fichier marde...
{
	bool chargeReussie = false;
	caractereLu grilleTemp[LARGEURMAX][HAUTEURMAX];
	std::string line;
	std::ifstream myfile(fichier);
	if (!myfile.is_open())
		return false;
	int noLigne = -1;
	while (getline(myfile, line))
	{
		++noLigne;
		
		//spliter la ligne	
		int noColonne = 0;
		auto symboles = split(line, ';');
		for (auto symbole : symboles)
		{			
			grilleTemp[noLigne][noColonne] = caractereLu(symbole[0]);
			chargerCase(grilleTemp, noLigne, noColonne);
			++noColonne;
		}
		if (GetLargeur() == 0)
			SetLargeur(noColonne+1);
	}
	if (GetHauteur() == 0)
		SetHauteur(noLigne+1);

	myfile.close();
	ConvertirSympoles(grilleTemp);

	return GetLargeur() && GetHauteur() && chargeReussie;
}

void CLabyrinthe::chargerCase(caractereLu grille[HAUTEURMAX][LARGEURMAX], int noLigne, int noColonne)
{	
	//remplir le vecteur de cases libres
	if (grille[noLigne][noColonne] == LIBRE_F)
		m_casesLibres.push_back(Pos(noColonne, noLigne));
	//setter debut
	if (grille[noLigne][noColonne] == ENTREE_F)
		SetDebut(Pos(noColonne, noLigne));
	//setter fin
	/*if (grille[noLigne][noColonne] == SORTIE_F)
		SetFin(Pos(noColonne, noLigne));*/
}

void CLabyrinthe::ConvertirSympoles(caractereLu grille[HAUTEURMAX][LARGEURMAX])
{
	for (int i = 0; i < GetHauteur(); ++i)
		for (int j = 0; j < GetLargeur(); ++j)
			m_grille[i][j] = ConvertirSympoleADisponible(grille[i][j]);
}

CLabyrinthe::contenuCase CLabyrinthe::ConvertirSympoleADisponible(caractereLu symbole)
{

	switch (symbole)
	{
	case MUR_F:
		return CLabyrinthe::MUR;
		break;
	case LIBRE_F:
		return CLabyrinthe::LIBRE;
		break;
	case ENTREE_F:
		return  CLabyrinthe::ENTREE;
		break;
	case SORTIE_F:
		return CLabyrinthe::SORTIE;
		break;
	default:
		return CLabyrinthe::MUR;
		break;
	}
	return CLabyrinthe::MUR;
}


CLabyrinthe::CLabyrinthe(std::string fichier) :m_hauteur{ 0 }, m_largeur{ 0 }
{
	initialiserGrille();
	chargerLabyrinthe(fichier);
	placerItems();
}

std::vector<Pos> CLabyrinthe::GetCasesLibres() const
{
	return m_casesLibres;
}

void CLabyrinthe::placerItems()
{
	//trouver liste dispo
	std::vector<Pos> dispo = GetCasesLibres();
	//shuffle dispo
	std::random_shuffle(begin(dispo), end(dispo));
	//push dans item
	Pos p = dispo[dispo.size() - 1];
	for (int i = 0; i < 3; ++i)
	{
		m_grille[p.y][p.x].setcontenueCase(new CItem(dispo[dispo.size() - 1], 'B', CItem::PAS, 5));
		dispo.pop_back();
		p = dispo[dispo.size() - 1];
	}
	for (int i = 0; i < 3; ++i)
	{
		m_grille[p.y][p.x].setcontenueCase(new CItem(dispo[dispo.size() - 1], 'V', CItem::VISION, 2));	
		dispo.pop_back();
		p = dispo[dispo.size() - 1];
	}	

}

bool CLabyrinthe::placerItemCase(Pos caseAOccuper)
{
	bool libre = false;
	if (m_grille[caseAOccuper.y][caseAOccuper.x] == LIBRE)
	{
		m_grille[caseAOccuper.y][caseAOccuper.x] = ITEM;
		
		int p = 0;
		for (auto i = begin(m_casesLibres); i < end(m_casesLibres); ++i, ++p)
		{
			if (m_casesLibres[p] == caseAOccuper)
			{ 
				m_casesLibres.erase(i);
				libre = true;
			}			
		}		
	}
	return libre;
}

bool CLabyrinthe::enleverItemCase(Pos caseAVider)
{
	bool libre = false;
	if (m_grille[caseAVider.y][caseAVider.x] == ITEM)
	{
		m_grille[caseAVider.y][caseAVider.x] = LIBRE;
		m_casesLibres.push_back(caseAVider);
		sort(begin(m_casesLibres), end(m_casesLibres));		
	}
	return libre; 	
}

CLabyrinthe::contenuCase CLabyrinthe::LireCase(int x, int y) const
{
	CLabyrinthe::contenuCase dispo = MUR;
	if (x >= 0 && x < GetLargeur() && y >= 0 && y < GetHauteur() )
		dispo = m_grille[y][x];
	return dispo;
}

CLabyrinthe::contenuCase CLabyrinthe::LireCase(Pos p) const
{	
	return LireCase(p.x, p.y);
}

CLabyrinthe::VECTEUR_INFOCASE CLabyrinthe::LireCasesVisibles(Pos posJoueur, int radiusVue) const
{
	VECTEUR_INFOCASE cases;

	//D�finir les bornes de la vision
	int dV = posJoueur.y - radiusVue > 0 ? posJoueur.y - radiusVue : 0;
	int fV = posJoueur.y + radiusVue < GetHauteur() ? posJoueur.y + radiusVue : GetHauteur() - 1;
	int dH = posJoueur.x - radiusVue > 0 ? posJoueur.x - radiusVue : 0;
	int fH = posJoueur.x + radiusVue < GetLargeur() ? posJoueur.x + radiusVue : GetLargeur() - 1;

	INFOCASE uneCase;

	for (int i = dV; i <= fV; ++i)
	{
		for (int j = dH; j <= fH; ++j)
		{
			uneCase = std::make_pair(Pos(j, i), m_grille[i][j]);
			cases.push_back(uneCase);
		}		
	}		
	return cases;
}

// CLASSE contenuCase

//MUR, LIBRE, ENTREE, SORTIE, ITEM

const CLabyrinthe::contenuCase
CLabyrinthe::MUR = CLabyrinthe::contenuCase(CLabyrinthe::contenuCase::MUR_A),
CLabyrinthe::LIBRE = CLabyrinthe::contenuCase(CLabyrinthe::contenuCase::LIBRE_A),
CLabyrinthe::ENTREE = CLabyrinthe::contenuCase(CLabyrinthe::contenuCase::ENTRE_A),
CLabyrinthe::SORTIE = CLabyrinthe::contenuCase(CLabyrinthe::contenuCase::SORTIE_A),
CLabyrinthe::ITEM = CLabyrinthe::contenuCase(CLabyrinthe::contenuCase::ITEM_A);

CLabyrinthe::contenuCase::contenuCase(const contenuCase& c)
{
	m_carac = c.getCarac(); 
	if (c.GetItem())
		m_pItem = new CItem(*c.GetItem());
	else
		m_pItem = nullptr;
}

void CLabyrinthe::contenuCase::Swap(contenuCase& c)
{
	using std::swap;
	swap(m_carac, c.m_carac);
	swap(m_pItem, c.m_pItem);
}

CLabyrinthe::contenuCase& CLabyrinthe::contenuCase::operator=(const contenuCase& c)
{
	contenuCase{ c }.Swap(*this);
	return *this;	
}
//Pour d�bogage seulement
//void CLabyrinthe::afficher() const
//{
//	using namespace std;
//	for (int i = 0; i < GetHauteur(); ++i)
//	{
//		for (int j = 0; j < GetLargeur(); ++j)
//		{
//			cout << m_grille[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	cout << endl;
//}