#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

void consoleParam(void);
void introduction(void);
void ligne(void);
void ligne_c(const char c);
void ligneLimite(int lenght);
void infoCommande(void);
void titre(const char* titre);
void menuPrincipale(void);
void listeGrille(void);
void function_play(void);
void center(const char* texte_centrer);

void affichage_chargeGrille(void);

void rules(void);
int back(int* screen);
void quit(void);
void lister_grille(void);
void print(const char* name_file);
void print_screen(const int screen);
void listerCmd(const int nbr_elem, char* tableauCmd[]);



#endif // AFFICHAGE_H_INCLUDED
