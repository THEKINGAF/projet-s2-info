#include "bellman.h"

int main(int argc, char * argv[]) {
  GRAPHE g;
  CHEMIN chemin;

	if(argc!=4) {
		printf("Utilisation :\nbellman fichier_graphe départ arrivée\n");
		return 0;
	}

 	g = lecture_graphe(argv[1]);
	chemin = plus_court_chemin(g, argv[2], argv[3]);
  affiche_chemin(g, chemin);

  liberer_chemin(chemin);
  liberer_graphe(&g);

  return 0;
}
