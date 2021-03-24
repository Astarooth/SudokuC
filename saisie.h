#ifndef SAISIE_H_INCLUDED
#define SAISIE_H_INCLUDED

/** \brief : retourne un char* saisie par l'utilisateur parmis une liste
 *
 * \param : varnb = nbr de choix
 * \param : liste de tout les choix
 * \return : char* saisie par l'utilisateur
 *
 */
char* saisie_parmis_cmd(const int nbr_elem, char* tableauCmd[]);

/** \brief : affiche le manuel d'une commande si commande inconnu affiche unkown command
 *
 * \param : nom de la commande
 *
 */
void man(const char* cmd);

/** \brief : retourne l'indice d'un char dans un tableau de char de taille size
 *
 * \param : char chercher
 * \param : liste de char
 * \param : taille du tableau
 * \return : indice du char, -1 si par trouver
 *
 */
int getInd(const char* searched, const char* liste[], const int size);


int getIndCmd(const char* searched);

/** \brief : divise un string d'une certaine longueur a partir d'une position
            Code repris de : https://www.programmingsimplified.com/c/source-code/c-substring
 *
 * \param : string a couper
 * \param : position de depart
 * \param : longueur
 * \return : string couper
 *
 */
char* substring(char* string, const unsigned int position, const unsigned int lenght);
char* concat(const char* str1, const char* str2);
void trim(char* str);
void gestionnaireCmd(const int position, const int cur_screen);
void play(void);
int getNbrCommandePermise(const char* nom);
void initTabCmd(char* *tableauCmd,const int nbrElem, const char* nom);
int gestionCmd(const int nbr_elem, const char* tableauCmd);

#endif // SAISIE_H_INCLUDED
