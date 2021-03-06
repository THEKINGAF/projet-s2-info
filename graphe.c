#include "graphe.h"

GRAPHE creer_graphe(unsigned int nbsommets, unsigned int nbarcs) {
  GRAPHE g;

	// allocation mémoire du tableau des sommets
  g.sommets = calloc(nbsommets, sizeof(SOMMET));
	// allocation mémoire du tableau des arcs
  g.arcs = malloc(nbarcs * sizeof(ARC)); 

  g.nbsommets = nbsommets;
  g.nbarcs = nbarcs;

  return g;
}

void liberer_graphe(GRAPHE * pg) {
  free(pg->sommets);
  free(pg->arcs);
}

GRAPHE lecture_graphe(char * fichier){
  FILE* f;
  GRAPHE g;
  SOMMET * s;
  ARC * a;
  char mot[255];
	unsigned int i, nbsommets, nbarcs;

	// ouverture du fichier
	if ((f=fopen(fichier,"r")) == NULL) perror("Une erreur s’est produite à l'ouverture'"); 
	// lecture du nombre de sommets et du nombre d'arcs
	fscanf(f,"%d %d", &(nbsommets), &(nbarcs)); fgets(mot,254,f);fgets(mot,254,f);

  g=creer_graphe(nbsommets, nbarcs);
  s=g.sommets;
  a=g.arcs;

	// lecture des sommets
  for(i=0; i<nbsommets; i++) {
    fscanf(f,"%d %lf %lf %s ", &((s+i)->id), &((s+i)->lat), &((s+i)->lon), ((s+i)->ligne));
    fgets(mot,254,f); if (mot[strlen(mot)-1]<32) mot[strlen(mot)-1]=0; strcpy((s+i)->nom, mot);
  }

  fgets(mot,254,f);

	// lecture des arcs
  for(i=0; i<nbarcs; i++) {
    fscanf(f,"%d %d %lf", &((a+i)->dep), &((a+i)->dest), &((a+i)->poids));
    ((s+((a+i)->dep))->nbarcs)++;
		// si premier arc partant du sommet i
    if(((s+((a+i)->dep))->nbarcs)==1) {
			// alors ajout du pointeur vers la liste d'arcs de chaque sommet
      ((s+((a+i)->dep))->arcs)=a+i;
    }
  }

	// fermeture du fichier
	if (fclose(f) != 0 ) perror("Une erreur s’est produite à la fermeture");

  return g;
}

void affiche_graphe(GRAPHE g) {
  unsigned int i, j;

  printf("Graphe :\nnbsommets=%d, nbarcs=%d\n", g.nbsommets, g.nbarcs);

	// parcours des sommets
  for(i=0; i<g.nbsommets; i++) {
    printf("%d |%s| %s\n", (g.sommets+i)->id, (g.sommets+i)->nom, (g.sommets+i)->ligne);
		// parcours des arcs partant du sommet i
    for(j=0; j<(g.sommets+i)->nbarcs; j++) {
      printf("  %d %d %lf\n", ((g.sommets+i)->arcs+j)->dep, ((g.sommets+i)->arcs+j)->dest, ((g.sommets+i)->arcs+j)->poids);
    }
  }
}
