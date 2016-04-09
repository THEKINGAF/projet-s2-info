#include "graphe.h"

GRAPHE creergraphe(int nbsommets, int nbarcs) {
  GRAPHE g;

  g.sommets = calloc(nbsommets, sizeof(SOMMET)); // allocation mémoire du tableau des sommets
  g.arcs = calloc(nbarcs, sizeof(ARC)); // allocation mémoire du tableau des arcs
  g.nbsommets = nbsommets;
  g.nbarcs = nbarcs;

  return g;
}

void liberergraphe(GRAPHE * pg) {
  free(pg->sommets);
  free(pg->arcs);
  free(pg);
}

GRAPHE lecturegraphe(char * fichier){
  FILE* f;
  GRAPHE g;
  SOMMET * s;
  ARC * a;
  char mot[255];
  int i, j;
	int nbsommets, nbarcs;

	if ((f=fopen(fichier,"r")) == NULL) perror("Une erreur s’est produite à l'ouverture'"); // ouverture du fichier

	fscanf(f,"%d %d", &(nbsommets), &(nbarcs)); fgets(mot,254,f);fgets(mot,254,f);

  g=creergraphe(nbsommets, nbarcs);
  s=g.sommets;
  a=g.arcs;

  for(i=0; i<nbsommets; i++) {
    fscanf(f,"%d", &((s+i)->id));
    fgets(mot,254,f); if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0; strcpy((s+i)->nom, mot);
    printf("%d %s\n", (s+i)->id, (s+i)->nom);
  }

  for(i=0; i<nbarcs; i++) {
    fscanf(f,"%d %d %d", &j, &((a+i)->dest), &((a+i)->poids));
    ((s+j)->nbarcs)++;
  }

	if (fclose(f) != 0 ) perror("Une erreur s’est produite à la fermeture");

  return g;
}
