#ifndef ECRAN_H_INCLUDED
#define ECRAN_H_INCLUDED

    ///Definitions des structures

    typedef struct{
        char* nom;
        char* titre;
        char* text;

    }Ecran;


    ///Prototypes
    void Ecran_setEcran(Ecran* e, char* nom, char* titre,char* texte);
    Ecran* new_Ecran(void);
    void Ecran_printEcran(const Ecran* e);

    Ecran* Ecran_generateIntroduction(void);
    Ecran* Ecran_generateRules(void);
    Ecran* Ecran_generateQuit(void);
    void gestionChoix(char* choix_user, Ecran* tableauEcran[], int* indiceEcran);


#endif // ECRAN_H_INCLUDED
