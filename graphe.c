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
  int i;
	int nbsommets, nbarcs;

	if ((f=fopen(fichier,"r")) == NULL) perror("Une erreur s’est produite à l'ouverture'"); // ouverture du fichier

	fscanf(f,"%d %d", &(nbsommets), &(nbarcs)); fgets(mot,254,f);fgets(mot,254,f);

  g=creergraphe(nbsommets, nbarcs);
  s=g.sommets;
  a=g.arcs;

  for(i=0; i<nbsommets; i++) {
    fscanf(f,"%d ", &((s+i)->id));
    fgets(mot,254,f); if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0; strcpy((s+i)->nom, mot);
  }

  fgets(mot,254,f);

  for(i=0; i<nbarcs; i++) {
    fscanf(f,"%d %d %d", &((a+i)->dep), &((a+i)->dest), &((a+i)->poids));
    ((s+((a+i)->dep))->nbarcs)++;
  }

	if (fclose(f) != 0 ) perror("Une erreur s’est produite à la fermeture");

  return g;
}

void affichegraphe(GRAPHE g) {
  int i;

  printf("test :\nnbsommets=%d, nbarcs=%d\nSommets :\n", g.nbsommets, g.nbarcs);
  for(i=0; i<g.nbsommets; i++) printf("%d |%s|\n", (g.sommets+i)->id, (g.sommets+i)->nom);
  printf("Arcs :\n");
  for(i=0; i<g.nbarcs; i++) printf("%d %d %d\n", (g.arcs+i)->dep, (g.arcs+i)->dest, (g.arcs+i)->poids);
}
