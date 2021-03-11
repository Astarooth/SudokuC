#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "sudoku.h"
#include "testFunction.h"
#include "commande.h"
#include "color.h"
#include "interactionConsole.h"

void test_afficher(void){
    Sudoku* sudoku = new_Sudoku();
    Sudoku_posInit(sudoku);

    afficher(sudoku);

    Sudoku_end(sudoku);

}

void test_getPosFromCase3_3(void){
    int tab[9];
    for(int i=0;i<9;i++){
        getPosFromCase3_3(i, tab);
        for(int j=0;j<9;j++){
            printf("%d ",tab[j]);
        }
        printf("\n");
    }
}

void test_substring(){
    printf("In test_substring\n");
    char* string = "man rules";
    char* retour = substring(string,1,3);
    printf("String : %s\nRetour : %s\n", string, retour);
    free(retour);
    free(string);
}

void test_listeCommande(void){
    listeCommande* listeCmd = new_listeCommande();
    listeCommande_init(listeCmd);
    listeCommande_afficher(listeCmd);
    listeCommande_end(listeCmd);
}

void affichageTest() {
    FILE* fichier = NULL;
    int score[3] = { 0 }; // Tableau des 3 meilleurs scores
    int grille[9][9];
    int i;
    char carac;

    fichier = fopen("grilleFacile", "r");

    if (fichier != NULL)
    {
        for (i = 1; i < 9; i++)
        {
            for (j = 1; j < 9; j++)
            {
                carac = fgetc(fichier);
                if (carac = 0)
                    grille[j][i] = NULL;
                else
                    grille[j][i] = carac;
            }
        }
        fclose(fichier);
    }
    return 0;
}
