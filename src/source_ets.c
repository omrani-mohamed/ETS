#include "source_ets.h"
#include<stdlib.h>
#include<stdio.h>
#include <gtk/gtk.h>
#include <string.h>
enum {
	ID_ETS,
	REGION,
	ADRESSE_ETS,
	ID_Resp,
	CONTACT,
	CAPACITE,
	COLUMNS
};
int ETSParRegion( char reg[])
{FILE* f1=fopen("etablissement.txt","r");
	ets e;
	int n=0;
	FILE* f=fopen("regionF.txt","w");
	if( f1 != NULL && f != NULL)
	{ while (fscanf(f1,"%s %s %s %s %s %d\n",e.id,e.reg,e.adr,e.idr,e.ct,&e.ca)!=EOF)
		{if(strcmp(e.reg, reg) == 0){
			fprintf(f,"%s %s %s %s %s %d \n",e.id,e.reg,e.adr,e.idr,e.ct,e.ca);
			n++;}}
fclose(f1);
fclose(f);}
//(g,"%s %s %s %s %s %d \n",e1.id,e1.reg,e1.adr,e1.idr,e1.ct,e1.ca);
return n;}
//Ajouter//
int ajouter_ets(ets e)
{
    int tr=0;
    FILE * f=fopen("etablissement.txt","a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %d \n",e.id,e.reg,e.adr,e.idr,e.ct,e.ca);
        fclose(f);
	tr=1;
        
    }
return tr;  
}
// verifier l'existance de e//
int verifierid_ets(char id[]) {
    FILE *f;
    ets e;
    int test =0;

    f = fopen("etablissement.txt", "r");

    if (f != NULL) {
    	while (fscanf(f, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, &e.ca) != EOF) {
        	if (strcmp(e.id, id) == 0) {
	    		test =1;
		}
    	}
    }
fclose(f);
return test;
}
// chercher ets by id//
ets chercher_ets01(char id[]){
    	FILE *f;
        ets e;
	f = fopen("etablissement.txt", "r");
	if (f == NULL) {
        printf("Error opening file for verification.\n");
    }
	 while (fscanf(f, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, &e.ca) != EOF) {
	if (strcmp(e.id, id) == 0) {  return e; }}
}
// index de region//
int trouverregion_ets(char id[]){
ets e1;
e1=chercher_ets01(id);
char  reg[24][30]={"Ariana","Beja","Ben_Arous","Bizerte","Gabes","Gafsa","Jendouba","Kairouan","Kasserine",
"Kebili","Kef","Mahdia","Manouba","Medenine","Monastir","Nabeul","Sfax","Sidi_Bouzid","Siliana","Sousse","Tataouine","Tozeur","Tunis","Zaghouan"};
for(int i=0;i<24;i++)
{if(strcmp(e1.reg,reg[i])==0)
return i;
}
return -1;
}
//Modifier//
int modifier_ets(ets e1)
{

FILE *f;
FILE *g;
ets e;
int tr=0;
f=fopen("etablissement.txt","r");
g=fopen("tempo.txt","w");

    if ( f!=NULL && g!=NULL ){

    while (fscanf(f,"%s %s %s %s %s %d \n",e.id,e.reg,e.adr,e.idr,e.ct,&e.ca)!=EOF)
    {
	if(strcmp(e.id,e1.id)==0)
        {

		fprintf(g,"%s %s %s %s %s %d \n",e1.id,e1.reg,e1.adr,e1.idr,e1.ct,e1.ca);
		tr=1;
	}
	else{
		fprintf(g,"%s %s %s %s %s %d \n",e.id,e.reg,e.adr,e.idr,e.ct,e.ca);
    	}
    }
}
fclose(g);
fclose(f);
remove("etablissement.txt");
rename("tempo.txt","etablissement.txt");
return tr;
}
//Supprimer//
int supprimer_ets(ets e1)
{
int tr=0;
ets e;
FILE *f,*g;
f=fopen("etablissement.txt","a+");
g=fopen("tempo.txt","w");

if (f!=NULL)
{
    while (fscanf(f,"%s %s %s %s %s %d \n",e.id,e.reg,e.adr,e.idr,e.ct,&e.ca)!=EOF)
    {
		if(strcmp(e1.id,e.id)==0){
			tr=1;
		}
		else{
			fprintf(g,"%s %s %s %s %s %d \n",e.id,e.reg,e.adr,e.idr,e.ct,e.ca);
		}
    }
}
fclose(f);
fclose(g);
remove("etablissement.txt");
rename("tempo.txt","etablissement.txt");
return tr;
}
///fonction affiche treeview///  
/*void afficher_ets(GtkWidget *liste)
{
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;
    GtkTreeIter iter; 
    GtkTreeModel *model;   

char id[20];
char reg[20];
char adr[20];
char idr[20];
char ct[20];
char ca [20];

ets e;
store=NULL;

FILE *f;
  model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);


    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_ETS", renderer, "text", ID_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("REGION", renderer, "text", REGION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("NOM_ETS", renderer, "text", NOM_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_Resp", renderer, "text", ID_Resp, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CONTACT", renderer, "text", CONTACT, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CAPACITE", renderer, "text", CAPACITE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
}
   
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f=fopen("etablissement.txt","r");
if (f==NULL){
return ;
}
else
{f=fopen("etablissement.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID_ETS,id,REGION,reg,NOM_ETS,adr,ID_Resp,idr,CONTACT,ct,CAPACITE,ca,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}

}*/
void afficher_ets(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
	char id[20];
	char reg[20];
	char adr[20];
	char idr[20];
	char ct[20];
	char ca [20];
    file = fopen("etablissement.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    	while (fscanf(file,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF) {
	
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID_ETS, id, REGION, reg, ADRESSE_ETS, adr, ID_Resp, idr, CONTACT, ct, CAPACITE, ca,-1);
     }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, " ID RTS ");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ID_ETS);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 100);
        

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "REGION");
       gtk_tree_view_column_add_attribute(column, renderer, "text", REGION);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);


   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ADRESSE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ADRESSE_ETS);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);



       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ID RESPONSABLE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ID_Resp);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CONTACT");
       gtk_tree_view_column_add_attribute(column, renderer, "text",CONTACT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CAPACITE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", CAPACITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);


       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}

//////////////////AFFICHER REGIONNNNNNN   ///////////////////////////////////////////////////////
int afficher_ets_reg(GtkWidget *liste,char REG[])
{
int rr;
rr=ETSParRegion(REG);

GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;
    GtkTreeIter iter; 
    GtkTreeModel *model;   

char id[20];
char reg[20];
char adr[20];
char idr[20];
char ct[20];
char ca [20];
/*sprintf(x ,"%d" ,ca);*/
ets e;
store=NULL;

FILE *f;
  model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);


    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_ETS", renderer, "text", ID_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("REGION", renderer, "text", REGION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ADRESSE_ETS", renderer, "text", ADRESSE_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_Resp", renderer, "text", ID_Resp, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CONTACT", renderer, "text", CONTACT, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CAPACITE", renderer, "text", CAPACITE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
}
   
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f=fopen("regionF.txt","r");
if (f!=NULL){
f=fopen("regionF.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID_ETS,id,REGION,reg,ADRESSE_ETS,adr,ID_Resp,idr,CONTACT,ct,CAPACITE,ca,-1);
}
fclose(f);
remove("regionF.txt");
gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
return rr;
}
int sorting_choice = 1;
//CAPACITE TRI////////////////////////////////
void ETStrieCapaciteTRI(char* mainF){
 	FILE* f1=fopen(mainF,"r");
	g_print("TRIIII");
	//ets E;
	int permut=0;
	ets aux;
	//copie dans un tab
	ets tab[1000];
	int n=0;
	if( f1 !=NULL)
	{while(n<1000 &&fscanf(f1,"%s %s %s %s %s %d \n",tab[n].id,tab[n].reg,tab[n].adr,tab[n].idr,tab[n].ct,&tab[n].ca)!=EOF)	
	{n++;}}
	fclose(f1);
	//TriDecroissant (choix==2)
	if(sorting_choice==2){
	do{permut=0;
	for(int i=0;i<n-1;i++){
	if(tab[i].ca>tab[i+1].ca){
	aux=tab[i];
	tab[i]=tab[i+1];
	tab[i+1]=aux;
	permut=1;	}}}while(permut ==1);
 	// open trif.txt  
	FILE* f2=fopen("trif.txt","w");
	int j=0;
	if(f2 !=NULL){
	while(j<n)
	{fprintf(f2,"%s %s %s %s %s %d \n",tab[j].id,tab[j].reg,tab[j].adr,tab[j].idr,tab[j].ct,tab[j].ca);
	j++; }}
 	// close
 	fclose(f2);
	} 
	//TRI CROISSANT (choix==3)
	if(sorting_choice==3)
	{do{permut=0;
	for(int i=0;i<n-1;i++){
	if(tab[i].ca<tab[i+1].ca){
	aux=tab[i];
	tab[i]=tab[i+1];
	tab[i+1]=aux;
	permut=1;	}}}while(permut ==1);
	// open
	FILE* f2=fopen("trif.txt","w");
	int j=0;
	if(f2 !=NULL){
	while(j<n)
	{fprintf(f2,"%s %s %s %s %s %d \n",tab[j].id,tab[j].reg,tab[j].adr,tab[j].idr,tab[j].ct,tab[j].ca);
	j++; }}
	// close
 	fclose(f2);
	}}
/////////////////////////    AFFICHER ETS TRI CAPACITE ALL               /////////////////////////////////////////////////
void afficher_ets_capacite_tri(GtkWidget *liste,int choix)
{
sorting_choice=choix;
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;
    GtkTreeIter iter; 
    GtkTreeModel *model;   

char id[20];
char reg[20];
char adr[20];
char idr[20];
char ct[20];
char ca [20];

ets e;
store=NULL;

FILE *f;
  model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);


    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_ETS", renderer, "text", ID_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("REGION", renderer, "text", REGION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ADRESSE_ETS", renderer, "text", ADRESSE_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_Resp", renderer, "text", ID_Resp, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CONTACT", renderer, "text", CONTACT, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CAPACITE", renderer, "text", CAPACITE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
}
   
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
ETStrieCapaciteTRI("etablissement.txt");
    f=fopen("trif.txt","r");
if (f!=NULL){
f=fopen("trif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID_ETS,id,REGION,reg,ADRESSE_ETS,adr,ID_Resp,idr,CONTACT,ct,CAPACITE,ca,-1);
}
fclose(f);
// remove trif.txt
remove("trif.txt");

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
}
////////////////// AFFICHER REGION TRI/////////////////
int afficher_ets_reg_tri(GtkWidget *liste,char REG[])
{
int rr;
//rr=ETSParRegion(REG);
ETStrieCapaciteTRI("regionF.txt");
GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;
    GtkTreeIter iter; 
    GtkTreeModel *model;   

char id[20];
char reg[20];
char adr[20];
char idr[20];
char ct[20];
char ca [20];

ets e;
store=NULL;

FILE *f;
  model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);


    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_ETS", renderer, "text", ID_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("REGION", renderer, "text", REGION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ADRESSE_ETS", renderer, "text", ADRESSE_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_Resp", renderer, "text", ID_Resp, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CONTACT", renderer, "text", CONTACT, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CAPACITE", renderer, "text", CAPACITE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
}
   
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

    f=fopen("trif.txt","r");
if (f!=NULL){
f=fopen("trif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID_ETS,id,REGION,reg,ADRESSE_ETS,adr,ID_Resp,idr,CONTACT,ct,CAPACITE,ca,-1);
}
fclose(f);

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
remove("regionF.txt");
remove("trif.txt");
}
return rr;
}
int afficher_ets_reg_tri_croi(GtkWidget *liste,char REG[])
{sorting_choice=3;
 int rr;
rr=ETSParRegion(REG);
ETStrieCapaciteTRI("regionF.txt");

GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;
    GtkTreeIter iter; 
    GtkTreeModel *model;   

char id[20];
char reg[20];
char adr[20];
char idr[20];
char ct[20];
char ca [20];

ets e;
store=NULL;

FILE *f;
  model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);


    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_ETS", renderer, "text", ID_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("REGION", renderer, "text", REGION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ADRESSE_ETS", renderer, "text", ADRESSE_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_Resp", renderer, "text", ID_Resp, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CONTACT", renderer, "text", CONTACT, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CAPACITE", renderer, "text", CAPACITE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
}
   
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("trif.txt","r");
if (f!=NULL){
f=fopen("trif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID_ETS,id,REGION,reg,ADRESSE_ETS,adr,ID_Resp,idr,CONTACT,ct,CAPACITE,ca,-1);
}
fclose(f);
remove("regionF.txt");
remove("trif.txt");

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
return rr;
}
int afficher_ets_reg_tri_dcroi(GtkWidget *liste,char REG[])
{sorting_choice=2;
 int rr;
rr=ETSParRegion(REG);
ETStrieCapaciteTRI("regionF.txt");

GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;
    GtkTreeIter iter; 
    GtkTreeModel *model;   

char id[20];
char reg[20];
char adr[20];
char idr[20];
char ct[20];
char ca [20];

ets e;
store=NULL;

FILE *f;
  model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);


    if (store == NULL)
    {

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_ETS", renderer, "text", ID_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("REGION", renderer, "text", REGION, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ADRESSE_ETS", renderer, "text", ADRESSE_ETS, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("ID_Resp", renderer, "text", ID_Resp, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
   
renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CONTACT", renderer, "text", CONTACT, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

renderer = gtk_cell_renderer_text_new ();
    column = gtk_tree_view_column_new_with_attributes ("CAPACITE", renderer, "text", CAPACITE, NULL);
    gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

    
}
   
    store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  f=fopen("trif.txt","r");
if (f!=NULL){
f=fopen("trif.txt","a+");
while (fscanf(f,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF)
{
gtk_list_store_append(store,&iter);

gtk_list_store_set(store,&iter,ID_ETS,id,REGION,reg,ADRESSE_ETS,adr,ID_Resp,idr,CONTACT,ct,CAPACITE,ca,-1);
}
fclose(f);
remove("regionF.txt");
remove("trif.txt");

gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref(store);
}
return rr;
}

int chercher_ets(char id[]){
    	FILE *f;
        ets e;
	int tr=0;
	f = fopen("etablissement.txt", "r");
	if (f == NULL) {
        printf("Error opening file for verification.\n");
        }
	else{
		while (fscanf(f, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, &e.ca) != EOF) {
			if (strcmp(e.id, id) == 0) {  
				tr=1;
				return tr; 
			}
		}
	}
}

int verifier_ets(char *id, char *mdp) {
    FILE *f;
    int userExists = 0;
    char test_id[50], test_mdp[50];

    f = fopen("user1.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s\n", test_id, test_mdp) != EOF) {
            if (strcmp(test_id, id) == 0 && strcmp(test_mdp, mdp) == 0) {
                userExists = 2;
                break;
            }
        }
        fclose(f);
    } 
    else {
        printf("Error: Could not open the file for reading.\n");
    }
    return userExists;
}
///////////////////////////
void swap_ets(ets *a, ets *b) {
    ets temp = *a;
    *a = *b;
    *b = temp;
}

int partition(ets arr[], int low, int high) {
    int pivot = arr[high].ca; // Choose the pivot as the last element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j].ca <= pivot) {
            i++;
            swap_ets(&arr[i], &arr[j]); // Use the modified swap_ets function
        }
    }
    swap_ets(&arr[i + 1], &arr[high]); // Use the modified swap_ets function
    return (i + 1);
}

void quickSort(ets arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
/////////////////////////
void capacite_cori() {
    FILE *f;
    FILE *f1;
    ets e;
    ets arr[1000];
    int j;
    f = fopen("etablissement.txt", "r");
    f1 = fopen("croi.txt", "w");
    if (f != NULL && f1 != NULL) {
        int i = 0;
        while (fscanf(f, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, &e.ca) != EOF) {
            arr[i] = e;
            i++;
        }
        int n = i; // Number of elements read, instead of using sizeof(arr) / sizeof(arr[0])
        quickSort(arr, 0, n - 1);
        for (j = 0; j < n; j++) {
            fprintf(f1, "%s %s %s %s %s %d \n", arr[j].id, arr[j].reg, arr[j].adr, arr[j].idr, arr[j].ct, arr[j].ca);
        }
        fclose(f); // Close files after usage
        fclose(f1);
    } else {
        printf("Failed to open files.\n");
    }
}
////////////////////////
void afficher_ets_croi(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
	char id[20];
	char reg[20];
	char adr[20];
	char idr[20];
	char ct[20];
	char ca [20];
    file = fopen("croi.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    	while (fscanf(file,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF) {
	
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID_ETS, id, REGION, reg, ADRESSE_ETS, adr, ID_Resp, idr, CONTACT, ct, CAPACITE, ca,-1);
     }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, " ID RTS ");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ID_ETS);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 100);
        

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "REGION");
       gtk_tree_view_column_add_attribute(column, renderer, "text", REGION);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);


   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ADRESSE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ADRESSE_ETS);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);



       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ID RESPONSABLE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ID_Resp);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CONTACT");
       gtk_tree_view_column_add_attribute(column, renderer, "text",CONTACT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CAPACITE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", CAPACITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);


       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}
/////////////////////////////
void swap_ets1(ets *a, ets *b) {
    ets temp = *a;
    *a = *b;
    *b = temp;
}
int partition1(ets arr[], int low, int high) {
    int pivot = arr[high].ca; // Choose the pivot as the last element
    int i = (low - 1); // Index of smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j].ca >= pivot) {
            i++;
            swap_ets1(&arr[i], &arr[j]); // Use the modified swap_ets function
        }
    }
    swap_ets1(&arr[i + 1], &arr[high]); // Use the modified swap_ets function
    return (i + 1);
}

void quickSort1(ets arr[], int low, int high) {
    if (low < high) {
        // Partitioning index
        int pi = partition1(arr, low, high);

        // Sort elements before and after partition
        quickSort1(arr, low, pi - 1);
        quickSort1(arr, pi + 1, high);
    }
}

void capacite_decori() {
    FILE *f;
    FILE *f1;
    ets e;
    ets arr[1000];
    int j;
    f = fopen("etablissement.txt", "r");
    f1 = fopen("decroi.txt", "w");
    if (f != NULL && f1 != NULL) {
        int i = 0;
        while (fscanf(f, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, &e.ca) != EOF) {
            arr[i] = e;
            i++;
        }
        int n = i; // Number of elements read, instead of using sizeof(arr) / sizeof(arr[0])
        quickSort1(arr, 0, n - 1);
        for (j = 0; j < n; j++) {
            fprintf(f1, "%s %s %s %s %s %d \n", arr[j].id, arr[j].reg, arr[j].adr, arr[j].idr, arr[j].ct, arr[j].ca);
        }
        fclose(f); // Close files after usage
        fclose(f1);
    } else {
        printf("Failed to open files.\n");
    }
}

void afficher_ets_decroi(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
	char id[20];
	char reg[20];
	char adr[20];
	char idr[20];
	char ct[20];
	char ca [20];
    file = fopen("decroi.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    	while (fscanf(file,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF) {
	
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID_ETS, id, REGION, reg, ADRESSE_ETS, adr, ID_Resp, idr, CONTACT, ct, CAPACITE, ca,-1);
     }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, " ID RTS ");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ID_ETS);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 100);
        

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "REGION");
       gtk_tree_view_column_add_attribute(column, renderer, "text", REGION);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);


   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ADRESSE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ADRESSE_ETS);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);



       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ID RESPONSABLE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ID_Resp);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CONTACT");
       gtk_tree_view_column_add_attribute(column, renderer, "text",CONTACT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CAPACITE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", CAPACITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);


       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}

void region1(char region[])
{
    FILE *f;
    FILE *f1;
    ets e;
    int j;
    f = fopen("etablissement.txt", "r");
    f1 = fopen("region.txt", "w");
    if (f != NULL && f1 != NULL) {
        int i = 0;
        while (fscanf(f, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, &e.ca) != EOF) {
		if (strcmp(e.reg,region)==0){
			fprintf(f1, "%s %s %s %s %s %d \n", e.id, e.reg, e.adr, e.idr, e.ct, e.ca);
		}
        }
    }
    fclose(f1);
    fclose(f);
}
void afficher_region1(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
	char id[20];
	char reg[20];
	char adr[20];
	char idr[20];
	char ct[20];
	char ca [20];
    file = fopen("region.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    	while (fscanf(file,"%s %s %s %s %s %s\n",id,reg,adr,idr,ct,ca)!=EOF) {
	
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID_ETS, id, REGION, reg, ADRESSE_ETS, adr, ID_Resp, idr, CONTACT, ct, CAPACITE, ca,-1);
     }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, " ID RTS ");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ID_ETS);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 100);
        

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "REGION");
       gtk_tree_view_column_add_attribute(column, renderer, "text", REGION);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);


   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ADRESSE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ADRESSE_ETS);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);



       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ID RESPONSABLE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ID_Resp);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CONTACT");
       gtk_tree_view_column_add_attribute(column, renderer, "text",CONTACT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "CAPACITE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", CAPACITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);


       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}


