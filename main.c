#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <tchar.h>
#include <string.h>

#include "sudoku.h"
#include "affichage.h"
#include "saisie.h"
#include "ecran.h"

#define NBR_CMD 10

int main(){

    ///D�clarations des variables
    //Ecran d'introduction (affiche toujours)
    Ecran *introduction = Ecran_generateIntroduction();
    Ecran* tableauEcran[100];
    tableauEcran[0] = introduction;

    //Variables utilis�
    int cur_screen = 0;
    bool quit = false;
    char* user_choice = "";

    ///D�but du programme
    consoleParam();

    //J'affiche l'ecran demand�
    Ecran_printEcran(tableauEcran[cur_screen]);

    //"quit" est vrai si l'utilisateur a saisie "quit" sinon est faux
    while(!(quit = (strcmp(user_choice,"quit") == 0))){

        if(!quit){

            //Recup�re la liste des commandes en fonction de l'�cran
            int nbrCmd = getNbrCommandePermise(tableauEcran[cur_screen]->nom);
            char* tabCommmandePermise[nbrCmd];
            initTabCmd(tabCommmandePermise,nbrCmd, tableauEcran[cur_screen]->nom);

            //Afficher la liste des commandes
            listerCmd(nbrCmd,tabCommmandePermise);

            //R�cup�rer la saisie de l'utilsiateurs
            user_choice = saisie_parmis_cmd(nbrCmd, tabCommmandePermise);

            //On g�re la saisie utilisateurs
            gestionChoix(user_choice,tableauEcran,&cur_screen);

        }
    }

    free(user_choice);

    for(int i=0;i<cur_screen;i++)
        free(tableauEcran[i]);

    //free(user_choice);
    return 0;
}
