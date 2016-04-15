#include "testgraphe.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;

  g = lecture_graphe("graphes/graphe1.csv");
  affiche_graphe(g);

  return 0;
}
