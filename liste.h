#ifndef _LISTE
#define _LISTE
#include <stdlib.h>
#include <stdio.h>

struct cellule{
	void * elmt;
	struct cellule* suiv;
};

typedef struct cellule CELLULE;
typedef struct cellule* Liste;

Liste creer_liste(void);
int est_vide(Liste l);
void visualiser_liste(Liste l);
Liste ajout_tete(void * c, Liste l);
Liste supprimer_tete(Liste l);
Liste ajout_queue(void * c, Liste l);
Liste supprimen(int n, Liste l);
Liste concat(Liste l1, Liste l2);
Liste copie(Liste l);
#endif
