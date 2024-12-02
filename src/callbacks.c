#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <stdlib.h>
#include <gtk/gtk.h>
#include <string.h>
#include "gdps.h"
#include "interface.h"
#include "support.h"
#include "callbacks.h"
#include <string.h>
#include <glib.h>

int x=1;
int y=1;
int K=0;
void
on_radiobuttonAp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=1;}
}


void
on_radiobuttonBp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=2;}
}


void
on_radiobuttonOp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=3;}
}


void
on_radiobuttonABp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=4;}
}


void
on_radiobuttonAm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=5;}
}


void
on_radiobuttonBm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=6;}
}


void
on_radiobuttonOm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=7;}
}


void
on_radiobuttonABm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{x=8;}
}



void
on_Deconnexion_don_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget *fenetre_1;
  GtkWidget *fenetre_2;
  fenetre_2 = lookup_widget(objet,"authpage");
  fenetre_1 = lookup_widget(objet, "window_don");
  gtk_widget_hide (fenetre_1);
  fenetre_2 = create_authpage ();
  gtk_widget_show (fenetre_2);

}





void
on_buttonAjouter_don_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{
    Dons d;
  GtkWidget *fenetre_1;

GtkWidget *input1, *input2,*input3,*input5,*input6,*input7,*combobox1,*output1,*output2,*output3,*output4;
int jour,mois,annee,R,V;
char ch[25],ch1[25],ch2[25];
input1=lookup_widget (objet, "entryId_donneur_don");
input2=lookup_widget (objet, "entryCode_don_don" ) ;
input3=lookup_widget (objet, "entryQuantite_sang_don");
input5=lookup_widget (objet, "spinbuttonJour_don");
input6=lookup_widget (objet, "spinbuttonMois_don");
input7=lookup_widget (objet, "spinbuttonAnnee_don");
combobox1=lookup_widget (objet, "combobox1_don");

output1=lookup_widget (objet, "controID_don");
output2=lookup_widget (objet, "controlCODE_don");
output3=lookup_widget (objet, "controlQUANTITE_don");



//  control saisie id
strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input1)));
int ID= verifID( ch );
if(ID==1){
strcpy(d.Id_donneur,ch);
gtk_label_set_text(GTK_LABEL(output1),"ID correct");
}
else{
gtk_label_set_text(GTK_LABEL(output1),"ID invalid");
}


//  control saisie code don
strcpy(ch1,gtk_entry_get_text(GTK_ENTRY(input2)));
int code=verif_entier( ch1);
int unique=verif_unicite(ch1);
if(code==1 && unique==1){
strcpy(d.Code_don,ch1);
gtk_label_set_text(GTK_LABEL(output2),"Code correct");
}
else if(unique!=1){
gtk_label_set_text(GTK_LABEL(output2),"Code deja existe");
}
else if(code!=1){
gtk_label_set_text(GTK_LABEL(output2),"Code invalid");

}

//control saisie quatite don
strcpy(ch2,gtk_entry_get_text(GTK_ENTRY(input3)));
int qs=verif_quantitesang(ch2);
if(qs==1){
strcpy(d.Quantite_sang,ch2);
gtk_label_set_text(GTK_LABEL(output3)," valeur correct");
}
else{
gtk_label_set_text(GTK_LABEL(output3),"valeur invalid");
}

//datedon
jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input5));
mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input6));
annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input7));

sprintf(d.Jour,"%d", jour);
sprintf(d.Mois,"%d", mois);
sprintf(d.Annee,"%d", annee);
//ets
strcpy(d.ets,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));

if(x==1)
{strcpy(d.Type_sang,"A+");}
if(x==2)
{strcpy(d.Type_sang,"B+");}
if(x==3)
{strcpy(d.Type_sang,"O+");}
if(x==4)
{strcpy(d.Type_sang,"AB+");}
if(x==5)
{strcpy(d.Type_sang,"A-");}
if(x==6)
{strcpy(d.Type_sang,"B-");}
if(x==7)
{strcpy(d.Type_sang,"O-");}
if(x==8)
{strcpy(d.Type_sang,"AB-");}


if(ID==1 && code==1 && unique==1 && qs==1 ){
R=ajouter_don(d);
}
if(R==1){

  fenetre_1 = lookup_widget(objet, "windowAjout_don");
  fenetre_1 = create_windowAjout_don ();
  gtk_widget_show (fenetre_1);
}

}


void
on_radiobuttonApp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=1;}
}


void
on_radiobuttonBpp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=2;}
}


void
on_radiobuttonOpp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=3;}
}


void
on_radiobuttonABpp_don_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=4;}
}


void
on_radiobuttonAmm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=5;}
}


void
on_radiobuttonBmm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=6;}
}


void
on_radiobuttonOmm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=7;}
}


void
on_radiobuttonABmm_don_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{y=8;}
}


void
on_Chercher_don_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* input1,*output1,*output2,*output3,*output4,*output5,*output6;
char id_donneur[25];
char msg[50],ch1[10],ch2[10],ch3[10],ch[50];
char p[]="/";
Dons d ;




input1=lookup_widget(objet,"idcherch_don");

output1=lookup_widget(objet,"msgcherch_don");
strcpy(id_donneur,gtk_entry_get_text (GTK_ENTRY(input1)));

output2=lookup_widget(objet,"codecherch_don");
output3=lookup_widget(objet,"typecherch_don");
output4=lookup_widget(objet,"quantitecherch_don");
output5=lookup_widget(objet,"datecherch_don");
output6=lookup_widget(objet,"etscherch_don");



d=chercher_don (id_donneur);

if(strcmp(d.Id_donneur,"-1")==0){
strcpy(msg,"Don introuvable");
gtk_label_set_text (GTK_LABEL(output1),msg);


gtk_label_set_text (GTK_LABEL(output2),"NULL");
gtk_label_set_text (GTK_LABEL(output3),"NULL");
gtk_label_set_text (GTK_LABEL(output4),"NULL");
gtk_label_set_text (GTK_LABEL(output5),"NULL");
gtk_label_set_text (GTK_LABEL(output6),"NULL");


}
else{
strcpy(msg ,"Don trouvé");
gtk_label_set_text (GTK_LABEL(output1),msg);

     strcpy(ch1,d.Jour);
     strcpy(ch2,d.Mois);
     strcpy(ch3,d.Annee);

     strcat(ch1,p);
     strcat(ch1,ch2);
     strcat(ch1,p);
     strcat(ch1,ch3);
     strcpy(ch,ch1) ;
    


gtk_label_set_text (GTK_LABEL(output2),d.Code_don);
gtk_label_set_text (GTK_LABEL(output3),d.Type_sang);
gtk_label_set_text (GTK_LABEL(output4),d.Quantite_sang);
gtk_label_set_text (GTK_LABEL(output5),ch);
gtk_label_set_text (GTK_LABEL(output6),d.ets);
}

}

void
on_Modifier_don_don_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* input,*input1,*input2,*input3,*input4,*input5,*input6,*combobox2,*fenetre_1;
    Dons nvdon;
int jour,mois,annee,tr;
char id_donneur[20];


input=lookup_widget(objet,"idcherch_don");
input1=lookup_widget (objet, "entryCode_don" ) ;
input2=lookup_widget (objet, "entryQuantite_don");
input3=lookup_widget (objet, "spinbuttonjourr_don");
input4=lookup_widget (objet, "spinbuttonmoiss_don");
input5=lookup_widget (objet, "spinbuttonanneee_don");
combobox2=lookup_widget (objet, "combobox2_don");


strcpy(id_donneur,gtk_entry_get_text (GTK_ENTRY(input)));
strcpy(nvdon.Code_don,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(nvdon.Quantite_sang,gtk_entry_get_text(GTK_ENTRY(input2)));
jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input3));
mois= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input4));
annee= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (input5));
strcpy(nvdon.ets,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));

sprintf(nvdon.Jour,"%d", jour);
sprintf(nvdon.Mois,"%d", mois);
sprintf(nvdon.Annee,"%d", annee);


if(y==1)
{strcpy(nvdon.Type_sang,"A+");}
if(y==2)
{strcpy(nvdon.Type_sang,"B+");}
if(y==3)
{strcpy(nvdon.Type_sang,"O+");}
if(y==4)
{strcpy(nvdon.Type_sang,"AB+");}
if(y==5)
{strcpy(nvdon.Type_sang,"A-");}
if(y==6)
{strcpy(nvdon.Type_sang,"B-");}
if(y==7)
{strcpy(nvdon.Type_sang,"O-");}
if(y==8)
{strcpy(nvdon.Type_sang,"AB-");}

tr=modifier_don( id_donneur, nvdon );
if(tr==1){
fenetre_1 = lookup_widget(objet, "windowModif_don");
  fenetre_1 = create_windowModif_don ();
  gtk_widget_show (fenetre_1);
}
}


void
on_treeview1_don_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter ;
gchar* id;
gchar* code;
gchar* quantite ;
gchar* type ;
gchar* jour ;
gchar* mois ;
gchar* annee ;
gchar* ets ;
Dons d ;

GtkTreeModel* model = gtk_tree_view_get_model(treeview);
if(gtk_tree_model_get_iter(model,&iter,path)){
gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&id,1,&code,2,&quantite,3,&type,4,&jour,5,&mois,6,&annee,7,&ets,-1);
strcpy(d.Id_donneur,id);
strcpy(d.Code_don,code);
strcpy(d.Quantite_sang,quantite);
strcpy(d.Type_sang,type);
strcpy(d.Jour,jour);
strcpy(d.Mois,mois);
strcpy(d.Annee,annee);
strcpy(d.ets,ets);

supprimer_select(d);

afficher_don(treeview);
}
}

void
on_buttonAfficher_don_trv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* treeview1;

treeview1=lookup_widget(objet,"treeview1_don");

afficher_don(treeview1);

}




void
on_buttonafficher2_don_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
 GtkWidget* output1;

char msg1[50]="Type de sang le plus rare :";
char msg2[50]="Quantite disponible  :";


Sang SR;

output1= lookup_widget(objet, "textview1_don");

SR=SangPlusRare();

strcat(msg1,SR.typesang);
strcat(msg2,SR.quantitesang);
strcat(msg1,"\n\n");


    // Effacer le contenu actuel du GtkTextView
    gtk_text_buffer_set_text(gtk_text_view_get_buffer(GTK_TEXT_VIEW(output1)), "", -1);

    // Ajouter le nouveau texte dans le GtkTextView
    gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(GTK_TEXT_VIEW(output1)), msg1, -1);
    gtk_text_buffer_insert_at_cursor(gtk_text_view_get_buffer(GTK_TEXT_VIEW(output1)), msg2, -1);
}





void
on_buttonAfficher1_don_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* treeview2;

treeview2=lookup_widget(objet,"treeview2_don");

AfficherQuantitesTousTypes(treeview2);

}




void
on_supprimer2_don_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget* input,*output;
char id_donneur[25],Result[50];
int msg;
input=lookup_widget(objet,"entry8_don") ;
output=lookup_widget(objet,"labelResultat_don") ;

strcpy(id_donneur,gtk_entry_get_text (GTK_ENTRY(input)));
if(K==1){
//K=0;
msg=supprimer_don(id_donneur);

if(msg==1){
strcpy(Result,"suppression faite avec succes");
gtk_label_set_text(GTK_LABEL(output),Result);
}

else{
strcpy(Result,"echec verifier votre ID !");
gtk_label_set_text(GTK_LABEL(output),Result);
}

}
else{
strcpy(Result,"Vous Devez confirmer votre Suppression !");
gtk_label_set_text(GTK_LABEL(output),Result);
}

}

void
on_checkbutton1Confirmer_don_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
K=1;}
else{K=0;}
}
void
on_bouton_acceuil_rechercher_un_donneur_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget(button, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 3);
}


void
on_bouton_acceuil_supprimer_un_donneur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget(button, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 5);
}


void
on_bouton_acceuil_modifier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget(button, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 6);
}


void
on_bouton_acceuil_moyRDV_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget(button, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 7);
}


void
on_bouton_acceuil_filtrage_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget(button, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 4);
}


void
on_bouton_acceuil_ajouter_un_donneur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	GtkWidget * notebook1;
	notebook = lookup_widget (button, "notebook2infirmier");
	gtk_notebook_set_current_page (notebook, 1);
	notebook1 = lookup_widget (notebook, "notebook3infirmier");
	gtk_notebook_set_current_page (notebook1, 0);
}


void
on_bouton_acceuil_affichage_donneurs_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget (button, "notebook2infirmier");
	gtk_notebook_set_current_page (notebook, 2);
}

int choix[]={0};
void
on_checkbutton_ajout_confirmerici_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active (togglebutton))
		choix[0]=1;
}
int gender1;
void
on_radiobutton_ajout_homme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		gender1=1;
}


void

on_radiobutton_ajout_femme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if( gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		gender1=2;
}

void
on_bouton_ajoutdonneur_ajouter_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
	
	donneur d;
	GtkWidget* Output;
	
	if (choix[0]==1)
	{	if (gender1==1)
			strcpy(d.infirmier_sexe,"homme");
		if (gender1==2)
			strcpy(d.infirmier_sexe,"femme");
		GtkWidget* jour11;
		jour11 = lookup_widget(button,"spinbutton4infirmier") ;
		d.infirmier_jour_naissance=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour11));
		GtkWidget* mois11;
		mois11 = lookup_widget(button, "spinbutton5infirmier") ;
		d.infirmier_mois_naissance=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois11));
		GtkWidget* annee11;
		annee11 = lookup_widget(button, "spinbutton6infirmier") ;
		d.infirmier_annee_naissance=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee11));
		GtkWidget* combobox1;
		combobox1=lookup_widget(button,"combobox1infirmier");
		strcpy(d.infirmier_type_sang,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
		GtkWidget* nom;
		nom= lookup_widget(button, "entry_ajout_nom") ;
		strcpy(d.infirmier_nom,gtk_entry_get_text(GTK_ENTRY(nom)));
		GtkWidget* prenom;
		prenom= lookup_widget(button, "entry_ajout_prenom") ;
		strcpy(d.infirmier_prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
		GtkWidget* adresse;
		adresse= lookup_widget(button, "entry_ajout_adresse") ;
		strcpy(d.infirmier_adresse,gtk_entry_get_text(GTK_ENTRY(adresse)));
		GtkWidget* mail;
		mail= lookup_widget(button, "entry_ajout_mail") ;
		strcpy(d.infirmier_mail,gtk_entry_get_text(GTK_ENTRY(mail)));
		GtkWidget* cin;
		cin= lookup_widget(button, "entry_ajout_cin") ;
		d.infirmier_cin=atoi(gtk_entry_get_text(GTK_ENTRY(cin)));
		GtkWidget* numero;
		numero= lookup_widget(button, "entry_ajout_numero") ;
		d.infirmier_numero_telephone=atoi(gtk_entry_get_text(GTK_ENTRY(numero)));
		GtkWidget* password;
		password= lookup_widget(button, "entry_ajout_password") ;
		strcpy(d.infirmier_password,gtk_entry_get_text(GTK_ENTRY(password)));
		
		int u=infirmier_ajouter_information_generale("donneur.txt",d);

	gtk_entry_set_text(GTK_ENTRY(nom),"");
	gtk_entry_set_text(GTK_ENTRY(prenom),"");
	gtk_entry_set_text(GTK_ENTRY(adresse),"");
	gtk_entry_set_text(GTK_ENTRY(mail),"");
	gtk_entry_set_text(GTK_ENTRY(mail),"");
	gtk_entry_set_text(GTK_ENTRY(cin),"");
	gtk_entry_set_text(GTK_ENTRY(numero),"");
	gtk_entry_set_text(GTK_ENTRY(password),"");
	gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry3infirmier")),"");
	gtk_entry_set_text(GTK_ENTRY(lookup_widget(button,"entry1infirmier")),"");
	
	
//ajout adminuser;aziz:
admin_user new_user;
strcpy(new_user.adminuser_password,d.infirmier_password);
strcpy(new_user.adminuser_name,d.infirmier_nom);         
 strcpy(new_user.adminuser_surname,d.infirmier_prenom);
strcpy(new_user.adminuser_role,"donor");
sprintf(new_user.adminuser_phone,"%d",d.infirmier_numero_telephone);
strcpy(new_user.adminuser_email,d.infirmier_mail);
strcpy(new_user.adminuser_gender,d.infirmier_sexe);
sprintf(new_user.adminuser_identification_card_number,"%d",d.infirmier_cin);
strcpy(new_user.adminuser_address,d.infirmier_adresse);
strcpy(new_user.adminuser_region,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry3infirmier"))));
strcpy(new_user.adminuser_username,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button,"entry1infirmier"))));
int join_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "spinbutton7infirmier")));
int join_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "spinbutton8infirmier")));
int join_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "spinbutton9infirmier")));
 snprintf(new_user.adminuser_joindate, sizeof(new_user.adminuser_joindate), "%02d/%02d/%04d", join_day, join_month, join_year);//new!!!!!!!!
 int user_day =d.infirmier_jour_naissance;
 int user_month =d.infirmier_mois_naissance;
 int user_year =d.infirmier_annee_naissance;
 snprintf(new_user.adminuser_date, sizeof(new_user.adminuser_date), "%02d/%02d/%04d", user_day, user_month, user_year);
admin_user_add("adminusers.txt", new_user);

		GtkWidget * notebook;
		notebook = lookup_widget(button, "notebook3infirmier");
		gtk_notebook_set_current_page(notebook, 1);
	}
	else
	{
		Output = lookup_widget(button, "label105444") ;
		gtk_label_set_text(GTK_LABEL(Output),"veuillez cochez la case\n au dessus");
	}
}







void
on_bouton_ajoutdonneur_retour_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget (button, "notebook2infirmier");
	gtk_notebook_set_current_page (notebook, 0);
}

void
on_button1infirmier_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
	Etablissement ets;
	admin_user adu;
	GtkWidget * notebook;
	GtkWidget * notebook1;
	notebook = lookup_widget (button, "notebook2infirmier");
	notebook1 = lookup_widget (notebook, "notebook3infirmier");
	GtkCombo *combobox4 = GTK_COMBO_BOX(lookup_widget(notebook1, "combobox4infirmier"));
	/*GtkComboBox *combobox4=lookup_widget(button,"combo1");*/
	FILE *file1 = fopen("etablissement.txt", "r");
	if (file1 != NULL) 
		    {
		while (fscanf(file1, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day ) != EOF)
			{
			    gtk_combo_box_append_text(combobox4, ets.name);
			}
			fclose(file1);
		    }
	
	GtkCombo *combobox5 = GTK_COMBO_BOX(lookup_widget(notebook1, "combobox5infirmier"));
	/*GtkComboBox *combobox5=lookup_widget(button,"combo2");*/
	
	FILE *file2 = fopen("adminusers.txt", "r");
	if (file2 != NULL) 
		    {
		while (fscanf(file2,"%s %s %s %s %s %s %s %s %s %s %s %s %s\n",adu.adminuser_username,adu.adminuser_password,
              adu.adminuser_name,adu.adminuser_surname,adu.adminuser_role,adu.adminuser_phone, adu.adminuser_email,
              adu.adminuser_gender,adu.adminuser_identification_card_number,adu.adminuser_address,
              adu.adminuser_joindate,adu.adminuser_region,adu.adminuser_date) != EOF)
			{
				if ((strcmp(adu.adminuser_role,"medecin")==0) || (strcmp(adu.adminuser_role,"doctor")==0))
			    gtk_combo_box_append_text(combobox5, adu.adminuser_name);
			}
			fclose(file2);
		    }
}


int mois1,jour1,annee1;
void
on_calendar1infirmier_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&annee1,&mois1,&jour1);
}
void
on_bouton_ajoutdonneur_confirmer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{	
	
	
	
	if ( choix[0]==1)
	{
	GtkWidget* Output;
	RDV r;
	r.infirmier_jour_RDV=jour1;
	r.infirmier_mois_RDV=mois1;
	r.infirmier_annee_RDV=annee1;
	GtkWidget* combobox3;
	combobox3=lookup_widget(button,"combobox3infirmier");
	r.infirmier_heure_RDV=atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

	GtkCombo *combobox4=lookup_widget(button,"combobox4infirmier");
	
	strcpy(r.infirmier_ID_ETS,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

	GtkCombo *combobox5=lookup_widget(button,"combobox5infirmier");
	
	strcpy(r.infirmier_medecin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));	
	
	
	
	int q=infirmier_ajouter_RDV("RDV.txt",r);
		if (q==1)
		{
			Output = lookup_widget(button, "confirmationajout") ;
			gtk_label_set_text(GTK_LABEL(Output),"ajout avec succée !");
		}
			else
		{
			Output = lookup_widget(button, "confirmationajout") ;
			gtk_label_set_text(GTK_LABEL(Output),"echec!");
		}
	}
	else if (choix[0]==0)
	{
		GtkWidget* Output;
		Output = lookup_widget(button, "confirmationajout") ;
		gtk_label_set_text(GTK_LABEL(Output),"echec!\nveuillez entrer les informations\ngenerales");
	}
	
}





void
on_bouton_affichage_filtrer_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget (button, "notebook2infirmier");
	gtk_notebook_set_current_page (notebook, 4);
}






void
on_bouton_filtrage_afficher_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *espaceinfirmier;
	GtkWidget *contenufiltre;
	espaceinfirmier = lookup_widget(button, "espaceinfirmier");
	gtk_widget_hide (espaceinfirmier);
	contenufiltre = create_contenufiltre ();
	gtk_window_set_position(GTK_WINDOW(contenufiltre),GTK_WIN_POS_CENTER);
	gtk_widget_show (contenufiltre);
}



void
on_radiobutton_filtrage_homme_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_filtrage_femme_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}

int supp;
void
on_bouton_suppression_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{	
	GtkWidget* Output;
	char cinn[50];
	int cin;
	
	strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "entry_suppression"))));
	cin=atoi(cinn);
	supp=cin;
	donneur d=infirmier_chercher("donneur.txt",cin);
	if(d.infirmier_cin!=-1)
	{
	GtkWidget *confirmationsuppression;
	confirmationsuppression = create_confirmationsuppression ();
	gtk_window_set_position(GTK_WINDOW(confirmationsuppression),GTK_WIN_POS_CENTER);
	gtk_widget_show (confirmationsuppression);
	}
	else 
	{
		Output = lookup_widget(button, "confirmationexistance") ;
		gtk_label_set_text(GTK_LABEL(Output),"ce donneur n'existe pas !");
	}
	
}




void
on_bouton_suppression_retour_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget (button, "notebook2infirmier");
	gtk_notebook_set_current_page (notebook, 0);
}



int mois2,jour2,annee2;
void
on_calendar2infirmier_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&annee2,&mois2,&jour2);
}
void
on_bouton_moyRDV_confirmer_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{	
	
	char ch[20];
	float x=moyRDV_ETS ("RDV.txt",jour2,mois2,annee2);
	GtkWidget* Output;
	sprintf(ch,"%.2f",x);
	Output = lookup_widget(button, "moyennecalculee") ;
	gtk_label_set_text(GTK_LABEL(Output),ch);
}


void
on_bouton_moyRDV_retour_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget * notebook;
	notebook = lookup_widget (button, "notebook2infirmier");
	gtk_notebook_set_current_page (notebook, 0);
}


void
on_treeview_filtre_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_bouton_contenufiltre_retour_clicked (GtkWidget       *w,
                                        gpointer         user_data)
{
	GtkWidget * contenufiltre;
	GtkWidget * espaceinfirmier;
	espaceinfirmier = create_espaceinfirmier ();
	gtk_window_set_position(GTK_WINDOW(espaceinfirmier),GTK_WIN_POS_CENTER);
	gtk_widget_show (espaceinfirmier);
	contenufiltre = lookup_widget(w, "contenufiltre");
  	gtk_widget_hide (contenufiltre);
	
	
}





void
on_bouton_affichagedonneur_retour_clicked
                                        (GtkWidget       *w,
                                        gpointer         user_data)
{
	
	GtkWidget * espaceinfirmier;
	GtkWidget * affichage_un_donneur;
	GtkWidget * notebook;
	espaceinfirmier = create_espaceinfirmier ();
	gtk_window_set_position(GTK_WINDOW(espaceinfirmier),GTK_WIN_POS_CENTER);
	gtk_widget_show (espaceinfirmier);
	affichage_un_donneur = lookup_widget (w,"affichage_un_donneur");
  	gtk_widget_hide (affichage_un_donneur);

}

int j;
void
on_bouton_confirmation_suppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{	
	
	j=infirmier_supprimer_donneur("donneur.txt","RDV.txt",supp);

	GtkWidget *confirmationsuppression;
	confirmationsuppression = lookup_widget(button,"confirmationsuppression");
	gtk_widget_hide (confirmationsuppression);
	
	
	
	
	
		
	
}


void
on_bouton_annuler_suppression_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *confirmationsuppression;
	
	confirmationsuppression = lookup_widget(button, "confirmationsuppression");
	gtk_widget_hide (confirmationsuppression);
	
}





int cin3;
void
on_bouton_modification_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{	GtkWidget* Cin;
	GtkWidget* Output;
	char cinn[50];
	
	Cin= lookup_widget(button, "entry_modification_cin") ;
	strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(Cin)));
	cin3=atoi(cinn);
	donneur d=infirmier_chercher("donneur.txt",cin3);
	if(d.infirmier_cin!=-1)
	{
	GtkWidget *espaceinfirmier;
	GtkWidget *modification;
	espaceinfirmier = lookup_widget(button, "espaceinfirmier");
	gtk_widget_hide (espaceinfirmier);
	modification = create_modification();
	gtk_window_set_position(GTK_WINDOW(modification),GTK_WIN_POS_CENTER);
	gtk_widget_show (modification);
	
	}
	else 
	{
		Output = lookup_widget(button, "modification_existance_cin") ;
		gtk_label_set_text(GTK_LABEL(Output),"ce donneur n'existe pas !");
	}
	

	
}

int choix1[]={0};
void
on_checkbutton_modifier_confirmerici_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if (gtk_toggle_button_get_active (togglebutton))
		choix1[0]=1;
}

void
on_bouton_modifierRDV_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
	if(choix1[0]==1)
	{
		int b;
		donneur a;
		strcpy(a.infirmier_adresse,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "entry_modifier_adresse"))));
		strcpy(a.infirmier_mail,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "entry_modifier_mail"))));
		a.infirmier_numero_telephone=atoi(gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "entry_modifier_numero"))));
		int i=infirmier_modifier_donneur("donneur.txt",cin3,a);
	
		GtkWidget * notebook;
		notebook = lookup_widget(button, "notebook4");
		gtk_notebook_set_current_page(notebook, 1);
//--------------------------------------------------------------------------------------------
		
		Etablissement ets;
	admin_user adu;
	GtkWidget * notebook7;
	notebook7 = lookup_widget (button, "notebook4");
	GtkCombo *combobox4 = GTK_COMBO_BOX(lookup_widget(notebook7, "combobox8infirmier"));
	
	FILE *file1 = fopen("etablissement.txt", "r");
	if (file1 != NULL) 
		    {
		while (fscanf(file1, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day ) != EOF)
			{
			    gtk_combo_box_append_text(combobox4, ets.name);
			}
			fclose(file1);
		    }
	
	GtkCombo *combobox5 = GTK_COMBO_BOX(lookup_widget(notebook, "combobox9infirmier"));
	
	
	FILE *file2 = fopen("adminusers.txt", "r");
	if (file2 != NULL) 
		    {
		while (fscanf(file2, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n",adu.adminuser_username,adu.adminuser_password,
              adu.adminuser_name,adu.adminuser_surname,adu.adminuser_role,adu.adminuser_phone, adu.adminuser_email,
              adu.adminuser_gender,adu.adminuser_identification_card_number,adu.adminuser_address,
              adu.adminuser_joindate,adu.adminuser_region,adu.adminuser_date) != EOF)
			{
				if ((strcmp(adu.adminuser_role,"medecin")==0)||(strcmp(adu.adminuser_role,"doctor")==0))
			    gtk_combo_box_append_text(combobox5, adu.adminuser_name);
			}
			fclose(file2);
		    }
//--------------------------------------------------------------------------------------------------
	}
	else
	{
		GtkWidget* Output = lookup_widget(button, "label106infirmier") ;
		gtk_label_set_text(GTK_LABEL(Output),"veuillez cochez la case\n au dessus");
	}
}

int mois3,jour3,annee3;
void
on_calendar3infirmier_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data)
{
	gtk_calendar_get_date(GTK_CALENDAR(calendar),&annee3,&mois3,&jour3);
}

void
on_bouton_modifier_comfirmationmodif_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
	if ( choix1[0]==1)
	{
	GtkWidget* Output;
	RDV m;
	m.infirmier_jour_RDV=jour3;
	m.infirmier_mois_RDV=mois3;
	m.infirmier_annee_RDV=annee3;
	GtkWidget* combobox3;
	combobox3=lookup_widget(button,"combobox7infirmier");
	m.infirmier_heure_RDV=atoi(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));

	GtkCombo *combobox4=lookup_widget(button,"combobox8infirmier");
	
	strcpy(m.infirmier_ID_ETS,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox4)));

	GtkCombo *combobox5=lookup_widget(button,"combobox9infirmier");
	
	strcpy(m.infirmier_medecin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox5)));	
	
	
	
	int p=infirmier_modifier_RDV("RDV.txt",cin3,m);
		if (p==1)
		{
			Output = lookup_widget(button, "messagemodification") ;
			gtk_label_set_text(GTK_LABEL(Output),"modifié avec succée !");
		}
			else
		{
			Output = lookup_widget(button, "messagemodification") ;
			gtk_label_set_text(GTK_LABEL(Output),"echec!");
		}
	}
	else if (choix[0]==0)
	{
		GtkWidget* Output;
		Output = lookup_widget(button, "messagemodification") ;
		gtk_label_set_text(GTK_LABEL(Output),"echec!\nveuillez entrer les informations\ngenerales");
	}
}

void
on_bouton_modifier_retour_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{	
	
	GtkWidget * espaceinfirmier;
	GtkWidget * modification;
	GtkWidget * notebook;
	espaceinfirmier = create_espaceinfirmier ();
	gtk_window_set_position(GTK_WINDOW(espaceinfirmier),GTK_WIN_POS_CENTER);
	gtk_widget_show (espaceinfirmier);
	modification = lookup_widget(button,"modification");
  	gtk_widget_hide (modification);
}



int a=0;
void
on_bouton_filtre_recherche_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GtkWidget *espaceinfirmier;
	GtkWidget *contenufiltre;
	a=1;
	contenufiltre = lookup_widget(button, "contenufiltre");
	gtk_widget_hide (contenufiltre);
	espaceinfirmier = create_espaceinfirmier ();
	gtk_window_set_position(GTK_WINDOW(espaceinfirmier),GTK_WIN_POS_CENTER);
	gtk_widget_show (espaceinfirmier);
	
}

void
on_espaceinfirmier_show                (GtkWidget      *widget,
                                        gpointer         user_data)
{
	if (a==1)
	{
	GtkWidget * notebook;
	notebook = lookup_widget(widget, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 3);
	
	}
a=0;
}


void
on_bouton_affichage_recherche_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
	
	GtkWidget * notebook;
	notebook = lookup_widget(button, "notebook2infirmier");
	gtk_notebook_set_current_page(notebook, 3);
}















//////still not working-----------------------------------------------------------------
void
on_confirmationsuppression_close       (GtkDialog       *dialog,
                                        gpointer         user_data)
{
 	if(j==1)
	{GtkWidget* notebook=lookup_widget(dialog,"notebook2infirmier");
	GtkWidget* abc=lookup_widget(notebook,"confirmationsuppressionmessage");
	gtk_label_set_text(GTK_LABEL(abc),"supprimée avec succée");
	}
	
}






void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *espaceinfirmier;
	espaceinfirmier = lookup_widget(button, "espaceinfirmier");
	GtkWidget *treeview1;
	treeview1=lookup_widget(espaceinfirmier,"treeview_affichage");
//----------------------------------------------------------------------
	GtkTreeModel *model=gtk_tree_view_get_model(treeview1);
	GList *columns=gtk_tree_view_get_columns(treeview1);
	if (GTK_IS_LIST_STORE(model))
	{
		gtk_list_store_clear(GTK_LIST_STORE(model));
	}
//-----------------------------------------------------------------------------
	afficher_donneurs(treeview1);
	
	
	
	
	
}


void
on_treeview_affichage_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* cin;

	donneur d;
	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&cin,-1);
		d.infirmier_cin=atoi(cin);
		strcpy(d.infirmier_prenom,prenom);
		strcpy(d.infirmier_nom,nom);
		/*vider(treeview);*/ // ???????????????
		afficher_donneurs(treeview);
	}
	
}



void
on_bouton_recherche_afficherdonneur_clicked
                                        (GtkWidget      *button,
                                        gpointer         user_data)
{	
	GtkWidget* Cin;
	GtkWidget* Output;
	char cinn[50];
	int cin;
	Cin= lookup_widget(button, "entry_recherche") ;
	strcpy(cinn,gtk_entry_get_text(GTK_ENTRY(Cin)));
	cin=atoi(cinn);
	l=cin;
	donneur d=infirmier_chercher("donneur.txt",cin);
	if(d.infirmier_cin!=-1)
	{
	GtkWidget *espaceinfirmier;
	GtkWidget *affichage_un_donneur;
	

	espaceinfirmier =lookup_widget(button, "espaceinfirmier");
	gtk_widget_hide (espaceinfirmier);

	
	affichage_un_donneur = create_affichage_un_donneur();
	gtk_window_set_position(GTK_WINDOW(affichage_un_donneur),GTK_WIN_POS_CENTER);
	gtk_widget_show (affichage_un_donneur);
	
	
	
	
	}
	else 
	{
		Output = lookup_widget(button, "recherche_existance") ;
		gtk_label_set_text(GTK_LABEL(Output),"ce donneur n'existe pas !");
	}
}

void
on_affichage_un_donneur_show           (GtkWidget       *widget,
                                        gpointer         user_data)
{
	GtkWindow *affichage_un_donneur=lookup_widget(widget,"affichage_un_donneur");
	GtkWidget *treeview1=lookup_widget(GTK_WINDOW(affichage_un_donneur),"treeview_affichagedonneur");
	afficher_donneur(treeview1);
}

void
on_treeview_affichagedonneur_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{	
	
	GtkTreeIter iter;
	gchar* nom;
	gchar* prenom;
	gchar* sexe;
	gchar* adresse;
	gchar* mail;
	gchar* cin;
	gchar* numerotelephone;
	gchar* typesang;
	gchar* datenaissance;
	gchar* ets;
	gchar* medecin;
	gchar* dateRDV;
	gchar* heureRDV;
	

	
	
	GtkTreeModel *model=gtk_tree_view_get_model(treeview);
	if (gtk_tree_model_get_iter(model,&iter,path))
	{
		gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&nom,1,&prenom,2,&sexe,&adresse,&mail,&cin,&numerotelephone,&typesang,&datenaissance,&ets,&medecin,&dateRDV,&heureRDV,-1);
		
		
		afficher_donneur(treeview);
	}
}





//recherche sur le RESET de tous les entry



int value, aj = 0, mod = 0;
d_poche_de_sang d;
char msg1[10];
char msg2[10];
int xw1=0,yw1=0,xw2=0,yw2=0;
char plus;
d_poche_de_sang daj;
d_poche_de_sang dmod;
d_poche_de_sang modon;

void
on_Console_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS;
GtkWidget *Affichage,*Notebook;
Notebook = lookup_widget(button,"gdps_notebook1");
Affichage=lookup_widget(button,"Affichage");
GDPS=lookup_widget(button,"GDPS");
GDPS=create_GDPS();
gtk_widget_show(GDPS);
gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook),0);
gtk_widget_destroy(Affichage);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////


void
on_Urgence_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	xw1=1;else xw1=0;
}


void
on_gdps_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	yw1=1; else yw1=0;
}


void
on_gdps_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	yw1=2; else yw1=0;
}

void
on_Ajouter_GDPS_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *nomet, *iddd, *x_entry, *y_entry, *jourr, *moiss, *Anneee, *Heuree1,*Heuree2, *idemail, *infosupp,*Notebook2,*output,*output1,*output2,*output3,*output50;
    GtkWidget *GDPS,*indication;
	int Aj=1,h1,h2,a,b,c,h,m,fl1=1,fl2=1;
	char h1ch[10],h2ch[10],aux[10];
	char *erreur1,*erreur2,*erreur3,*erreurh,*erreurm,*result,chem[30];
    // Récupération des éléments de l'interface
    GDPS = lookup_widget(button, "GDPS");


    nomet = lookup_widget(button, "gdps_entry17");
    iddd = lookup_widget(button, "gdps_entry11");
    x_entry = lookup_widget(button, "gdps_entry12");
    y_entry = lookup_widget(button, "gdps_entry14");
    jourr = lookup_widget(button, "gdps_spinbutton1");
    moiss = lookup_widget(button, "gdps_spinbutton2");
    Anneee = lookup_widget(button, "gdps_spinbutton3");
    Heuree1 = lookup_widget(button, "gdps_entry15");
    Heuree2 = lookup_widget(button, "gdps_entry73");
    idemail = lookup_widget(button, "gdps_entry13");
    infosupp = lookup_widget(button, "gdps_entry16");
    output = lookup_widget(button, "gdps_label148");
    output1 = lookup_widget(button, "gdps_label149");
    output2 = lookup_widget(button, "gdps_label150");
    output3 = lookup_widget(button, "gdps_label151");
    output50 = lookup_widget(button, "gdps_label203");
    // Variables pour stocker les valeurs des entrées

    // Obtention des valeurs des entrées

	a=strtol(gtk_entry_get_text(GTK_ENTRY(iddd)), &erreur1, 10);
if (strcmp(gtk_entry_get_text(GTK_ENTRY(iddd)),"")==0 )
{
    Aj = 0;
    gtk_label_set_text(output1, "Saisir un Identifiant svp");
}
else if (*erreur1 != '\0' && *erreur1 !='\n') 
{
    Aj = 0;
gtk_label_set_markup(GTK_LABEL(output1), "<span color=\"red\">Erreur d' Identifiant !</span>");
}
else
{
gtk_label_set_text(output1, " ");
}
    daj.idd = atoi(gtk_entry_get_text(GTK_ENTRY(iddd)));
    strcpy(daj.demandeur, gtk_entry_get_text(GTK_ENTRY(nomet)));

	strcpy(chem, gtk_entry_get_text(GTK_ENTRY(idemail)));
	result=strstr(chem,"@");
if (strcmp(gtk_entry_get_text(GTK_ENTRY(idemail)),"")==0 )
{
    Aj = 0;
    gtk_label_set_text(output3, "Saisir un Email svp");
}
else if (result == NULL )
{
    Aj = 0;
gtk_label_set_markup(GTK_LABEL(output3), "<span color=\"red\">Erreur de Format !</span>");
}else{gtk_label_set_text(output3, " ");}

    strcpy(daj.idemail, gtk_entry_get_text(GTK_ENTRY(idemail)));




    strcpy(daj.infosupp, gtk_entry_get_text(GTK_ENTRY(infosupp)));
if(strcmp(daj.infosupp,"")==0){Aj=0;gtk_label_set_text(output50, "Saisir une info svp");}else{gtk_label_set_text(output50, " ");}                                                          //


    daj.datedd.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourr));
    daj.datedd.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiss));
    daj.datedd.Annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Anneee));

    h1=atoi(gtk_entry_get_text(GTK_ENTRY(Heuree1)));
    h2=atoi(gtk_entry_get_text(GTK_ENTRY(Heuree2)));
h=strtol(gtk_entry_get_text(GTK_ENTRY(Heuree1)), &erreurh, 10);
m=strtol(gtk_entry_get_text(GTK_ENTRY(Heuree2)), &erreurm, 10);

if ((h1 < 0 || h1 > 23) || (h2 < 0 || h2 > 59)) {
    fl1 = 0;
	Aj=0;
}
if ((*erreurh != '\0' && *erreurh !='\n' ) || (*erreurm != '\0' && *erreurm !='\n' ))
{
    fl2 = 0;
	Aj=0;

}

if(fl1==0 && fl2==1){
gtk_label_set_markup(GTK_LABEL(output), "<span color=\"red\">Erreur d' Heure !</span>");
}
if(fl2==0){gtk_label_set_markup(GTK_LABEL(output), "<span color=\"red\">Erreur de Type !</span>");}
if(fl1==1&&fl2==1){gtk_label_set_text(output, " ");}


strcpy(h1ch,gtk_entry_get_text(GTK_ENTRY(Heuree1)));
strcpy(h2ch,gtk_entry_get_text(GTK_ENTRY(Heuree2)));

if (strlen(h2ch) == 1){
strcpy(aux,h2ch);
strcpy(h2ch,"0");
strcat(h2ch,aux);
}

strcat(h1ch,h2ch);

daj.datedd.Heure = atoi(h1ch);

b=strtol(gtk_entry_get_text(GTK_ENTRY(x_entry)), &erreur2, 10);
c=strtol(gtk_entry_get_text(GTK_ENTRY(y_entry)), &erreur3, 10);
if ((*erreur2 != '\0' && *erreur2 !='\n' ) || (*erreur3 != '\0' && *erreur3 !='\n' ) )
{
Aj = 0;
gtk_label_set_markup(GTK_LABEL(output2), "<span color=\"red\">Erreur de Location !</span>");
}else{gtk_label_set_text(output2, " ");}



daj.place[0] = atoi(gtk_entry_get_text(GTK_ENTRY(x_entry)));
daj.place[1] = atoi(gtk_entry_get_text(GTK_ENTRY(y_entry)));







    if (xw1 == 0)
        daj.urgency = 0;
    else if (xw1 == 1)
        {daj.urgency = 1;}

d_poche_de_sang dhm=chercherDemande2("gdps.txt", daj.idd, daj.idemail, daj.demandeur, daj.place[0], daj.place[1], daj.urgency, daj.datedd.Heure, daj.datedd.jour, daj.datedd.mois, daj.datedd.Annee);



if (dhm.idd != -1) {
	Aj=0;
	indication=create_indication();
	gtk_widget_show(indication);
}







    if (yw1 == 1 && Aj==1)  {
    Notebook2 = lookup_widget(button,"gdps_notebook2");
	gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook2),2);
    } else if (yw1 == 2 && Aj==1) {
    Notebook2 = lookup_widget(button,"gdps_notebook2");
	gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook2),1);
    }

}


///////////////////////////////////////////////////////////////////////////////
void
on_lestypes_annuler_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{    	
	GtkWidget *GDPS, *Notebook;
Notebook = lookup_widget(button,"gdps_notebook2");
gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook),0);
}
///////////////////////////////////////////////////////////////////////
void on_lestypes_confirmer_clicked(GtkWidget *button, gpointer user_data)
{
    GtkWidget *result2;
    GtkWidget *result3,*result5;
    GtkWidget *GDPS, *Affichage;
    GtkWidget *text3, *text4, *text5, *text6, *text7, *text8, *text9, *text10;
    int value3, value4, value5, value6, value7, value8, value9, value10,a,b,c,d,e,f,g,h;
	int Aj=1;
	char *erreur3,*erreur4,*erreur5,*erreur6,*erreur7,*erreur8,*erreur9,*erreur10;

text3=lookup_widget(button,"gdps_entry3");

a=strtol(gtk_entry_get_text(GTK_ENTRY(text3)), &erreur3, 10);
if (*erreur3 != '\0' && *erreur3 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value3=atoi(gtk_entry_get_text(GTK_ENTRY(text3)));
daj.qt_demande[0]=value3;



text4=lookup_widget(button,"gdps_entry4");

b=strtol(gtk_entry_get_text(GTK_ENTRY(text4)), &erreur4, 10);
if (*erreur4 != '\0' && *erreur4 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value4=atoi(gtk_entry_get_text(GTK_ENTRY(text4)));
daj.qt_demande[1]=value4;



text5=lookup_widget(button,"gdps_entry5");

c=strtol(gtk_entry_get_text(GTK_ENTRY(text5)), &erreur5, 10);
if (*erreur5 != '\0' && *erreur5 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value5=atoi(gtk_entry_get_text(GTK_ENTRY(text5)));
daj.qt_demande[2]=value5;




text6=lookup_widget(button,"gdps_entry6");

d=strtol(gtk_entry_get_text(GTK_ENTRY(text6)), &erreur6, 10);
if (*erreur6 != '\0' && *erreur6 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value6=atoi(gtk_entry_get_text(GTK_ENTRY(text6)));
daj.qt_demande[3]=value6;



text7=lookup_widget(button,"gdps_entry7");

e=strtol(gtk_entry_get_text(GTK_ENTRY(text7)), &erreur7, 10);
if (*erreur7 != '\0' && *erreur7 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value7=atoi(gtk_entry_get_text(GTK_ENTRY(text7)));
daj.qt_demande[4]=value7;




text8=lookup_widget(button,"gdps_entry8");

f=strtol(gtk_entry_get_text(GTK_ENTRY(text8)), &erreur8, 10);
if (*erreur8 != '\0' && *erreur8 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value8=atoi(gtk_entry_get_text(GTK_ENTRY(text8)));
daj.qt_demande[5]=value8;



text9=lookup_widget(button,"gdps_entry9");

g=strtol(gtk_entry_get_text(GTK_ENTRY(text9)), &erreur9, 10);
if (*erreur9 != '\0' && *erreur9 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value9=atoi(gtk_entry_get_text(GTK_ENTRY(text9)));
daj.qt_demande[6]=value9;




text10=lookup_widget(button,"gdps_entry10");

h=strtol(gtk_entry_get_text(GTK_ENTRY(text10)), &erreur10, 10);
if (*erreur10 != '\0' && *erreur10 !='\n' ) 
{
    Aj = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value10=atoi(gtk_entry_get_text(GTK_ENTRY(text10)));
daj.qt_demande[7]=value10;


if (Aj==1){
        ajouter_demande(daj);
        result3 = create_result3();
        gtk_widget_show(result3);
}
}



/////////////////////////////////////////////////////////////////////////////////////////////////




void on_button9_clicked(GtkWidget *button, gpointer user_data)
{
    GtkWidget *GDPS;
    GtkWidget *Affichage;
    Affichage = lookup_widget(button, "Affichage");
    GDPS = lookup_widget(button, "GDPS");
    gtk_widget_destroy(Affichage);
    GDPS = create_GDPS();
    gtk_widget_show(GDPS);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_confer_type_Ajou_clicked            (GtkWidget       *button,
                                        gpointer         user_data)
{

		GtkWidget *GDPS,*Notebook,*output;
		GtkWidget *result2;
		GtkWidget *result3;		
		char type[4],*erreur1;
		GtkWidget *typee,*Quantitee,*Affichage;
    output = lookup_widget(button, "gdps_label152");
		int Quantite,Aj=1,a;
		typee=lookup_widget(button,"gdps_comboboxentry1");
		Quantitee=lookup_widget(button,"gdps_entry1");
		strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typee)));
		a=strtol(gtk_entry_get_text(GTK_ENTRY(Quantitee)), &erreur1, 10);
if (*erreur1 != '\0' && *erreur1 !='\n' ) 
{
    Aj = 0;
gtk_label_set_markup(GTK_LABEL(output), "<span color=\"red\">Erreur de Type !</span>");
}else{gtk_label_set_text(output, " ");}
		Quantite=atoi(gtk_entry_get_text(GTK_ENTRY(Quantitee)));
			
				if (strcmp(type,"A+")==0)
				daj.qt_demande[0]=Quantite;
				else  {
			    		if (strcmp(type,"A-")==0)
						daj.qt_demande[1]=Quantite;
					else	{
						if (strcmp(type,"B+")==0)
					    		daj.qt_demande[2]=Quantite;
						else{ 
	    						if (strcmp(type,"B-")==0)
								daj.qt_demande[3]=Quantite;
	    						else  {
	    							if (strcmp(type,"AB+")==0)
									daj.qt_demande[4]=Quantite;
	    							else	{
					    				if (strcmp(type,"AB-")==0)
					    					daj.qt_demande[5]=Quantite;
	    				    				else{ 
	    				    					if (strcmp(type,"O+")==0)
											daj.qt_demande[6]=Quantite;
	    									else	
					    						daj.qt_demande[7]=Quantite;
									}
								}
							}
						}
					}
				}
		if (Aj==1){
			result3=create_result3();
			gtk_widget_show(result3);
			aj=0;		
			ajouter_demande(daj);
		GDPS=lookup_widget(button,"GDPS");

		}
}



/////////////////////////////////////////////////////////////////////

void
on_Urgence2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	xw2=1;else xw2=0;
}


void
on_gdps_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	yw2=1; else yw2=0;
}


void
on_gdps_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
	yw2=2; else yw2=0;
}

void
on_Modifier_GDB_clicked                (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *nomet,*iddd,*x,*y,*jourr,*moiss,*Anneee,*Heuree1,*Heuree2,*idemaill,*infosuppp,*Notebook3;
GtkWidget *output20,*output40,*output60,*output50;
GtkWidget *GDPS;
char *erreur2,*erreur3,aux[10];
char email10[30];
char infosupp[300],h1ch[10],h2ch[10],*result,chem[30];
mod=1;
int b,c,h1,h2;

output20=lookup_widget(button,"gdps_label170");
output40=lookup_widget(button,"gdps_label171");
output60=lookup_widget(button,"gdps_label172");
output50=lookup_widget(button,"gdps_label204");



GDPS=lookup_widget(button,"GDPS");
nomet= lookup_widget(button,"gdps_entry24");
x= lookup_widget(button,"gdps_entry19");
y= lookup_widget(button,"gdps_entry21");
jourr= lookup_widget(button,"gdps_spinbutton4");	
moiss= lookup_widget(button,"gdps_spinbutton5");
Anneee= lookup_widget(button,"gdps_spinbutton6");
Heuree1= lookup_widget(button,"gdps_entry22");
Heuree2= lookup_widget(button,"gdps_entry74");
idemaill= lookup_widget(button,"gdps_entry20");
infosuppp = lookup_widget(button, "gdps_entry23");
char *erreurh,*erreurm;
int h,m,fl1=1,fl2=1;
    strcpy(dmod.demandeur, gtk_entry_get_text(GTK_ENTRY(nomet)));

strcpy(chem, gtk_entry_get_text(GTK_ENTRY(idemaill)));
result=strstr(chem,"@");
if (result == NULL )
{
    mod = 0;
gtk_label_set_markup(GTK_LABEL(output60), "<span color=\"red\">Erreur de Format !</span>");
}else{gtk_label_set_text(output60, " ");}

    strcpy(dmod.idemail, gtk_entry_get_text(GTK_ENTRY(idemaill)));


    strcpy(dmod.infosupp, gtk_entry_get_text(GTK_ENTRY(infosuppp)));
if(strcmp(dmod.infosupp,"")==0){mod=0;gtk_label_set_text(output50, "Saisir une info svp");}else{gtk_label_set_text(output50, " ");} 

    dmod.datedd.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jourr));
    dmod.datedd.mois = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(moiss));
    dmod.datedd.Annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(Anneee));

    h1=atoi(gtk_entry_get_text(GTK_ENTRY(Heuree1)));
    h2=atoi(gtk_entry_get_text(GTK_ENTRY(Heuree2)));
h=strtol(gtk_entry_get_text(GTK_ENTRY(Heuree1)), &erreurh, 10);
m=strtol(gtk_entry_get_text(GTK_ENTRY(Heuree2)), &erreurm, 10);

if ((h1 < 0 || h1 > 23) || (h2 < 0 || h2 > 59)) {
    fl1 = 0;
	mod=0;
}
if ((*erreurh != '\0' && *erreurh !='\n' ) || (*erreurm != '\0' && *erreurm !='\n' ))
{
    fl2 = 0;
	mod=0;

}

if(fl1==0 && fl2==1){
gtk_label_set_markup(GTK_LABEL(output20), "<span color=\"red\">Erreur d' Heure !</span>");
}
if(fl2==0){gtk_label_set_markup(GTK_LABEL(output20), "<span color=\"red\">Erreur de Type !</span>");}
if(fl1==1&&fl2==1){gtk_label_set_text(output20, " ");}

strcpy(h1ch,gtk_entry_get_text(GTK_ENTRY(Heuree1)));
strcpy(h2ch,gtk_entry_get_text(GTK_ENTRY(Heuree2)));

if (strlen(h2ch) == 1){
strcpy(aux,h2ch);
strcpy(h2ch,"0");
strcat(h2ch,aux);
}

strcat(h1ch,h2ch);

dmod.datedd.Heure = atoi(h1ch);



	b=strtol(gtk_entry_get_text(GTK_ENTRY(x)), &erreur2, 10);
	c=strtol(gtk_entry_get_text(GTK_ENTRY(y)), &erreur3, 10);
if (*erreur2 != '\0' && *erreur2 !='\n' ) 
{
    mod = 0;
gtk_label_set_markup(GTK_LABEL(output40), "<span color=\"red\">Erreur de Location !</span>");
}else{gtk_label_set_text(output40, " ");}
if (*erreur3 != '\0' && *erreur3 !='\n' ) 
{
    mod = 0;
gtk_label_set_markup(GTK_LABEL(output40), "<span color=\"red\">Erreur de Location !</span>");
}else{gtk_label_set_text(output40, " ");}

    dmod.place[0] = atoi(gtk_entry_get_text(GTK_ENTRY(x)));
    dmod.place[1] = atoi(gtk_entry_get_text(GTK_ENTRY(y)));
    if (xw2 == 0)
        dmod.urgency = 0;
    else if (xw2 == 1)
        dmod.urgency = 1;






    if (yw2 == 1 && mod==1) {
    Notebook3 = lookup_widget(button,"gdps_notebook3");
	gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook3),1);
    } else if (yw2 == 2 && mod==1) {
    Notebook3 = lookup_widget(button,"gdps_notebook3");
	gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook3),2);
    }

    xw2 = 0;
    yw2 = 0;
}
///////////////////////////////////////////////////////////////////////////////
void
on_Modif_recher_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *new_text,*gdps_treeview5;
GtkWidget *GDPS,*w1,*Notebook,*Notebook1;
        GtkWidget *result1;




    int value26;
    new_text=lookup_widget(button,"gdps_entry54");
value26=atoi(gtk_entry_get_text(GTK_ENTRY(new_text)));
    d_poche_de_sang dpp;

    dpp = chercherDemande("gdps.txt", value26);
    if (dpp.idd == -1)
    {
	result1 = create_result1();
	gtk_window_set_position(GTK_WINDOW(result1), GTK_WIN_POS_CENTER);
	gtk_widget_show(result1);
	gtk_window_present(GTK_WINDOW(result1));
    }
    if (dpp.idd != -1)
    {

	w1=lookup_widget(button,"GDPS");
	GDPS=create_GDPS();


	gtk_widget_show(GDPS);


	gtk_widget_hide(w1);

	gdps_treeview5=lookup_widget(GDPS,"gdps_treeview5");

	vider1(gdps_treeview5);



	afficher_demande3(gdps_treeview5,dpp.idd);
GDPS=lookup_widget(button,"GDPS");


}
}















////////////////////////////////////////////////////////////////////////////

void
on_Annuler_modif_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
	GtkWidget *Notebook;
Notebook = lookup_widget(button,"gdps_notebook3");
gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook),0);
}
///////////////////////////////////////////////////////////////////////////////
void
on_confer_type_modif_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
		
		mod=1;
		GtkWidget *GDPS;
		GtkWidget *result2;
		GtkWidget *result3;		
		char type[3],*erreur1;
		GtkWidget *typee,*Quantitee,*Affichage,*output;
		int Quantite,a;
		typee=lookup_widget(button,"gdps_comboboxentry2");
		Quantitee=lookup_widget(button,"gdps_entry64");
		output=lookup_widget(button,"gdps_label168");
		strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(typee)));
		a=strtol(gtk_entry_get_text(GTK_ENTRY(Quantitee)), &erreur1, 10);
if (*erreur1 != '\0' && *erreur1 !='\n' ) 
{
    mod = 0;
gtk_label_set_markup(GTK_LABEL(output), "<span color=\"red\">Erreur de Type !</span>");
}else{gtk_label_set_text(output, " ");}
		Quantite=atoi(gtk_entry_get_text(GTK_ENTRY(Quantitee)));
			


				if (strcmp(type,"A+")==0)
				dmod.qt_demande[0]=Quantite;
				else  {
			    		if (strcmp(type,"A-")==0)
						dmod.qt_demande[1]=Quantite;
					else	{
						if (strcmp(type,"B+")==0)
					    		dmod.qt_demande[2]=Quantite;
						else{ 
	    						if (strcmp(type,"B-")==0)
								dmod.qt_demande[3]=Quantite;
	    						else  {
	    							if (strcmp(type,"AB+")==0)
									dmod.qt_demande[4]=Quantite;
	    							else	{
					    				if (strcmp(type,"AB-")==0)
					    					dmod.qt_demande[5]=Quantite;
	    				    				else{ 
	    				    					if (strcmp(type,"O+")==0)
											dmod.qt_demande[6]=Quantite;
	    									else	
					    						dmod.qt_demande[7]=Quantite;
									}
								}
							}
						}
					}
				}
		if (mod==1){
			result2=create_result2();
			gtk_widget_show(result2);		
			modifierDemande2("gdps.txt",dmod,modon.idd, modon.idemail, modon.demandeur, modon.place[0], modon.place[1], modon.urgency, modon.datedd.Heure, modon.datedd.jour, modon.datedd.mois, modon.datedd.Annee);

		}
}

///////////////////////////////////////////////////////////////////////////////
void
on_Confirmer_modif_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *result2,*result5;
    GtkWidget *result3;
    GtkWidget *GDPS, *Affichage;
    GtkWidget *text3, *text4, *text5, *text6, *text7, *text8, *text9, *text10;
    int value3, value4, value5, value6, value7, value8, value9, value10;
	int a,b,c,d,e,f,g,h;
	char *erreur3,*erreur4,*erreur5,*erreur6,*erreur7,*erreur8,*erreur9,*erreur10;
	int mod=1;


text3=lookup_widget(button,"gdps_entry72");

a=strtol(gtk_entry_get_text(GTK_ENTRY(text3)), &erreur3, 10);
if (*erreur3 != '\0' && *erreur3 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value3=atoi(gtk_entry_get_text(GTK_ENTRY(text3)));
dmod.qt_demande[0]=value3;



text4=lookup_widget(button,"gdps_entry65");

b=strtol(gtk_entry_get_text(GTK_ENTRY(text4)), &erreur4, 10);
if (*erreur4 != '\0' && *erreur4 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value4=atoi(gtk_entry_get_text(GTK_ENTRY(text4)));
dmod.qt_demande[1]=value4;



text5=lookup_widget(button,"gdps_entry66");

c=strtol(gtk_entry_get_text(GTK_ENTRY(text5)), &erreur5, 10);
if (*erreur5 != '\0' && *erreur5 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value5=atoi(gtk_entry_get_text(GTK_ENTRY(text5)));
dmod.qt_demande[2]=value5;




text6=lookup_widget(button,"gdps_entry67");

d=strtol(gtk_entry_get_text(GTK_ENTRY(text6)), &erreur6, 10);
if (*erreur6 != '\0' && *erreur6 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value6=atoi(gtk_entry_get_text(GTK_ENTRY(text6)));
dmod.qt_demande[3]=value6;



text7=lookup_widget(button,"gdps_entry68");

e=strtol(gtk_entry_get_text(GTK_ENTRY(text7)), &erreur7, 10);
if (*erreur7 != '\0' && *erreur7 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value7=atoi(gtk_entry_get_text(GTK_ENTRY(text7)));
dmod.qt_demande[4]=value7;




text8=lookup_widget(button,"gdps_entry69");

f=strtol(gtk_entry_get_text(GTK_ENTRY(text8)), &erreur8, 10);
if (*erreur8 != '\0' && *erreur8 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value8=atoi(gtk_entry_get_text(GTK_ENTRY(text8)));
dmod.qt_demande[5]=value8;



text9=lookup_widget(button,"gdps_entry70");

g=strtol(gtk_entry_get_text(GTK_ENTRY(text9)), &erreur9, 10);
if (*erreur9 != '\0' && *erreur9 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value9=atoi(gtk_entry_get_text(GTK_ENTRY(text9)));
dmod.qt_demande[6]=value9;




text10=lookup_widget(button,"gdps_entry71");

h=strtol(gtk_entry_get_text(GTK_ENTRY(text10)), &erreur10, 10);
if (*erreur10 != '\0' && *erreur10 !='\n' ) 
{
    mod = 0;
        result5 = create_result5();
	gtk_window_set_position(GTK_WINDOW(result5), GTK_WIN_POS_CENTER);
	gtk_widget_show(result5);
	gtk_window_present(GTK_WINDOW(result5));

    
}

value10=atoi(gtk_entry_get_text(GTK_ENTRY(text10)));
dmod.qt_demande[7]=value10;
if (mod==1){
modifierDemande2("gdps.txt",dmod,modon.idd, modon.idemail, modon.demandeur, modon.place[0], modon.place[1], modon.urgency, modon.datedd.Heure, modon.datedd.jour, modon.datedd.mois, modon.datedd.Annee);
result2 = create_result2();
gtk_widget_show(result2);
}
}



////////////////////////////////////////////////////////////////////////////


void
on_gdps_Afficher_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Affichage;
GtkWidget *resultat_recherche;
Affichage=lookup_widget(button,"Affichage");

resultat_recherche=lookup_widget(button,"resultat_recherche");
resultat_recherche=create_resultat_recherche();
gtk_widget_show (resultat_recherche);
gtk_widget_destroy(Affichage);
}


/////////////////////////////recherche////////////////////////////////////////////////////

void on_confirmer_recher_clicked(GtkWidget *button, gpointer user_data)
{
    GtkWidget *new_text,*gdps_treeview3;
GtkWidget *resultat_recherche,*w1;
        GtkWidget *result1;




    int value26;
    new_text=lookup_widget(button,"gdps_entry26");
value26=atoi(gtk_entry_get_text(GTK_ENTRY(new_text)));
    d_poche_de_sang dpp;

    dpp = chercherDemande("gdps.txt", value26);
    if (dpp.idd == -1)
    {
	result1 = create_result1();
	gtk_window_set_position(GTK_WINDOW(result1), GTK_WIN_POS_CENTER);
	gtk_widget_show(result1);
	gtk_window_present(GTK_WINDOW(result1));
    }
    if (dpp.idd != -1)
    {

	w1=lookup_widget(button,"resultat_recherche");
	resultat_recherche=create_resultat_recherche();


	gtk_widget_show(resultat_recherche);


	gtk_widget_hide(w1);
	gdps_treeview3=lookup_widget(resultat_recherche,"gdps_treeview3");

	vider1(gdps_treeview3);
	afficher_demande3(gdps_treeview3,dpp.idd);
resultat_recherche=lookup_widget(button,"resultat_recherche");







}
}


/////////////////////////////actualiser///////////////////////////////////////////////////////



void
on_gdps_Actualiser_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Affichage,*w1;
	GtkWidget *gdps_treeview1;


	w1=lookup_widget(button,"Affichage");
	Affichage=create_Affichage();


	gtk_widget_show(Affichage);


	gtk_widget_hide(w1);
	gdps_treeview1=lookup_widget(Affichage,"gdps_treeview1");

	vider1(gdps_treeview1);
	afficher_demande1(gdps_treeview1);

}



///////////////////////////////////////////////////////////////////////////////////








void
on_gdps_treeview1_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	int A;	
	GtkWidget *result4;
	GtkTreeIter iter;
	gchar* idd;
	gchar* urgency;
	gchar* x;
	gchar* y;
	gchar* idemail;
	gchar* demandeur;
	gchar* Heure;
	gchar* jour;
	gchar* mois;
	gchar* Annee;
	int val1,val2,val3,val4,val5,val6,val7,val8;
	

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&idd,1,&demandeur,2,&idemail,3,&x,4,&y,5,&Heure,6,&jour,7,&mois,8,&Annee,9,&urgency,-1);
		val1=atoi(idd);
		val2=atoi(x);
		val3=atoi(y);
		val4=atoi(urgency);
		val5=atoi(Heure);
		val6=atoi(jour);
		val7=atoi(mois);
		val8=atoi(Annee);

		A=supprimerDemande2("gdps.txt",val1,idemail,demandeur,val2,val3,val4,val5,val6,val7,val8);
		afficher_demande1(treeview);
		result4=create_result4();
		gtk_widget_show(result4);
	}
}




////////////////////////////////////////////////////////////////////////////////////////////////

void
on_Confirmer_GDPS_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *new_text,*GDPS,*result4,*result1;
    int iddd,testsupp;
    new_text=lookup_widget(button,"gdps_entry25");
    iddd=atoi(gtk_entry_get_text(GTK_ENTRY(new_text)));
    testsupp=supprimerDemande("gdps.txt", iddd);
		if(testsupp == 0){
			result1=create_result1();
			gtk_widget_show(result1);}
		else {result4=create_result4();
			gtk_widget_show(result4);}
}






























//////////////////////////////////////////////////////////////////////////////




void
on_gdps_retour_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *resultat_recherche, *Affichage;
resultat_recherche=lookup_widget(button,"resultat_recherche");

Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(resultat_recherche);
}

















void
on_RetourAj_ver_Aff_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS, *Affichage;
GDPS=lookup_widget(button,"GDPS");

Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}


void
on_RetourMod_ver_Aff_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS, *Affichage;
GDPS=lookup_widget(button,"GDPS");

Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}


void
on_RetourSupp_ver_Aff_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS, *Affichage;
GDPS=lookup_widget(button,"GDPS");

Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}


void
on_LeType_Annuler_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *GDPS, *Notebook;
Notebook = lookup_widget(button,"gdps_notebook2");
gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook),0);
}



////////////////////////////////////////////////////////

void
on_Statistique_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *static1,*output,*output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9;
	static1=lookup_widget(button,"static1");
	static1=create_static1();
	gtk_widget_show(static1);



}

void
on_calcul_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *static1,*output,*output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9;
	static1=lookup_widget(button,"static1");
	int val1,val2,val3,val4,val5,val6,val7,val8;
	char res[4];
	char Va1[50],Va2[50],Va3[50],Va4[50],Va5[50],Va6[50],Va7[50],Va8[50];
	
	val1=quantiteDemandee_type("gdps.txt", "A+");
	val2=quantiteDemandee_type("gdps.txt", "A-");
	val3=quantiteDemandee_type("gdps.txt", "B+");
	val4=quantiteDemandee_type("gdps.txt", "B-");
	val5=quantiteDemandee_type("gdps.txt", "AB+");
	val6=quantiteDemandee_type("gdps.txt", "AB-");
	val7=quantiteDemandee_type("gdps.txt", "O+");
	val8=quantiteDemandee_type("gdps.txt", "O-");
	sang_demandee("gdps.txt", res);



sprintf(Va1,"%d", val1);
sprintf(Va2,"%d", val2);
sprintf(Va3,"%d", val3);
sprintf(Va4,"%d", val4);
sprintf(Va5,"%d", val5);
sprintf(Va6,"%d", val6);
sprintf(Va7,"%d", val7);
sprintf(Va8,"%d", val8);

output=lookup_widget(button,"gdps_label188");
output2=lookup_widget(button,"gdps_label187");
output3=lookup_widget(button,"gdps_label190");
output4=lookup_widget(button,"gdps_label189");
output5=lookup_widget(button,"gdps_label192");
output6=lookup_widget(button,"gdps_label191");
output7=lookup_widget(button,"gdps_label194");
output8=lookup_widget(button,"gdps_label193");


output9=lookup_widget(button,"gdps_label178");

gtk_label_set_text(output,Va1);
gtk_label_set_text(output2,Va2);
gtk_label_set_text(output3,Va3);
gtk_label_set_text(output4,Va4);
gtk_label_set_text(output5,Va5);
gtk_label_set_text(output6,Va6);
gtk_label_set_text(output7,Va7);
gtk_label_set_text(output8,Va8);


gtk_label_set_text(output9,res);
}











void
on_Annulerletype_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Notebook;
Notebook = lookup_widget(button,"gdps_notebook3");
gtk_notebook_set_current_page(GTK_NOTEBOOK(Notebook),0);
}






void
on_actualiser_stat_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *static1,*w2;
	GtkWidget *gdps_treeview2,*Notebook;
	w2=lookup_widget(button,"static1");
	Notebook = lookup_widget(button,"gdps_notebook4");

	static1=create_static1();


	gtk_widget_show(static1);


	gtk_widget_hide(w2);
	gdps_treeview2=lookup_widget(static1,"gdps_treeview2");

	vider2(gdps_treeview2);
	afficher_demande2(gdps_treeview2);
}


void
on_gdps_treeview2_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

	int A;	
	GtkWidget *result4;
	GtkTreeIter iter;
	gchar* idd;
	d_poche_de_sang d;
	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&idd,-1);
		d.idd=atoi(idd);
		A=supprimerDemande("gdps.txt",d.idd);
		afficher_demande2(treeview);
		result4=create_result4();
		gtk_widget_show(result4);	
	}
}





void
on_Aff_ret_aj_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS,*Affichage;
GDPS=lookup_widget(button,"GDPS");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}


void
on_Aff_ret2_aj_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS,*Affichage;
GDPS=lookup_widget(button,"GDPS");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}


void
on_Aff_ret2_mod_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS,*Affichage;
GDPS=lookup_widget(button,"GDPS");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}


void
on_Aff_ret_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *GDPS,*Affichage;
GDPS=lookup_widget(button,"GDPS");
Affichage=create_Affichage();
gtk_widget_show(Affichage);
gtk_widget_destroy(GDPS);
}





















void
on_gdps_treeview3_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *output8, *output11, *output12, *output13, *output14, *output15, *output16, *output17, *output18;
GtkWidget *resultat_recherche;	

	GtkTreeIter iter;
	gchar* idd;
	gchar* urgency;
	gchar* x;
	gchar* y;
	gchar* idemail;
	gchar* demandeur;
	gchar* Heure;
	gchar* jour;
	gchar* mois;
	gchar* Annee;
	int val1,val2,val3,val4,val5,val6,val7,val8;
	d_poche_de_sang dpp;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&idd,1,&demandeur,2,&idemail,3,&x,4,&y,5,&Heure,6,&jour,7,&mois,8,&Annee,9,&urgency,-1);
		val1=atoi(idd);
		val2=atoi(x);
		val3=atoi(y);
		val4=atoi(urgency);
		val5=atoi(Heure);
		val6=atoi(jour);
		val7=atoi(mois);
		val8=atoi(Annee);

		dpp=chercherDemande2("gdps.txt",val1,idemail,demandeur,val2,val3,val4,val5,val6,val7,val8);



char qt_demande0[20], qt_demande1[20], qt_demande2[20], qt_demande3[20], qt_demande4[20], qt_demande5[20], qt_demande6[20], qt_demande7[20];
sprintf(qt_demande0,"%d", dpp.qt_demande[0]);
sprintf(qt_demande1,"%d", dpp.qt_demande[1]);
sprintf(qt_demande2,"%d", dpp.qt_demande[2]);
sprintf(qt_demande3,"%d", dpp.qt_demande[3]);
sprintf(qt_demande4,"%d", dpp.qt_demande[4]);
sprintf(qt_demande5,"%d", dpp.qt_demande[5]);
sprintf(qt_demande6,"%d", dpp.qt_demande[6]);
sprintf(qt_demande7,"%d", dpp.qt_demande[7]);






output8=lookup_widget(treeview,"gdps_label87");

output11=lookup_widget(treeview,"gdps_label98");
output12=lookup_widget(treeview,"gdps_label99");
output13=lookup_widget(treeview,"gdps_label100");
output14=lookup_widget(treeview,"gdps_label101");
output15=lookup_widget(treeview,"gdps_label102");
output16=lookup_widget(treeview,"gdps_label103");
output17=lookup_widget(treeview,"gdps_label104");
output18=lookup_widget(treeview,"gdps_label105");




gtk_label_set_text(output8,dpp.infosupp);
gtk_label_set_text(output11,qt_demande0);
gtk_label_set_text(output12,qt_demande1);
gtk_label_set_text(output13,qt_demande2);
gtk_label_set_text(output14,qt_demande3);
gtk_label_set_text(output15,qt_demande4);
gtk_label_set_text(output16,qt_demande5);
gtk_label_set_text(output17,qt_demande6);
gtk_label_set_text(output18,qt_demande7);


}
}




void
on_gdps_treeview5_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *iddd,*result1;
GtkWidget *output,*output1,*output2, *output3, *output4, *output5, *output6, *output7, *output8, *output9, *output10,*output11;
    char urgencych[100];
    char Xch[100];
    char Ych[100];
    char jourch[100];
    char moisch[100];
    char Anneech[100];
    char Heurech[100];
	GtkTreeIter iter;
	gchar* idd;
	gchar* urgency;
	gchar* x;
	gchar* y;
	gchar* idemail;
	gchar* demandeur;
	gchar* Heure;
	gchar* jour;
	gchar* mois;
	gchar* Annee;
	int val1,val2,val3,val4,val5,val6,val7,val8;
	d_poche_de_sang dpp;

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);
	if(gtk_tree_model_get_iter(model,&iter,path)){
		gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&idd,1,&demandeur,2,&idemail,3,&x,4,&y,5,&Heure,6,&jour,7,&mois,8,&Annee,9,&urgency,-1);
		val1=atoi(idd);
		val2=atoi(x);
		val3=atoi(y);
		val4=atoi(urgency);
		val5=atoi(Heure);
		val6=atoi(jour);
		val7=atoi(mois);
		val8=atoi(Annee);

		dpp=chercherDemande2("gdps.txt",val1,idemail,demandeur,val2,val3,val4,val5,val6,val7,val8);
sprintf(urgencych,"%d", dpp.urgency);
sprintf(Xch,"%d", dpp.place[0]);
sprintf(Ych,"%d", dpp.place[1]);
sprintf(jourch,"%d", dpp.datedd.jour);
sprintf(moisch,"%d", dpp.datedd.mois);
sprintf(Anneech,"%d", dpp.datedd.Annee);
sprintf(Heurech,"%d", dpp.datedd.Heure);



output1=lookup_widget(treeview,"gdps_label157");
output2=lookup_widget(treeview,"gdps_label158");
output3=lookup_widget(treeview,"gdps_label159");
output4=lookup_widget(treeview,"gdps_label160");
output5=lookup_widget(treeview,"gdps_label161");
output6=lookup_widget(treeview,"gdps_label162");
output7=lookup_widget(treeview,"gdps_label163");
output8=lookup_widget(treeview,"gdps_label164");
output9=lookup_widget(treeview,"gdps_label165");
output10=lookup_widget(treeview,"gdps_label166");
output11=lookup_widget(treeview,"gdps_label167");

char part1[5], minu[3], heur[3];
int len;
len = strlen(Heurech);

if (len == 3) {
    strcpy(part1, "0");
    strcat(part1, Heurech);
} else if (len == 2) {
    strcpy(part1, "00");
    strcat(part1, Heurech);
} else if (len == 4) {
    strcpy(part1, Heurech);
}

heur[0] = part1[0];
heur[1] = part1[1];
heur[2] = '\0';

minu[0] = part1[2];
minu[1] = part1[3];
minu[2] = '\0';


gtk_label_set_text(output1,dpp.demandeur);
gtk_label_set_text(output2,Xch);
gtk_label_set_text(output3,Ych);
gtk_label_set_text(output4,jourch);
gtk_label_set_text(output5,moisch);
gtk_label_set_text(output6,Anneech);
gtk_label_set_text(GTK_LABEL(output7), heur);
gtk_label_set_text(GTK_LABEL(output8), minu);
gtk_label_set_text(output9,dpp.idemail);
gtk_label_set_text(output10,dpp.infosupp);
gtk_label_set_text(output11,urgencych);
modon = dpp;
dmod.idd=modon.idd;
}}

//******************************************************************************---***********************---************---****************

int xq,yq,x1,y1,y2;
char input_textsearch[9];
admin_user userselected;

void
on_adminuseraddentrymale_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
yq=1;
else 
yq=0;
}


void
on_adminuseraddentryfemale_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
yq=2;
else
yq=0;
}


void
on_adminuseraddentrydoctor_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
xq=0;
}

void
on_adminuseraddentrynurse_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
xq=1;
}
void
on_adminuseraddentrydirector_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
xq=2;
}


void
on_adminaddnewstaffsubmit_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
admin_user new_user;

strcpy(new_user.adminuser_username, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryusername"))));
strcpy(new_user.adminuser_password, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentrypassword"))));
strcpy(new_user.adminuser_name, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryname"))));         
strcpy(new_user.adminuser_surname, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentrysurname"))));
if (xq==0)
strcpy(new_user.adminuser_role,"doctor");
else if (xq==1)
strcpy(new_user.adminuser_role,"nurse");
else if (xq==2)
strcpy(new_user.adminuser_role,"director");
strcpy(new_user.adminuser_phone, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryphone"))));
strcpy(new_user.adminuser_email, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryemail"))));
if (yq==1)
{
strcpy(new_user.adminuser_gender,"male");
}

else if (yq==2){
strcpy(new_user.adminuser_gender,"female");}
strcpy(new_user.adminuser_identification_card_number, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryid"))));
strcpy(new_user.adminuser_address, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryadress"))));
strcpy(new_user.adminuser_region, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminuseraddentryregion"))));
int join_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminuseraddentryday")));
int join_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminuseraddentrymonth")));
int join_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminuseraddentryyear")));
 snprintf(new_user.adminuser_joindate, sizeof(new_user.adminuser_joindate), "%02d/%02d/%04d", join_day, join_month, join_year);

 int user_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminuseraddentrybday")));
 int user_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminuseraddentrybmonth")));
 int user_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminuseraddentrybyear")));
 snprintf(new_user.adminuser_date, sizeof(new_user.adminuser_date), "%02d/%02d/%04d", user_day, user_month, user_year);
  if (!is_valid_username(new_user.adminuser_username)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelusername")), "<span color=\"red\">Donnée invalide</span>");}
  else
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelusername")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_password(new_user.adminuser_password)){gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelpassword")), "<span color=\"red\">Donnée invalide</span>");} 
   else
   {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelpassword")), "<span color=\"green\">Donnée valide</span>");} 
   if (!is_alpha_string(new_user.adminuser_name)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelname")), "<span color=\"red\">Donnée invalide</span>");}
   else
   {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelname")), "<span color=\"green\">Donnée valide</span>");}
  if (!is_alpha_string(new_user.adminuser_surname)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelsurname")), "<span color=\"red\">Donnée invalide</span>");}
  else
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelsurname")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_email(new_user.adminuser_email)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelemail")), "<span color=\"red\">Donnée invalide</span>");}
   else
   { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelemail")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_region(new_user.adminuser_region)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelregion")), "<span color=\"red\">Donnée invalide</span>");}
   else  
   { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelregion")), "<span color=\"green\">Donnée valide</span>");}
    if (!is_valid_phone(new_user.adminuser_phone)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelphone")), "<span color=\"red\">Donnée invalide</span>");}
    else
     {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelphone")), "<span color=\"green\">Donnée valide</span>");}
    if (!is_valid_id(new_user.adminuser_identification_card_number))  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelid")), "<span color=\"red\">Donnée invalide</span>");}
    else
    { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelid")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_address(new_user.adminuser_address)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabeladress")), "<span color=\"red\">Donnée invalide</span>");}
     else
     { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabeladress")), "<span color=\"green\">Donnée valide</span>");}
    ////////////////////////////////////////////
    
    if (!is_valid_username(new_user.adminuser_username)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelusername")), "<span color=\"red\">Donnée invalide</span>");}
    else if (!is_valid_password(new_user.adminuser_password)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelpassword")), "<span color=\"red\">Donnée invalide</span>");}
   else if (!is_alpha_string(new_user.adminuser_name))  {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelname")), "<span color=\"red\">Donnée invalide</span>");}
 else if (!is_alpha_string(new_user.adminuser_surname)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelsurname")), "<span color=\"red\">Donnée invalide</span>");}
    else if (!is_valid_email(new_user.adminuser_email)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelemail")), "<span color=\"red\">Donnée invalide</span>");}
  else if (!is_valid_region(new_user.adminuser_region)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelregion")), "<span color=\"red\">Donnée invalide</span>");}
  else  if (!is_valid_phone(new_user.adminuser_phone)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelphone")), "<span color=\"red\">Donnée invalide</span>");}
  
  else  if (!is_valid_id(new_user.adminuser_identification_card_number)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabelid")), "<span color=\"red\">Donnée invalide</span>");}
  else  if (!is_valid_address(new_user.adminuser_address)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserlabeladress")), "<span color=\"red\">Donnée invalide</span>");}
  else{
  int add_result = admin_user_add("adminusers.txt", new_user);
   if (add_result == 1)
        gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "label_status")), "<span color=\"green\">Ajout avec succès.</span>");
    else
        gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "label_status")), "<span color=\"red\">Ajout échoués</span>");
}
}








void
on_adminviewmodify_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
int verif;
GtkWidget* notebook;
notebook=lookup_widget(button, "adminuser") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),2) ;
gtk_entry_set_text(GTK_ENTRY(lookup_widget(button, "searchentry")),userselected.adminuser_identification_card_number);
 verif= admin_user_verif("adminusers.txt", userselected.adminuser_identification_card_number); 
 if (verif==1)
 {admin_user user;
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "searchuserresult")), "Utilisateur trouvé");
 user=admin_user_search("adminusers.txt", userselected.adminuser_identification_card_number);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldusername")), user.adminuser_username);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldpassword")), user.adminuser_password);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldname")),  user.adminuser_name);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldsurname")), user.adminuser_surname);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldrole")), user.adminuser_role);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldphone")), user.adminuser_phone);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldemail")),  user.adminuser_email);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldgender")), user.adminuser_gender);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldid")), userselected.adminuser_identification_card_number);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldadress")), user.adminuser_address);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuserolddate2")),  user.adminuser_joindate);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuseroldregion")), user.adminuser_region);
 gtk_label_set_text(GTK_LABEL(lookup_widget(button, "adminuserolddate")), user.adminuser_date);
 
  
}
}


void
on_adminviewdelete_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
admin_user_delete("adminusers.txt", userselected.adminuser_identification_card_number);

}


void
on_adminusermodifyentrymale_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y1=1;
}


void
on_adminusermodifyentryfemale_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y1=2;
}

void
on_adminusermodifyentrynurse_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x1=1;
}


void
on_adminusermodifyentrydoctor_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x1=0;
}


void
on_adminusermodifyentrydirector_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
x1=2;
}
void
on_adminusermodifysubmit_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
char result[50];

strcpy(result,GTK_LABEL(lookup_widget(button, "searchuserresult")));
//if (strcmp(result,"user found")==0)
//{
admin_user user;
user=admin_user_search("adminusers.txt", input_textsearch);
admin_user new_user;
strcpy(new_user.adminuser_username, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryusername"))));
strcpy(new_user.adminuser_password, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentrypassword"))));
strcpy(new_user.adminuser_name, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryname"))));         
 strcpy(new_user.adminuser_surname, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentrysurname"))));
if (x1==0)
strcpy(new_user.adminuser_role,"doctor");
else if (x1==1)
strcpy(new_user.adminuser_role,"nurse");
else if (x1==2)
strcpy(new_user.adminuser_role,"director");
strcpy(new_user.adminuser_phone, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryphone"))));
strcpy(new_user.adminuser_email, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryemail"))));
if (y1==1)
{
strcpy(new_user.adminuser_gender, "male");
}

else if (y1==2){
strcpy(new_user.adminuser_gender, "female");}
strcpy(new_user.adminuser_identification_card_number, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryid"))));
strcpy(new_user.adminuser_address, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryadress"))));
strcpy(new_user.adminuser_region, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "adminusermodifyentryregion"))));
int join_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminusermodifyentryday2")));
int join_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminusermodifyentrymonth2")));
int join_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminusermodifyentryyear2")));
 snprintf(new_user.adminuser_joindate, sizeof(new_user.adminuser_joindate), "%02d/%02d/%04d", join_day, join_month, join_year);

 int user_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminusermodifyentryday")));
 int user_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminusermodifyentrymonth")));
 int user_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "adminusermodifyentryyear")));
 snprintf(new_user.adminuser_date, sizeof(new_user.adminuser_date), "%02d/%02d/%04d", user_day, user_month, user_year);
  if (!is_valid_username(new_user.adminuser_username)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredusername")),  " <span color=\"red\">Donnée invalide</span>");}
  else
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredusername")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_password(new_user.adminuser_password)){gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredpassword")),   "<span color=\"red\">Donnée invalide</span>");} 
   else
   {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredpassword")), "<span color=\"green\">Donnée valide</span>");} 
   if (!is_alpha_string(new_user.adminuser_name)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredname")),  "<span color=\"red\">Donnée invalide</span>");}
   else
   {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredname")), "<span color=\"green\">Donnée valide</span>");}
  if (!is_alpha_string(new_user.adminuser_surname)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredsurname")),   "<span color=\"red\">Donnée invalide</span>");}
  else
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredsurname")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_email(new_user.adminuser_email)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredemail")), "<span color=\"red\">Donnée invalide</span>");}
   else
   { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredemail")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_region(new_user.adminuser_region)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredregion")),   "<span color=\"red\">Donnée invalide</span>");}
   else  
   { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredregion")), "<span color=\"green\">Donnée valide</span>");}
    if (!is_valid_phone(new_user.adminuser_phone)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredphone")),   "<span color=\"red\">Donnée invalide</span>");}
    else
     {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredphone")),"<span color=\"green\">Donnée valide</span>");}
    if (!is_valid_id(new_user.adminuser_identification_card_number))  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredid")),   "<span color=\"red\">Donnée invalide</span>");}
    else
    { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredid")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_address(new_user.adminuser_address)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredadress")),   "<span color=\"red\">Donnée invalide</span>");}
     else
     { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredadress")), "<span color=\"green\">Donnée valide</span>");}
    ////////////////////////////////////////////
    
    if (!is_valid_username(new_user.adminuser_username)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredusername")),   "<span color=\"red\">Donnée invalide</span>");}
    else if (!is_valid_password(new_user.adminuser_password)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredpassword")),   "<span color=\"red\">Donnée invalide</span>");}
   else if (!is_alpha_string(new_user.adminuser_name))  {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredname")),   "<span color=\"red\">Donnée invalide</span>");}
 else if (!is_alpha_string(new_user.adminuser_surname)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredsurname")),   "<span color=\"red\">Donnée invalide</span>");}
    else if (!is_valid_email(new_user.adminuser_email)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredemail")),   "<span color=\"red\">Donnée invalide</span>");}
  else if (!is_valid_region(new_user.adminuser_region)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredregion")),   "<span color=\"red\">Donnée invalide</span>");}
  else  if (!is_valid_phone(new_user.adminuser_phone)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredphone")),  "<span color=\"red\">Donnée invalide</span>");}
  
  else  if (!is_valid_id(new_user.adminuser_identification_card_number)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredid")),  "<span color=\"red\">Donnée invalide</span>");}
  else  if (!is_valid_address(new_user.adminuser_address)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminmodifyrequiredadress")),   "<span color=\"red\">Donnée invalide</span>");}
  else{
  int modify_result = admin_user_edit("adminusers.txt",input_textsearch,new_user);
   if (modify_result == 1)
        gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "label_statusmodify")), "<span color=\"green\">Ajout avec succès.</span>");
    else
        gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "label_statusmodify")), "<span color=\"red\">Modification échoués</span>");
}
//}

}

void
on_adminusersubmitsearch_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

int verif;

strncpy(input_textsearch, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "searchentry"))),9 );
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldusername")),"");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldpassword")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldname")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldsurname")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldrole")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldphone")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldemail")),  "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldgender")),"");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldid")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldadress")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserolddate2")),  "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldregion")), "");
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserolddate")),"");
 
      
 if (!is_valid_id(input_textsearch) )
    
   gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "searchuserresult")), " not valid ");
   else
   { 
 verif= admin_user_verif("adminusers.txt", input_textsearch); 
 if (verif==1)
 {admin_user user;
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "searchuserresult")), "Utilisateur trouvé");
 user=admin_user_search("adminusers.txt", input_textsearch);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldusername")), user.adminuser_username);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldpassword")), user.adminuser_password);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldname")),  user.adminuser_name);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldsurname")), user.adminuser_surname);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldrole")), user.adminuser_role);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldphone")), user.adminuser_phone);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldemail")),  user.adminuser_email);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldgender")), user.adminuser_gender);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldid")), user.adminuser_identification_card_number);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldadress")), user.adminuser_address);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserolddate2")),  user.adminuser_joindate);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuseroldregion")), user.adminuser_region);
 gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserolddate")), user.adminuser_date);
 
  
}
else 
gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "searchuserresult")), " Utilisateur non trouvé ");
}
}


void
on_adminuserdeletebutton_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
char input_text[9];
int delete_result;
 strncpy(input_text, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "deleteentryconfirm"))),9 );

      
 if (!is_valid_id(input_text) )
    {
   gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserdeletemessage")), " not valid ");
    }
  
    else
    { 
      delete_result = admin_user_delete("adminusers.txt", input_text);    
if (delete_result==1) 
{ gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserdeletemessage")), "<span color=\"green\">Supprimer avec succès.</span>");}
  else 
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "adminuserdeletemessage")), "<span color=\"red\">Utilisateur non trouvé</span>");
  }
  }
  }
void
on_adminusertreeview_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *username;
gchar *name;
gchar *surname ;
gchar *region;
gchar *phone;
gchar *role ;
gchar *email ;
gchar *gender ;
gchar *id ;
gchar *adress;
gchar *joindate;
gchar *date;

GtkTreeModel *model= gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&username,1,&name,2,&surname,3,&region,4,&phone,5,&role,6,&email,7,&gender,8,&id,9,&adress,10,&joindate,11,&date,-1);
strcpy(userselected.adminuser_gender,gender);
strcpy(userselected.adminuser_identification_card_number, id);
strcpy(userselected.adminuser_address, adress);
strcpy(userselected.adminuser_region, region);
strcpy(userselected.adminuser_username,username);
strcpy(userselected.adminuser_name,name);
strcpy(userselected.adminuser_surname,surname);
strcpy(userselected.adminuser_phone,phone);
strcpy(userselected.adminuser_role,role);
strcpy(userselected.adminuser_email,email);
strcpy(userselected.adminuser_joindate,joindate);
strcpy(userselected.adminuser_date,date);
}
}
void
on_treeviewshow_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char choice[50];
GtkWidget*combobox ;
combobox=lookup_widget(button,"adminuserchoice");
strcpy(choice,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
GtkWidget *treeview;
treeview=lookup_widget(button,"adminusertreeview");
if (strcmp(choice,"All")==0){
show_user("adminusers.txt",treeview);

}
if(strcmp(choice,"doctor")==0)
{
UserRole("adminusers.txt","doctor");
show_user("role.txt",treeview);

}
if(strcmp(choice,"admin")==0)
{
UserRole("adminusers.txt","admin");
show_user("role.txt",treeview);
}
if(strcmp(choice,"nurse")==0)
{
UserRole("adminusers.txt","nurse");
show_user("role.txt",treeview);
}
if(strcmp(choice,"director")==0)
{
UserRole("adminusers.txt","director");
show_user("role.txt",treeview);

}
if(strcmp(choice,"donor")==0)
{
UserRole("adminusers.txt","donor");
show_user("role.txt",treeview);

}

}


void
on_authsignin_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2 ,*Admin,*authpage,*director,*doctor,*nurse;
char a[50],b[50],role[50];
int k;
authpage = lookup_widget(button, "authpage");
/*strcpy(input1,lookup_widget(button,"authusername"));
strcpy(input2,lookup_widget(button,"authpassword"));
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(b,gtk_entry_get_text(GTK_ENTRY(input2)));*/
strcpy(a,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "authusername"))));
strcpy(b,gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "authpassword"))));
k=userrolecheck(a,b,role);
if (k==1)
gtk_label_set_text(GTK_LABEL(lookup_widget(button, "testsignin")), role);


if (strcmp(role,"admin")==0 )
{
Admin= create_Admin();
gtk_widget_show(Admin);
gtk_window_fullscreen(GTK_WINDOW(Admin));
gtk_widget_hide(authpage);
}
if ((strcmp(role,"nurse")==0) || (strcmp(role,"infirmier")==0))
{
nurse= create_espaceinfirmier();//////////////////:
gtk_widget_show(nurse);
gtk_window_fullscreen(GTK_WINDOW(nurse));
gtk_widget_hide(authpage);
}

if ((strcmp(role,"doctor"))==0 || (strcmp(role,"medecin")==0))
{
doctor= create_window_don();
gtk_widget_show(doctor);//////////////
gtk_window_fullscreen(GTK_WINDOW(doctor));
gtk_widget_hide(authpage);
}


if (strcmp(role,"director")==0 || (strcmp(role,"ressponsable")==0))
{
director= create_Affichage();//////////////
gtk_widget_show(director);
gtk_window_fullscreen(GTK_WINDOW(director));
gtk_widget_hide(authpage);
}
/*
if (strcmp(role,"donor")==0)
{
donor= create_donor();///////////////::
gtk_widget_show(donor);
gtk_window_fullscreen(GTK_WINDOW(donor));

gtk_widget_hide(authpage);
}*/
}

void
on_authsignup_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *adminuseradddonor;
adminuseradddonor= create_adminuseradddonor();
gtk_widget_show(adminuseradddonor);
gtk_window_fullscreen(GTK_WINDOW(adminuseradddonor));
}


void
on_donorsubmit_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
admin_user new_user;

strcpy(new_user.adminuser_username, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorusername"))));
strcpy(new_user.adminuser_password, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorpassword"))));
strcpy(new_user.adminuser_name, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorname"))));         
 strcpy(new_user.adminuser_surname, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorsurname"))));
strcpy(new_user.adminuser_phone, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorphone"))));
strcpy(new_user.adminuser_email, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donoremail"))));
if (y2==1)
{
strcpy(new_user.adminuser_gender, "male");
}

else if (y2==2){
strcpy(new_user.adminuser_gender, "female");}
strcpy(new_user.adminuser_identification_card_number, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorid"))));
strcpy(new_user.adminuser_address, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donoradress"))));
strcpy(new_user.adminuser_region, gtk_entry_get_text(GTK_ENTRY(lookup_widget(button, "donorregion"))));
int join_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "donorday")));
int join_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "donormonth")));
int join_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "donoryear")));
 snprintf(new_user.adminuser_joindate, sizeof(new_user.adminuser_joindate), "%02d/%02d/%04d", join_day, join_month, join_year);

 int user_day = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "donorbday")));
 int user_month = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "donorbmonth")));
 int user_year = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(lookup_widget(button, "donorbyear")));
 snprintf(new_user.adminuser_date, sizeof(new_user.adminuser_date), "%02d/%02d/%04d", user_day, user_month, user_year);
 strcpy(new_user.adminuser_role,"donor");
  if (!is_valid_username(new_user.adminuser_username)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvusername")),   "<span color=\"red\">Donnée invalide</span>");}
  else
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvusername")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_password(new_user.adminuser_password)){gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvpassword")),   "<span color=\"red\">Donnée invalide</span>");} 
   else
   {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvpassword")), "<span color=\"green\">Donnée valide</span>");} 
   if (!is_alpha_string(new_user.adminuser_name)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvname")),   "<span color=\"red\">Donnée invalide</span>");}
   else
   {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvname")), "<span color=\"green\">Donnée valide</span>");}
  if (!is_alpha_string(new_user.adminuser_surname)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvsurname")),  "<span color=\"red\">Donnée invalide</span>");}
  
  else
  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvsurname")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_email(new_user.adminuser_email)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvemail")),  "<span color=\"red\">Donnée invalide</span>");}
   else
   { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvemail")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_region(new_user.adminuser_region)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvregion")),  "<span color=\"red\">Donnée invalide</span>");}
   else  
   { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvregion")), "<span color=\"green\">Donnée valide</span>");}
    if (!is_valid_phone(new_user.adminuser_phone)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvphone")),   "<span color=\"red\">Donnée invalide</span>");}
    else
     {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvphone")),"<span color=\"green\">Donnée valide</span>");}
    if (!is_valid_id(new_user.adminuser_identification_card_number))  { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvid")),   "<span color=\"red\">Donnée invalide</span>");}
    else
    { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvid")), "<span color=\"green\">Donnée valide</span>");}
   if (!is_valid_address(new_user.adminuser_address)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvadress")),   "<span color=\"red\">Donnée invalide</span>");}
     else
     { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvadress")), "<span color=\"green\">Donnée valide</span>");}
    ////////////////////////////////////////////
    
    if (!is_valid_username(new_user.adminuser_username)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvusername")),   "<span color=\"red\">Donnée invalide</span>");}
    else if (!is_valid_password(new_user.adminuser_password)) {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvpassword")),   "<span color=\"red\">Donnée invalide</span>");}
   else if (!is_alpha_string(new_user.adminuser_name))  {gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvname")),  "<span color=\"red\">Donnée invalide</span>");}
 else if (!is_alpha_string(new_user.adminuser_surname)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvsurname")),  "<span color=\"red\">Donnée invalide</span>");}
    else if (!is_valid_email(new_user.adminuser_email)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvemail")),   "<span color=\"red\">Donnée invalide</span>");}
  else if (!is_valid_region(new_user.adminuser_region)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvregion")),  "<span color=\"red\">Donnée invalide</span>");}
  else  if (!is_valid_phone(new_user.adminuser_phone)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvphone")),   "<span color=\"red\">Donnée invalide</span>");}
  
  else  if (!is_valid_id(new_user.adminuser_identification_card_number)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvid")),  "<span color=\"red\">Donnée invalide</span>");}
  else  if (!is_valid_address(new_user.adminuser_address)) { gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvadress")),  "<span color=\"red\">Donnée invalide</span>");}
  else{
  int add_result = admin_user_add("adminusers.txt", new_user);
   if (add_result == 1)
        gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvlabel")), "<span color=\"green\">Ajout avec succès.</span>");
    else
        gtk_label_set_markup(GTK_LABEL(lookup_widget(button, "dvlabel")), "<span color=\"red\">Ajout échoués</span>");
}

}


void
on_donormale_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y2=1;
}


void
on_donorfemale_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
y2=2;
}


void
on_percentagegender_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{float percentagemale, percentagefemale;
char choice[50],c[50];
GtkWidget*combobox ;
combobox=lookup_widget(togglebutton,"adminuserchoice");
strcpy(choice,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

if (strcmp(choice,"All")==0){
admin_user_percentage("adminusers.txt", &percentagemale, &percentagefemale);
 snprintf(c, sizeof(c), "Hommes :%.3f %%/Femmes :%.3f %%", percentagemale, percentagefemale);
 gtk_label_set_text(GTK_LABEL(lookup_widget(togglebutton, "genderpercentage")),c);
}
else{
if(strcmp(choice,"doctor")==0)
{
UserRole("adminusers.txt","doctor");
}
if(strcmp(choice,"admin")==0)
{
UserRole("adminusers.txt","admin");
}
if(strcmp(choice,"nurse")==0)
{
UserRole("adminusers.txt","nurse");
}
if(strcmp(choice,"director")==0)
{
UserRole("adminusers.txt","director");
}
if(strcmp(choice,"donor")==0)
{
UserRole("adminusers.txt","donor");
}
admin_user_percentage("role.txt", &percentagemale, &percentagefemale);
 snprintf(c, sizeof(c), "males :%.3f %%/females :%.3f %%", percentagemale, percentagefemale);
 gtk_label_set_text(GTK_LABEL(lookup_widget(togglebutton, "genderpercentage")),c);
}}


int x,y,z,o;

void
on_button_admin_quit_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* admin;
admin=lookup_widget(button,"Admin");
gtk_widget_destroy(admin);
}


void
on_button_admin_dcnx_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* admin,*authpage;
admin=lookup_widget(button,"Admin");
gtk_widget_destroy(admin);
authpage=create_authpage();
gtk_widget_show(authpage);


}





void
on_checkbutton_add__toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{x=1;}
else
	x=0;
}





void
on_button_add_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{
int t,a,z,n,i,b;
Etablissement ets;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*output0,*output1,*output2,*output3,*output5,*output4,*fenetre_ajouter;

input1= lookup_widget(button,"saentry3");
input2= lookup_widget(button,"saentry4");
input3 = lookup_widget(button,"saentry5");           
input4 = lookup_widget(button,"saentry12");
input5 = lookup_widget(button,"saentry6");
input6 = lookup_widget(button,"saspinbutton_add_annee");
input7 = lookup_widget(button,"saspinbutton_add_mois");
input8 = lookup_widget(button,"saspinbutton_add_jour");
output0= lookup_widget(button,"salabel77");
output1= lookup_widget(button,"salabel64");
output2= lookup_widget(button,"salabel67");
output3= lookup_widget(button,"salabel68");
output4= lookup_widget(button,"salabel69");
output5= lookup_widget(button,"salabel78");
strcpy(ets.id,gtk_entry_get_text(GTK_ENTRY(input1)));
b=ext_id(ets.id);
if (b==0){
strcpy(ets.name,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ets.region,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ets.capacite,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ets.phone,gtk_entry_get_text(GTK_ENTRY(input5)));
sprintf(ets.year, "%d", (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(input6)));
sprintf(ets.month, "%d", (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(input7)));
sprintf(ets.day, "%d", (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(input8)));
i=verife_id(ets.id);
a=verife_nom(ets.name);
z=verife_cap(ets.capacite);
t=verife_phone(ets.phone);
n=verife_reg(ets.region);
if (i==1){
if (a==1){	     
	 if (n==1){	
	if (z==1){
		if (t==1){
			if(x==1)
			{ 
			add_ets(ets);
                        fenetre_ajouter=create_fenetre_ajouter();
			gtk_window_set_position(GTK_WINDOW(fenetre_ajouter), GTK_WIN_POS_CENTER);
			gtk_widget_show(fenetre_ajouter);
			gtk_entry_set_text(GTK_ENTRY(input1), "");
			gtk_entry_set_text(GTK_ENTRY(input2), "");
			gtk_entry_set_text(GTK_ENTRY(input3), "");
			gtk_entry_set_text(GTK_ENTRY(input4), "");
			gtk_entry_set_text(GTK_ENTRY(input5), "");
			gtk_entry_set_text(GTK_SPIN_BUTTON(input6), "2023");
			gtk_entry_set_text(GTK_SPIN_BUTTON(input7), "1");
			gtk_entry_set_text(GTK_SPIN_BUTTON(input8), "1");
				}
			
			}
		}
	}
}
}
if (x!=1){
	
	gtk_label_set_markup(GTK_LABEL(output5), "<span color=\"red\">Veuiller confirmer</span>");

}
else
	gtk_label_set_text(output5,"");

if(t==0) 
	
	gtk_label_set_markup(GTK_LABEL(output4), "<span color=\"red\">Donnée invalide</span>");
else
	
	gtk_label_set_markup(GTK_LABEL(output4), "<span color=\"green\">Donnée valide</span>");
if(z==0) 
	
	gtk_label_set_markup(GTK_LABEL(output3), "<span color=\"red\">Donnée invalide</span>");
else
	
	gtk_label_set_markup(GTK_LABEL(output3), "<span color=\"green\">Donnée valide</span>");
if(n==0)
		
		gtk_label_set_markup(GTK_LABEL(output2), "<span color=\"red\">Donnée invalide</span>");
else 

	
	gtk_label_set_markup(GTK_LABEL(output2), "<span color=\"green\">Donnée valide</span>");		
if(a==0) 
	
	gtk_label_set_markup(GTK_LABEL(output1), "<span color=\"red\">Donnée invalide</span>");
else

	
	gtk_label_set_markup(GTK_LABEL(output1), "<span color=\"green\">Donnée valide</span>");

if (i==0)
	
	gtk_label_set_markup(GTK_LABEL(output0), "<span color=\"red\">Donnée invalide</span>");
else
	
	gtk_label_set_markup(GTK_LABEL(output0), "<span color=\"green\">Donnée valide</span>");	
}
else {
	gtk_label_set_markup(GTK_LABEL(output0), "<span color=\"red\">id deja existe</span>");
	gtk_label_set_text(output1,"");
	gtk_label_set_text(output2,"");
	gtk_label_set_text(output3,"");
	gtk_label_set_text(output4,"");
	gtk_label_set_text(output5,"");
}
if ((x==1)&&(i==1)&&(t=1)&&(a==1)&&(z==1)&&(n==1)){
	gtk_label_set_text(output0,"");
	gtk_label_set_text(output1,"");
	gtk_label_set_text(output2,"");
	gtk_label_set_text(output3,"");
	gtk_label_set_text(output4,"");
	gtk_label_set_text(output5,"");
}
}
void
on_button_admin_edit_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
char id[50];
int t,a,z,tr,n;
Etablissement ets1,ets2;
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*output5,*output6,*output3,*output4,*output7,*fenetre_modification_,*output11,*output22,*output33,*output44,*output55,*output66;
input1 = lookup_widget(button,"saentry7");
input2 = lookup_widget(button,"saentry8");
input3 = lookup_widget(button,"saentry9");
input4 = lookup_widget(button,"saentry13");
input5 = lookup_widget(button,"saentry10");
input6 = lookup_widget(button,"saspinbutton_edit_annee");
input7 = lookup_widget(button,"saspinbutton_edit_mois");
input8 = lookup_widget(button,"saspinbutton_edit_jour");
output3= lookup_widget(button,"salabel71");
output4= lookup_widget(button,"salabel72");
output5= lookup_widget(button,"salabel73");
output6= lookup_widget(button,"salabel74");
output7= lookup_widget(button,"salabel79");
output11= lookup_widget(button,"salabel70");
output22= lookup_widget(button,"salabel25");
output33= lookup_widget(button,"salabel26");
output44= lookup_widget(button,"salabel42");
output55= lookup_widget(button,"salabel27");
output66= lookup_widget(button,"salabel28");
strcpy(ets2.id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(ets2.name,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(ets2.region,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(ets2.capacite,gtk_entry_get_text(GTK_ENTRY(input4)));
strcpy(ets2.phone,gtk_entry_get_text(GTK_ENTRY(input5)));
sprintf(ets2.year, "%d", (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(input6)));
sprintf(ets2.month, "%d", (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(input7)));
sprintf(ets2.day, "%d", (int)gtk_spin_button_get_value(GTK_SPIN_BUTTON(input8)));
strcpy(id,ets2.id);
a=verife_nom(ets2.name);
z=verife_cap(ets2.capacite);
t=verife_phone(ets2.phone);
n=verife_reg(ets2.region);
if (a==1){
	if (z==1) {
		if (t==1){
			if (n==1){
				if(y==1)
					{ 
					tr=edit_ets(id,ets2);
					if (tr==1){
					fenetre_modification_=create_fenetre_modification_();
					gtk_window_set_position(GTK_WINDOW(fenetre_modification_), GTK_WIN_POS_CENTER);
					gtk_widget_show(fenetre_modification_);
					gtk_entry_set_text(GTK_ENTRY(input1), "");
					gtk_entry_set_text(GTK_ENTRY(input2), "");
					gtk_entry_set_text(GTK_ENTRY(input3), "");
					gtk_entry_set_text(GTK_ENTRY(input4), "");
					gtk_entry_set_text(GTK_ENTRY(input5), "");
					gtk_entry_set_text(GTK_SPIN_BUTTON(input6), "2023");
					gtk_entry_set_text(GTK_SPIN_BUTTON(input7), "1");
					gtk_entry_set_text(GTK_SPIN_BUTTON(input8), "1");
					}
				}
					
			}
		}
	}
}
if (y!=1)
	gtk_label_set_markup(GTK_LABEL(output7), "<span color=\"red\">Veuiller confirmer</span>");
else
	gtk_label_set_text(output7,"");
if(t==0) 
	gtk_label_set_markup(GTK_LABEL(output6), "<span color=\"red\">Donnée invalide</span>");
	
else
	gtk_label_set_markup(GTK_LABEL(output6), "<span color=\"green\">Donnée valide</span>");
	
if(z==0) 
	gtk_label_set_markup(GTK_LABEL(output5), "<span color=\"red\">Donnée invalide</span>");
	
else
	gtk_label_set_markup(GTK_LABEL(output5), "<span color=\"green\">Donnée valide</span>");	

if(n==0)
		gtk_label_set_markup(GTK_LABEL(output4), "<span color=\"red\">Donnée invalide</span>");
else 
	gtk_label_set_markup(GTK_LABEL(output4), "<span color=\"green\">Donnée valide</span>");
			
if(a==0) 
	gtk_label_set_markup(GTK_LABEL(output3), "<span color=\"red\">Donnée invalide</span>");
else
	gtk_label_set_markup(GTK_LABEL(output3), "<span color=\"green\">Donnée valide</span>");

if ((y==1)&&(t=1)&&(a==1)&&(z==1)&&(n==1)){
	gtk_label_set_text(output7,"");
	gtk_label_set_text(output6,"");
	gtk_label_set_text(output5,"");
	gtk_label_set_text(output3,"");
	gtk_label_set_text(output4,"");
	gtk_label_set_text(output11,"");
	gtk_label_set_text(output22,"");
	gtk_label_set_text(output33,"");
	gtk_label_set_text(output44,"");
	gtk_label_set_text(output55,"");
	gtk_label_set_text(output66,"");
}		

}







void
on_checkbutton_edit_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
{y=1;}
else 
	y=0;
}





void
on_button_admin_search_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
char ch[50]="";
Etablissement ets,ets3;
GtkWidget *id,*output11,*output22,*output33,*output44,*output55,*output66;
id= lookup_widget(button,"saentry7");
strcpy(ets.id,gtk_entry_get_text(GTK_ENTRY(id)));
ets3=search("etablissement.txt",ets.id);
output11= lookup_widget(button,"salabel70");
if (strcmp((ets3.id),"-1")==0)
	gtk_label_set_markup(GTK_LABEL(output11), "<span color=\"red\">Donnée invalide</span>");
else {
output22= lookup_widget(button,"salabel25");
output33= lookup_widget(button,"salabel26");
output44= lookup_widget(button,"salabel42");
output55= lookup_widget(button,"salabel27");
output66= lookup_widget(button,"salabel28");
strcat(ch,ets3.day);
strcat(ch,"/");
strcat(ch,ets3.month);
strcat(ch,"/");
strcat(ch,ets3.year);
gtk_label_set_markup(GTK_LABEL(output11), "<span color=\"green\">Donnée valide</span>");
gtk_label_set_text(output22,ets3.name);
gtk_label_set_text(output33,ets3.region);
gtk_label_set_text(output44,ets3.capacite);
gtk_label_set_text(output55,ets3.phone);
gtk_label_set_text(output66,ch);
	}

}






void
on_treeview_show_ets_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter;
gchar *id;
gchar *nom;
gchar *region ;
gchar *cap ;
gchar *tel ;
gchar *annee ;
gchar *mois ;
gchar *jour ;
Etablissement ets;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);

if (gtk_tree_model_get_iter(model, &iter,path))
{
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&nom,2,&region,3,&cap,4,&tel,5,&annee,6,&mois,7,&jour,-1);
strcpy(ets.id,id);  
strcpy(ets.name,nom);
strcpy(ets.region,region);
strcpy(ets.capacite,cap);
strcpy(ets.phone,tel);
strcpy(ets.year,annee);
strcpy(ets.month,mois);
strcpy(ets.day,jour);

delete_ets(ets.id);

show_ets("etablissement.txt",treeview);

}

}






void
on_button_admin_show_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{

GtkWidget *treeview,*input1,*admin,*fenetre_select_region,*fenetre_aff_cap;
 char choix[50];

int t;

treeview=lookup_widget(button,"treeview_show_ets");


input1=lookup_widget(button,"comboboxentry_show_tri");

strcpy(choix,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input1)));


if (strcmp(choix,"ETS par region")==0)
{
fenetre_select_region=create_fenetre_select_region();
gtk_widget_show (fenetre_select_region);
gtk_window_fullscreen(GTK_WINDOW(fenetre_select_region));
admin=lookup_widget(button,"Admin");
gtk_widget_destroy(admin);


}

if (strcmp(choix,"ETS capacite")==0)
{
fenetre_aff_cap=create_fenetre_aff_cap();
gtk_widget_show (fenetre_aff_cap);
gtk_window_fullscreen(GTK_WINDOW(fenetre_aff_cap));
admin=lookup_widget(button,"Admin");
gtk_widget_destroy(admin);

}

}




void
on_radiobutton_delete_oui_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=0;}
}





void
on_radiobutton_delete_non_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{z=1;}
}




void
on_button_delete_clicked               (GtkWidget       *button,
                                        gpointer         user_data)
{
int t;
Etablissement ets2,ets1;
GtkWidget *supp1,*output44,*output55,*fenetre_suppression_;
supp1= lookup_widget(button,"saentry_id_delete");
strcpy(ets2.id,gtk_entry_get_text(GTK_ENTRY(supp1)));
output44= lookup_widget(button,"salabel82");
output55= lookup_widget(button,"salabel80");
ets1=search("etablissement.txt",ets2.id);
if (strcmp((ets1.id),"-1")==0)
	gtk_label_set_markup(GTK_LABEL(output44), "<span color=\"red\">Donnée invalide</span>");
else {
	gtk_label_set_markup(GTK_LABEL(output44), "<span color=\"green\">Donnée valide</span>");
	if(z==0){
		gtk_label_set_text(output44,"");
		gtk_label_set_text(output55,"");
		delete_ets(ets1.id);		
                fenetre_suppression_=create_fenetre_suppression_();
		gtk_window_set_position(GTK_WINDOW(fenetre_suppression_), GTK_WIN_POS_CENTER);
		gtk_widget_show(fenetre_suppression_);	
		gtk_entry_set_text(GTK_ENTRY(supp1), "");	
		}
	else
		gtk_label_set_markup(GTK_LABEL(output55), "<span color=\"red\">Veuiller confirmer</span>");
}
}


void
on_button_retour_add_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),0);
}


void
on_button_retour_edit_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),0) ;
}


void
on_button_retour_delete_clicked        (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),0);
}


void
on_button_retour_show_clicked          (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),0) ;
}


void
on_refresh_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview;
treeview=lookup_widget(button,"treeview_show_ets");
//vider(treeview);
show_ets("etablissement.txt",treeview); 
}





void
on_button_afficher_region_clicked      (GtkWidget       *button,
                                        gpointer         user_data)
{

int t;
char abs[50],bb[50],c[50]="le nombre de region est : " ;
GtkWidget *input,*output8,*treeview2;

treeview2=lookup_widget(button,"satreeview2");
input=lookup_widget(button,"sacomboboxentry1");
output8=lookup_widget(button,"salabel102");
strcpy(abs,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

if (strcmp(abs,"kasserine")==0)
{
t=ETSParRegion(abs);
sprintf(bb, "%d", (int)t);
show_ets("regions.txt",treeview2);
strcat(c,bb);
gtk_label_set_text(output8,c);
}
if (strcmp(abs,"monastir")==0)
{
t=ETSParRegion(abs);
sprintf(bb, "%d", (int)t);
show_ets("regions.txt",treeview2);
strcat(c,bb);
gtk_label_set_text(output8,c);
}

}


void
on_button_retoure_region_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *admin,*fenetre_select_region;

fenetre_select_region=lookup_widget(button,"fenetre_select_region");
gtk_widget_destroy(fenetre_select_region);
admin=create_Admin();
gtk_widget_show(admin);
gtk_window_fullscreen(GTK_WINDOW(admin));
}


void
on_radiobutton_ascendant_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{o=1;}
}


void
on_button_afficher_cap_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *treeview3;

treeview3=lookup_widget(button,"satreeview3");
if (o==1)
{
ETSTrieCapacite_croissant();
show_ets("captriecroi.txt",treeview3);
}
else 
{
if (o==2)
{
ETSTrieCapacite_decroissant();
show_ets("captriedecroi.txt",treeview3);
}
}
}

void
on_radiobutton_descandant_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON (togglebutton)))
{o=2;}
}


void
on_button_retoure_capacite_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *Admin,*fenetre_aff_cap;

fenetre_aff_cap=lookup_widget(button,"fenetre_aff_cap");
gtk_widget_destroy(fenetre_aff_cap);
Admin=create_Admin();
gtk_widget_show(Admin);
gtk_window_fullscreen(GTK_WINDOW(Admin));

}


void
on_button_espace_ajouter_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),1) ;
}


void
on_button_espace_modifie_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),2) ;
}


void
on_button_espace_affichage_clicked     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),3) ;
}


void
on_button_espace_suppression_clicked   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),4) ;
}






void
on_button_retour_contact_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),0) ;
}


void
on_button_send_ets_clicked             (GtkWidget       *button,
                                        gpointer         user_data)
{
Etablissement ets,ets3;
GtkWidget *input1,*input2,*output1,*output2;
input1 = lookup_widget(button,"saentry1");
input2 = lookup_widget(button,"saentry2");
output1= lookup_widget(button,"salabelsa1");
output2= lookup_widget(button,"salabelsa2");
strcpy(ets.id,gtk_entry_get_text(GTK_ENTRY(input1)));
ets3=search("etablissement.txt",ets.id);
if (strcmp((ets3.id),"-1")==0){
	gtk_label_set_markup(GTK_LABEL(output1), "<span color=\"red\">Donnée invalide</span>");
	gtk_label_set_text(output2,"");
}
else{
	gtk_label_set_markup(GTK_LABEL(output1), "<span color=\"green\">Donnée valide</span>");
	gtk_entry_set_text(GTK_ENTRY(input1), "");
	gtk_entry_set_text(GTK_ENTRY(input2), "");
	gtk_label_set_markup(GTK_LABEL(output2), "<span color=\"green\">Reclamation envoyée</span>");
}
}


void
on_button_espace_contact_clicked       (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "sanotebook2") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),5) ;
}


void
on_button70_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "adminuser") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),1) ;
}


void
on_button90_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "adminuser") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),2) ;
}


void
on_button60_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "adminuser") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),3) ;
}


void
on_button80_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget* notebook;
notebook=lookup_widget(button, "adminuser") ;
gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook),4) ;
}




