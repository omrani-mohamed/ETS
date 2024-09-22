#ifndef DON_H_
#define DON_H_
#include <string.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>
typedef struct {
    char jour[10];
    char mois[10];
    char annee[10];
} Date;

typedef struct {
    char code_de_don[50];
    char Identifiant_du_donneur[50];
    char Type_de_sang[10];
    int quantite_de_prelevement;
    Date Date_de_prelevement;
    char gouvernerat[50];
    char adresse[50];
    char idets[50];
} Don;
typedef struct {
	char type_sang[10];
	int qte;
}Type_Qte;

int ajouter(char *filename, Don D);
void Afficher_Dons(GtkTreeView *treeview);
int modifier(char *filename, char *code_de_don, Don d3);
int supprimer(char *filename, char *code_de_don);
int chercher(char *filename, char *code_de_don);
int quantite_type(char nomFichier[], char type_sang[]);
char* sang_rare(char nomFichier[], char* resultType);
int verifier(char *id, char *mdp);
void type_de_sang (int x , char ts[]);
int verifier_id(char *code_don);
int verifier01(char *id, char *mdp);
#endif
