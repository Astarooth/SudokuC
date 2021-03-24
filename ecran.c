#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "ecran.h"
#include "affichage.h"
#include "saisie.h"

Ecran* new_Ecran(void){
    Ecran* e = malloc(sizeof(*e));

    if(e==NULL){
        exit(EXIT_FAILURE);
    }


    e->nom = "";
    e->titre = "";
    e->text = "";
    return e;
}

void Ecran_setEcran(Ecran* e, char* nom, char* titre,char* texte){
    e->nom = nom;
    e->titre = titre;
    e->text = texte;
}

void Ecran_printEcran(const Ecran* e){
    system("cls");
    titre(concat(concat(" ",e->titre)," "));
    if(strcmp("quit",e->nom) == 0)
        center(e->text);
    else
        printf(" %s \n",e->text);
    ligne();
}


Ecran* Ecran_generateIntroduction(void){
    Ecran* e = new_Ecran();

    char* nom = "introduction";
    char* titre = "Bienvenue dans le jeu du SUDOKU !";
    char* texte = "Coder par Maxime KUGLER et Thomas ARONICA.\n\n Bonne chance !\n\n";

    Ecran_setEcran(e,nom,titre,texte);

    return e;
}

Ecran* Ecran_generateRules(void){
    Ecran* e = new_Ecran();

    char* nom = "rules";
    char* titre = "Regle du sudoku";
    char* texte = "Vous devez completer une grille de 9 par 9.\n Pour se faire vous devez placer des chiffres   de 1 a 9.\n Mais il ne peut y avoir qu'un seul chiffres    identique dans chaque ligne, colonne et case   de 3 par 3.\n";

    Ecran_setEcran(e,nom,titre,texte);

    return e;
}

Ecran* Ecran_generateQuit(void){
    Ecran* e = new_Ecran();

    char* nom = "quit";
    char* titre = "Quitter";
    char* texte = "Au revoir ! ";

    Ecran_setEcran(e,nom,titre,texte);

    return e;
}

Ecran* Ecran_generateCharge(void){
    Ecran* e = new_Ecran();

    char* nom = "charge";
    char* titre = "Liste des grilles";
    char* texte = "Voici la listes des grilles disponibles :";

    Ecran_setEcran(e,nom,titre,texte);

    return e;
}

void gestionChoix(char* choix_user, Ecran* tableauEcran[], int* indiceEcran){
    if(strcmp(choix_user,"back") == 0){
        free(tableauEcran[*indiceEcran]);
        (*indiceEcran)--;
         Ecran_printEcran(tableauEcran[*indiceEcran]);
    }
    else if(strcmp(choix_user,"rules") == 0){
        (*indiceEcran)++;
        tableauEcran[*indiceEcran] = Ecran_generateRules();
         Ecran_printEcran(tableauEcran[*indiceEcran]);
    }
    else if(strcmp(choix_user,"quit") == 0){
        (*indiceEcran)++;
        tableauEcran[*indiceEcran] = Ecran_generateQuit();
        Ecran_printEcran(tableauEcran[*indiceEcran]);
    }
    else if(strcmp(choix_user,"charge") == 0){
        (*indiceEcran)++;
        tableauEcran[*indiceEcran] = Ecran_generateCharge();
        Ecran_printEcran(tableauEcran[*indiceEcran]);
        lister_grille();
    }

}
