#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

#include "saisie.h"
#include "color.h"
#include "affichage.h"

#define NBR_CMD 8

const char* listeCmd[NBR_CMD*2] =  {"quit",                 "quitte le jeu",
                                    "play",
                                    "lance un grille",
                                    "charge",               "liste les grilles",
                                    "rules",                "affiche les regles du jeu",
                                    "save",                 "sauvegarde la grille",
                                    "man",                  "affiche le manuel",
                                    "back",                 "retour a l'écran précédent",
                                    "print",                "affiche une grille de sudoku"
                                    };


char* saisie_parmis_cmd(const int varnb, ...){
    //Déclarations des variables
    char* param[varnb];
    va_list listeParm;
    va_start(listeParm, varnb);
    bool BonneSaisie = false ;

    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //initialisations des variables et affichage des chaines de caractere autorise
    printf("Liste des commandes autorise : \n");
    for(int i=0;i<varnb;i++){
        param[i] = (char*)va_arg(listeParm,char*);
        printf(" - %s\n",param[i]);
    }
    printf(" - man [commande] : afficher le manuel\n\n");

    //Déclarations de la variables de saisie utilisateurs qui ne peut être > a la taille max des commandes autorisé
    int size = 0;
    for(int i=0;i<varnb;i++){
        if(strlen(param[i])>size)
            size = strlen(param[i]);
    }
    char* saisie = (char*)malloc((size+4)*sizeof(char));
    if(saisie == NULL){
        exit(1);
    }

    do{
        SetConsoleTextAttribute(hConsole,VERT_CLAIR);
        printf("#: ");
        scanf("%s",saisie);
        SetConsoleTextAttribute(hConsole,BLANC);

        if(strcmp(saisie,"man")==0){
            scanf("%s",saisie);
            man(saisie);
        }
        else {
            for(int i=0;i<varnb;i++){
                if(strcmp(param[i],saisie)== 0){
                    BonneSaisie = true;
                }
            }
        }

    }while(!BonneSaisie);


    va_end(listeParm);
    return saisie;
}

void man(const char* cmd){
    const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    int indice = getInd(cmd,listeCmd,NBR_CMD*2);
    if(indice != -1 && indice< NBR_CMD*2-1){
        printf(" %s : %s\n",listeCmd[indice],listeCmd[indice+1]);
    }
    else{
        SetConsoleTextAttribute(hConsole,ROUGE);
        printf(" man error : unkown command\n");
    }
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

void gestionnaireCmd(const int position, const char* ecran){
    printf("%d",position);
    switch(position){
    case -1 :   // la cmd chercher n'est pas dans la liste
        break;
    case 0 :    //quit
        quit();
        break;
    case 1 :    //play
        play();
        break;
    case 2 :    //charge
        charge();
        break;
    case 3 :    //rules
        rules(ecran);
        break;
    case 4 :    //save
        break;
    case 6 :    //back
        back(ecran);
        break;
    case 7 :    //print
        print();
        break;
    default :
        break;
    }
}

void play(void){
    printf("play");
}

void print(void){
    printf("print");
}
