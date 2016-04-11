#include "testchemin.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
	int i;

  g = lecturegraphe("graphes/graphe1.txt");
	bellman (g, g.sommets, g.sommets+4);
	/*printf("Poids :\n");
	for(i=0; i<g.nbsommets; i++) printf("%d |%d|\n", (g.sommets+i)->id, (g.sommets+i)->poids);*/
  return 0;
}
