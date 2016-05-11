#include "teststation.h"

int main(int argc, char const *argv[]) {
  GRAPHE g;
  STATION * pstation;

  g = lecture_graphe("graphes/metro.csv");
	pstation =  construit_station(g, "Montparasse Bienvenue");
  affiche_station(g, *pstation);
  liberer_graphe(&g);
  return 0;
}
