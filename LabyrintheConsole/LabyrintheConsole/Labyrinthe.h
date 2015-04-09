#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <functional>

#include "Pos.h"
#include "Item.h"
#include "ContenuCase.h"


// hors contexte, utilitaire
std::vector<std::string> &Split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> Split(const std::string &s, char delim);
/// fin hors contexte


class CLabyrinthe
{	 
public:	

	typedef std::vector<std::pair<CPos, CContenuCase>> VECTEUR_INFOCASE;
	typedef std::pair<CPos, CContenuCase> INFOCASE;

	static const int LARGEURMAX = 80;      //Maximum affichable en console
	static const int HAUTEURMAX = LARGEURMAX; //garder un format carré
	
	static const CContenuCase MUR, LIBRE, ENTREE, SORTIE, ITEM;

private:

	//Attributs
	//Énum a adapter selon le format du fichier lu
	static enum  e_CaractereLu{ MUR_F = 'W', LIBRE_F = 'v',  ENTREE_F = 'd', SORTIE_F = 's' };
	CPos m_debut;
	int m_largeur, m_hauteur; //dimensions réelles du labyrinthe
	CContenuCase m_grille[HAUTEURMAX][LARGEURMAX];    // tab 2d contenant les disponibilité des cases du labyrinthe
	std::vector<CPos> m_casesLibres;  // disponibilité pour le reste du jeux qui voudrait placer des items ou  perso.
	std::vector<CItem> m_listeItems;		
	
	//Accesseurs - mutateurs
	void SetLargeur(int l);
	void SetHauteur(int h);
	void SetDebut(CPos d){ m_debut = d; }	

	//Méthodes
	void InitialiserGrille();// met tous les char de la grille à "vide"
	bool ChargerLabyrinthe(std::string fichier);

	void ChargerCases(e_CaractereLu grille[HAUTEURMAX][LARGEURMAX], int noLigne, int noColonne);
	void ConvertirSympoles(e_CaractereLu grille[HAUTEURMAX][LARGEURMAX]);	
	CContenuCase ConvertirSympoleADisponible(e_CaractereLu symbole);
	
	static CItem* CreerItemBouffe(CPos p);
	static CItem* CreerItemTorche(CPos p);
	void PlacerUnTypeItem(std::function<CItem* (CPos p)> modele, int nbreItem, std::vector<CPos> &liste);
	void PlacerItems();
	CContenuCase LireCase(int x, int y) const; //retourne le statut de la case selon l'énum.

	//Constructeur
	CLabyrinthe() = default;

public:
	//Constructeur - destructeur
	CLabyrinthe(std::string fichier);
	~CLabyrinthe() = default;
	
	int GetLargeur() const;						// largeur utilisée par le labyrinthe
	int GetHauteur() const;						// hauteur utilisée par le labyrinthe
	CPos GetDebut() const{ return m_debut; }		// Position de départ du labyrinthe	
	std::vector<CPos> GetCasesLibres() const;	// vecteur de positions de toutes les cases vides.
	
	bool PlacerItemCase(CPos caseAOccuper);		// inscrit un item dans la grille, retourne vrai si c'est fait
	bool EnleverItemCase(CPos caseAVider);		// libère une case de la grille, retourne faux s'il n'y avais pas d'item à retirer
	
	CContenuCase LireCase(CPos p) const;		//retourne le statut de la case selon l'énum version CPos.

	VECTEUR_INFOCASE LireCasesVisibles(CPos posJoueur, int radiusVue) const;

	const CContenuCase* GetGrille() const { return *m_grille; }   // tab 2d contenant les disponibilité des cases du labyrinthe

};

