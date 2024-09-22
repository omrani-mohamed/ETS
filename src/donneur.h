#ifndef DONNEUR_H_INCLUDED
#define DONNEUR_H_INCLUDED
#include<gtk/gtk.h>
#include"rdv.h"


typedef struct
{
char jour[10];
char mois[10];
char annee[10];
}date;
typedef struct
{
char nom[20];
char prenom [20];
char id[20];
date date_de_prelevement;
char heure_prelevement[30];
char type_transfusion[30];
char idets[20];
}donneur;

int ajouter_donneur(donneur d , char filename []);
int modifier_donneur(char id[],donneur nouv);
int supprimer_donneur(char id[]);
donneur chercher_donneur(char x[],char * filename);
void afficher(char id[], char * filename);
void heure_donneur(int heure,char msg[]);
void Afficher_Donneurs(GtkTreeView *treeview);
int nbETS(char nomFichier[]);
float moyRDV_ETS(char nomFichier[], int jour, int mois, int annee);
int listeRDV(char nomFichier[], char ETS[], int jour, int mois, int annee);
int verifier_existant_donneur(char id[]);
int trouvertype5(char id[]);
int trouverjour5(char id[]);
int trouvermois5(char id[]);
int trouverannee5(char id[]);
int chercher_donneur01(char x[],char * filename);
void type_de_transfusion (int x , char tt[]);
int trouverheure(char id[]);
int verifier_inf(char *id, char *mdp);
#endif // DONNEUR_H_INCLUDED
