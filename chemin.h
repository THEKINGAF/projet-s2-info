#ifndef _CHEMIN
#define _CHEMIN

#include "graphe.h"
#include <float.h>
#define MAX_STATION 50

// struture de file de sommets utilisé dans l'algo de Bellman optimisé
struct cellule{
	SOMMET * elmt;
	struct cellule* suiv;
};

typedef struct cellule CELLULE;
typedef struct cellule* File;

// structure chemin dans laquelle sera stockée le résultat de Bellman
typedef
  struct vchemin {
   	ARC * arc;
		struct vchemin* suiv; } * CHEMIN;

typedef
  struct station {
   	int * tabid;
		int n; } STATION;

// fonctions sur la file de sommets
File creer_file (void);
int file_vide (File f);
File enfiler( SOMMET * elmt, File f);
SOMMET * defiler (File* pf);

// initialisations de diverses valeurs du graphe
void init_poids (GRAPHE g, SOMMET * s);
void init_file (GRAPHE g);
void init_amont (GRAPHE g);
int sommet_dans_file (SOMMET * s);

// fonctions sur les chemins
CHEMIN creer_chemin (void);
void liberer_chemin (CHEMIN chemin);
int chemin_vide (CHEMIN chemin);
CHEMIN ajout_arc (ARC * arc, CHEMIN chemin);
void affiche_chemin (GRAPHE g, CHEMIN chemin);
CHEMIN reconstruit_chemin (GRAPHE g, SOMMET * depart, SOMMET * arrivee);
CHEMIN bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee);
STATION * construit_station (GRAPHE g, char * nom);
void affiche_station (GRAPHE g, STATION station);
double cout_chemin (GRAPHE g, CHEMIN chemin);
CHEMIN plus_court_chemin (GRAPHE g, char * depart, char * arrivee);
#endif
