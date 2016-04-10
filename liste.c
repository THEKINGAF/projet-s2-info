#include "liste.h"

Liste creer_liste(void){
	return NULL;
}

int est_vide(Liste l){
	if(l==NULL) return 1;
	else return 0;
}

Liste ajout_tete(void * c, Liste l){
	CELLULE* pcell;
	pcell = calloc(1, sizeof(*pcell));
	pcell->elmt=c;
	pcell->suiv=l;
	return pcell;
}

Liste supprimer_tete(Liste l){
	if(!est_vide(l)){
		Liste p=l->suiv;

		free(l);

		return p;
	}
	else return l;
}

Liste ajout_queue(void * c, Liste l){
	Liste p=l;
	CELLULE* pcell;

	pcell = calloc(1, sizeof(*pcell));
	pcell->elmt=c;
	pcell->suiv=NULL;

	if(est_vide(l)) return pcell;

	while(!est_vide(p->suiv)){
		p=p->suiv;
	}

	p->suiv=pcell;

	return l;
}

Liste supprimen(int n, Liste l){
	Liste q, p=l;
	int i=0;

	if(!(n-1)) l=supprimer_tete(l);
	else{
		while(!est_vide(p) && i<n-2){
			p=p->suiv;
			i++;
		}

		if(est_vide(p) || est_vide(p->suiv)) return l;

		q=(p->suiv)->suiv;
		free(p->suiv);
		p->suiv=q;
	}

	return l;
}

Liste concat(Liste l1, Liste l2){
	Liste p=l1;

	if(est_vide(l1)) return l2;

	while(!est_vide(p->suiv)){
		p=p->suiv;
	}

	p->suiv=l2;

	return l1;
}

Liste copie(Liste l){
	Liste lc = creer_liste();
	Liste p;

	if(est_vide(l)) return lc;
	else{
		lc = calloc(1, sizeof(*lc));
		*lc = *l;
		p = lc;
		l=l->suiv;

		while(!est_vide(l)){
			p->suiv = calloc(1, sizeof(*lc));
			p=p->suiv;
			*p=*l;
			l=l->suiv;
		}

		return lc;
	}
}
