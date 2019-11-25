#include <stdio.h>
#include <stdlib.h>
#include <cairo/cairo.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "grille.h"
#include "io.h"
#include "jeu.h"

/*!
 * \author Diaby Ibrahim
 * \version 0.1
 * \date 22 10 2019
 * \mainpage Jeu De La Vie
 * \section Consignes
 Voici les consignes que doivent respecter chacun de vos rendus.

Le dépôt git doit être partagé avec l’enseignant qui s’occupe de votre groupe de TP à qui vous donnerez le rôle Reporter.
make dist produit une archive (tarball). Cette archive en .tar.xz doit être mise en ligne sur Moodle dans la section prévue à cet effet (attention à respecter votre groupe).
make compile le code extrait en version debug.
doxygen crée la documentation.
Votre historique git doit contenir des étiquettes (tag) pour indiquer vos versions. Ainsi, le travail correspondant au niveau 1 aura une étiquette comme 0.1 (ou 1.0, ou autre selon vos préférences) et les archives déposées sur Moodle auront dans leur nom l’étiquette correspondante. Vous pouvez publier plusieurs versions d’un niveau en ajoutant des étiquettes pour cette série (0.1.x, 1.0.x…). Votre fichier README expliquera votre système de versionnement.
Un projet qui ne compile pas sera pénalisé. Un exécutable qui plante sera pénalisé. Tout ce qui entrave les tests par l’enseignant sera pénalisé.
 */


int main (int argc, char ** argv) {
	
	if (argc != 2 )
	{
		printf("usage : main <fichier grille>\n");
		return 1;
	}

    grille g, gc;
    cellule C;
    init_grille_from_file(argv[1],&g);
    alloue_grille (g.nbl, g.nbc, &gc);

    alloue_grille_cellule (g.nbl, g.nbc, &C);
    copie_grille_cellule(g,C);
    
    //affiche_grille(g,C, compteur, cyclique, vieillessement);
    affiche_grille(g, C, 0, 0, 0);
    
    debut_jeu(&g, &gc,&C);

    libere_cellule(&g, &C);
    libere_grille(&g);
    libere_grille(&gc);
    
	return EXIT_SUCCESS;
}
