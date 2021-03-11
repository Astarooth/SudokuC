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

void affichage_chargeGrille(void);

void rules(const char* ecran);
void back(const char* ecran);
void quit(void);
void charge(void);


#endif // AFFICHAGE_H_INCLUDED
