#include "chemin.h"

int sommet_dans_liste (SOMMET * s, File f) {

}

CHEMIN bellman (GRAPHE g, SOMMET * depart, SOMMET * arrivee) {
  File f=creer_file();
  int i;
  SOMMET * u;
  ARC arc;

  f = enfiler(depart, f); // Enfiler le sommet de depart

  i=0;
  while (!file_vide(f)) { //Tant que la file n’est pas vide
    i++;
    u = defiler(&f); // Defiler le sommet u
    for(j=0; j<u->nbarcs; j++) { // Pour tous les arcs(u,v) partant de ce sommet u
      arc = *(u.arcs+j);
      if (poids(u) + poids(arc(u, v)) < poids(v)) {
        /*le chemin passant par l’arc u,v est plus court pour
        rejoindre v que les précédents chemins trouvés mettre à
        jour le poids du sommet v */
        poids(v)= poids(u) + poids(arc(u, v));
        if (sommet_dans_liste(v, f)) { // si le sommet v n’est pas déjà dans la file
          f = enfiler(v, f); // enfiler ce sommet
        }
      }
    }
  }

  
}
