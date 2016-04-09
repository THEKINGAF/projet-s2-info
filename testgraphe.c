#include "testgraphe.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
  int i, nbsommets, nbarcs;

  g = lecturegraphe("graphes/graphe1.txt");
  affichegraphe(g);

  return 0;
}
