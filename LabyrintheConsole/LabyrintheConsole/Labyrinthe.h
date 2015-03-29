#pragma once
#include <string>
#include <vector>
#include <sstream>
#include "Pos.h"
#include "Item.h"


// hors contexte, utilitaire
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
/// fin hors contexte


class CLabyrinthe
{	 
public:	
	class contenuCase;

	typedef std::vector<std::pair<Pos, CLabyrinthe::contenuCase>> VECTEUR_INFOCASE;
	typedef std::pair<Pos, CLabyrinthe::contenuCase> INFOCASE;

	static const int LARGEURMAX = 80;      //Maximum affichable en console
	static const int HAUTEURMAX = LARGEURMAX; //garder un format carré
	
	class contenuCase
	{
		char m_carac;
		CItem * m_pItem;
	public:
		static enum caractereAafficher{ MUR_A = '\#', LIBRE_A = '.', ENTRE_A = 'A', SORTIE_A = 'S',ITEM_A = 'I' };
		contenuCase(caractereAafficher c) :m_carac(c){}
		contenuCase(CItem * pItem):m_pItem(pItem),m_carac(ITEM_A) {}
		void setcontenueCase(CItem *pItem){ m_carac = ITEM_A; m_pItem = pItem;}
		friend std::ostream& operator<<(std::ostream &os, const contenuCase& c){ return os << c.getCarac(); }
		
		CItem * GetItem() const{ return m_pItem; }
		bool operator==(const contenuCase& c) const { return m_carac == c.getCarac(); }
		bool operator!=(const contenuCase& c) const { return !(*this == c); }
		contenuCase& operator=(const contenuCase& c);
		void Swap(contenuCase& c);

		char getCarac() const{ return m_carac; }

		contenuCase():m_carac(MUR_A),m_pItem(nullptr) {};
		contenuCase(const contenuCase& c);
		~contenuCase(){ if (m_pItem)delete m_pItem; };
	};
	static const contenuCase MUR, LIBRE, ENTREE, SORTIE, ITEM;

private:

	//Attributs
	//Énum a adapter selon le format du fichier lu
	static enum  caractereLu{ MUR_F = 'W', LIBRE_F = 'v',  ENTREE_F = 'd', SORTIE_F = 's' };
	Pos m_debut;
	int m_largeur, m_hauteur; //dimensions réelles du labyrinthe
	contenuCase m_grille[HAUTEURMAX][LARGEURMAX];    // tab 2d contenant les disponibilité des cases du labyrinthe
	std::vector<Pos> m_casesLibres;  // disponibilité pour le reste du jeux qui voudrait placer des items ou  perso.

	std::vector<CItem> m_listeItems;


	//Accesseurs - mutateurs
	void SetLargeur(int l);
	void SetHauteur(int h);
	void SetDebut(Pos d){ m_debut = d; }
	

	//Méthodes
	void initialiserGrille();// met tous les char de la grille à "vide"
	bool chargerLabyrinthe(std::string fichier);

	void chargerCase(caractereLu grille[HAUTEURMAX][LARGEURMAX], int noLigne, int noColonne);
	void ConvertirSympoles(caractereLu grille[HAUTEURMAX][LARGEURMAX]);	
	contenuCase ConvertirSympoleADisponible(caractereLu symbole);
	void placerItems();
	contenuCase LireCase(int x, int y) const; //retourne le statut de la case selon l'énum.

	//Constructeur
	CLabyrinthe() = delete;

public:
	//Constructeur - destructeur
	CLabyrinthe(std::string fichier);
	~CLabyrinthe() = default;
	
	int GetLargeur() const;						// largeur utilisée par le labyrinthe
	int GetHauteur() const;						// hauteur utilisée par le labyrinthe
	Pos GetDebut() const{ return m_debut; }		// position de départ du labyrinthe	
	std::vector<Pos> GetCasesLibres() const;	// vecteur de positions de toutes les cases vides.
	
	bool placerItemCase(Pos caseAOccuper);		// inscrit un item dans la grille, retourne vrai si c'est fait
	bool enleverItemCase(Pos caseAVider);		// libère une case de la grille, retourne faux s'il n'y avais pas d'item à retirer
	
	contenuCase LireCase(Pos p) const;		//retourne le statut de la case selon l'énum version Pos.

	VECTEUR_INFOCASE LireCasesVisibles(Pos posJoueur, int radiusVue) const;

	const contenuCase* GetGrille() const { return *m_grille; }   // tab 2d contenant les disponibilité des cases du labyrinthe
	
	// pour debogage seulement
	//void afficher() const;
};

