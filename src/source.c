#include<string.h>
#include<stdio.h>
#include<gtk/gtk.h>
#include"source.h"
#include "Don.h"
enum {
	TYPE,
	QUANTITE,
	COLUMNS
};
void Afficher_type_sang(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
    char type[10];
    int quantite;
    char strqte[10];
    file = fopen("output.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING);

    while (fscanf(file, "%s %d\n", type, &quantite) != EOF) {
	sprintf(strqte , "%d", quantite);
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, TYPE, type, QUANTITE, strqte,-1);
    }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, "Type DE Sang");
        gtk_tree_view_column_add_attribute(column, renderer, "text", TYPE);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 200);
        
   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "QUANTITE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", QUANTITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);


       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}

int verifier_existant_don(char code[])
{
  int verif =-1;
  Don tableau[1000];
  Don d;
  FILE *f;
  int nbline=0, i=0;
  f= fopen("Dons.txt","r");
  if (f != NULL)
     {
      while (fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",d.code_de_don,d.Identifiant_du_donneur,d.Type_de_sang,&d.quantite_de_prelevement,d.Date_de_prelevement.jour,d.Date_de_prelevement.mois,d.Date_de_prelevement.annee,d.gouvernerat,d.adresse,d.idets)!=EOF)
      {
        nbline ++;
        tableau[i]=d;
        i++;
      }
      fclose(f);
    }
  for (i =0; i<nbline; i++)
    {
      if (strcmp(code, tableau[i].code_de_don) == 0)
        {
          verif = 0; 
          break;
        }
      else
      {
        verif =1;
      }
    }
  return verif;
}
int trouverregion(char code_de_don[]){
    int i;
    FILE *f;
    Don D;
    f = fopen("Dons.txt", "r");
    char reg[24][30]={"Ariana","Beja","Ben_Arous","Bizerte","Gabes","Gafsa","Jendouba","Kairouan","Kasserine",
"Kebili","Kef","Mahdia","Manouba","Medenine","Monastir","Nabeul","Sfax","Sidi_Bouzid","Siliana","Sousse","Tataouine","Tozeur","Tunis","Zaghouan"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF) {
		if (strcmp(D.code_de_don, code_de_don) == 0) {
			for(int i=0;i<24;i++){
				if(strcmp(D.gouvernerat,reg[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}
Don chercher01(char *filename, char *code_de_don)
{
    Don D;
    int tr=0;
    FILE * f=fopen("Dons.txt", "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s \n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF)
        {
            if (strcmp(D.code_de_don,code_de_don) == 0)
		{
                	tr=1;
			return D;
                	break;
		}
	    
	    else
		{
			strcpy(D.code_de_don,"-1");
                }
	}
    fclose(f);
    }
return D;
}

int trouvertype(char code_de_don[]){
    Don D;
    FILE *f;
    int i;
    f = fopen("Dons.txt", "r");
    char type[8][4]={"A+","A-","B+","B-","AB+","AB-","O+","O-"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF) {
		if (strcmp(D.code_de_don, code_de_don) == 0) {
			for(i=0;i<8;i++){
				if(strcmp(D.Type_de_sang,type[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return (-1);
}

int trouverjour(char code_de_don[]){
    Don D;
    FILE *f;
    int i;
    f = fopen("Dons.txt", "r");
    char jours[31][4] = {"01","02","03","04","05","06","07","08","09","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30","31"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF) {
		if (strcmp(D.code_de_don, code_de_don) == 0) {
			for(int i=0;i<31;i++){
				if(strcmp(D.Date_de_prelevement.jour,jours[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}
int trouvermois(char code_de_don[]){
    Don D;
    FILE *f;
    int i;
    f = fopen("Dons.txt", "r");
    char mois[12][4] = {"01","02","03","04","05","06","07","08","09","10","11","12"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF) {
		if (strcmp(D.code_de_don, code_de_don) == 0) {
			for(int i=0;i<12;i++){
				if(strcmp(D.Date_de_prelevement.mois,mois[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}
int trouverannee(char code_de_don[]){
    Don D;
    FILE *f;
    int i;
    f = fopen("Dons.txt", "r");
    char annees[32][5] = {"2000","2001","2002","2003","2004","2005","2006","2007","2008","2009","2010","2011","2012","2013","2014","2015","2016","2017","2018","2019","2020","2021","2022","2023","2024","2025","2026","2027","2028","2029","2030"};
    if (f == NULL) {
                printf("Error opening file for verification.\n");
    }
    else{
	    while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF) {
		if (strcmp(D.code_de_don, code_de_don) == 0) {
			for(int i=0;i<31;i++){
				if(strcmp(D.Date_de_prelevement.annee,annees[i])==0)
					return i;
			}
		}
			

	}
    	fclose(f);
    }
return -1;
}

