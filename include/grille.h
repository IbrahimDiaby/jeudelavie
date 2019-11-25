#ifndef __GRILLE_H
#define __GRILLE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// structure grille : nombre de lignes, nombre de colonnes, tableau de tableau de cellules
typedef struct {int nbl; int nbc; int** cellules;} grille;
// structure cellule : tableau de tableau de cellules correspondant à l'age de la cellule
typedef struct {int** cellules;} cellule;
 
// alloue une grille de taille l*c, et initialise toutes les cellules à mortes
void alloue_grille (int l, int c, grille* g);
// alloue une grille de taille l*c
void alloue_grille_cellule (int l, int c, cellule *C);

// libère une grille
void libere_grille (grille* g);

// libère une cellule
void libere_cellule (grille *g, cellule* c);

// alloue et initalise la grille g à partir d'un fichier
void init_grille_from_file (char * filename, grille* g);

// rend vivante la cellule (i,j) de la grille g
static inline void set_vivante(int i, int j, grille g){g.cellules[i][j] = 1;}
static inline void set_vivante_cellule(int i, int j, cellule c){c.cellules[i][j] = 1;}
// rend morte la cellule (i,j) de la grille g
static inline void set_morte(int i, int j, grille g){g.cellules[i][j] = 0;}
static inline void set_morte_cellule(int i, int j, cellule c){c.cellules[i][j] = 0;}
// teste si la cellule (i,j) de la grille g est vivante
static inline int est_vivante(int i, int j, grille g){return g.cellules[i][j] == 1;}
// rend non viable la cellule (i,j) de la grille g est non viable
static inline void set_nonViable(int i, int j, grille g){g.cellules[i][j] = -1;}
// teste si la cellule (i,j) de la grille g est non viable
static inline int est_nonViable(int i, int j, grille g){return g.cellules[i][j] == -1;}

// recopie gs dans gd (sans allocation)
void copie_grille (grille gs, grille gd);

// recopie gs dans c (sans allocation)
void copie_grille_cellule (grille gs, cellule c);

// veillir la cellule : la cellule meurt si elle atteint 8 pas
void vieillir(int i,int j,grille g,cellule c);

#endif
