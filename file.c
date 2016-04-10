#include "file.h"

File creer_file(void){
	return creer_liste();
}

int file_vide(File f){
	return est_vide(f);
}

File enfiler(void * elmt, File f){
	File p=calloc(1, sizeof(*p));

	if(file_vide(f)){
		p->suiv=p;
		p->elmt=c;
	}

	else{
		p->suiv=f->suiv;
		p->elmt=c;
		f->suiv=p;
	}

	return p;
}

void * defiler(File* pf){
	void * elmt;

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

	return elmt;
}
