#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _GRAPHE
#define _GRAPHE

typedef
  struct arc {
    int dep;
    int dest;
    int poids; } ARC;
typedef
  struct sommet {
    int id;
    char nom[255];
		char file;
		int poids;
    int nbarcs;
    ARC* arcs; } SOMMET;
typedef
  struct graphe {
    SOMMET* sommets;
    ARC* arcs;
    int nbsommets;
    int nbarcs; } GRAPHE;

GRAPHE creergraphe(int nbsommets, int nbarcs);
void liberergraphe(GRAPHE * pg);
GRAPHE lecturegraphe(char * fichier);
void affichegraphe(GRAPHE g);
#endif
