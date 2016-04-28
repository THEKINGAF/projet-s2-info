#include "testchemin.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
  CHEMIN chemin;

  g = lecture_graphe("graphes/metro.csv");
	chemin=bellman (g, g.sommets, g.sommets+295);
  affiche_chemin(g, chemin);
  liberer_chemin(chemin);
  liberer_graphe(&g);
  return 0;
}
