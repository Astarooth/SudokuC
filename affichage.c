#include <stdio.h>
#include <windows.h>
#include <dirent.h>
#include <stdbool.h>

#include "saisie.h"
#include "affichage.h"
#include "sudoku.h"

#define COLONNE 47
#define LIGNE 75

///Commande d'affichage basique
void ligne(void){
    for(int i=0;i<COLONNE;i++){
        printf("=");
    }
    printf("\n");
}

void ligne_c(const char c){
    for(int i=0; i<COLONNE; i++)
        printf("%c",c);
    printf("\n");
}

void ligneLimite(const int lenght){
    for(int i=0;i<lenght;i++){
        printf("=");
    }
}

void ligneLimite_c(const int lenght, const char c){
    for(int i=0;i<lenght;i++){
        printf("%c",c);
    }
}

void titre(const char* titre){
    int size = strlen(titre);
    ligne();
    ligneLimite((COLONNE-size)/2);
    printf("%s", titre);
    if((COLONNE - size)%2 != 0)
        ligneLimite(((COLONNE-size)/2)+1);
    else
        ligneLimite(((COLONNE-size)/2));

    ligne();
    printf("\n");
}

void center(const char* texte_centrer){
    int size = strlen(texte_centrer);
    ligneLimite_c((COLONNE-size)/2,' ');
    printf("%s",texte_centrer);

    if((COLONNE - size)%2 != 0)
        ligneLimite_c(((COLONNE-size)/2)+1,' ');
    else
        ligneLimite_c(((COLONNE-size)/2),' ');
    printf("\n\n");
}

void consoleParam(void){
    SetConsoleTitle("SUDOKU");
    system("mode con lines=75 cols=47");
}

///Fonction d'affcihage des ecrans

void lister_grille(void){

    //On ouvre le repertoire
    DIR* grille_dir = opendir("Grille/");

    if(grille_dir == NULL){
        perror("");
        exit(1);
    }

    //Liste des fichier
    struct dirent* fichier_lu = NULL;

    while((fichier_lu = readdir(grille_dir)) != NULL){
        if(strcmp(fichier_lu->d_name,".") != 0 &&  strcmp(fichier_lu->d_name,"..")){
            printf(" %s\n", fichier_lu->d_name);
        }
    }

    //Fermeture du repertoire
    if(closedir(grille_dir) == -1){
        perror("");
        exit(-1);
    }

    ligne();

    printf("\n");

    closedir(grille_dir);
}

void play(void){
    printf("play");
}

void print(const char* name_file){
    Sudoku* SUDOKU = new_Sudoku();

    SUDOKU = chargeSudokuFromFile(concat("Grille/", name_file));

    if(SUDOKU != NULL){
        afficher_grille(SUDOKU);

        Sudoku_end(SUDOKU);
    }
}


void listerCmd(const int nbr_elem, char* tableauCmd[]){
    printf("Liste des commandes autorise : \n");
    for(int i=0;i<nbr_elem;i++){
        printf(" - %s\n",tableauCmd[i]);
    }
    printf(" - man [commande] : afficher le manuel\n\n");
    ligne();
}



