#ifndef _FILE
#define _FILE
#include "liste.h"

typedef Liste File;

File creer_file(void); /*Crée une file vide*/
int file_vide(File f); /*Teste si la file est vide*/
File enfiler(void * elmt, File f); /*Ajoute une carte à la file par la queue*/
void * defiler(File* pf); /*Renvoie la carte en tete de file ET la supprime de la file*/
#endif
