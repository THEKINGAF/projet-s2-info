#include "chemin.h"

File creer_file(void){
	return NULL;
}

int file_vide(File f){
	if(f==NULL) return 1;
	else return 0;
}

File enfiler(SOMMET * elmt, File f){
	File p=calloc(1, sizeof(*p));

	if(file_vide(f)){
		p->suiv=p;
		p->elmt=elmt;
	}

	else{
		p->suiv=f->suiv;
		p->elmt=elmt;
		f->suiv=p;
	}

	elmt->file=0;

	return p;
}

SOMMET * defiler(File* pf){
	SOMMET * elmt;

	if((*pf)==(*pf)->suiv){
		elmt = (*pf)->elmt;
		free(*pf);
		*pf=NULL;
	}

	else{
		File f2 = ((*pf)->suiv)->suiv;
		elmt = ((*pf)->suiv)->elmt;

		free((*pf)->suiv);
		(*pf)->suiv=f2;
	}

	elmt->file=1;

	return elmt;
}

CHEMIN * creer_chemin(void) {
	return NULL;
}

void ajout_arc(ARC * arc, CHEMIN * chemin) {
	while (chemin!=NULL) chemin=chemin->suiv;
	
	chemin=malloc(sizeof(*chemin));
	chemin->arc = arc;
	chemin->suiv = NULL;	
}

void init_poids (GRAPHE g, SOMMET * s) {
	int i;

	for (i=0; i<g.nbsommets; i++) {
		if ((g.sommets+i)==s) (g.sommets+i)->poids=0;
		else (g.sommets+i)->poids=INT_MAX;
	}
}

int sommet_dans_file (SOMMET * s) {
	return s->file;	
}

CHEMIN * bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee) {
  File f=creer_file();
  int i, j;
  SOMMET * u;
	SOMMET * v;
  ARC * arc;

	init_poids(g, depart);
  f = enfiler(depart, f); // Enfiler le sommet de depart

  i=0;
  while (!file_vide(f)) { //Tant que la file n’est pas vide
    i++;
    u = defiler(&f); // Defiler le sommet u
    for(j=0; j<(u->nbarcs); j++) { // Pour tous les arcs(u,v) partant de ce sommet u
      arc = (u->arcs)+j;
			v = g.sommets+(arc->dest);
			//printf("poids(u) = %d, poids(arc(u,v)) = %d, poids(v) = %d\n", u->poids, arc->poids, v->poids);
      if ((u->poids + arc->poids) < (v->poids)) {
        /*le chemin passant par l’arc u,v est plus court pour
        rejoindre v que les précédents chemins trouvés mettre à
        jour le poids du sommet v */
        v->poids = u->poids + arc->poids;
        if (!sommet_dans_file(v)) { // si le sommet v n’est pas déjà dans la file
          f = enfiler(v, f); // enfiler ce sommet
        }
      }
    }
  }

  return NULL;
}
