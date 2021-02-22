#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

    typedef struct grille{
        int tableau[8][8];
    }grille;

//Proc�dure de cr�ations
grille new_grille();
grille init();

//Proc�dure de v�rifications : retourn 0 si bon
int verif_ligne(const grille G,const int l);
int verif_colonne(const grille G,const int c);
int verif_case(const grille G,const int k);
int verif(const grille G);

//proc�dure d'affichage
void affichage(const grille G);

//proc�dure de sauvegarde/chargement
grille charge();
grille save();
#endif // SUDOKU_H_INCLUDED
