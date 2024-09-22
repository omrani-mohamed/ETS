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
	ETABLISSEMENT,
	JOUR,
	MOIS,
	ANNEE,
	SEXE,
	COLUMNS
};
void afficher_rdv(GtkWidget *liste,char j[],char m[],char a[],char etab[])
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
GtkTreeModel *model;
char id[20];
char nom[20];
char prenom [20];
char etablissement[20];
char sexe[20];
char jour[20];
char mois[20];
char annee[20];
rdv r;
char jj[20];
sprintf(jj,"%d",r.nouvelle_don.jn);
char mm[20];
sprintf(mm,"%d",r.nouvelle_don.mn);
char aa[20];
sprintf(aa,"%d",r.nouvelle_don.an);
/*int jj=atoi(j);
int mm=atoi(m);
int aa=atoi(a);*/

store=NULL;
FILE *f;
model=gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
store=GTK_LIST_STORE(model);
if(store==NULL)
{
 renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("NOM",renderer,"text",NOM,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("PRENOM",renderer,"text",PRENOM,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("ETABLISSEMENT",renderer,"text",ETABLISSEMENT,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("JOUR",renderer,"text",JOUR,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("MOIS",renderer,"text",MOIS,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("ANNEE",renderer,"text",ANNEE,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new ();
 column = gtk_tree_view_column_new_with_attributes("SEXE",renderer,"text",SEXE,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("rdv.txt","r");
if(f==NULL)
{
return;
}
else
(f=fopen("rdv.txt","a+"));
	
	while(fscanf(f,"%s %s %s %s %s %s %s %s\n",r.id,r.nom, r.prenom,r.etablissement,jj,mm,aa,r.sexe)!=EOF)
{if((strcmp(j,jj)==0)&&(strcmp(m,mm)==0)&&(strcmp(a,aa)==0)&&(strcmp(etab,r.etablissement)==0)) 
{gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,ID,r.id,NOM,r.nom,PRENOM,r.prenom,ETABLISSEMENT,r.etablissement,JOUR,jj,MOIS,mm,ANNEE,aa,SEXE,r.sexe,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);
}
} 
//////////////////////////CHERCHER RDV//////////////////
rdv chercher_rdv(char etablissement[],int j,int m,int a,char * filename)
{
rdv r; 
    FILE * f=fopen(filename, "r");
    /*int j=atoi(jour);
    int m=atoi(mois);
    int a=atoi(annee);*/
    
 if(f!=NULL )
    {
while(fscanf(f,"%s %s %s %s %d %d %d %s\n", r.id, r.nom, r.prenom,r.etablissement, &r.nouvelle_don.jn, &r.nouvelle_don.mn, &r.nouvelle_don.an,r.sexe)!=EOF)
{if((strcmp(etablissement,r.etablissement)==0)&&(j==r.nouvelle_don.jn)&&(m==r.nouvelle_don.mn)&&(a==r.nouvelle_don.an)){  
return r;
}
}
fclose(f);
}
strcpy(r.etablissement, "-1");
  return r;

}

