#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED

    typedef struct{
        int value;
        _Bool modifiable;
    }Case;

    typedef struct{
        Case* grille[9][9];
        _Bool finished;
    }Sudoku;

    ///Constructeur
Case* new_Case(void);
Sudoku* new_Sudoku(void);

    ///Getters & Setters Case
int Case_getValue(const Case* c);
bool Case_getModifiable(const Case* c);
void Case_setModifiable(Case* c, const bool modifiable);
void Case_setValue(Case *c, const int value);
void Case_setCase(Case* c, const int value, const bool modifiable);

    ///Getters & Setters Sudoku
void Sudoku_setCase(Sudoku* SUDOKU, const int posX, const int posY, Case* c);
Case* Sudoku_getCase(Sudoku* SUDOKU, const int posX, const int posY);

/** \brief : Fonction qui initialise une grille de sudoku avec des valeurs allant de 0 a 80
 *
 * \param : Sudoku* SUDOKU
 * \return : void
 *
 */
void Sudoku_posInit(Sudoku* SUDOKU);

    ///Destructeurs Sudoku

/** \brief : Fonction qui libère la mémoire d'un sudoku, case par case, puis le sudoku
 *
 * \param : Sudoku* SUDOKU
 * \return : void
 *
 */
void Sudoku_end(Sudoku* SUDOKU);

    ///Methodes génériques

/** \brief : Fonction d'affichage d'une grille de sudoku avec gestion des couleurs (defini dans color.h) inspirer de :
 *              - https://www.gladir.com/CODER/CWINDOWS/setconsoletextattribute.htm (pour les codes couleurs)
 *              - https://code-examples.net/fr/q/3ddb4d                             (pour l'utilisations de SetConsoleTextAttribute)
 *
 * \param : const Sudoku* Sudoku
 * \return : void
 *
 */
void afficher_grille(const Sudoku* SUDOKU);
void afficher_case(const Case* c);
bool solveur(const Sudoku* SUDOKU);
bool juste(int tableau[9]);
int compare(const void* a, const void*b);
int tabIndex(const int tableau[9], const int search_int);
void getPosFromCase3_3(const int num_case,int tab_retour[9]);

Sudoku* chargeSudokuFromFile(const char* chemain);

#endif // SUDOKU_H_INCLUDED
