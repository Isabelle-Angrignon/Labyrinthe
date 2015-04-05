#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Pos.h"
#include "Item.h"


// hors contexte, utilitaire
std::vector<std::string> &Split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> Split(const std::string &s, char delim);
/// fin hors contexte


class CLabyrinthe
{	 
public:	
	class CContenuCase;

	typedef std::vector<std::pair<CPos, CLabyrinthe::CContenuCase>> VECTEUR_INFOCASE;
	typedef std::pair<CPos, CLabyrinthe::CContenuCase> INFOCASE;

	static const int LARGEURMAX = 80;      //Maximum affichable en console
	static const int HAUTEURMAX = LARGEURMAX; //garder un format carré
	
	class CContenuCase
	{
		char m_carac;
		CItem * m_pItem;
	public:
		static enum e_CaractereAAfficher{ MUR_A = '#', LIBRE_A = '.', ENTRE_A = 'A', SORTIE_A = 'S',ITEM_A = 'I' };
		CContenuCase(e_CaractereAAfficher c) :m_carac(c){}
		CContenuCase(CItem * pItem):m_pItem(pItem),m_carac(ITEM_A) {}
		void SetContenueCase(CItem *pItem){ m_carac = ITEM_A; m_pItem = pItem;}
		friend std::ostream& operator<<(std::ostream &os, const CContenuCase& c){ return os << c.GetCarac(); }
		
		CItem * GetItem() const{ return m_pItem; }
		bool operator==(const CContenuCase& c) const { return m_carac == c.GetCarac(); }
		bool operator!=(const CContenuCase& c) const { return !(*this == c); }
		CContenuCase& operator=(const CContenuCase& c);
		void Swap(CContenuCase& c);

		char GetCarac() const{ return m_carac; }

		CContenuCase():m_carac(MUR_A),m_pItem(nullptr) {};
		CContenuCase(const CContenuCase& c);
		~CContenuCase(){ if (m_pItem)delete m_pItem; };
	};
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
	void PlacerItems();
	CContenuCase LireCase(int x, int y) const; //retourne le statut de la case selon l'énum.

	//Constructeur
	CLabyrinthe() = delete;

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
	
	// pour debogage seulement
	//void afficher() const;
};

