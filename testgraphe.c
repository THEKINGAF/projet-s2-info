#include "testgraphe.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
  int i, nbsommets, nbarcs;

  g = lecturegraphe("graphes/graphe1.txt");
  printf("test :\nnbsommets=%d, nbarcs=%d\n", g.nbsommets, g.nbarcs);
  for(i=0; i<g.nbsommets; i++) printf("%d\n", (g.sommets+i)->id);

  return 0;
}
