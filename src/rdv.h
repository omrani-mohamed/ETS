#ifndef RDV_H_INCLUDED
#define RDV_H_INCLUDED
#include<gtk/gtk.h>
#include"donneur.h"
typedef struct {
 int j ,m,a;
}Date1;
 typedef struct { 
 int jd ,md,ad; 
}Dated;
 typedef struct {
 int jn ,mn,an; 
}Daten; 
typedef struct {
 char id[50];
 char nom[10] ;
 char prenom[10] ; 
 char cin[10] ; 
 char sexe[50] ;
 char type[50] ; 
 Date1 date_nais; 
 int don ; 
 char d_etablissement[50] ; 
 Dated dernier_don ;
 Daten nouvelle_don; 
 char etablissement[50] ;
}rdv ; 
/*void ajouter( rdv r); 
int supprimer(char id);
int modifier(char id ,rdv nouv); 
rdv chercher(char id, char * filename); */
void historique(char nomFichier[], int cinRecherche);
void afficher_rdv(GtkWidget *liste,char j[],char m[],char a[],char etab[]);
rdv chercher_rdv(char etablissement[],int j,int m,int a,char * filename);
#endif
