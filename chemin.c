#include "chemin.h"

// initialisations de diverses valeurs du graphe

void init_poids (GRAPHE g, SOMMET * s) {
	unsigned int i;

	for (i=0; i<g.nbsommets; i++) {
		// poids à 0 pour le sommet s
		if ((g.sommets+i)==s) (g.sommets+i)->poids=0;
		// poids au maximum pour les autres
		else (g.sommets+i)->poids=DBL_MAX;
	}
}

void init_file (GRAPHE g) {
	unsigned int i;

	// mise à 0 du drapeau file de tous les sommets
	for (i=0; i<g.nbsommets; i++) (g.sommets+i)->file=0;
}

void init_amont (GRAPHE g) {
	unsigned int i;

	// mise à NULL de tous les arcs en amont
	for (i=0; i<g.nbsommets; i++) (g.sommets+i)->amont=NULL;
}

int sommet_dans_file (SOMMET * s) {
	return s->file;
}

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
	double cout = 0;

	printf("Chemin :\n");
	while (!chemin_vide(c)) {
		printf("(%d)--->(%d) ligne %s |%s\n",c->arc->dep, c->arc->dest, (g.sommets + c->arc->dest)->ligne, (g.sommets + c->arc->dest)->nom);
		cout += c->arc->poids;
		c=c->suiv;
	}

	printf("coût : %lf\n", cout);
}

CHEMIN reconstruit_chemin (GRAPHE g, SOMMET * depart, SOMMET * arrivee) {
	CHEMIN chemin = creer_chemin();
	SOMMET * s = arrivee;

	// on part de l'arrivée et on remonte jusqu'au sommet de départ
	while(s->amont!=NULL) {
		chemin=ajout_arc(s->amont, chemin);
		s=g.sommets+((s->amont)->dep);
	}

	return chemin;
}

double cout_chemin (GRAPHE g, CHEMIN chemin) {
	double cout = 0;
	CHEMIN c = chemin;

	while (!chemin_vide(c)) {
		cout += c->arc->poids;
		c=c->suiv;
	}

	return cout;
}

// fonctions sur les stations

void liberer_station (STATION * pstation) {
	free(pstation->tabid);
	free(pstation);
}

STATION * construit_station (GRAPHE g, char * nom) {
	int tab[MAX_STATION];
	int nb, i;

	STATION * pstation;

	nb=0;
	// on parcourt tous les sommets
	for (i=0; i<g.nbsommets; ++i) {
		// si le sommet à le nom de la station on stocke son numéro
		if (!strcmp(nom, (g.sommets+i)->nom)) {
			tab[nb]=i;
			++nb;
		}
	}

	// on crée l'objet qui contient le nombre de sommets de même nom et leur nombre
	pstation = malloc(sizeof(*pstation));
	pstation->tabid=malloc(sizeof(int)*nb);
	for (i=0; i<nb; ++i) {
		pstation->tabid[i]=tab[i];
	}
	pstation->n=nb;

	return pstation;
}

void affiche_station (GRAPHE g, STATION station) {
	int i;

	if (station.n) {
		printf("Station: %s\n", (g.sommets+station.tabid[0])->nom);
		for (i=0; i<station.n; ++i) {
			printf("	ligne %s\n", (g.sommets+station.tabid[i])->ligne);
		}
	}

	else {
		printf("Pas de station à afficher\n");
	}
}

// fonctions de construction d'itinéraire

CHEMIN bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee) {
  File f=creer_file();
  unsigned int j;
  SOMMET * u;
	SOMMET * v;
  ARC * arc;

	init_poids(g, depart);
	init_file(g);
	init_amont(g);

  f = enfiler(depart, f); // enfiler le sommet de depart

  while (!file_vide(f)) { // tant que la file n’est pas vide
    u = defiler(&f); // défiler le sommet u
    for(j=0; j<(u->nbarcs); j++) { // pour tous les arcs(u,v) partant de ce sommet u
      arc = (u->arcs)+j;
			v = g.sommets+(arc->dest);
      if ((u->poids + arc->poids) < (v->poids)) {
        /* si le chemin passant par l’arc(u,v) est plus court pour
        rejoindre v que les précédents chemins trouvés, alors mettre à
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

CHEMIN plus_court_chemin (GRAPHE g, char * depart, char * arrivee) {
	STATION * pstation1;
	STATION * pstation2;
	CHEMIN chemin=creer_chemin();
	CHEMIN chemin_tmp=creer_chemin();
	unsigned int i, j;
	double cout=DBL_MAX, cout_tmp=0.0;

	pstation1 = construit_station(g, depart);
	pstation2 = construit_station(g, arrivee);

	// pour tous les sommets de la station de départ
	for (i=0; i<pstation1->n; ++i) {
		// pour tous les sommets de la station d'arrivée
		for (j=0; j<pstation2->n; ++j) {
			// on calcule le plus court chemin entre les 2 sommets
			chemin_tmp = bellman (g, g.sommets+(pstation1->tabid[i]), g.sommets+(pstation2->tabid[j]));
			cout_tmp = cout_chemin(g, chemin_tmp);
			// si le nouveau chemin est plus court que celui stocké
			if (cout_tmp < cout) {
				// alors on détruit celui stocké
				if (!chemin_vide(chemin)) liberer_chemin(chemin);
				// et on le mémorise le nouveau chemin
				chemin=chemin_tmp;
				cout = cout_tmp;
			}
			// sinon on détruit le nouveau chemin
			else {
					liberer_chemin(chemin_tmp);
			}
		}
	}

	liberer_station(pstation1);
	liberer_station(pstation2);

	return chemin;
}
