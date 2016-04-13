#ifndef _GRAPHE
#define _GRAPHE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure d'arc
typedef
  struct arc {
    unsigned int dep;
    unsigned int dest;
    unsigned int poids; } ARC;

// structure de sommet
typedef
  struct sommet {
    unsigned int id;
    char nom[255];
		char file;
    ARC * amont;
		unsigned int poids;
    unsigned int nbarcs;
    ARC* arcs; } SOMMET;

// structure de graphe
typedef
  struct graphe {
    SOMMET* sommets;
    ARC* arcs;
    unsigned int nbsommets;
    unsigned int nbarcs; } GRAPHE;

GRAPHE creer_graphe(unsigned int nbsommets, unsigned int nbarcs);
void liberer_graphe(GRAPHE * pg);
GRAPHE lecture_graphe(char * fichier);
void affiche_graphe(GRAPHE g);
#endif
