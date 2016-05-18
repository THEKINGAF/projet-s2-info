#ifndef _GRAPHE
#define _GRAPHE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure d'arc
typedef
  struct arc {
    unsigned int dep; // id du sommet de départ
    unsigned int dest; // id du sommet de d'arrivée
    double poids; 
} ARC;

// structure de sommet
typedef
  struct sommet {
    unsigned int id;
    double lat; // latitude
    double lon; // longitude
    char ligne[255]; // nom de la ligne
    char nom[255]; // nom de la station
		char file; // présence ou non dans la file (cf algorithme de Bellman optimisé)
    ARC * amont; // pointeur vers l'arc qui arrive à ce sommet (reconstruction du chemin)
		double poids;
    unsigned int nbarcs; // nombre arcs partant de ce sommet
    ARC* arcs; // pointeur sur la liste des arcs partant de ce sommet
} SOMMET;

// structure de graphe
typedef
  struct graphe {
    SOMMET* sommets; // pointeur sur la liste des sommets
    ARC* arcs; // pointeur sur la liste des arcs
    unsigned int nbsommets; // nombre de sommets du graphe
    unsigned int nbarcs; // nombre d'arcs du graphe
} GRAPHE;

GRAPHE creer_graphe(unsigned int nbsommets, unsigned int nbarcs); // alloue la mémoire nécessaire au stockage du graphe
void liberer_graphe(GRAPHE * pg);
GRAPHE lecture_graphe(char * fichier); // crée un graphe à partire d'un fichier .csv
void affiche_graphe(GRAPHE g);
#endif
