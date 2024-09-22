#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "Don.h"
#include "source.h"
#include "source_ets.h"
#include "donneur.h"
#include "rdv.h"

int x=0;
int c=0;
int a=0;
int s=0;
int v,y,R;
int nn;
char reg[20]="";
int a2=0;
int c2=0;
int s2=0;
int choix=3;
int x1=0;
int heure=0;
int a1=0;
int c1=0;
int s1=0;
void
on_esp_pro_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *acceuil;
GtkWidget *Authentification_;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
acceuil =lookup_widget(objet_graphique, "acceuil");
if (acceuil != NULL) {
	gtk_widget_hide(acceuil);
}
}

void
on_esp_donneur_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}


void
on_connect_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int result;
int result01;
int result02;
int result03;
GtkWidget *msgsucc;
GtkWidget *Authentification_  = GTK_WIDGET(user_data);
GtkWidget *Espace_Med_ = GTK_WIDGET(user_data);
GtkWidget *Espaces_Admin_ETS = GTK_WIDGET(user_data);
GtkWidget *Espace_infirmier = GTK_WIDGET(user_data);
GtkWidget *entry1 = lookup_widget(objet_graphique, "entry1");
GtkWidget *entry2 = lookup_widget(objet_graphique, "entry2");
GtkWidget *output_connect = lookup_widget(objet_graphique, "output_connect");
char id[50],mdp[50];
strcpy(id , gtk_entry_get_text(GTK_ENTRY(entry1)));
strcpy(mdp , gtk_entry_get_text(GTK_ENTRY(entry2)));
result = verifier(id, mdp);
result01 = verifier01(id, mdp);
result02 = verifier_ets(id, mdp);
result03 = verifier_inf(id, mdp);
if (result01==0) {
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Entrer Votre ID et Mot De Passe, D'abord. Puis, Reessayer");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
else if (result==1) {
	Espace_Med_ = create_Espace_Med_ ();
    	gtk_widget_show (Espace_Med_);
	Authentification_ = lookup_widget(objet_graphique, "Authentification_");
        if (Authentification_ != NULL) {
                gtk_widget_hide(Authentification_);
	}
} 
else if (result02==2) {
	Espaces_Admin_ETS = create_Espaces_Admin_ETS ();
    	gtk_widget_show (Espaces_Admin_ETS);
	Authentification_ = lookup_widget(objet_graphique, "Authentification_");
        if (Authentification_ != NULL) {
                gtk_widget_hide(Authentification_);
	}
} 
else if (result03==3) {
	Espace_infirmier = create_Espace_infirmier ();
    	gtk_widget_show (Espace_infirmier);
	Authentification_ = lookup_widget(objet_graphique, "Authentification_");
        if (Authentification_ != NULL) {
                gtk_widget_hide(Authentification_);
	}
} 
else {
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"L'Utilisateur n'existe pas.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
}


void
on_Ret_Aut_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *acceuil;
GtkWidget *Authentification_;
acceuil= create_acceuil();
gtk_widget_show (acceuil);
Authentification_ =lookup_widget(objet_graphique, "Authentification_");
if (Authentification_ != NULL) {
	gtk_widget_hide(Authentification_);
}
}


void
on_Esp_Med_decon_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Med_;
GtkWidget *Authentification_;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
Espace_Med_ =lookup_widget(objet_graphique, "Espace_Med_");
if (Espace_Med_ != NULL) {
	gtk_widget_hide(Espace_Med_);
}
}


void
on_Stat_1_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Med_;
GtkWidget *Statistique_1;
Statistique_1= create_Statistique_1();
gtk_widget_show (Statistique_1);
Espace_Med_ =lookup_widget(objet_graphique, "Espace_Med_");
if (Espace_Med_ != NULL) {
	gtk_widget_hide(Espace_Med_);
}
}


void
on_Stat_2_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *msgsucc;
char resultType[4];
GtkWidget *Espace_Med_;
GtkWidget *Statistique2;
Statistique2= create_Statistique2();
gtk_widget_show (Statistique2);
Espace_Med_ =lookup_widget(objet_graphique, "Espace_Med_");
if (Espace_Med_ != NULL) {
	gtk_widget_hide(Espace_Med_);
}
sang_rare("Don.txt", resultType);
GtkWidget *treeview1;
treeview1=lookup_widget(Statistique2, "treeview1");
Afficher_type_sang(treeview1);
msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Type du Sang le Plus Rare est : %s ",resultType);
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}


void
on_G_De_Don_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Med_;
GtkWidget *Gestion_De_Dons;
Gestion_De_Dons= create_Gestion_De_Dons();
gtk_widget_show (Gestion_De_Dons);
Espace_Med_ =lookup_widget(objet_graphique, "Espace_Med_");
if (Espace_Med_ != NULL) {
	gtk_widget_hide(Espace_Med_);
}
}


void
on_G_De_Don_Ret_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *Espace_Med_;
GtkWidget *Gestion_De_Dons;
Espace_Med_= create_Espace_Med_();
gtk_widget_show (Espace_Med_);
Gestion_De_Dons =lookup_widget(objet_graphique, "Gestion_De_Dons");
if (Gestion_De_Dons != NULL) {
	gtk_widget_hide(Gestion_De_Dons);
}

}


void
on_rechercher_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *msgsucc;
char code[20];
GtkWidget *entry3= lookup_widget(objet_graphique, "entry3");
strcpy(code , gtk_entry_get_text(GTK_ENTRY(entry3)));
r = chercher("Don.txt", code);
if (r==1){
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Un Don de ce Code existe.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
else{
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Don de ce Code n'existe pas.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
}


void
on_rech_afficher_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
Affichage= create_Affichage();
gtk_widget_show (Affichage);
GtkWidget *treeview2;
treeview2=lookup_widget(Affichage, "treeview2");
Afficher_Dons(treeview2);
}


void
on_Ajou_aff_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
Affichage= create_Affichage();
gtk_widget_show (Affichage);
GtkWidget *treeview2;
treeview2=lookup_widget(Affichage, "treeview2");
Afficher_Dons(treeview2);
}


void
on_Ajou_ajouter_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *msgsucc;
GtkWidget *entry4 = lookup_widget(objet_graphique, "entry4");
GtkWidget *entry5 = lookup_widget(objet_graphique, "entry5");
GtkWidget *entry6 = lookup_widget(objet_graphique, "entry6");
GtkWidget *entry7 = lookup_widget(objet_graphique, "entry7");
GtkWidget *Combobox1=lookup_widget(objet_graphique, "combobox1");
GtkWidget *comboboxentry1=lookup_widget(objet_graphique,"comboboxentry1");
GtkWidget *comboboxentry2=lookup_widget(objet_graphique,"comboboxentry2");
GtkWidget *comboboxentry3=lookup_widget(objet_graphique,"comboboxentry3");
GtkWidget *spinbutton1=lookup_widget(objet_graphique,"spinbutton1");
Don D;
int y,z=0;
char code_don[50];
strcpy(D.code_de_don , gtk_entry_get_text(GTK_ENTRY(entry4)));
strcpy(D.Identifiant_du_donneur , gtk_entry_get_text(GTK_ENTRY(entry5)));
strcpy(code_don, gtk_entry_get_text(GTK_ENTRY(entry4)));
type_de_sang(x,D.Type_de_sang);
D.quantite_de_prelevement=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton1));
strcpy(D.Date_de_prelevement.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
strcpy(D.Date_de_prelevement.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry2)));
strcpy(D.Date_de_prelevement.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry3)));
strcpy(D.gouvernerat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox1)));
strcpy(D.adresse , gtk_entry_get_text(GTK_ENTRY(entry6)));
strcpy(D.idets , gtk_entry_get_text(GTK_ENTRY(entry7)));
z=verifier_id(code_don);
if (a==1){
	if (z==1)
	{
		a=0;
		msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Ce code du Don exixte déja.Choisissez un autre code.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		a=0;
		y=ajouter("Dons.txt",D);
		if(y==1){
			msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ajout avec succes .");
			    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
			    {
			    case GTK_RESPONSE_OK:
			    gtk_widget_destroy(msgsucc);
			    break;
			    }
		}
	}
}
else{
	a=0;
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cocher ''continuer'' pour ajouter le Don");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
}


void
on_Mod_afficher_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
Affichage= create_Affichage();
gtk_widget_show (Affichage);
GtkWidget *treeview2;
treeview2=lookup_widget(Affichage, "treeview2");
Afficher_Dons(treeview2);

}


void
on_Mod_modifier_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char code[20];
int r;
Don D1;
GtkWidget *msgsucc;
GtkWidget *entry9,*entry10,*entry11,*entry12,*entry13;
GtkWidget *combobox3=lookup_widget (objet_graphique, "combobox3");
GtkWidget *combobox2=lookup_widget (objet_graphique, "combobox2");
GtkWidget *comboboxentry4=lookup_widget(objet_graphique,"comboboxentry4");
GtkWidget *comboboxentry5=lookup_widget(objet_graphique,"comboboxentry5");
GtkWidget *comboboxentry6=lookup_widget(objet_graphique,"comboboxentry6");
entry9=lookup_widget(objet_graphique,"entry9");
entry10=lookup_widget(objet_graphique,"entry10");
entry11=lookup_widget(objet_graphique,"entry11");
entry12=lookup_widget(objet_graphique,"entry12");
entry13=lookup_widget(objet_graphique, "entry13");
strcpy(D1.code_de_don , gtk_entry_get_text(GTK_ENTRY(entry9)));
strcpy(D1.Identifiant_du_donneur , gtk_entry_get_text(GTK_ENTRY(entry10)));
D1.quantite_de_prelevement=atoi(gtk_entry_get_text(GTK_ENTRY(entry11)));
strcpy(D1.Date_de_prelevement.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry4)));
strcpy(D1.Date_de_prelevement.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry5)));
strcpy(D1.Date_de_prelevement.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry6)));
strcpy(D1.gouvernerat,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
strcpy(D1.Type_de_sang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(D1.adresse , gtk_entry_get_text(GTK_ENTRY(entry12)));
strcpy(D1.idets , gtk_entry_get_text(GTK_ENTRY(entry13)));
GtkWidget *entry8= lookup_widget(objet_graphique, "entry8");
strcpy(code , gtk_entry_get_text(GTK_ENTRY(entry8)));
if (c==1){
	s=0;
	r = modifier("Dons.txt", code, D1);
	if (r==1){
		    c=0;
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Don est modifié avec succeé.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		    c=0;
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Echec De Modification");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
}
else{
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cocher ''Je Confirme Les Modifivation'' pour continuer.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}

}


void on_MOd_trouv_clicked(GtkWidget *objet_graphique, gpointer user_data) {
GtkWidget *msgsucc;
GtkWidget *entry8,*entry9,*entry10,*entry11,*entry12,*entry13,*combobox2,*combobox3,*comboboxentry4,*comboboxentry5,*comboboxentry6;
char code[20];
Don d;
int v;
entry8 = lookup_widget(objet_graphique,"entry8");
entry9=lookup_widget(objet_graphique,"entry9");
entry10=lookup_widget(objet_graphique,"entry10");
entry11=lookup_widget(objet_graphique,"entry11");
entry12= lookup_widget (objet_graphique,"entry12");
entry13= lookup_widget (objet_graphique,"entry13");
combobox2=lookup_widget(objet_graphique, "combobox2");
combobox3=lookup_widget(objet_graphique, "combobox3");
comboboxentry4=lookup_widget(objet_graphique, "comboboxentry4");
comboboxentry5=lookup_widget(objet_graphique, "comboboxentry5");
comboboxentry6=lookup_widget(objet_graphique, "comboboxentry6");
strcpy(code,gtk_entry_get_text(GTK_ENTRY(entry8)));
v=verifier_existant_don(code);
if ( v != 0){
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Code non existant.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
else{
strcpy(code,gtk_entry_get_text(GTK_ENTRY(entry8)));
d= chercher01("Dons.txt",code);
int i= trouvertype(code);
int k= trouverregion(code);
int j= trouverjour(code);
int m= trouvermois(code);
int y= trouverannee(code);
char qte[30];
sprintf(qte,"%d",d.quantite_de_prelevement);
gtk_entry_set_text (GTK_ENTRY (entry9),d.code_de_don);
gtk_entry_set_text (GTK_ENTRY (entry10),d.Identifiant_du_donneur);
gtk_entry_set_text (GTK_ENTRY (entry11),qte);
gtk_entry_set_text (GTK_ENTRY (entry12),d.adresse);
gtk_entry_set_text (GTK_ENTRY (entry13),d.idets);
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox2),(atoi(d.Type_de_sang)+i));
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox3),/*(atoi(d.gouvernerat)+*/k);
gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentry4),/*(atoi(d.Date_de_prelevement.jour)+*/j);
gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentry5),/*(atoi(d.Date_de_prelevement.mois)+*/m);
gtk_combo_box_set_active(GTK_COMBO_BOX(comboboxentry6),/*(atoi(d.Date_de_prelevement.annee)+*/y);
}


}

void
on_Sup_supprimer_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *msgsucc;
char code[20];
GtkWidget *entry14= lookup_widget(objet_graphique, "entry14");
strcpy(code , gtk_entry_get_text(GTK_ENTRY(entry14)));
if (s==1){
	s=0;
	r = supprimer("Dons.txt", code);
	if (r==1){
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Don est Supprimé.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Echec De Supprission, Verifier Le code Donné");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
}
else{
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Don n'a pas etait supprimer.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
}


void
on_Sup_afficher_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
Affichage= create_Affichage();
gtk_widget_show (Affichage);
GtkWidget *treeview2;
treeview2=lookup_widget(Affichage, "treeview2");
Afficher_Dons(treeview2);
}


void
on_G_De_Don_deconn_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Authentification_;
GtkWidget *Gestion_De_Dons;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
Gestion_De_Dons =lookup_widget(objet_graphique, "Gestion_De_Dons");
if (Gestion_De_Dons != NULL) {
	gtk_widget_hide(Gestion_De_Dons);
}
}


void
on_Stat2_Ret_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Med_;
GtkWidget *Statistique2;
Espace_Med_= create_Espace_Med_();
gtk_widget_show (Espace_Med_);
Statistique2 =lookup_widget(objet_graphique, "Statistique2");
if (Statistique2 != NULL) {
	gtk_widget_hide(Statistique2);
}
}

void
on_Stat1_ret_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_Med_;
GtkWidget *Statistique_1;
Espace_Med_= create_Espace_Med_();
gtk_widget_show (Espace_Med_);
Statistique_1 =lookup_widget(objet_graphique, "Statistique_1");
if (Statistique_1 != NULL) {
	gtk_widget_hide(Statistique_1);
}
}

void
on_Stat1_aff_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *msgsucc;
//GtkWidget *output_stat1;
char type_sang[10];
int qte;
char strqte[30];
GtkWidget *Combobox4=lookup_widget(objet_graphique, "combobox4");
strcpy(type_sang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(Combobox4)));
qte=quantite_type("Don.txt",type_sang);
sprintf(strqte , "%d", qte);
//gtk_label_set_text(GTK_LABEL(output_stat1),"la quantite est :");
msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"la Quantite Disponible de ce Type du Sang = %s ml",strqte);
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}

void
on_Aff_ret_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
Affichage =lookup_widget(objet_graphique, "Affichage");
if (Affichage != NULL) {
	gtk_widget_hide(Affichage);
}
}


void
on_Actualiser_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
Affichage= create_Affichage();
gtk_widget_show (Affichage);
Affichage =lookup_widget(objet_graphique, "Affichage");
if (Affichage != NULL) {
	gtk_widget_hide(Affichage);
}
GtkWidget *treeview2;
treeview2=lookup_widget(Affichage, "treeview2");
Afficher_Dons(treeview2);
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=1;
}

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=2;
}

}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=3;
}

}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=4;
}

}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=5;
}

}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=6;
}

}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=7;
}

}


void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	x=8;
}

}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
c=1;
}
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
a=1;
}
}


void
on_radiobutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
s=0;
}
}


void
on_radiobutton9_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if (gtk_toggle_button_get_active(togglebutton))
{
s=1;
}

}


void
on_Esp_Admin_ETS_ret_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espaces_Admin_ETS;
GtkWidget *Authentification_;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
Espaces_Admin_ETS =lookup_widget(objet_graphique, "Espaces_Admin_ETS");
if (Espaces_Admin_ETS != NULL) {
	gtk_widget_hide(Espaces_Admin_ETS);
}
}


void
on_Stat_des_ETS_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Statistiques;
GtkWidget *Espaces_Admin_ETS;
Statistiques= create_Statistiques();
gtk_widget_show (Statistiques);
Espaces_Admin_ETS =lookup_widget(objet_graphique, "Espaces_Admin_ETS");
if (Espaces_Admin_ETS != NULL) {
	gtk_widget_hide(Espaces_Admin_ETS);
}
}


void
on_Gestion_Des_ETS_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestions_De_ETS;
GtkWidget *Espaces_Admin_ETS;
Gestions_De_ETS= create_Gestions_De_ETS();
gtk_widget_show (Gestions_De_ETS);
Espaces_Admin_ETS =lookup_widget(objet_graphique, "Espaces_Admin_ETS");
if (Espaces_Admin_ETS != NULL) {
	gtk_widget_hide(Espaces_Admin_ETS);
}
}


void
on_G_DE_ETS_dec_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestions_De_ETS;
GtkWidget *Authentification_;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
Gestions_De_ETS =lookup_widget(objet_graphique, "Gestions_De_ETS");
if (Gestions_De_ETS != NULL) {
	gtk_widget_hide(Gestions_De_ETS);
}
}


void
on_G_De_ETS_ret_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestions_De_ETS;
GtkWidget *Espaces_Admin_ETS;
Espaces_Admin_ETS= create_Espaces_Admin_ETS();
gtk_widget_show (Espaces_Admin_ETS);
Gestions_De_ETS =lookup_widget(objet_graphique, "Gestions_De_ETS");
if (Gestions_De_ETS != NULL) {
	gtk_widget_hide(Gestions_De_ETS);
}
}


void
on_ETS_Aff_Afficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage_ETS;
Affichage_ETS= create_Affichage_ETS();
gtk_widget_show (Affichage_ETS);
GtkWidget *treeview_ETS;
treeview_ETS=lookup_widget(Affichage_ETS, "treeview_ETS");
afficher_ets(treeview_ETS);
}


void
on_ETS_Rech_Rechercher_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *msgsucc;
char id[20];
GtkWidget *inputets1= lookup_widget(objet_graphique, "inputets1");
strcpy(id , gtk_entry_get_text(GTK_ENTRY(inputets1)));
r = chercher_ets(id);
if (r==1){
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Un ets avec cet id existe.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
else{
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Cet id n'existe pas.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
}


void
on_ETS_Ajou_aff_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage_ETS;
Affichage_ETS= create_Affichage_ETS();
gtk_widget_show (Affichage_ETS);
GtkWidget *treeview_ETS;
treeview_ETS=lookup_widget(Affichage_ETS, "treeview_ETS");
afficher_ets(treeview_ETS);
}


void
on_ETS_Ajou_ajouter_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
ets e;
GtkWidget *msgsucc;
GtkWidget *inputets2 = lookup_widget(objet_graphique, "inputets2");
GtkWidget *inputets3 = lookup_widget(objet_graphique, "inputets3");
GtkWidget *inputets4 = lookup_widget(objet_graphique, "inputets4");
GtkWidget *inputets5 = lookup_widget(objet_graphique, "inputets5");
GtkWidget *combobox_gouvernerat_ajou=lookup_widget(objet_graphique,"combobox_gouvernerat_ajou");
GtkWidget *spinbutton_capacite_ajou=lookup_widget(objet_graphique,"spinbutton_capacite_ajou");
int y,z=0;
char id[50];
strcpy(id, gtk_entry_get_text(GTK_ENTRY(inputets2)));
strcpy(e.id , gtk_entry_get_text(GTK_ENTRY(inputets2)));
strcpy(e.adr , gtk_entry_get_text(GTK_ENTRY(inputets3)));
strcpy(e.ct , gtk_entry_get_text(GTK_ENTRY(inputets4)));
strcpy(e.idr , gtk_entry_get_text(GTK_ENTRY(inputets5)));
strcpy(e.reg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_gouvernerat_ajou)));
e.ca=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_capacite_ajou));
z=chercher_ets(id);
if (a2==1){
	if (z==1)
	{
		a2=0;
		msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Cet id existe déja.Choisissez un autre id.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		a2=0;
		y=ajouter_ets(e);
		if(y==1){
			msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ajout avec succes .");
			    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
			    {
			    case GTK_RESPONSE_OK:
			    gtk_widget_destroy(msgsucc);
			    break;
			    }
		}
	}
}
else{
	a2=1;
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cocher ''continuer'' pour ajouter le Donneur");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
}


void
on_ajouter_Ets_continuer_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
a2=1;
}
}


void
on_ETS_Mod_Trouver_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *msgsucc;
GtkWidget *inputets,*inputets6,*inputets7,*inputets8,*inputets9,*spinbutton_capacite_mod,*combobox_gouvernerat_mod;
char id[20];
ets e;
int v;
inputets = lookup_widget(objet_graphique,"inputets");
inputets6 = lookup_widget(objet_graphique,"inputets6");
inputets7=lookup_widget(objet_graphique,"inputets7");
inputets8=lookup_widget(objet_graphique,"inputets8");
inputets9= lookup_widget (objet_graphique,"inputets9");
combobox_gouvernerat_mod=lookup_widget(objet_graphique, "combobox_gouvernerat_mod");
spinbutton_capacite_mod=lookup_widget(objet_graphique, "spinbutton_capacite_mod");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(inputets)));
v=chercher_ets(id);
if ( v == 0){
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"id non existant.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
else{
strcpy(id,gtk_entry_get_text(GTK_ENTRY(inputets)));
e = chercher_ets01(id);
int i= trouverregion_ets(id);
gtk_entry_set_text (GTK_ENTRY (inputets6),e.id);
gtk_entry_set_text (GTK_ENTRY (inputets7),e.adr);
gtk_entry_set_text (GTK_ENTRY (inputets8),e.ct);
gtk_entry_set_text (GTK_ENTRY (inputets9),e.idr);
gtk_combo_box_set_active(GTK_COMBO_BOX(combobox_gouvernerat_mod),i);
gtk_spin_button_set_value(GTK_SPIN_BUTTON (spinbutton_capacite_mod),e.ca);
}


}


void
on_ETS_Mod_Modifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[20];
int r;
ets e1;
GtkWidget *msgsucc;
GtkWidget *inputets6,*inputets7,*inputets8,*inputets9,*spinbutton_capacite_mod,*combobox_gouvernerat_mod;
inputets6 = lookup_widget(objet_graphique,"inputets6");
inputets7=lookup_widget(objet_graphique,"inputets7");
inputets8=lookup_widget(objet_graphique,"inputets8");
inputets9= lookup_widget (objet_graphique,"inputets9");
combobox_gouvernerat_mod=lookup_widget(objet_graphique, "combobox_gouvernerat_mod");
spinbutton_capacite_mod=lookup_widget(objet_graphique, "spinbutton_capacite_mod");

strcpy(e1.id , gtk_entry_get_text(GTK_ENTRY(inputets6)));
strcpy(e1.adr , gtk_entry_get_text(GTK_ENTRY(inputets7)));
strcpy(e1.ct , gtk_entry_get_text(GTK_ENTRY(inputets8)));
strcpy(e1.idr , gtk_entry_get_text(GTK_ENTRY(inputets9)));
strcpy(e1.reg,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_gouvernerat_mod)));
e1.ca=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (spinbutton_capacite_mod));
if (c2==1){
	r = modifier_ets(e1);
	if (r==1){
		    c2=0;
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"L'ETS est modifié avec succeé.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
		
	}
	else{
		    c2=0;
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Echec De Modification");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
}
else{
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cocher ''Je Confirme Les Modifivation'' pour continuer.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}

}


void
on_ETS_Mod_Afficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage_ETS;
Affichage_ETS= create_Affichage_ETS();
gtk_widget_show (Affichage_ETS);
GtkWidget *treeview_ETS;
treeview_ETS=lookup_widget(Affichage_ETS, "treeview_ETS");
afficher_ets(treeview_ETS);
}


void
on_ETS_Mod_Confirm_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
c2=1;
}
}


void
on_ETS_Sup_Supprimer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *msgsucc;
char id[20];
ets e;
GtkWidget *inputets10= lookup_widget(objet_graphique, "inputets10");
strcpy(e.id , gtk_entry_get_text(GTK_ENTRY(inputets10)));
if (s2==1){
	s2=0;
	r = supprimer_ets(e);
	if (r==1){
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"L'ETS est Supprimé.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Echec De Supprission, Verifier L'id Donné");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
}
else{
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"L'ETS n'a pas etait supprimer.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
}


void
on_ETS_Supp_Supprimer_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage_ETS;
Affichage_ETS= create_Affichage_ETS();
gtk_widget_show (Affichage_ETS);
GtkWidget *treeview_ETS;
treeview_ETS=lookup_widget(Affichage_ETS, "treeview_ETS");
afficher_ets(treeview_ETS);
}


void
on_ETS_oui_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
s2=1;
}
}


void
on_ETS_non_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
s2=0;
}
}


void
on_ETS_Aff_ret_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Affichage_ETS;
Affichage_ETS =lookup_widget(objet_graphique, "Affichage_ETS");
if (Affichage_ETS != NULL) {
	gtk_widget_hide(Affichage_ETS);
}
}


void
on_Stat_region_aff_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    char region[100];
    GtkWidget *Statistiques;
    GtkWidget *treeview_Stat;
    GtkWidget *combobox1;
    combobox1 = lookup_widget(objet_graphique,"combobox1");
    strcpy(region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
    region1(region);
    Statistiques=lookup_widget(objet_graphique, "Statistiques");
    treeview_Stat=lookup_widget(Statistiques,"treeview_Stat");
    afficher_region1(treeview_Stat);
}


void
on_ETS_Stat_croi_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
choix =3;
}
}


void
on_ETS_stat_decroi_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
choix =2;
}
}


void
on_Ets_Stat_ret_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Statistiques;
GtkWidget *Espaces_Admin_ETS;
Espaces_Admin_ETS= create_Espaces_Admin_ETS();
gtk_widget_show (Espaces_Admin_ETS);
Statistiques =lookup_widget(objet_graphique, "Statistiques");
if (Statistiques != NULL) {
	gtk_widget_hide(Statistiques);
}
}


void
on_Stat_capacite_Aff_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Statistiques;
GtkWidget *treeview_Stat;
if (choix==3){
	capacite_cori();
	Statistiques=lookup_widget(objet_graphique, "Statistiques");
	treeview_Stat=lookup_widget(Statistiques,"treeview_Stat");
	afficher_ets_croi(treeview_Stat);	
}
if (choix==2){
	capacite_decori();
	Statistiques=lookup_widget(objet_graphique, "Statistiques");
	treeview_Stat=lookup_widget(Statistiques,"treeview_Stat");
	afficher_ets_decroi(treeview_Stat);
}
}



void
on_G_De_Donneur_Ret_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestions_De_Donneurs;
GtkWidget *Espace_infirmier;
Espace_infirmier= create_Espace_infirmier();
gtk_widget_show (Espace_infirmier);
Gestions_De_Donneurs =lookup_widget(objet_graphique, "Gestions_De_Donneurs");
if (Gestions_De_Donneurs != NULL) {
	gtk_widget_hide(Gestions_De_Donneurs);
}
}

void
on_Inf_donneur_rech_afficher_clicked   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Donneur_Affichage;
Donneur_Affichage= create_Donneur_Affichage();
gtk_widget_show (Donneur_Affichage);
GtkWidget *treeview_Donneurs;
treeview_Donneurs=lookup_widget(Donneur_Affichage, "treeview_Donneurs");
Afficher_Donneurs(treeview_Donneurs);

}


void
on_Inf_donneur_rechercher_clicked      (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *msgsucc;
char id[20];
GtkWidget *cin_donneur= lookup_widget(objet_graphique, "cin_donneur");
strcpy(id , gtk_entry_get_text(GTK_ENTRY(cin_donneur)));
r = chercher_donneur01(id,"donneur.txt");
if (r==1){
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Un Donneur de cet id existe.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
else{
	    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Cet id n'existe pas.");
            switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
            {
            case GTK_RESPONSE_OK:
            gtk_widget_destroy(msgsucc);
            break;
            }
}
}


void
on_Inf_Ajou_aff_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Donneur_Affichage;
Donneur_Affichage= create_Donneur_Affichage();
gtk_widget_show (Donneur_Affichage);
GtkWidget *treeview_Donneurs;
treeview_Donneurs=lookup_widget(Donneur_Affichage, "treeview_Donneurs");
Afficher_Donneurs(treeview_Donneurs);
}


void
on_Inf_Ajou_ajouter_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
donneur d;
GtkWidget *msgsucc;
GtkWidget *input1 = lookup_widget(objet_graphique, "input1");
GtkWidget *input2 = lookup_widget(objet_graphique, "input2");
GtkWidget *input3 = lookup_widget(objet_graphique, "input3");
GtkWidget *input4 = lookup_widget(objet_graphique, "input4");
GtkWidget *ajouter_jour=lookup_widget(objet_graphique,"ajouter_jour");
GtkWidget *ajouter_mois=lookup_widget(objet_graphique,"ajouter_mois");
GtkWidget *ajouter_annee=lookup_widget(objet_graphique,"ajouter_annee");
int y,z=0;
char id[50];
strcpy(id, gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(d.id , gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(d.nom , gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(d.prenom , gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(d.idets , gtk_entry_get_text(GTK_ENTRY(input4)));
type_de_transfusion(x1,d.type_transfusion);
heure_donneur(heure,d.heure_prelevement);
strcpy(d.date_de_prelevement.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ajouter_jour)));
strcpy(d.date_de_prelevement.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ajouter_mois)));
strcpy(d.date_de_prelevement.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(ajouter_annee)));
z=verifier_existant_donneur(id);
if (a1==1){
	if (z==1)
	{
		a1=0;
		msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Cet id exixte déja.Choisissez un autre id.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		a1=0;
		y=ajouter_donneur(d , "donneur.txt");
		if(y==1){
			msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"ajout avec succes .");
			    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
			    {
			    case GTK_RESPONSE_OK:
			    gtk_widget_destroy(msgsucc);
			    break;
			    }
		gtk_entry_set_text (GTK_ENTRY (input1),"");
		gtk_entry_set_text (GTK_ENTRY (input2),"");
		gtk_entry_set_text (GTK_ENTRY (input3),"");
		gtk_entry_set_text (GTK_ENTRY (input4),"");
		gtk_combo_box_set_active(GTK_COMBO_BOX(ajouter_jour),NULL);
		gtk_combo_box_set_active(GTK_COMBO_BOX(ajouter_mois),NULL);
		gtk_combo_box_set_active(GTK_COMBO_BOX(ajouter_annee),NULL);
		}
	}
}
else{
	a1=1;
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cocher ''continuer'' pour ajouter le Donneur");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
}


void
on_Apres_midi_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	heure=2;
}
}


void
on_Matin_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{
	heure=1;
}
}


void
on_Plaquette_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
x1=3;
}
}


void
on_Plasma_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
x1=2;
}
}


void
on_Sang_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
x1=1;
}
}


void
on_Inf_ajouter_continuer_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
a1=1;
}
}


void
on_INF_Mod_Trouver_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *msgsucc;
GtkWidget *input5,*input6,*input7,*input8,*input9,*modifier_jour,*modifier_mois,*modifier_annee,*type_transfusion,*mod_combobox;
char id[20];
donneur d;
int v;
input5 = lookup_widget(objet_graphique,"input5");
input6=lookup_widget(objet_graphique,"input6");
input7=lookup_widget(objet_graphique,"input7");
input8=lookup_widget(objet_graphique,"input8");
input9= lookup_widget (objet_graphique,"input9");
type_transfusion=lookup_widget(objet_graphique, "type_transfusion");
modifier_jour=lookup_widget(objet_graphique, "modifier_jour");
modifier_mois=lookup_widget(objet_graphique, "modifier_mois");
modifier_annee=lookup_widget(objet_graphique, "modifier_annee");
mod_combobox=lookup_widget(objet_graphique, "mod_combobox");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
v=verifier_existant_donneur(id);
if ( v == 0){
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"id non existant.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
else{
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
d= chercher_donneur(id,"donneur.txt");
int i= trouvertype5(id);
int j= trouverjour5(id);
int m= trouvermois5(id);
int y= trouverannee5(id);
int h= trouverheure(id);
gtk_entry_set_text (GTK_ENTRY (input6),d.nom);
gtk_entry_set_text (GTK_ENTRY (input7),d.prenom);
gtk_entry_set_text (GTK_ENTRY (input8),d.id);
gtk_entry_set_text (GTK_ENTRY (input9),d.idets);
gtk_combo_box_set_active(GTK_COMBO_BOX(type_transfusion),i);
gtk_combo_box_set_active(GTK_COMBO_BOX(mod_combobox),h);
gtk_combo_box_set_active(GTK_COMBO_BOX(modifier_jour),j);
gtk_combo_box_set_active(GTK_COMBO_BOX(modifier_mois),m);
gtk_combo_box_set_active(GTK_COMBO_BOX(modifier_annee),y);
}


}


void
on_Inf_Mod_Modifier_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id[20];
int r;
donneur d1;
GtkWidget *msgsucc;
GtkWidget *input6,*input7,*input8,*input9,*modifier_jour,*modifier_mois,*modifier_annee,*type_transfusion,*mod_combobox;
input6=lookup_widget(objet_graphique,"input6");
input7=lookup_widget(objet_graphique,"input7");
input8=lookup_widget(objet_graphique,"input8");
input9= lookup_widget (objet_graphique,"input9");
type_transfusion=lookup_widget(objet_graphique, "type_transfusion");
modifier_jour=lookup_widget(objet_graphique, "modifier_jour");
modifier_mois=lookup_widget(objet_graphique, "modifier_mois");
modifier_annee=lookup_widget(objet_graphique, "modifier_annee");
mod_combobox=lookup_widget(objet_graphique, "mod_combobox");
strcpy(d1.nom , gtk_entry_get_text (GTK_ENTRY (input6)));
strcpy(d1.prenom , gtk_entry_get_text (GTK_ENTRY (input7)));
strcpy(d1.id , gtk_entry_get_text (GTK_ENTRY (input8)));
strcpy(d1.idets , gtk_entry_get_text (GTK_ENTRY (input9)));
strcpy(d1.date_de_prelevement.jour,gtk_combo_box_get_active_text(GTK_COMBO_BOX(modifier_jour)));
strcpy(d1.date_de_prelevement.mois,gtk_combo_box_get_active_text(GTK_COMBO_BOX(modifier_mois)));
strcpy(d1.date_de_prelevement.annee,gtk_combo_box_get_active_text(GTK_COMBO_BOX(modifier_annee)));
strcpy(d1.type_transfusion,gtk_combo_box_get_active_text(GTK_COMBO_BOX(type_transfusion)));
strcpy(d1.heure_prelevement,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mod_combobox)));
GtkWidget *input5= lookup_widget(objet_graphique, "input5");
strcpy(id , gtk_entry_get_text(GTK_ENTRY(input5)));
if (c1==1){
	r = modifier_donneur(id, d1);
	if (r==1){
		    c1=0;
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Donneur est modifié avec succeé.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
		
	}
	else{
		    c1=0;
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Echec De Modification");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
}
else{
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"cocher ''Je Confirme Les Modifivation'' pour continuer.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}

}


void
on_Inf_Mod_Afficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Gestions_De_Donneurs;
GtkWidget *Donneur_Affichage;
Donneur_Affichage= create_Donneur_Affichage();
gtk_widget_show (Donneur_Affichage);
GtkWidget *treeview_Donneurs;
treeview_Donneurs=lookup_widget(Donneur_Affichage, "treeview_Donneurs");
Afficher_Donneurs(treeview_Donneurs);
}


void
on_modifier_confirm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
c1=1;
}
}


void
on_Inf_Sup_Afficher_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Donneur_Affichage;
Donneur_Affichage= create_Donneur_Affichage();
gtk_widget_show (Donneur_Affichage);
GtkWidget *treeview_Donneurs;
treeview_Donneurs=lookup_widget(Donneur_Affichage, "treeview_Donneurs");
Afficher_Donneurs(treeview_Donneurs);
}


void
on_Inf_Sup_Supprimer_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
int r;
GtkWidget *msgsucc;
char id[20];
GtkWidget *input10= lookup_widget(objet_graphique, "input10");
strcpy(id , gtk_entry_get_text(GTK_ENTRY(input10)));
if (s1==1){
	s1=0;
	r = supprimer_donneur(id);
	if (r==1){
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Donneur est Supprimé.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
	else{
		    msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Echec De Supprission, Verifier Le code Donné");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
	}
}
else{
	msgsucc=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Le Donneur n'a pas etait supprimer.");
		    switch(gtk_dialog_run(GTK_DIALOG(msgsucc)))
		    {
		    case GTK_RESPONSE_OK:
		    gtk_widget_destroy(msgsucc);
		    break;
		    }
}
}


void
on_Inf_non_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
s1=0;
}
}

void
on_Inf_oui_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
{
s1=1;
}
}

void
on_G_De_Donneur_dec_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Gestion_De_Donneurs;
GtkWidget *Authentification_;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
Gestion_De_Donneurs =lookup_widget(objet_graphique, "Gestion_De_Donneurs");
if (Gestion_De_Donneurs != NULL) {
	gtk_widget_hide(Gestion_De_Donneurs);
}

}

void
on_Esp_De_Inf_Dec_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *Espace_infirmier;
GtkWidget *Authentification_;
Authentification_= create_Authentification_();
gtk_widget_show (Authentification_);
Espace_infirmier =lookup_widget(objet_graphique, "Espace_infirmier");
if (Espace_infirmier != NULL) {
	gtk_widget_hide(Espace_infirmier);
}

}

void
on_G_Des_Donneur_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_infirmier;
GtkWidget *Gestions_De_Donneurs;
Gestions_De_Donneurs= create_Gestions_De_Donneurs();
gtk_widget_show (Gestions_De_Donneurs);
Espace_infirmier =lookup_widget(objet_graphique, "Espace_infirmier");
if (Espace_infirmier != NULL) {
	gtk_widget_hide(Espace_infirmier);
}
}


void
on_Stat_Des_RDVs_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_infirmier;
GtkWidget *stat_rdv;
stat_rdv= create_stat_rdv();
gtk_widget_show (stat_rdv);
Espace_infirmier =lookup_widget(objet_graphique, "Espace_infirmier");
if (Espace_infirmier != NULL) {
	gtk_widget_hide(Espace_infirmier);
}
}

void
on_inf_TAB5rdvdon_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_inf_BT5rech_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4;
GtkWidget *inf_rdv5,*stat_rdv;
GtkWidget *treeview_inf;
char nometab[20];
int j;
int m;
int a;
rdv r;

input1 = lookup_widget(objet_graphique,"inf_ET5etab");
input2=lookup_widget(objet_graphique,"inf_SB5jour");
input3=lookup_widget(objet_graphique,"inf_SB5mois");
input4=lookup_widget(objet_graphique, "inf_SB5anne");

strcpy(nometab,gtk_entry_get_text(GTK_ENTRY(input1)));

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
/*char jour[20];
sprintf(jour,"%d",j);
char mois[20];
sprintf(mois,"%d",m);
char annee[20];
sprintf(annee,"%d",a);*/
r= chercher_rdv(nometab,j,m,a,"rdv.txt");
char jour[20];
sprintf(jour,"%d",j);
char mois[20];
sprintf(mois,"%d",m);
char annee[20];
sprintf(annee,"%d",a);
/*inf_rdv5=lookup_widget(objet_graphique, "inf_rdv5");

gtk_widget_destroy(inf_rdv5);
inf_rdv5=lookup_widget(objet_graphique,"inf_rdv5");
inf_rdv5=create_inf_rdv5();

gtk_widget_show(inf_rdv5);*/
stat_rdv=lookup_widget(objet_graphique, "stat_rdv");
treeview_inf=lookup_widget(stat_rdv, "treeview_inf");
afficher_rdv(treeview_inf,jour,mois,annee,nometab);

}


void
on_inf_BT5moy_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*output;
int j;
int m;
int a;
rdv r;

input1=lookup_widget(objet_graphique,"inf_SB5jour");
input2=lookup_widget(objet_graphique,"inf_SB5mois");
input3=lookup_widget(objet_graphique, "inf_SB5anne");
output=lookup_widget (objet_graphique, "inf_LB51");

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
double x= moyRDV_ETS("rdv.txt",j,m,a);
char moy[20];
sprintf(moy,"%.2f %%",x);
char markup[50];
sprintf(markup,"<span foreground='blue'>%s</span>",moy);
gtk_label_set_markup(GTK_LABEL(output),markup);
}


void
on_inf_BT5moyetab_clicked              (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*output;
char nometab[20];
int j;
int m;
int a;
rdv r;


input1 = lookup_widget(objet_graphique,"inf_ET5etab");
input2=lookup_widget(objet_graphique,"inf_SB5jour");
input3=lookup_widget(objet_graphique,"inf_SB5mois");
input4=lookup_widget(objet_graphique, "inf_SB5anne");
output=lookup_widget (objet_graphique, "inf_LB52");
strcpy(nometab,gtk_entry_get_text(GTK_ENTRY(input1)));

j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
int x =listeRDV("rdv.txt",nometab , j, m, a);
char nrdv[30];
sprintf(nrdv,"%d",x);
char markup[50];
sprintf(markup,"<span foreground='blue'>%s</span>",nrdv);
gtk_label_set_markup(GTK_LABEL(output),markup);

}


void
on_inf_BT5ret_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Espace_infirmier;
GtkWidget *stat_rdv;
Espace_infirmier= create_Espace_infirmier();
gtk_widget_show (Espace_infirmier);
stat_rdv =lookup_widget(objet_graphique, "stat_rdv");
if (stat_rdv != NULL) {
	gtk_widget_hide(stat_rdv);
}
}


void
on_Donneur_Affichage_ret_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *Donneur_Affichage;
Donneur_Affichage =lookup_widget(objet_graphique, "Donneur_Affichage");
if (Donneur_Affichage != NULL) {
	gtk_widget_hide(Donneur_Affichage);
}
}



/*
void
on_ETS_non_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_ETS_oui_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}*/


/*void
on_Donneur_Affichage_ret_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}*/

