#include <stdio.h>
#include <windows.h>
#include <dirent.h>

#include "saisie.h"
#include "affichage.h"

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

void consoleParam(void){
    SetConsoleTitle("SUDOKU");
    system("mode con lines=75 cols=47");
}

///Fonction d'affcihage des ecrans
void introduction(void){
    consoleParam();
    system("cls");

    titre(" Bienvenue dans le jeu du SUDOKU ! ");
    ligne();
    printf(" Coder par Maxime KUGLER et Thomas ARONICA.\n\n Bonne chance !\n\n");
    ligne();
    printf("\n");

    char* cmdTemp = saisie_parmis_cmd(4,"quit","play","charge","rules");

    char cmd[strlen(cmdTemp)];
    strcpy(cmd,cmdTemp);
    free(cmdTemp);

    gestionnaireCmd(getIndCmd(cmd),"introduction");


}

void rules(const char* ecran){
    system("cls");
    titre(" Regle du sudoku ");
    printf(" Vous devez completer une grille de 9 par 9.\n Pour se faire vous devez placer des chiffres   de 1 a 9.\n Mais il ne peut y avoir qu'un seul chiffres    identique dans chaque ligne, colonne et case   de 3 par 3.\n");
    ligne();

    char* cmdTemp = saisie_parmis_cmd(1,"back");
    char cmd[strlen(cmdTemp)];
    strcpy(cmd,cmdTemp);
    free(cmdTemp);

    switch(getIndCmd(cmd)){
    case -1:
        break;
    case 6 : //back
        back(ecran);
        break;
    default :
        break;
    }
}

void back(const char* ecran){
    if(strcmp(ecran,"introduction")==0)
        introduction();
    else if(strcmp(ecran,"charge") == 0)
        charge();
}

void quit(void){
    system("exit");
}

void charge(void){
    system("cls");
    titre(" Liste des grilles ");

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

    char* cmdTemp = saisie_parmis_cmd(4,"print","play","back","quit");
    char cmd[strlen(cmdTemp)];
    strcpy(cmd,cmdTemp);
    free(cmdTemp);

    gestionnaireCmd(getIndCmd(cmd),"introduction");
}





