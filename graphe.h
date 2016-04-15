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
    double poids; } ARC;

// structure de sommet
typedef
  struct sommet {
    unsigned int id;
    double lat;
    double lon;
    char ligne[255];
    char nom[255];
		char file;
    ARC * amont;
		double poids;
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
