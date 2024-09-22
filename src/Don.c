#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<gtk/gtk.h>
#include"source.h"
#include "Don.h"
enum
{
	CODE_DE_DON,
	IDENTIFIANT_DU_DONNEUR,
	TYPE_DE_SANG,
	QUANTITE,
	DATE,
	GOUVERNERAT,
	ADRESSE,
	IDETS,
	COLUMNS
};
int ajouter(char *filename, Don D)
{
    FILE *f = fopen("Dons.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %s %s %s %s %s %s \n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets);
        fclose(f);
        return 1;
    }
    else return 0;
}

void Afficher_Dons(GtkTreeView *treeview) {
    GtkListStore *store;
    FILE *file;
    char Date[100];
    char Date_de_prelevement_jour[10];
    char Date_de_prelevement_mois[10];
    char Date_de_prelevement_annee[10];
    char Quantite[20];
    char code_de_don[20];
    char Identifiant_du_donneur[20];
    char Type_de_sang[10];
    int quantite_de_prelevement;
    char gouvernerat[30];
    char adresse[100];
    char idets[50];
    file = fopen("Dons.txt", "r");
    if (!file) {
        return;
    }

    store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

    	while(fscanf(file,"%s %s %s %d %s %s %s %s %s %s\n",code_de_don,Identifiant_du_donneur,Type_de_sang,&quantite_de_prelevement,Date_de_prelevement_jour,Date_de_prelevement_mois,Date_de_prelevement_annee,gouvernerat,adresse,idets)!=EOF) {
	sprintf(Quantite , "%d", quantite_de_prelevement);
	memset(Date, 0, sizeof(Date));

        strcat(Date, Date_de_prelevement_jour);
        strcat(Date, " / ");
        strcat(Date, Date_de_prelevement_mois);
        strcat(Date, " / ");
        strcat(Date, Date_de_prelevement_annee);
        GtkTreeIter iter;
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, CODE_DE_DON, code_de_don, IDENTIFIANT_DU_DONNEUR, Identifiant_du_donneur, TYPE_DE_SANG, Type_de_sang,QUANTITE, Quantite, DATE, Date, GOUVERNERAT, gouvernerat, ADRESSE, adresse, IDETS, idets,-1);
     }

    fclose(file);

    GtkTreeModel *model = GTK_TREE_MODEL(store);

    if (gtk_tree_view_get_columns(GTK_TREE_VIEW(treeview)) == 0) {
        GtkTreeViewColumn *column;
        GtkCellRenderer *renderer;

        column = gtk_tree_view_column_new();
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(column, renderer, TRUE);
        gtk_tree_view_column_set_title(column, " Code ");
        gtk_tree_view_column_add_attribute(column, renderer, "text", CODE_DE_DON);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
        gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
        gtk_tree_view_column_set_fixed_width(column, 100);
        
   
       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Identifiant du donneur");
       gtk_tree_view_column_add_attribute(column, renderer, "text", IDENTIFIANT_DU_DONNEUR);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 160);


       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "Type de sang");
       gtk_tree_view_column_add_attribute(column, renderer, "text", TYPE_DE_SANG);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "QUANTITE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", QUANTITE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 100);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "DATE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", DATE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "GOUVERNERAT");
       gtk_tree_view_column_add_attribute(column, renderer, "text", GOUVERNERAT);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 120);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ADRESSE");
       gtk_tree_view_column_add_attribute(column, renderer, "text", ADRESSE);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 200);

       column = gtk_tree_view_column_new();
       renderer = gtk_cell_renderer_text_new();
       gtk_tree_view_column_pack_start(column, renderer, TRUE);
       gtk_tree_view_column_set_title(column, "ID ETS");
       gtk_tree_view_column_add_attribute(column, renderer, "text", IDETS);
       gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), column);
       gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
       gtk_tree_view_column_set_fixed_width(column, 80);

       gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);

    } 
    else {
        gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), model);
    }

    g_object_unref(store);
}

int modifier(char *filename, char *code_de_don, Don d3){
    int tr=0;
    Don D;
    FILE * f=fopen("Dons.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF)
        {
            if (strcmp(D.code_de_don,code_de_don) == 0)
            {
                    fprintf(f2, "%s %s %s %d %s %s %s %s %s %s\n",d3.code_de_don,d3.Identifiant_du_donneur,d3.Type_de_sang,d3.quantite_de_prelevement,d3.Date_de_prelevement.jour,d3.Date_de_prelevement.mois,d3.Date_de_prelevement.annee,d3.gouvernerat,d3.adresse,d3.idets);

                    tr=1;
            }
            else
	    {
                fprintf(f2,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets);

	    }
	}
    fclose(f);
    fclose(f2);
    remove("Dons.txt");
    rename("nouv.txt", "Dons.txt");
    return tr;
    }

}

int supprimer(char *filename, char *code_de_don)
{
    int tr=0;
    Don D;
    FILE * f=fopen("Dons.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s \n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF)
        {
            if (strcmp(D.code_de_don,code_de_don) == 0)
	    {
                tr=1;
	    }
            else
	    {
                fprintf(f2,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets);
            }
        }        
    fclose(f);
    fclose(f2);
    remove("Dons.txt");
    rename("nouv.txt", "Dons.txt");
    return tr;
    }
}
int chercher(char *filename, char *code_de_don)
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
                	break;
		}
        }
    fclose(f);
    return tr;
    }
}
int quantite_type(char nomFichier[], char type_sang[]){
	FILE *f = fopen("Dons.txt", "r");
	int q;
	Don D;
    	if(f!=NULL){
			q=0;
		        while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF)
			{
				if (strcmp(type_sang,D.Type_de_sang)==0){
					q+=D.quantite_de_prelevement;
				}
			}
			return q;
	}
}
char* sang_rare(char nomFichier[], char* resultType){
	char T[8][4]={"AB+","AB-","A+","A-","B+","B-","O+","O-"};
	int T1[8]={0,0,0,0,0,0,0,0};
	Type_Qte tab[10];
	int i,min,min_i,k;

	for (i=0;i<8;i++){
		T1[i]=quantite_type("Dons.txt",T[i]);
	}

	min=T1[0];
	for (i=0;i<8;i++){
		if (T1[i] <= min){
			min=T1[i];
			min_i=i;
		}
	}
	strcpy(resultType, T[min_i]);
	Don D;
	Type_Qte TQ;
	for(i=0;i<8;i++){
		strcpy(TQ.type_sang,T[i]);
		TQ.qte=T1[i];
		tab[i]=TQ;
	}

	FILE *f1 = fopen("output.txt", "w");		
	if(f1!=NULL){
		for(i=0;i<8;i++){
			fprintf(f1,"%s %d\n",tab[i].type_sang,tab[i].qte);
		}
	fclose(f1);
	}
	
	return resultType;
}
int verifier(char *id, char *mdp) {
    FILE *f;
    int userExists = 0;
    char test_id[50], test_mdp[50];

    f = fopen("user.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s\n", test_id, test_mdp) != EOF) {
            if (strcmp(test_id, id) == 0 && strcmp(test_mdp, mdp) == 0) {
                userExists = 1;
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

void type_de_sang (int x , char ts[]){
	if (x==1)
		strcpy(ts,"A+");
	if (x==2)
		strcpy(ts,"A-");
	if (x==3)
		strcpy(ts,"B+");
	if (x==4)
		strcpy(ts,"B-");
	if (x==5)
		strcpy(ts,"AB+");
	if (x==6)
		strcpy(ts,"AB-");
	if (x==7)
		strcpy(ts,"O+");
	if (x==8)
		strcpy(ts,"O-");
}
int verifier_id(char *code_don) {
    FILE *f;
    int codeExists = 0;
    char test_code_don[50];
    Don D;
    f = fopen("Dons.txt", "r");
    if (f != NULL) {
        while(fscanf(f,"%s %s %s %d %s %s %s %s %s %s\n",D.code_de_don,D.Identifiant_du_donneur,D.Type_de_sang,&D.quantite_de_prelevement,D.Date_de_prelevement.jour,D.Date_de_prelevement.mois,D.Date_de_prelevement.annee,D.gouvernerat,D.adresse,D.idets)!=EOF) {
            if (strcmp(test_code_don,D.code_de_don) == 0) {
                codeExists = 1;
                break;
            }
        }
        fclose(f);
    } 
    return codeExists;
}
int verifier01(char *id, char *mdp) {
    FILE *f;
    int length = 1;
    char test_id[50], test_mdp[50];

    f = fopen("user.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s\n", test_id, test_mdp) != EOF) {
	    if (strcmp(test_id,"") ==0 && strcmp(test_mdp,"")==0){
	    	length = 0;
		break;
	     }
        }
        fclose(f);
    } 
    else {
        printf("Error: Could not open the file for reading.\n");
    }
    return length;
}




