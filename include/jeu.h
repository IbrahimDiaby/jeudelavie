#ifndef __JEU_H
#define __JEU_H

#include "grille.h"

// modulo modifié pour traiter correctement les bords i=0 et j=0
// dans le calcul des voisins avec bords cycliques
static inline int modulo(int i, int m) {return (i+m)%m;}

// compte le nombre de voisins vivants de la cellule (i,j)
// les bords sont cycliques.
int compte_voisins_vivants_cyclique(int i, int j, grille g);

int compte_voisins_vivants_non_cyclique (int i, int j, grille g);

// fait évoluer la grille g d'un pas de temps
void evolue (grille *g, grille *gc, cellule *C,int (*compte_voisins_vivants) (int, int, grille), int vieillissement);

int (*compte_voisins_vivants) (int, int, grille);

#endif
