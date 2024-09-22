#include "donneur.h"
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include<gtk/gtk.h>
#include"rdv.h"

enum
{
	ID,
	NOM,
	PRENOM,
	DATE_DE_PRELEVEMENT,
	HEURE_DE_PRELEVEMENT,
	TYPE_TRANSFUSION,
	IDETS,
	COLUMNS
};

int modifier_donneur(char id[],donneur nouv)
{
int tr=0;
donneur d;
FILE * f=fopen("donneur.txt","r");
FILE * f1=fopen("nouv.txt","w");
if(f!=NULL && f1!=NULL)
{
	while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!= EOF)
	{
		if(strcmp(d.id,id)==0){
			fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",nouv.id,nouv.nom,nouv.prenom,nouv.date_de_prelevement.jour,nouv.date_de_prelevement.mois,nouv.date_de_prelevement.annee,nouv.heure_prelevement,nouv.type_transfusion,nouv.idets);
			tr=1;
		}
		else{
			fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets);
		}
	}
	fclose(f);
	fclose(f1);
	remove("donneur.txt");
	rename("nouv.txt","donneur.txt");
	return tr;
}
}
//////////ajouter donneur//////////////////////////////////////
int ajouter_donneur(donneur d , char filename [])
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets);
        fclose(f);
        return 1;
    }
    else return 0;
}
/////////////////supprimer donneur///////////////////////////////
int supprimer_donneur(char id[])
{
int tr=0;
donneur d;
    FILE * f=fopen("donneur.txt", "a+");
    FILE * f1 =fopen("aux.tmp", "w");
    
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF)
{
if(strcmp(id,d.id)==0){
	tr=1;
}
else{
        fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets);

}
}
        fclose(f);
        fclose(f1);
remove("donneur.txt");
rename("aux.tmp", "donneur.txt");
return tr;
        
    
}
//////////////////////////////chercher donneur////////////////////////////
donneur chercher_donneur(char x[],char *filename)
{
donneur d; 
FILE * f=fopen(filename, "r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF){
	if(strcmp(x,d.id)==0)
	{
		return d;
		break;
	}
	else
	{
		strcpy(d.id, "-1");
	}
}
fclose(f);
}
return d;
}

///////////////////////////heure donneur//////////////////////////////



void heure_donneur(int heure,char msg[])
{
if(heure==1)
strcpy(msg,"Matin");
else if(heure==2)
strcpy(msg,"Apres-midi");
}

void type_de_transfusion (int x , char tt[]){
	if (x==1)
		strcpy(tt,"Sang");
	if (x==2)
		strcpy(tt,"Plasma");
	if (x==3)
		strcpy(tt,"Plaquette");

}





////////////afficher donneur //////////////
void Afficher_Donneurs(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
    char Date[100];
    char Date_de_prelevement_jour[10];
    char Date_de_prelevement_mois[10];
    char Date_de_prelevement_annee[10];
    char heure[20];
    char nom[20];
    char prenom [20];
    char id[20];
    char type_transfusion[30];
    char idets[20];
    file = fopen("donneur.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    	while(fscanf(file,"%s %s %s %s %s %s %s %s %s\n",id,nom,prenom,Date_de_prelevement_jour,Date_de_prelevement_mois,Date_de_prelevement_annee,heure,type_transfusion,idets)!=EOF) {
	
	memset(Date, 0, sizeof(Date));

        strcat(Date, Date_de_prelevement_jour);
        strcat(Date, " / ");
        strcat(Date, Date_de_prelevement_mois);
        strcat(Date, " / ");
        strcat(Date, Date_de_prelevement_annee);
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, ID,id, NOM, nom, PRENOM, prenom,DATE_DE_PRELEVEMENT, Date, HEURE_DE_PRELEVEMENT, heure, TYPE_TRANSFUSION, type_transfusion, IDETS, idets,-1);
     }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, " ID ");
        gtk_tree_view_column_add_attribute(column, renderer, "text", ID);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 100);
        
   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "NOM");
       gtk_tree_view_column_add_attribute(column, renderer, "text", NOM);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 160);


       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "PRENOM");
       gtk_tree_view_column_add_attribute(column, renderer, "text", PRENOM);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "DATE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", DATE_DE_PRELEVEMENT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "HEURE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", HEURE_DE_PRELEVEMENT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "TYPE TRANSFUSION");
       gtk_tree_view_column_add_attribute(column, renderer, "text", TYPE_TRANSFUSION);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 180);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "IDETS");
       gtk_tree_view_column_add_attribute(column, renderer, "text", IDETS);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 100);


       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}


//////////////////////////moy rdv par jour//////////////////
int nbETS(char nomFichier[]) {
	rdv r;
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        return 0;  
    }
    int nombreETS = 0;
    while (fscanf(f,"%s %s %s %s %d %d %d %s\n", r.id, r.nom, r.prenom,r.etablissement, &r.nouvelle_don.jn, &r.nouvelle_don.mn, &r.nouvelle_don.an,r.sexe)!=EOF) {
        nombreETS++;
    }
	fclose(f);
    return nombreETS;
}


float moyRDV_ETS(char nomFichier[], int jour, int mois, int annee) {

    int nombreETS = nbETS(nomFichier);
	rdv r;
    if (nombreETS == 0.0) {
   
        return -1.0; 
    }
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        
        return -1.0; 
    }
    int nombreTotalRDVs = 0;
    while (fscanf(f,"%s %s %s %s %d %d %d %s\n", r.id, r.nom, r.prenom,r.etablissement, &r.nouvelle_don.jn, &r.nouvelle_don.mn, &r.nouvelle_don.an,r.sexe)!=EOF) {
        if (r.nouvelle_don.jn == jour && r.nouvelle_don.mn == mois && r.nouvelle_don.an == annee) {
            nombreTotalRDVs++;
        }
    }       
    fclose(f);
    float moyenneRDVs = ((float)nombreTotalRDVs / nombreETS)*100;
    return moyenneRDVs;
}

////////////////////////////rdv par jour dans un ets////////
int listeRDV(char nomFichier[], char ETS[], int jour, int mois, int annee) {
    rdv r;
    FILE *f = fopen(nomFichier, "r");
   
   
    if (f == NULL) {
       
        return -1;  
    }

    
    FILE *fichierResultat = fopen("resultat.txt", "w");
   
    if (fichierResultat == NULL) {
       
        fclose(f);
        return -1;  
    }

    
    int nombreRDVs = 0;
    while (fscanf(f,"%s %s %s %s %d %d %d %s\n", r.id, r.nom, r.prenom,r.etablissement, &r.nouvelle_don.jn, &r.nouvelle_don.mn, &r.nouvelle_don.an,r.sexe)!=EOF) {

            if (strcmp(r.etablissement,ETS)==0 && r.nouvelle_don.jn == jour && r.nouvelle_don.mn == mois && r.nouvelle_don.an == annee){
                nombreRDVs++;
            }
    }

  
    fclose(f);
    fclose(fichierResultat);


    return nombreRDVs;
}


/////////////////verfifier existance/////////////////////:
int verifier_existant_donneur(char id[])
{
  int verif =0;
  donneur tableau[100];
  donneur d;
  FILE *f;
  int nbline=0, i=0;
  f= fopen("donneur.txt","r");
  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF)
      {
        nbline ++;
        tableau[i]=d;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(id, tableau[i].id) == 0)
        {
          verif = 1; //Existant
        }
    }
  return verif;
}

/////////////////////////////////////////
int trouvertype5(char id[]){
    donneur d;
    FILE *f;
    int i;
    f = fopen("donneur.txt", "r");
    char type[3][20]={"Sang","Plasma","Plaquette"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF) {
		if (strcmp(d.id, id) == 0) {
			for(i=0;i<3;i++){
				if(strcmp(d.type_transfusion,type[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return (-1);
}

int trouverjour5(char id[]){
    donneur d;
    FILE *f;
    int i;
    f = fopen("donneur.txt", "r");
    char jours[31][4] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF) {
		if (strcmp(d.id, id) == 0) {
			for(int i=0;i<31;i++){
				if(strcmp(d.date_de_prelevement.jour,jours[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}
int trouvermois5(char id[]){
    donneur d;
    FILE *f;
    int i;
    f = fopen("donneur.txt", "r");
    char mois[12][4] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF) {
		if (strcmp(d.id, id) == 0) {
			for(int i=0;i<12;i++){
				if(strcmp(d.date_de_prelevement.mois,mois[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}
int trouverannee5(char id[]){
    donneur d;
    FILE *f;
    int i;
    f = fopen("donneur.txt", "r");
    char annees[32][5] = {"2000","2001","2002","2003","2004","2005","2006","2007","2008","2009","2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027","2028","2029","2030"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF) {
		if (strcmp(d.id, id) == 0) {
			for(int i=0;i<31;i++){
				if(strcmp(d.date_de_prelevement.annee,annees[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}

int chercher_donneur01(char x[],char * filename)
{
donneur d; 
    FILE * f=fopen(filename, "r");
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF){
	if(strcmp(x,d.id)==0){
		return 1;
	}
	else{
		return 0;
	}
}
fclose(f);
}

}

int trouverheure(char id[]){
    donneur d;
    FILE *f;
    int i;
    f = fopen("donneur.txt", "r");
    char heure[2][30]={"Matin","Apres-midi"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",d.id,d.nom,d.prenom,d.date_de_prelevement.jour,d.date_de_prelevement.mois,d.date_de_prelevement.annee,d.heure_prelevement,d.type_transfusion,d.idets)!=EOF) {
		if (strcmp(d.id, id) == 0) {
			for(i=0;i<2;i++){
				if(strcmp(d.heure_prelevement,heure[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return (-1);
}

int verifier_inf(char *id, char *mdp) {
    FILE *f;
    int userExists = 0;
    char test_id[50], test_mdp[50];

    f = fopen("user2.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s\n", test_id, test_mdp) != EOF) {
            if (strcmp(test_id, id) == 0 && strcmp(test_mdp, mdp) == 0) {
                userExists = 3;
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


