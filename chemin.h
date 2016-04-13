#ifndef _CHEMIN
#define _CHEMIN

#include "graphe.h"
#include <limits.h>

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
#endif
