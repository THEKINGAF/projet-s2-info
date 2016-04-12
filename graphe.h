#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _GRAPHE
#define _GRAPHE

// structure d'arc
typedef
  struct arc {
    int dep;
    int dest;
    int poids; } ARC;

// structure de sommet
typedef
  struct sommet {
    int id;
    char nom[255];
		char file;
    ARC * amont;
		int poids;
    int nbarcs;
    ARC* arcs; } SOMMET;

// structure de graphe
typedef
  struct graphe {
    SOMMET* sommets;
    ARC* arcs;
    int nbsommets;
    int nbarcs; } GRAPHE;

GRAPHE creer_graphe(int nbsommets, int nbarcs);
void liberer_graphe(GRAPHE * pg);
GRAPHE lecture_graphe(char * fichier);
void affiche_graphe(GRAPHE g);
#endif
