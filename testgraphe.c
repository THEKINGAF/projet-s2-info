#include "testgraphe.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
  int i, nbsommets, nbarcs;

  g = lecture_graphe("graphes/graphe1.txt");
  affiche_graphe(g);

  return 0;
}
