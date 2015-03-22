#pragma once
#include <string>
#include <vector>
#include <utility>
#include <sstream>


// hors contexte, utilitaire
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
/// fin hors contexte


struct Pos
{
	int x, y;	
	Pos() throw() : x{}, y{} { void; }
	Pos(const int _x, const int _y) throw() : x{ _x }, y{ _y } { void; }
	bool operator==(const Pos &p) const throw()
	{
		return x == p.x && y == p.y;
	}
	bool operator!=(const Pos &p) const throw()
	{
		return !(*this == p);
	}

};

class CLabyrinthe
{	
public:

	//static enum caractereAafficher{ LIBRE = '█', MUR = ' ', ENTRE = '▲', SORTIE = '§' };  //va dans affichage
	static enum disponibiliteCase { MUR = 0,  LIBRE, ENTREE, SORTIE, ITEM};  
	static const int LARGEURMAX = 80;      //Maximum affichable en console
	static const int HAUTEURMAX = LARGEURMAX; //garder un format carré

private:
	//Attributs
	//Énum a adapter selon le format du fichier lu
	static enum  caractereLu{ MUR_F = 'W', LIBRE_F = 'v',  ENTREE_F = 'd', SORTIE_F = 's' };
	Pos m_debut, m_fin;
	int m_largeur, m_hauteur; //dimensions réelles du labyrinthe
	disponibiliteCase m_grille[HAUTEURMAX][LARGEURMAX];    // tab 2d contenant les disponibilité des cases du labyrinthe
	std::vector<Pos> m_casesLibres;  // disponibilité pour le reste du jeux qui voudrait placer des items ou  perso.

	//Accesseurs - mutateurs
	void SetLargeur(int l);
	void SetHauteur(int h);
	void SetDebut(Pos d){ m_debut = d; }
	void SetFin(Pos f){ m_fin = f;}

	//Méthodes
	void initialiserGrille();// met tous les char de la grille à "vide"
	bool chargerLabyrinthe(std::string fichier);
	void chargerCase(caractereLu grille[LARGEURMAX][HAUTEURMAX], int noLigne, int noColonne);
	void ConvertirSympoles(caractereLu grille[HAUTEURMAX][LARGEURMAX]);	
	disponibiliteCase ConvertirSympoleADisponible(caractereLu symbole);
	
	//Constructeur
	CLabyrinthe() = delete;

public:
	//Constructeur - destructeur
	CLabyrinthe(std::string fichier);
	~CLabyrinthe() = default;
	
	int GetLargeur() const;						// largeur utilisée par le labyrinthe
	int GetHauteur() const;						// hauteur utilisée par le labyrinthe
	Pos GetDebut() const{ return m_debut; }		// position de départ du labyrinthe
	Pos GetFin() const { return m_fin; }		// position de la sorti du labyrinthe
	std::vector<Pos> GetCasesLibres() const;	// vecteur de positions de toutes les cases vides.
	
	bool placerItemCase(Pos caseAEmplir);		// inscrit un item dans la grille, retourne vrai si possible
	bool enleverItemCase(Pos caseAVider);		// libère une case de la grille, retourne faux s'il n'y avais pas d'item à retirer
	disponibiliteCase LireCase(int x, int y) const; //retourne le statut de la case selon l'énum.
	disponibiliteCase LireCase(Pos p) const;		//retourne le statut de la case selon l'énum version Pos.

	std::vector<std::pair<Pos, disponibiliteCase>> LireCasesVisibles(Pos posJoueur, int radiusVue) const;

	const disponibiliteCase* GetGrille() const { return *m_grille; }   // tab 2d contenant les disponibilité des cases du labyrinthe
	
	// pour debogage seulement
	void afficher() const;
};

