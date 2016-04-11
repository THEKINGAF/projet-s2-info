#include "graphe.h"
#include <limits.h>

struct cellule{
	SOMMET * elmt;
	struct cellule* suiv;
};

typedef struct cellule CELLULE;
typedef struct cellule* File;

typedef
  struct chemin {
   	ARC * arc;
		struct chemin* suiv; } CHEMIN;

File creer_file(void);
int file_vide(File f);
File enfiler(SOMMET * elmt, File f);
SOMMET * defiler(File* pf);

CHEMIN * creer_chemin(void);
void ajout_arc(ARC * arc, CHEMIN * chemin);

int sommet_dans_file (SOMMET * s);
CHEMIN * bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee);
