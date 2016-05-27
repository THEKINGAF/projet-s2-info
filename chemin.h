#ifndef _CHEMIN
#define _CHEMIN

#include "graphe.h"
#include <float.h>
#include <ctype.h>
#define MAX_STATION 500

// struture de file de sommets utilisée dans l'algorithme de Bellman optimisé
struct cellule {
	SOMMET * elmt;
	struct cellule* suiv;
};

typedef struct cellule CELLULE;
typedef struct cellule* File;

// structure chemin dans laquelle sera stockée les itinéraires
typedef
  struct vchemin {
   	ARC * arc;
		struct vchemin* suiv;
} * CHEMIN;

// structure station qui contient les id des sommets de même nom et leur nombre
typedef
  struct station {
   	int * tabid;
		int n;
} STATION;

// initialisations de diverses valeurs du graphe
void init_poids (GRAPHE g, SOMMET * s);
void init_file (GRAPHE g);
void init_amont (GRAPHE g);
int sommet_dans_file (SOMMET * s); // teste la présence du sommet s dans la file
// fonctions sur la file de sommets
File creer_file (void);
int file_vide (File f);
File enfiler( SOMMET * elmt, File f);
SOMMET * defiler (File* pf);
// fonctions sur les chemins
CHEMIN creer_chemin (void);
void liberer_chemin (CHEMIN chemin);
int chemin_vide (CHEMIN chemin);
CHEMIN ajout_arc (ARC * arc, CHEMIN chemin);
void affiche_chemin (GRAPHE g, CHEMIN chemin);
CHEMIN reconstruit_chemin (GRAPHE g, SOMMET * depart, SOMMET * arrivee); // renvoie le chemin après la modification du graphe par Bellman
double cout_chemin (GRAPHE g, CHEMIN chemin);
// fonctions sur les stations
void liberer_station (STATION * pstation);
STATION * construit_station (GRAPHE g, char * nom); // cherche tous les sommets ayants pour nom "nom"
void affiche_station (GRAPHE g, STATION station);
// fonctions de construction d'itinéraire
CHEMIN bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee); // détermine le plus court chemin entre 2 sommets
CHEMIN plus_court_chemin (GRAPHE g, char * depart, char * arrivee); // détermine le plus court chemin entre 2 stations
#endif
