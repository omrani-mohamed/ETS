#ifndef HEADER_H
#define HEADER_H

#include<stdlib.h>
#include<stdio.h>
#include <gtk/gtk.h>
#include <string.h>
typedef struct
{
	char id[100]; //identiteets
	char reg[100];//region
	char adr[100];//adresse
	char idr[100];//idresponsableets
	char ct[10];//contact
	int ca;//capacite
} ets ;

int ajouter_ets(ets e);
int verifierid_ets(char id[]);
ets chercher_ets01(char id[]);
int modifier_ets(ets e);
int trouverregion_ets(char id[]);
//ets chercher(char id[]);
int supprimer_ets(ets e);
void afficher_ets(GtkTreeView *treeview);
//int ETSParRegion(GtkWidget *liste, char reg[]);
int ETSParRegion( char reg[]);
int afficher_ets_reg(GtkWidget *liste,char REG[]);
void afficher_ets_capacite_tri(GtkWidget *liste,int choix);
void ETStrieCapaciteTRI(char* mainF);
int afficher_ets_reg_tri(GtkWidget *liste,char REG[]);
int afficher_ets_reg_tri_dcroi(GtkWidget *liste,char REG[]);
int afficher_ets_reg_tri_croi(GtkWidget *liste,char REG[]);
int chercher_ets(char id[]);
int verifier_ets(char *id, char *mdp);
void swap(int *a, int *b);
int partition(ets arr[], int low, int high);
void quickSort(ets arr[], int low, int high);
void capacite_cori();
void afficher_ets_croi(GtkTreeView *treeview);
void swap_ets1(ets *a, ets *b);
void quickSort1(ets arr[], int low, int high);
int partition1(ets arr[], int low, int high);
void afficher_ets_decroi(GtkTreeView *treeview);
void capacite_decori();
void region1();
void afficher_region1(GtkTreeView *treeview);
#endif
