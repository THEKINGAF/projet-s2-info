#include "chemin.h"

// fonctions sur la file de sommets

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

// initialisations de diverses valeurs du graphe

void init_poids (GRAPHE g, SOMMET * s) {
	int i;

	for (i=0; i<g.nbsommets; i++) {
		if ((g.sommets+i)==s) (g.sommets+i)->poids=0;
		else (g.sommets+i)->poids=INT_MAX;
	}
}

void init_file (GRAPHE g) {
	int i;

	for (i=0; i<g.nbsommets; i++) (g.sommets+i)->file=0;
}

void init_amont (GRAPHE g) {
	int i;

	for (i=0; i<g.nbsommets; i++) (g.sommets+i)->amont=NULL;
}

int sommet_dans_file (SOMMET * s) {
	return s->file;
}

// fonctions sur les chemins

CHEMIN creer_chemin(void) {
	return NULL;
}

void liberer_chemin (CHEMIN chemin) {
	CHEMIN c=chemin, csuiv;

	while (!chemin_vide(c)) {
		csuiv = c->suiv;
		free(c);
		c=csuiv;
	}
}

int chemin_vide(CHEMIN chemin) {
	if(chemin==NULL) return 1;
	else return 0;
}

CHEMIN ajout_arc(ARC * arc, CHEMIN chemin) {
	CHEMIN p=calloc(1, sizeof(*p));

	if(chemin_vide(chemin)){
		p->suiv=NULL;
		p->arc=arc;
	}

	else{
		p->suiv=chemin;
		p->arc=arc;
	}

	return p;
}

void affiche_chemin (GRAPHE g, CHEMIN chemin) {
	CHEMIN c = chemin;
	int cout = 0;

	printf("Chemin :\n");
	 while (!chemin_vide(c)) {
		printf("(%d)--->(%d) | %d\n",c->arc->dep, c->arc->dest, c->arc->poids);
		cout += c->arc->poids;
		c=c->suiv;
	}

	printf("coût total : %d\n", cout);
}

CHEMIN reconstruit_chemin (GRAPHE g, SOMMET * depart, SOMMET * arrivee) {
	CHEMIN chemin = creer_chemin();
	SOMMET * s = arrivee;

	while(s->amont!=NULL) {
		chemin=ajout_arc(s->amont, chemin);
		s=g.sommets+((s->amont)->dep);
	}

	return chemin;
}

CHEMIN bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee) {
  File f=creer_file();
  int j;
  SOMMET * u;
	SOMMET * v;
  ARC * arc;

	init_poids(g, depart);
	init_file(g);
	init_amont(g);

  f = enfiler(depart, f); // Enfiler le sommet de depart

  while (!file_vide(f)) { //Tant que la file n’est pas vide
    u = defiler(&f); // Defiler le sommet u
    for(j=0; j<(u->nbarcs); j++) { // Pour tous les arcs(u,v) partant de ce sommet u
      arc = (u->arcs)+j;
			v = g.sommets+(arc->dest);
      if ((u->poids + arc->poids) < (v->poids)) {
        /* si le chemin passant par l’arc u,v est plus court pour
        rejoindre v que les précédents chemins trouvés mettre à
        jour le poids du sommet v */
        v->poids = u->poids + arc->poids;
				v->amont = arc;
				// si le sommet v n’est pas déjà dans la file alors enfiler ce sommet
        if (!sommet_dans_file(v)) f = enfiler(v, f);
      }
    }
  }

  return reconstruit_chemin(g, depart, arrivee);
}
