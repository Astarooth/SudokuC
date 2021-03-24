#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#include "saisie.h"
#include "color.h"
#include "affichage.h"
#include "ecran.h"

#define NBR_CMD 11

const char* listeCmd[NBR_CMD*2] =  {"quit",                 "quitte le jeu",
                                    "play",                 "joue une partie aléatoire",
                                    "lance",                "[nom_fichier] joue la grille séléctionner",
                                    "charge",               "liste les grilles",
                                    "rules",                "affiche les regles du jeu",
                                    "save",                 "sauvegarde la grille",
                                    "man",                  "affiche le manuel",
                                    "back",                 "retour a l'écran précédent",
                                    "print",                "affiche une grille de sudoku",
                                    "set",                  "[chiffre] [colonne] [ligne] place un chiffre dans la case souhaité",
                                    "clear",                "efface les commandes saisies"
                                    };



char* saisie_parmis_cmd(const int nbr_elem, char* tableauCmd[]){
    //Déclarations des variables
    bool BonneSaisie = false ;
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Déclarations de la variables de saisie utilisateurs qui ne peut être > a la taille max des commandes autorisé
    int size = 0;
    for(int i=0;i<nbr_elem;i++){
        if(strlen(tableauCmd[i])>size)
            size = strlen(tableauCmd[i]);
    }

    char* saisie = (char*)malloc((size+4)*sizeof(char));

    if(saisie == NULL){
        exit(1);
    }


    while(!BonneSaisie){
        SetConsoleTextAttribute(hConsole,VERT_CLAIR);
        printf("#: ");
        scanf("%s",saisie);
        SetConsoleTextAttribute(hConsole,BLANC);

        if(strcmp("man",saisie) == 0){
            scanf("%s",saisie);
            man(saisie);
        }
        else{
            for(int i=0;i<nbr_elem;i++){
                if(strcmp(tableauCmd[i],saisie)== 0){
                    BonneSaisie = true;
                }
            }
            if(!BonneSaisie){
                SetConsoleTextAttribute(hConsole,ROUGE);
                printf("Erreur : commande non admise\n");
            }
        }
    }
    return saisie;
}

int getInd(const char* searched, const char* liste[], const int size){
    for(int i=0;i<size;i++){
        if(strcmp(liste[i],searched) == 0)
            return i;
    }
    return -1;
}

int getIndCmd(const char* searched){
    for(int i=0;i<NBR_CMD;i++){
        if(strcmp(listeCmd[i*2],searched) == 0)
            return i;
    }
    return -1;
}

char* substring(char* string, const unsigned int position, const unsigned int lenght){
    char *retour;

    retour = malloc(lenght+1);
    if(retour == NULL){
        printf("Erreur : allocutions memoire impossibe");
        exit(1);
    }

    int i = 0;
    for(i=0;i<lenght;i++){
        *(retour+i) = (*string+position-1);
        string++;
    }
    *(retour+i) = '\0';
    string--;
    return retour;
}

char* concat(const char* str1, const char* str2){

    char* retour = (char*)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));

    if(retour == NULL)
        exit(1);

    for(int i=0;i<strlen(str1);i++){
        retour[i] = str1[i];
    }

    for(int i=0;i<strlen(str2);i++){
        retour[strlen(str1)+i] = str2[i];
    }

    retour[strlen(str1)+strlen(str2)] = '\0';

    return retour;
}

void trim(char* str){
    for(int i=0;i<strlen(str);i++){
        if(str[i] == ' '){
            str[i] = str[i+1];
        }
    }
}


void man(const char* cmd){
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int indice = getInd(cmd,listeCmd,NBR_CMD*2);
    //la commande est dans la liste
    if(indice != -1 && indice< NBR_CMD*2-1){
        printf(" %s : %s\n",listeCmd[indice],listeCmd[indice+1]);
    }
    //la commande n'est pas dans la liste
    else{
        SetConsoleTextAttribute(hConsole,ROUGE);
        printf(" man error : unkown command\n");
    }
}

void initTabCmd(char* tableauCmd[],const int nbrElem, const char* nom){
    if(strcmp("introduction",nom) == 0){
        tableauCmd[0] = "quit";
        tableauCmd[1] = "play";
        tableauCmd[2] = "charge";
        tableauCmd[3] = "rules";
        tableauCmd[4] = "clear";
    }
    else if(strcmp("rules",nom) == 0){
        tableauCmd[0] = "quit";
        tableauCmd[1] = "back";
        tableauCmd[2] = "clear";
    }
    else if(strcmp("charge",nom) == 0){
        tableauCmd[0] = "quit";
        tableauCmd[1] = "back";
        tableauCmd[1] = "lance";
        tableauCmd[1] = "print";
        tableauCmd[1] = "rules";
        tableauCmd[1] = "clear";

    }
}

int getNbrCommandePermise(const char* nom){
    int n = 0;
    if(strcmp("introduction",nom) == 0)
        n=5;
    else if(strcmp("rules",nom) == 0)
        n=3;
    else if(strcmp("charge",nom) == 0)
        n=6;
    return n;
}


