#include "testchemin.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
  CHEMIN chemin;

  g = lecture_graphe("graphes/graphe3.txt");
	chemin=bellman (g, g.sommets, g.sommets+3);
  affiche_chemin(g, chemin);
  liberer_chemin(chemin);
  liberer_graphe(&g);
  return 0;
}
