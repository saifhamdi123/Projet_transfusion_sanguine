#include <stdio.h>
#include <string.h>
#include "gdps.h"
#include <stdlib.h>
#include <gtk/gtk.h>
enum
{
     ID_DONNEUR,
     CODE_DON,
     QUANTITE_SANG,
     TYPE_SANG,
     JOUR,
     MOIS,
     ANNEE,
     ETS,
     COLUMNSA,

};



//Ajouter don

int ajouter_don( Dons don )
{
int R;
    FILE * f=fopen("Dons.txt", "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %s %s %s\n",don.Id_donneur,don.Code_don,don.Quantite_sang,don.Type_sang,don.Jour,don.Mois,don.Annee,don.ets);
        fclose(f);
        R=1;
    }
    else
    R=0;

  return R ;
}


//Afficher don

void afficher_don(GtkWidget *liste){
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;


    char id[25] ;
    char code [25];
    char quantite[25];
    char type[5] ;
    char jour[10];
    char mois[10];
    char annee[10];
    char ets[25];
    store=NULL;

   FILE *f;

    store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Id_donneur", renderer, "text",ID_DONNEUR,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Code_don", renderer, "text",CODE_DON,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Quantite_sang", renderer, "text", QUANTITE_SANG,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Type_sang", renderer, "text",TYPE_SANG,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text",JOUR,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text",MOIS,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text",ANNEE,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("ets", renderer, "text",ETS,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

  }
  store=gtk_list_store_new (COLUMNSA, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING,   G_TYPE_STRING, G_TYPE_STRING,     G_TYPE_STRING,  G_TYPE_STRING);

  f=fopen("Dons.txt","r");
  if(f==NULL)
  {
  return;
  }
  else
  {
  f= fopen("Dons.txt","a+");
  while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,code,quantite,type,jour,mois,annee,ets)!=EOF)
        {
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter, ID_DONNEUR,id, CODE_DON,code, QUANTITE_SANG,quantite,TYPE_SANG,type, JOUR,jour,MOIS,mois,ANNEE ,annee,ETS,ets,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}


}

//supprimer
void supprimer_select(Dons d)
{     
    char id[25] ;
    char code[25];
    char quantite[25];
    char type[5] ;
    char jour[10];
    char mois[10];
    char annee[10];
    char ets[25];
    
    FILE * f=fopen("Dons.txt", "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f==NULL || f2==NULL)
    {
        return;
    }
    if(f!=NULL && f2!=NULL)
    {
     while(fscanf(f,"%s %s %s %s %s %s %s %s\n",id,code,quantite,type,jour,mois,annee,ets)!=EOF)
        {
            if(strcmp(d.Id_donneur, id)!=0 || strcmp(d.Code_don, code)!=0||   strcmp(d.Quantite_sang, quantite)!=0 ||  strcmp(d.Type_sang, type)!=0|| strcmp(d.Jour,jour)!=0  ||strcmp(d.Mois,mois)!=0 || strcmp(d.Annee,annee)!=0 )

        fprintf(f2,"%s %s %s %s %s %s %s %s\n",id,code,quantite,type,jour,mois,annee,ets);

        }
    }
    fclose(f);
    fclose(f2);
    remove("Dons.txt");
    rename("nouv.txt","Dons.txt");
}

//modifier don
 int modifier_don( char id_donneur[], Dons nvdon )
{
    char * filename="Dons.txt";
    int tr=0;
    Dons d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,d.Code_don,d.Quantite_sang,d.Type_sang,&d.Jour,&d.Mois,d.Annee,d.ets)!=EOF)
        {
            if(strcmp(d.Id_donneur, id_donneur)==0)
            {
                fprintf(f2,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,nvdon.Code_don,nvdon.Quantite_sang,nvdon.Type_sang,nvdon.Jour,nvdon.Mois,nvdon.Annee,nvdon.ets);
                tr=1;

            }
            else
                fprintf(f2,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,d.Code_don,d.Quantite_sang,d.Type_sang,&d.Jour,&d.Mois,d.Annee,d.ets);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}




/*
void vider(GtkWidget *liste)
{
    GtkCellRenderer *renderer;
    GtkTreeviewColumn *column;
    GtkTreeIter iter;
    GtkListstore *store;

   char id_donneur[25] ;
    char code_don [25];
    char quantitesang [25];
    char typesang[5] ;
    char jour[10];
    char mois[10];
    char annee[10];
    char ets[25];
    store=NULL;

    FILE *f;
    store=gtk_tree_view_get_nodel(liste);
    if (store==NULL)
    {
    renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Id_donneur", renderer, "text",Id,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Code_don", renderer, "text",CODE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Quantitesang", renderer, "text", QUANTITE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("Typesang", renderer, "text",TYPE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text",JOUR,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text",MOIS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",ANNEE,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes("ets", renderer, "text",ETS,NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);

}

store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

gtk_list_store_append (store, &iter);

gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));

}*/



int supprimer_don( char id_donneur[])
{   int R;
    char * filename="Dons.txt";
    int tr=0;
    Dons d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
     while(fscanf(f,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,d.Code_don,d.Quantite_sang,d.Type_sang,d.Jour,d.Mois,d.Annee,d.ets)!=EOF)
        {
            if(strcmp(d.Id_donneur, id_donneur)==0)
                tr=1;
            else
        fprintf(f2,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,d.Code_don,d.Quantite_sang,d.Type_sang,d.Jour,d.Mois,d.Annee,d.ets);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

Dons chercher_don(char id_donneur[])
{   char * filename="Dons.txt" ;
    Dons d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0 && fscanf(f,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,d.Code_don,d.Quantite_sang,d.Type_sang,d.Jour,d.Mois,d.Annee,d.ets)!=EOF)
        {
            if(strcmp(d.Id_donneur,id_donneur)==0)
                {tr=1;}
        }
    }
    fclose(f);
    if(tr==0){
     strcpy(d.Id_donneur,"-1");
     }
    return d;

}


float Quantite_sang(char*nomfichier ,char typesang []){
 Dons d;
 float Quantite__sang=0.0;
 FILE* f=fopen(nomfichier,"r");
 if(f!=NULL){
     while(fscanf(f,"%s %s %s %s %s %s %s %s\n",d.Id_donneur,d.Code_don,d.Quantite_sang,d.Type_sang,d.Jour,d.Mois,d.Annee,d.ets)!=EOF)
        {
           if(strcmp(d.Type_sang,typesang)==0){ Quantite__sang+=atof(d.Quantite_sang);}
        }
      }
    fclose(f);

 return Quantite__sang;
 }


void QuantitesTousTypes() {
    
    char nomfichier[30] = "sang.txt";
    char typesdesang[10][4] = {"A+", "B+", "O+", "AB+", "A-", "B-", "O-", "AB-"};
    float quantitesang;
    int i;
    char Quantitesang_str[50];
    FILE* f = fopen(nomfichier, "w");

    if (f != NULL) {
        for (i = 0; i < 8; i++) {
             quantitesang = Quantite_sang("Dons.txt", typesdesang[i]);
             sprintf(Quantitesang_str,"%.2f",quantitesang);

            fprintf(f, "%s %s\n",typesdesang[i], Quantitesang_str);
        }

        fclose(f);
      } 
}
Sang SangPlusRare() {
     QuantitesTousTypes();
    char quantitesang_min[50] = "9999.0";
    Sang SR;
    Sang S ;
    float  quantite;
    

    FILE* f = fopen("sang.txt", "r");

    if (f != NULL) {
        while (fscanf(f, "%s %s\n", S.typesang, S.quantitesang) != EOF) {
              quantite=atof(S.quantitesang);

            if (atof(quantitesang_min)> quantite) {
                sprintf(quantitesang_min,"%.2f",quantite);
              
                strcpy( SR.typesang,S.typesang);
                strcpy( SR.quantitesang,quantitesang_min);
            }
        }
       fclose(f);
    }
return SR ;
   
}

enum
{
  TYPE_DE_SANG,
  QUANTITE_DE_SANG,
  ECOLUMNS

};

void AfficherQuantitesTousTypes(GtkWidget *liste){
 GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

   QuantitesTousTypes();

    char Type[25] ;
    char quantitesang[25];
    
    store=NULL;

   FILE *f;

    store=gtk_tree_view_get_model(liste);
  if (store==NULL)
  {
  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Type_sang", renderer, "text",TYPE_DE_SANG,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);


  renderer = gtk_cell_renderer_text_new();
  column = gtk_tree_view_column_new_with_attributes("Quantite_sang", renderer, "text",QUANTITE_DE_SANG,NULL);
  gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
 
  }
  store=gtk_list_store_new (ECOLUMNS, G_TYPE_STRING, G_TYPE_STRING);

  f=fopen("sang.txt","r");
  if(f==NULL)
  {
  return;
  }
  else
  {
  f= fopen("sang.txt","a+");
  while(fscanf(f,"%s %s\n",Type,quantitesang)!=EOF)
        {
gtk_list_store_append(store, &iter);
gtk_list_store_set(store,&iter, TYPE_DE_SANG,Type, QUANTITE_DE_SANG,quantitesang,-1);
}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
g_object_unref (store);
}


}
int verifID(char id []){
  if(strlen(id)!=8){
   return 0;}
 for(int i=0;i<8;i++){
    if(!isdigit(id[i])){
    return 0 ;}
   }
  return 1;
}
int verif_entier(char code[]){
    for(int i=0;code[i]!='\0';i++){
        if(!isdigit(code[i])){
         return 0;
         }
    }
   return 1 ;
}
int verif_unicite(char code[]){
  Dons d ;
  int val=1 ;
  FILE* f=fopen("Dons.txt","r");
  if(f!=NULL){
    while(fscanf(f,"%*s %s %*s %*s %*s %*s %*s %*s\n",d.Code_don)!=EOF){
    if(strcmp(code,d.Code_don)==0){
        val=0;
        }
     }
}
     return val ;
     
}
int verif_quantitesang(char Q[]) {
    for (int i = 0; Q[i] != '\0'; i++) {
        if (!isdigit(Q[i]) && Q[i] != '.') {
            return 0;
        }
    }

    return 1;
}


enum 
{
	
	EINFIRMIERNOMW,
	EINFIRMIERPRENOMW,
	EINFIRMIERCINW,
	COLUMNSW,
};
enum
{
	
	EINFIRMIERNOM,
	EINFIRMIERPRENOM,
	ESEXE,
	EADRESSE,
	EMAIL,
	EINFIRMIERCIN,
	ENUMEROTELEPHONE,
	ETYPESANG,
	EDATENAISSANCE,
	EETS,
	EMEDECIN,
	EDATERDV,
	EHEURERDV,
	COLUMNSS,
};
void afficher_donneur(GtkWidget *liste)
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char infirmier_nom[50];
	char infirmier_prenom[50];
	char infirmier_sexe[50];
	char infirmier_adresse[50];
	char infirmier_mail[50];
	int infirmier_cin;
	int infirmier_numero_telephone;
	char infirmier_type_sang[50];
	int infirmier_jour_naissance;
	int infirmier_mois_naissance;
	int infirmier_annee_naissance;
	char infirmier_password[50];
	char infirmier_ID_ETS[50];
	char infirmier_medecin[50];
	char infirmier_ID_RDV[50];
	int infirmier_heure_RDV;
	int infirmier_jour_RDV;
	int infirmier_mois_RDV;
	int infirmier_annee_RDV;
	

	char cin[50];
	char numerotelephone[50];
	char heureRDV[50];
	char datenaissance[50];
	char dateRDV[50];

	store=NULL;

	FILE* f;
	FILE* f1;
	store=gtk_tree_view_get_model(liste);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",EINFIRMIERNOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EINFIRMIERPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Sexe",renderer,"text",ESEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Adresse",renderer,"text",EADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Mail",renderer,"text",EMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("CIN",renderer,"text",EINFIRMIERCIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Numero Telephone",renderer,"text",ENUMEROTELEPHONE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Type De Sang",renderer,"text",ETYPESANG,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Date De Naissance",renderer,"text",EDATENAISSANCE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("ETS",renderer,"text",EETS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Medecin",renderer,"text",EMEDECIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("DATE De RDV",renderer,"text",EDATERDV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Heure De RDV",renderer,"text",EHEURERDV,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	
	store=gtk_list_store_new(COLUMNSS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("donneur.txt","r");
	f1=fopen("RDV.txt","r");
//-------------------------------------------------
	 if ((f != NULL)&&(f1!=NULL))
    {
        while ((fscanf(f, "%s %s %s %s %s %d %d %s %d %d %d %s\n",infirmier_nom, infirmier_prenom,infirmier_sexe,infirmier_adresse,infirmier_mail,&infirmier_cin, &infirmier_numero_telephone,infirmier_type_sang,&infirmier_jour_naissance, &infirmier_mois_naissance, &infirmier_annee_naissance,infirmier_password)!= EOF)&&(fscanf(f1, "%s %s %s %d %d %d %d\n",infirmier_ID_ETS,infirmier_medecin,infirmier_ID_RDV,&infirmier_heure_RDV,&infirmier_jour_RDV,&infirmier_mois_RDV, &infirmier_annee_RDV)!=EOF))
        {
		sprintf(cin,"%d",infirmier_cin);
		sprintf(numerotelephone,"%d",infirmier_numero_telephone);
		sprintf(heureRDV,"%d",infirmier_heure_RDV);
	snprintf(datenaissance, sizeof(datenaissance), "%02d/%02d/%04d",infirmier_jour_naissance,infirmier_mois_naissance,infirmier_annee_naissance);
	

	snprintf(dateRDV, sizeof(dateRDV), "%02d/%02d/%04d",infirmier_jour_RDV,infirmier_mois_RDV,infirmier_annee_RDV);
	
                
	
	
	if ( l==infirmier_cin )
{
		gtk_list_store_append(store,&iter);	gtk_list_store_set(store,&iter,EINFIRMIERNOM,infirmier_nom,EINFIRMIERPRENOM,infirmier_prenom,ESEXE,infirmier_sexe,EADRESSE,infirmier_adresse,
EMAIL,infirmier_mail,EINFIRMIERCIN,cin,ENUMEROTELEPHONE,numerotelephone,ETYPESANG,infirmier_type_sang,EDATENAISSANCE,datenaissance,
EETS,infirmier_ID_ETS,EMEDECIN,infirmier_medecin,EDATERDV,dateRDV,EHEURERDV,heureRDV,-1);
	
	break;
}
        }
	fclose(f);
	fclose(f1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref (store);
		
    }
    
//-----------------------------------------------
	
}

void afficher_donneurs(GtkWidget *liste)
{	
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char infirmier_nom[50];
	char infirmier_prenom[50];
	char infirmier_sexe[50];
	char infirmier_adresse[50];
	char infirmier_mail[50];
	int infirmier_cin;
	int infirmier_numero_telephone;
	char infirmier_type_sang[50];
	int infirmier_jour_naissance;
	int infirmier_mois_naissance;
	int infirmier_annee_naissance;
	char infirmier_password[50];
	
	char infirmier_ID_ETS[50];
	char infirmier_medecin[50];
	char infirmier_ID_RDV[50]; 
	int infirmier_heure_RDV;
	int infirmier_jour_RDV;
	int infirmier_mois_RDV;
	int infirmier_annee_RDV;

	char cin[50];
	store=NULL;

	FILE* f;
	store=gtk_tree_view_get_model(liste);
	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",EINFIRMIERNOMW,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EINFIRMIERPRENOMW,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",EINFIRMIERCINW,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(COLUMNSW,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("donneur.txt","r");
//-------------------------------------------------
	 if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %d %d %s %d %d %d %s\n",
            infirmier_nom, infirmier_prenom,infirmier_sexe,infirmier_adresse,infirmier_mail,&infirmier_cin, &infirmier_numero_telephone,infirmier_type_sang,
            &infirmier_jour_naissance, &infirmier_mois_naissance, &infirmier_annee_naissance,infirmier_password) != EOF)
        {
		sprintf(cin,"%d",infirmier_cin);
                gtk_list_store_append(store,&iter);
		gtk_list_store_set(store,&iter,EINFIRMIERNOMW,infirmier_nom,EINFIRMIERPRENOMW,infirmier_prenom,EINFIRMIERCINW,cin,-1);
        }
	fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));
		g_object_unref (store);
    }
    
//-----------------------------------------------
	
}

/*void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char infirmier_nom[50];
	char infirmier_prenom[50];
	int infirmier_cin;

	char cin[50];
	store=NULL;

	FILE* f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Nom",renderer,"text",EINFIRMIERNOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Prenom",renderer,"text",EINFIRMIERPRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Cin",renderer,"text",EINFIRMIERCIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
	gtk_list_store_append(store,&iter);
	gtk_tree_view_set_model(GTK_TREE_VIEW (liste),GTK_TREE_MODEL(store));	
}*/


int infirmier_ajouter_information_generale(char * filename, donneur d)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s %d %d %s %d %d %d %s\n"  ,d.infirmier_nom,d.infirmier_prenom,d.infirmier_sexe,d.infirmier_adresse,d.infirmier_mail,d.infirmier_cin,d.infirmier_numero_telephone,d.infirmier_type_sang,d.infirmier_jour_naissance,d.infirmier_mois_naissance,d.infirmier_annee_naissance,
d.infirmier_password);
	sprintf(w,"%d",(d.infirmier_cin));
        fclose(f);
        return 1;
    }
    else return 0;

}
int infirmier_ajouter_RDV(char * filename,RDV r)
{
    FILE * f=fopen(filename, "a");
	strcpy(r.infirmier_ID_RDV,w);
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %d\n",
r.infirmier_ID_ETS,r.infirmier_medecin,r.infirmier_ID_RDV,r.infirmier_heure_RDV,r.infirmier_jour_RDV,r.infirmier_mois_RDV,r.infirmier_annee_RDV);
        fclose(f);
        return 1;
    }
    else return 0;

}

donneur infirmier_chercher(char* filename, int cin)
{
    donneur d;
    int tr = 0;
    FILE* f = fopen(filename , "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %d %d %s %d %d %d %s\n",
            d.infirmier_nom, d.infirmier_prenom, d.infirmier_sexe, d.infirmier_adresse, d.infirmier_mail, &d.infirmier_cin, &d.infirmier_numero_telephone, d.infirmier_type_sang,
            &d.infirmier_jour_naissance, &d.infirmier_mois_naissance, &d.infirmier_annee_naissance,d.infirmier_password) != EOF)
        {
            if (d.infirmier_cin == cin)
            {
                tr = 1;
                break; 
            }
        }
    }
    fclose(f);
    if (tr == 0)
        d.infirmier_cin = -1;
    return d;
}




int infirmier_modifier_donneur( char* filename, int cin,donneur a )
{
    int tr=0;
    donneur d;
    
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL )
    {
        while(fscanf(f,"%s %s %s %s %s %d %d %s %d %d %d %s\n",d.infirmier_nom,d.infirmier_prenom,d.infirmier_sexe,d.infirmier_adresse,d.infirmier_mail,&d.infirmier_cin,&d.infirmier_numero_telephone,d.infirmier_type_sang,&d.infirmier_jour_naissance,&d.infirmier_mois_naissance,&d.infirmier_annee_naissance,
d.infirmier_password)!=EOF)
        {
            if(d.infirmier_cin== cin)
            {
                fprintf(f2,"%s %s %s %s %s %d %d %s %d %d %d %s\n",d.infirmier_nom,d.infirmier_prenom,d.infirmier_sexe,a.infirmier_adresse,a.infirmier_mail,d.infirmier_cin,a.infirmier_numero_telephone,d.infirmier_type_sang,d.infirmier_jour_naissance,d.infirmier_mois_naissance,a.infirmier_annee_naissance,
d.infirmier_password);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %s %s %d %d %s %d %d %d %s\n",d.infirmier_nom,d.infirmier_prenom,d.infirmier_sexe,d.infirmier_adresse,d.infirmier_mail,d.infirmier_cin,d.infirmier_numero_telephone,d.infirmier_type_sang,d.infirmier_jour_naissance,d.infirmier_mois_naissance,d.infirmier_annee_naissance,
d.infirmier_password);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int infirmier_modifier_RDV( char* filename, int cin,RDV b)
{
    int tr=0;
    RDV r;
    
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL )
    {
        while(fscanf(f, "%s %s %s %d %d %d %d\n",
            r.infirmier_ID_ETS, r.infirmier_medecin, r.infirmier_ID_RDV, &r.infirmier_heure_RDV, &r.infirmier_jour_RDV, &r.infirmier_mois_RDV, &r.infirmier_annee_RDV)!=EOF)
        {int n=atoi(r.infirmier_ID_RDV);
            if(n== cin)
            {
                fprintf(f2,"%s %s %s %d %d %d %d\n",b.infirmier_ID_ETS,b.infirmier_medecin, r.infirmier_ID_RDV,b.infirmier_heure_RDV,b.infirmier_jour_RDV,b.infirmier_mois_RDV,b.infirmier_annee_RDV);
                tr=1;
            }
            else
                fprintf(f2,"%s %s %s %d %d %d %d\n",r.infirmier_ID_ETS, r.infirmier_medecin, r.infirmier_ID_RDV,r.infirmier_heure_RDV,r.infirmier_jour_RDV,r.infirmier_mois_RDV,r.infirmier_annee_RDV);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}





int infirmier_supprimer_donneur(char * filename,char * filename1, int cin)
{
   int tr = 0;
    donneur d;
    

    FILE* f = fopen(filename, "r");
    FILE* f2 = fopen("nouv.txt", "w");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %d %d %s %d %d %d %s\n",
            d.infirmier_nom, d.infirmier_prenom, d.infirmier_sexe, d.infirmier_adresse, d.infirmier_mail, &d.infirmier_cin, &d.infirmier_numero_telephone, d.infirmier_type_sang,
            &d.infirmier_jour_naissance, &d.infirmier_mois_naissance, &d.infirmier_annee_naissance,d.infirmier_password) != EOF)
        {
            if (d.infirmier_cin == cin)
            {
                tr = 1; 
            }
            else
            {
                fprintf(f2, "%s %s %s %s %s %d %d %s %d %d %d %s\n",
                    d.infirmier_nom, d.infirmier_prenom, d.infirmier_sexe, d.infirmier_adresse, d.infirmier_mail, d.infirmier_cin, d.infirmier_numero_telephone, d.infirmier_type_sang,
                    d.infirmier_jour_naissance, d.infirmier_mois_naissance, d.infirmier_annee_naissance,d.infirmier_password);
            }
        }
    }

    fclose(f);
    fclose(f2);
    if (tr)
    {
        remove(filename);
        rename("nouv.txt", filename);
    }
    else
    {
        remove("nouv.txt");
    }

int tr1 = 0;
    RDV r;
    

    FILE* ff = fopen(filename1, "r");
    FILE* ff2 = fopen("nouv.txt", "w");

    if (ff != NULL && ff2 != NULL)
    {
        while (fscanf(ff,"%s %s %s %d %d %d %d\n",
            r.infirmier_ID_ETS, r.infirmier_medecin, r.infirmier_ID_RDV, &r.infirmier_heure_RDV, &r.infirmier_jour_RDV, &r.infirmier_mois_RDV, &r.infirmier_annee_RDV)!=EOF)
	{	int h=atoi(r.infirmier_ID_RDV);
        
            if (h == cin)
            {
                tr1 = 1; 
            }
            else
            {
                fprintf(ff2,"%s %s %s %d %d %d %d\n",
            r.infirmier_ID_ETS, r.infirmier_medecin, r.infirmier_ID_RDV,r.infirmier_heure_RDV,r.infirmier_jour_RDV,r.infirmier_mois_RDV,r.infirmier_annee_RDV);
            }
        }
    }

    fclose(ff);
    fclose(ff2);
    if (tr1)
    {
        remove(filename1);
        rename("nouv.txt", filename1);
    }
    else
    {
        remove("nouv.txt");
    }

    return tr;
}





int listeRDV(char nomFichier[], int jour, int mois , int annee)
{
	int nbre_RDV=0;
	RDV r;
	FILE * f=fopen(nomFichier, "r");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %s %d %d %d %d\n",r.infirmier_ID_ETS,r.infirmier_medecin,r.infirmier_ID_RDV,
	&r.infirmier_heure_RDV,&r.infirmier_jour_RDV,&r.infirmier_mois_RDV,&r.infirmier_annee_RDV)!=EOF)
        {
            if((r.infirmier_annee_RDV==annee) && (r.infirmier_mois_RDV==mois) && (r.infirmier_jour_RDV==jour))
                {
			nbre_RDV++;
		}
        }
	
     }
	fclose(f);
	return nbre_RDV;
}




int nbETS( char nomFichier[])
{
	int nbETS=0;
	int flag=0;
	RDV r;
	char tab[50][50];
	FILE * f=fopen(nomFichier,"r");
	if(f!=NULL)
    {
        while(fscanf(f," %s %s %s %d %d %d %d\n",
	r.infirmier_ID_ETS,r.infirmier_medecin,r.infirmier_ID_RDV,&r.infirmier_heure_RDV,
	&r.infirmier_jour_RDV,&r.infirmier_mois_RDV,&r.infirmier_annee_RDV)!=EOF)
        {
		flag=0;
		for(int i=0;i<50;i++)
		{
		
			if (strcmp(tab[i],r.infirmier_ID_ETS)==0)
				flag=1;
			
		}		
		
		if (flag==0)
		{
			strcpy(tab[nbETS],r.infirmier_ID_ETS);
			nbETS++;
		}
		
                
        }
	
    }
	fclose(f);
	return nbETS;
}








float moyRDV_ETS (char nomFichier[], int jour, int mois , int annee)
{
	float moyRDV_ETS=0;
	int nbRDV = listeRDV(nomFichier, jour, mois, annee);
    	int nbets = nbETS(nomFichier);
	moyRDV_ETS = (float)nbRDV / nbets;
	return moyRDV_ETS;
}




int ajouter_rdv(char * filename, RDV r)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %d %d %d %d\n",r.infirmier_ID_ETS,r.infirmier_medecin,r.infirmier_ID_RDV,r.infirmier_heure_RDV,r.infirmier_jour_RDV,r.infirmier_mois_RDV,r.infirmier_annee_RDV);

        fclose(f);
        return 1;
    }
    else {
	return 0;
	}
}
int admin_user_add(char *filename,admin_user user) {
int tr=1;
  tr=admin_user_verif( filename , user.adminuser_identification_card_number);
  FILE *f = fopen(filename, "a");
    if(tr==0) {
       fprintf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n", user.adminuser_username, user.adminuser_password,
        user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
        user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address, user.adminuser_joindate,
        user.adminuser_region, user.adminuser_date);
        fclose(f);
        return 1;
    }
    return 0;
}

int modifierDemande2(char *filename, d_poche_de_sang nouv, int idDemande, char idemail[], char demandeur[], int x, int y, int urgency, int Heure, int jour, int mois, int Annee) {
    int tr = 0;
    d_poche_de_sang dpp;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f != NULL && f2 != NULL) {
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &dpp.qt_demande[0], &dpp.qt_demande[1], &dpp.qt_demande[2],
                      &dpp.qt_demande[3], &dpp.qt_demande[4], &dpp.qt_demande[5], &dpp.qt_demande[6],
                      &dpp.qt_demande[7], &dpp.place[0], &dpp.place[1],dpp.demandeur, &dpp.urgency, &dpp.idd, &dpp.datedd.Heure,
                      &dpp.datedd.jour, &dpp.datedd.mois, &dpp.datedd.Annee, dpp.idemail,
                       dpp.infosupp) != EOF) {
            printf(" %d ", dpp.idd);
            if ((dpp.idd == idDemande) && (strcmp(dpp.demandeur, demandeur) == 0)&& (strcmp(dpp.idemail, idemail) == 0) && (x == dpp.place[0]) && (y == dpp.place[1]) && (urgency == dpp.urgency) && (dpp.datedd.Heure == Heure) && (dpp.datedd.jour == jour) && (dpp.datedd.mois == mois) && (dpp.datedd.Annee == Annee))
                    {
                tr = 1;
                fprintf(f2, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                        nouv.qt_demande[0], nouv.qt_demande[1], nouv.qt_demande[2],
                        nouv.qt_demande[3], nouv.qt_demande[4], nouv.qt_demande[5], nouv.qt_demande[6],
                        nouv.qt_demande[7], nouv.place[0], nouv.place[1],nouv.demandeur, nouv.urgency, nouv.idd, nouv.datedd.Heure,
                        nouv.datedd.jour, nouv.datedd.mois, nouv.datedd.Annee, nouv.idemail,
                        nouv.infosupp);
            } else {
                fprintf(f2, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      dpp.qt_demande[0], dpp.qt_demande[1], dpp.qt_demande[2],
                      dpp.qt_demande[3], dpp.qt_demande[4], dpp.qt_demande[5], dpp.qt_demande[6],
                      dpp.qt_demande[7], dpp.place[0], dpp.place[1],dpp.demandeur, dpp.urgency, dpp.idd, dpp.datedd.Heure,
                      dpp.datedd.jour, dpp.datedd.mois, dpp.datedd.Annee, dpp.idemail,
                      dpp.infosupp);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    } else {
        return 0;
    }
}

int supprimerDemande2(char *filename, int idDemande, char idemail[], char demandeur[], int x, int y, int urgency, int Heure, int jour, int mois, int Annee) {
    int tr = 1;

    d_poche_de_sang dpp;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &dpp.qt_demande[0], &dpp.qt_demande[1], &dpp.qt_demande[2],
                      &dpp.qt_demande[3], &dpp.qt_demande[4], &dpp.qt_demande[5], &dpp.qt_demande[6],
                      &dpp.qt_demande[7], &dpp.place[0], &dpp.place[1], dpp.demandeur, &dpp.urgency, &dpp.idd, &dpp.datedd.Heure,
                      &dpp.datedd.jour, &dpp.datedd.mois, &dpp.datedd.Annee, dpp.idemail,
                      dpp.infosupp) != EOF) {

                if ((dpp.idd == idDemande) && (strcmp(dpp.demandeur, demandeur) == 0)&& (strcmp(dpp.idemail, idemail) == 0) && (x == dpp.place[0]) && (y == dpp.place[1]) && (urgency == dpp.urgency) && (dpp.datedd.Heure == Heure) && (dpp.datedd.jour == jour) && (dpp.datedd.mois == mois) && (dpp.datedd.Annee == Annee))
                    {
                    tr = 1;
                    }
                else {
                fprintf(f2, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                        dpp.qt_demande[0], dpp.qt_demande[1], dpp.qt_demande[2],
                        dpp.qt_demande[3], dpp.qt_demande[4], dpp.qt_demande[5], dpp.qt_demande[6],
                        dpp.qt_demande[7], dpp.place[0], dpp.place[1], dpp.demandeur, dpp.urgency, dpp.idd, dpp.datedd.Heure,
                        dpp.datedd.jour, dpp.datedd.mois, dpp.datedd.Annee, dpp.idemail,
                        dpp.infosupp);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    } else {
        return 0;
    }
}
d_poche_de_sang chercherDemande2(char *filename, int idDemande, char idemail[], char demandeur[], int x, int y, int urgency, int Heure, int jour, int mois, int Annee) {
    d_poche_de_sang dpp;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &dpp.qt_demande[0], &dpp.qt_demande[1], &dpp.qt_demande[2],
                      &dpp.qt_demande[3], &dpp.qt_demande[4], &dpp.qt_demande[5], &dpp.qt_demande[6],
                      &dpp.qt_demande[7], &dpp.place[0], &dpp.place[1],dpp.demandeur, &dpp.urgency, &dpp.idd, &dpp.datedd.Heure,
                      &dpp.datedd.jour, &dpp.datedd.mois, &dpp.datedd.Annee, dpp.idemail,
                       dpp.infosupp) != EOF) {
           if ((dpp.idd == idDemande) && (strcmp(dpp.demandeur, demandeur) == 0) && (strcmp(dpp.idemail, idemail) == 0) && (x == dpp.place[0]) && (y == dpp.place[1]) && (urgency == dpp.urgency) && (dpp.datedd.Heure == Heure) && (dpp.datedd.jour == jour) && (dpp.datedd.mois == mois) && (dpp.datedd.Annee == Annee))
                    {
                tr = 1;
                break;
            }
        }
        fclose(f);
    }
    if (tr == 0) {
        dpp.idd = -1;
    }
    return dpp;
}







int ajouterDemande(char *filename, d_poche_de_sang demande) {
    FILE *f = fopen(filename, "a");
    if (f != NULL) {
        fflush(stdin);
        fprintf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                demande.qt_demande[0], demande.qt_demande[1], demande.qt_demande[2],
                demande.qt_demande[3], demande.qt_demande[4], demande.qt_demande[5], demande.qt_demande[6],
                demande.qt_demande[7], demande.place[0], demande.place[1],demande.demandeur, demande.urgency, demande.idd, demande.datedd.Heure,
                demande.datedd.jour, demande.datedd.mois, demande.datedd.Annee, demande.idemail,
                demande.infosupp);
        fclose(f);
        return 1;
    } else {
        return 0;
    }
}



int supprimerDemande(char *filename, int idDemande) {
    int tr = 0;
    d_poche_de_sang dpp;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL) {
        int i;
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &dpp.qt_demande[0], &dpp.qt_demande[1], &dpp.qt_demande[2],
                      &dpp.qt_demande[3], &dpp.qt_demande[4], &dpp.qt_demande[5], &dpp.qt_demande[6],
                      &dpp.qt_demande[7], &dpp.place[0], &dpp.place[1],dpp.demandeur, &dpp.urgency, &dpp.idd, &dpp.datedd.Heure,
                      &dpp.datedd.jour, &dpp.datedd.mois, &dpp.datedd.Annee, dpp.idemail,
                       dpp.infosupp) != EOF) {
            if (dpp.idd == idDemande) {
                tr = 1;
            }
            else {
                fprintf(f2, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      dpp.qt_demande[0], dpp.qt_demande[1], dpp.qt_demande[2],
                      dpp.qt_demande[3], dpp.qt_demande[4], dpp.qt_demande[5], dpp.qt_demande[6],
                      dpp.qt_demande[7], dpp.place[0], dpp.place[1],dpp.demandeur, dpp.urgency, dpp.idd, dpp.datedd.Heure,
                      dpp.datedd.jour, dpp.datedd.mois, dpp.datedd.Annee, dpp.idemail,
                      dpp.infosupp);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    } else {
        return 0;
    }
}
d_poche_de_sang chercherDemande(char *filename, int idDemande) {
    d_poche_de_sang dpp;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &dpp.qt_demande[0], &dpp.qt_demande[1], &dpp.qt_demande[2],
                      &dpp.qt_demande[3], &dpp.qt_demande[4], &dpp.qt_demande[5], &dpp.qt_demande[6],
                      &dpp.qt_demande[7], &dpp.place[0], &dpp.place[1],dpp.demandeur, &dpp.urgency, &dpp.idd, &dpp.datedd.Heure,
                      &dpp.datedd.jour, &dpp.datedd.mois, &dpp.datedd.Annee, dpp.idemail,
                       dpp.infosupp) != EOF) {
            if (dpp.idd == idDemande) {
                tr = 1;
                break;
            }
        }
        fclose(f);
    }
    if (tr == 0) {
        dpp.idd = -1;
    }
    return dpp;
}

int modifierDemande(char *filename, d_poche_de_sang nouv, int idDemande) {
    int tr = 0;
    d_poche_de_sang dpp;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");

    if (f != NULL && f2 != NULL) {
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &dpp.qt_demande[0], &dpp.qt_demande[1], &dpp.qt_demande[2],
                      &dpp.qt_demande[3], &dpp.qt_demande[4], &dpp.qt_demande[5], &dpp.qt_demande[6],
                      &dpp.qt_demande[7], &dpp.place[0], &dpp.place[1],dpp.demandeur, &dpp.urgency, &dpp.idd, &dpp.datedd.Heure,
                      &dpp.datedd.jour, &dpp.datedd.mois, &dpp.datedd.Annee, dpp.idemail,
                       dpp.infosupp) != EOF) {
            printf(" %d ", dpp.idd);
            if (dpp.idd == idDemande) {
                tr = 1;
                fprintf(f2, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                        nouv.qt_demande[0], nouv.qt_demande[1], nouv.qt_demande[2],
                        nouv.qt_demande[3], nouv.qt_demande[4], nouv.qt_demande[5], nouv.qt_demande[6],
                        nouv.qt_demande[7], nouv.place[0], nouv.place[1],nouv.demandeur, nouv.urgency, nouv.idd, nouv.datedd.Heure,
                        nouv.datedd.jour, nouv.datedd.mois, nouv.datedd.Annee, nouv.idemail,
                        nouv.infosupp);
            } else {
                fprintf(f2, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      dpp.qt_demande[0], dpp.qt_demande[1], dpp.qt_demande[2],
                      dpp.qt_demande[3], dpp.qt_demande[4], dpp.qt_demande[5], dpp.qt_demande[6],
                      dpp.qt_demande[7], dpp.place[0], dpp.place[1],dpp.demandeur, dpp.urgency, dpp.idd, dpp.datedd.Heure,
                      dpp.datedd.jour, dpp.datedd.mois, dpp.datedd.Annee, dpp.idemail,
                      dpp.infosupp);
            }
        }
        fclose(f);
        fclose(f2);
        remove(filename);
        rename("nouv.txt", filename);
        return tr;
    } else {
        return 0;
    }
}

int quantiteDemandee_type(char *nomFichier, char *type_sang) {
    int quantit_total = 0;
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        return -1;
    }
    d_poche_de_sang record;
        while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &record.qt_demande[0], &record.qt_demande[1], &record.qt_demande[2],
                      &record.qt_demande[3], &record.qt_demande[4], &record.qt_demande[5], &record.qt_demande[6],
                      &record.qt_demande[7], &record.place[0], &record.place[1],record.demandeur, &record.urgency, &record.idd, &record.datedd.Heure,
                      &record.datedd.jour, &record.datedd.mois, &record.datedd.Annee, record.idemail,
                       record.infosupp) != EOF) {
        if (strcmp(type_sang, "A+") == 0) {
            quantit_total += record.qt_demande[0];
        } else if (strcmp(type_sang, "A-") == 0) {
            quantit_total += record.qt_demande[1];
        } else if (strcmp(type_sang, "B+") == 0) {
            quantit_total += record.qt_demande[2];
        } else if (strcmp(type_sang, "B-") == 0) {
            quantit_total += record.qt_demande[3];
        } else if (strcmp(type_sang, "AB+") == 0) {
            quantit_total += record.qt_demande[4];
        } else if (strcmp(type_sang, "AB-") == 0) {
            quantit_total += record.qt_demande[5];
        } else if (strcmp(type_sang, "O+") == 0) {
            quantit_total += record.qt_demande[6];
        } else if (strcmp(type_sang, "O-") == 0) {
            quantit_total += record.qt_demande[7];
        }
    }
    fclose(f);
    return quantit_total;
}

void sang_demandee(char *filename, char sangDemande[]) {
    int Max, indice;
    int tabdemande[8] = {quantiteDemandee_type(filename, "A+"), quantiteDemandee_type(filename, "A-"), quantiteDemandee_type(filename, "B+"), quantiteDemandee_type(filename, "B-"), quantiteDemandee_type(filename, "AB+"), quantiteDemandee_type(filename, "AB-"), quantiteDemandee_type(filename, "O+"), quantiteDemandee_type(filename, "O-")};
    Max = tabdemande[0];
    indice = 0;
    for (int i = 0; i < 8; i++) {
        if (tabdemande[i] > Max) {
            Max = tabdemande[i];
            indice = i;
        }
    }
    if (indice == 0){
        strcpy(sangDemande,"A+");
        return sangDemande;}
    if (indice == 1){
        strcpy(sangDemande,"A-");
        return sangDemande;}
    if (indice == 2){
        strcpy(sangDemande,"B+");
        return sangDemande;}
    if (indice == 3){
        strcpy(sangDemande,"B-");
        return sangDemande;}
    if (indice == 4){
        strcpy(sangDemande,"AB+");
        return sangDemande;}
    if (indice == 5){
        strcpy(sangDemande,"AB-");
        return sangDemande;}
    if (indice == 6){
        strcpy(sangDemande,"O+");
        return sangDemande;}
    if (indice == 7){
        strcpy(sangDemande,"O-");
        return sangDemande;}
}
float pourcentage(char nomFichier[], int id) {
    int total_requests = 0, id_requests = 0;
    float percentage;
    FILE *f = fopen(nomFichier, "r");
    if (f == NULL) {
        return -1;
    }
    d_poche_de_sang record;
    while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                    &record.qt_demande[0], &record.qt_demande[1], &record.qt_demande[2],
                    &record.qt_demande[3], &record.qt_demande[4], &record.qt_demande[5], &record.qt_demande[6],
                    &record.qt_demande[7], &record.place[0], &record.place[1],record.demandeur, &record.urgency, &record.idd, &record.datedd.Heure,
                    &record.datedd.jour, &record.datedd.mois, &record.datedd.Annee, record.idemail,
                    record.infosupp) != EOF) {
        total_requests+=1;
        if (record.idd == id) {
            id_requests+=1;
        }
    }
    fclose(f);
    if (total_requests == 0) {
        return 0.0;
    }
    percentage = (float)id_requests / total_requests * 100.0;
    return percentage;
}
void ajouter_demande(d_poche_de_sang d)
{
FILE *f;
f=fopen("gdps.txt","a+");
if (f!=NULL) {
fprintf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
        d.qt_demande[0], d.qt_demande[1], d.qt_demande[2],
        d.qt_demande[3], d.qt_demande[4], d.qt_demande[5], d.qt_demande[6],
        d.qt_demande[7], d.place[0], d.place[1],d.demandeur, d.urgency, d.idd, d.datedd.Heure,
        d.datedd.jour, d.datedd.mois, d.datedd.Annee, d.idemail,
        d.infosupp);
fclose(f);
}
}







enum {
    IDENTIFIANT,
    ETABLISSEMENT_DEMANDEUR,
    ADRESSE_EMAIL,
    X,
    Y,
    HEURE,
    JOURR,
    MOISS,
    ANNEEE,
    URGENCY,
    COLUMNS1
};

void afficher_demande1(GtkWidget *liste) {

    GtkCellRenderer *renderer;

    GtkTreeViewColumn *column;

    GtkTreeIter iter;


    GtkListStore *store;

    char idd[10];
    char demandeur[100];
    char idemail[100];
    int urgency[2];
    char Heure[10], jour[10], mois[10], Annee[10];
    char x[10],y[10];
    store = NULL;


    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", IDENTIFIANT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Demandeur", renderer, "text", ETABLISSEMENT_DEMANDEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("IDEMAIL", renderer, "text", ADRESSE_EMAIL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("X", renderer, "text", X, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Y", renderer, "text", Y, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Heure", renderer, "text", HEURE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOURR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOISS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEEE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("URGENCE", renderer, "text", URGENCY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
	}
 
	store = gtk_list_store_new(COLUMNS1,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    

	f = fopen("gdps.txt", "r");
    		if (f == NULL) 
		{
			perror("error!");
        		return;
    		}
		else{
			d_poche_de_sang record;
			f = fopen("gdps.txt", "a+");
      			while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &record.qt_demande[0], &record.qt_demande[1], &record.qt_demande[2],
                      &record.qt_demande[3], &record.qt_demande[4], &record.qt_demande[5], &record.qt_demande[6],
                      &record.qt_demande[7], &record.place[0], &record.place[1],record.demandeur, &record.urgency, &record.idd, &record.datedd.Heure,
                      &record.datedd.jour, &record.datedd.mois, &record.datedd.Annee, record.idemail,
                       record.infosupp) != EOF) {
				sprintf(Heure,"%d",record.datedd.Heure); sprintf(jour,"%d",record.datedd.jour); sprintf(mois,"%d",record.datedd.mois); sprintf(Annee,"%d",record.datedd.Annee);
				sprintf(x,"%d",record.place[0]);sprintf(y,"%d",record.place[1]);sprintf(urgency,"%d",record.urgency);strcpy(idemail,record.idemail);strcpy(demandeur,record.demandeur);sprintf(idd,"%d",record.idd);


					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter,
							   IDENTIFIANT, idd,
							   ETABLISSEMENT_DEMANDEUR, demandeur,
							   ADRESSE_EMAIL, idemail,
							   X, x,
							   Y, y,
							   HEURE, Heure,
							   JOURR, jour,
							   MOISS, mois,
							   ANNEEE, Annee,
							   URGENCY, urgency,
							   -1);
    						}

    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
		}
	
}













void vider1(GtkWidget *liste) 
{


    GtkCellRenderer *renderer;

    GtkTreeViewColumn *column;

    GtkTreeIter	iter;

    GtkListStore *store;

    char idd[10];
    char demandeur[100];
    char idemail[100];
    int urgency[2];
    char Heure[10], jour[10], mois[10], Annee[10];
    char x[10],y[10];
    store = NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", IDENTIFIANT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Demandeur", renderer, "text", ETABLISSEMENT_DEMANDEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("IDEMAIL", renderer, "text", ADRESSE_EMAIL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("X", renderer, "text", X, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Y", renderer, "text", Y, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Heure", renderer, "text", HEURE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOURR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOISS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEEE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("URGENCE", renderer, "text", URGENCY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	}
store = gtk_list_store_new(COLUMNS1,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	gtk_list_store_append(store,&iter);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
}
















enum {
    IDENTIFIANT2,
    ETABLISSEMENT_DEMANDEUR2,
    PERCENTAGE,
    COLUMNS2
};

void afficher_demande2(GtkWidget *liste) {

    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter	iter;
    GtkListStore *store;

    int idd;
    char demandeur[100];
    float percent;
    char perchent[100],iddch[20];

    store = NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);

    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", IDENTIFIANT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Demandeur", renderer, "text", ETABLISSEMENT_DEMANDEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Pourcentage", renderer, "text", PERCENTAGE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
	}
  
 store = gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f = fopen("gdps.txt", "r");
    		if (f == NULL) 
		{
        		return;
    		}
		else{
			d_poche_de_sang record;
			f = fopen("gdps.txt", "a+");
      			while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &record.qt_demande[0], &record.qt_demande[1], &record.qt_demande[2],
                      &record.qt_demande[3], &record.qt_demande[4], &record.qt_demande[5], &record.qt_demande[6],
                      &record.qt_demande[7], &record.place[0], &record.place[1],record.demandeur, &record.urgency, &record.idd, &record.datedd.Heure,
                      &record.datedd.jour, &record.datedd.mois, &record.datedd.Annee, record.idemail,
                       record.infosupp) != EOF) {
			percent=pourcentage("gdps.txt",record.idd);
			sprintf(perchent,"%f", percent);
			sprintf(iddch,"%d", record.idd);
            		gtk_list_store_append(store, &iter);
            		gtk_list_store_set(store, &iter, IDENTIFIANT, iddch, ETABLISSEMENT_DEMANDEUR, record.demandeur, PERCENTAGE, perchent, -1);	
        		}
        	fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
        	g_object_unref(store);
		}
        
    }	


void vider2(GtkWidget *liste) 
{


    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter	iter;
    GtkListStore *store;

    int idd;
    char demandeur[100];
    float percent;
    char perchent[100];

    store = NULL;
    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", IDENTIFIANT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Demandeur", renderer, "text", ETABLISSEMENT_DEMANDEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Pourcentage", renderer, "text", PERCENTAGE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
	}
 store = gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	gtk_list_store_append(store,&iter);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));

}


















void afficher_demande3(GtkWidget *liste, int idd) {

    GtkCellRenderer *renderer;

    GtkTreeViewColumn *column;

    GtkTreeIter iter;


    GtkListStore *store;

    char iddch[10];
    char demandeur[100];
    char idemail[100];
    int urgency[2];
    char Heure[10], jour[10], mois[10], Annee[10];
    char x[10],y[10];
    store = NULL;


    FILE *f;

    store = gtk_tree_view_get_model(liste);
    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", IDENTIFIANT, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Demandeur", renderer, "text", ETABLISSEMENT_DEMANDEUR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("IDEMAIL", renderer, "text", ADRESSE_EMAIL, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("X", renderer, "text", X, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Y", renderer, "text", Y, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Heure", renderer, "text", HEURE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Jour", renderer, "text", JOURR, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Mois", renderer, "text", MOISS, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("Annee", renderer, "text", ANNEEE, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes("URGENCE", renderer, "text", URGENCY, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
    
	}
 
	store = gtk_list_store_new(COLUMNS1,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
    

	f = fopen("gdps.txt", "r");
    		if (f == NULL) 
		{
			perror("error!");
        		return;
    		}
		else{
			d_poche_de_sang record;
			f = fopen("gdps.txt", "a+");
      			while (fscanf(f, " %d %d %d %d %d %d %d %d %d %d %s %d %d %d %d %d %d %s %s \n",
                      &record.qt_demande[0], &record.qt_demande[1], &record.qt_demande[2],
                      &record.qt_demande[3], &record.qt_demande[4], &record.qt_demande[5], &record.qt_demande[6],
                      &record.qt_demande[7], &record.place[0], &record.place[1],record.demandeur, &record.urgency, &record.idd, &record.datedd.Heure,
                      &record.datedd.jour, &record.datedd.mois, &record.datedd.Annee, record.idemail,
                       record.infosupp) != EOF) {
           if (record.idd == idd)
                    {
				sprintf(Heure,"%d",record.datedd.Heure); sprintf(jour,"%d",record.datedd.jour); sprintf(mois,"%d",record.datedd.mois); sprintf(Annee,"%d",record.datedd.Annee);
				sprintf(x,"%d",record.place[0]);sprintf(y,"%d",record.place[1]);sprintf(urgency,"%d",record.urgency);strcpy(idemail,record.idemail);strcpy(demandeur,record.demandeur);sprintf(iddch,"%d",record.idd);


					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter,
							   IDENTIFIANT, iddch,
							   ETABLISSEMENT_DEMANDEUR, demandeur,
							   ADRESSE_EMAIL, idemail,
							   X, x,
							   Y, y,
							   HEURE, Heure,
							   JOURR, jour,
							   MOISS, mois,
							   ANNEEE, Annee,
							   URGENCY, urgency,
							   -1);
    						}}

    fclose(f);
    gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
    g_object_unref(store);
		}
	
}



enum 
{
	adminutilisateur,
	adminname,
	adminsurname,
	adminregion,
	adminphone,
	adminrole,
	adminemail,
	admingender,
	adminid,
	adminadress,
	adminjoindate,
	admindate,
	COLUMNS,
};

void show_user(char *file,GtkWidget *liste)
 {
    
    
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkTreeIter iter;
    GtkListStore *store;
   
    char utilisateur[30];
    char name[30];
    char surname[30];
    char password[30];
    char region[30];
    char phone[30];
    char role[30];
    char email[30];
    char gender[30];
    char id[30];
    char adress[30];
    char joindate[30];
    char date[30];
    
     store = NULL;
     FILE *f;
    store = gtk_tree_view_get_model(liste);
   
    if (store == NULL) {
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Utilisateur ", renderer, "text", adminutilisateur, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Name ", renderer, "text", adminname, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Surname ", renderer, "text", adminsurname, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Region ", renderer, "text", adminregion, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
        
        
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Phone ", renderer, "text", adminphone, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Role ", renderer, "text", adminrole, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Email ", renderer, "text", adminemail, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Gender ", renderer, "text", admingender, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" ID ", renderer, "text", adminid, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Adress ", renderer, "text", adminadress, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Joindate ", renderer, "text", adminjoindate, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
       
        renderer = gtk_cell_renderer_text_new();
        column = gtk_tree_view_column_new_with_attributes(" Date ", renderer, "text", admindate, NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);
       
      } 
         store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,
                                   G_TYPE_STRING);	
          f = fopen(file, "r");
        if (f != NULL) {
         while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", utilisateur,password, name, surname,role,phone,email,gender,id,adress,joindate,region,date) != EOF) {
                           gtk_list_store_append(store, &iter);
                gtk_list_store_set(store, &iter, adminutilisateur, utilisateur, adminname, name, adminsurname, surname,
                                   adminregion, region, adminphone, phone, adminrole, role, adminemail, email,
                                   admingender, gender, adminid, id, adminadress, adress, adminjoindate, joindate,
                                   admindate, date, -1);    
                                    }
            fclose(f);
            gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
            g_object_unref(store);
        }
    
}                      



int admin_user_edit(char *filename, char id[50],admin_user new_user) {
    admin_user user;
    int tr=0;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF) {
            if (strcmp(user.adminuser_identification_card_number ,id)==0) {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n", new_user.adminuser_username, new_user.adminuser_password,
        new_user.adminuser_name,new_user.adminuser_surname, new_user.adminuser_role,new_user.adminuser_phone,new_user.adminuser_email,
        new_user.adminuser_gender,new_user.adminuser_identification_card_number,new_user.adminuser_address,new_user.adminuser_joindate,
        new_user.adminuser_region,new_user.adminuser_date);
                tr = 1;
            }else if (strcmp(user.adminuser_identification_card_number ,id)!=0) {
           fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n", user.adminuser_username, user.adminuser_password,
        user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
        user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address, user.adminuser_joindate,
        user.adminuser_region, user.adminuser_date);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;
}
int admin_user_delete(char *filename, char id[50]) {
    int tr = 0;
    admin_user user;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF) {
            if (strcmp(user.adminuser_identification_card_number ,id)==0) {
                tr = 1;
            } else {
                fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n", user.adminuser_username, user.adminuser_password,
        user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
        user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address, user.adminuser_joindate,
        user.adminuser_region, user.adminuser_date);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("new.txt", filename);
    return tr;
}
admin_user admin_user_search(char *filename, char id[50]) {
    admin_user user;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while  (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF)
              {
            if (strcmp(user.adminuser_identification_card_number,id)==0) {
                tr = 1;
                break;
               
            }
        }
    
    fclose(f);
    if (tr == 0) {
        strcpy(user.adminuser_identification_card_number ,"-1");
    }
    return user;
    }
} 
int admin_user_verif(char *filename, char id[50]) {
    admin_user user;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF) {
            if (strcmp(user.adminuser_identification_card_number ,id)==0) {
                return(1);
            }
        }
    }
    fclose(f);
    return 0;
} 
float admin_user_percentage(char *filename,float *percentagemale,float *percentagefemale) {
    int male = 0,  female = 0 ;
    float percentage;
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }
    admin_user user;
    while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF) {
if (strcmp(user.adminuser_gender, "male") == 0) {
            male++;
        }
if (strcmp(user.adminuser_gender,"female") == 0) {
            female++;
        }
    }
    fclose(f);
  *percentagemale =(float) male*100 / (female + male) ;
  *percentagefemale = (float) female*100 / (female+male) ;
    return 1.0;
}
int UserRole(char *filename, char *role)
{
 
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        return -1;
    }
admin_user user;
FILE *f2 = fopen("role.txt", "w");
while (fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF) {
if (strcmp(user.adminuser_role,role)==0)
{
fprintf(f2, "%s %s %s %s %s %s %s %s %s %s %s %s %s\n", user.adminuser_username, user.adminuser_password,
        user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
        user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address, user.adminuser_joindate,
        user.adminuser_region, user.adminuser_date);
}
}
fclose(f);
fclose(f2);
return 1;
}
int is_not_empty(const char *str) {
    return strlen(str) > 0;
}
int is_valid_address(const char *str) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    while (*str) {
        if (!isalnum(*str) && *str != ' ') {
            return 0; // Not alphanumeric or space
        }
        str++;
    }
    return 1; // All characters are valid
}
int is_alpha_string(const char *str) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    while (*str) {
        if (!isalpha(*str) && *str != ' ') {
            return 0; // Not a letter or space
        }
        str++;
    }
    return 1; // All characters are letters or space
}
int is_valid_email(const char *str)
 {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }
    int at_count = 0;
    int dot_count = 0;
 while (*str) {
        if (*str == '@') {
            at_count++;
        } else if (*str == '.') {
            dot_count++;
        } else if (!isalnum(*str) && *str != '_' && *str != '%'
                   && *str != '+' && *str != '-') {
            return 0; // Invalid character
        }
str++;
    }
     return (at_count == 1) && (dot_count >= 1);
}
int is_valid_region(const char *str) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    return is_alpha_string(str);
}
int is_valid_username(const char *str) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    while (*str) {
        if (!isalnum(*str) && *str != '_' && *str != '.' && *str != ' ') {
            return 0; // Not alphanumeric, _, ., or space
        }
        str++;
    }
    return 1; // All characters are valid
}

int is_valid_phone(const char *str) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    const char *original_str = str;

    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Not a digit
        }
        str++;
    }

    return (str - original_str) == 8; 
}


int is_numeric_string(const char *str, int length) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Not a digit
        }
        str++;
    }
    return strlen(str) == length; // Check  the length 
}
int is_valid_password(const char *str) {
if (!is_not_empty(str)) {
        return 0; // Empty string
    }
    return is_valid_username(str);
}

int is_valid_id(const char *str) {
    if (!is_not_empty(str)) {
        return 0; // Empty string
    }

    if (strlen(str) != 8) {
        return 0; // ID should have a fixed size of 8 digits
    }

    while (*str) {
        if (!isdigit(*str)) {
            return 0; // Not a digit
        }
        str++;
    }

    return 1; // All characters are digits, and the size is 8
}

int userrolecheck(char a[50],char b[50],char c[50])
{
FILE *f = fopen("adminusers.txt", "r");
admin_user user;


while(fscanf(f, "%s %s %s %s %s %s %s %s %s %s %s %s %s", user.adminuser_username, user.adminuser_password,
              user.adminuser_name, user.adminuser_surname, user.adminuser_role, user.adminuser_phone, user.adminuser_email,
              user.adminuser_gender, user.adminuser_identification_card_number, user.adminuser_address,
              user.adminuser_joindate, user.adminuser_region, user.adminuser_date) != EOF) {
              if ((strcmp(user.adminuser_identification_card_number,a)==0) &&(strcmp(user.adminuser_password,b)==0))
              {
               strcpy(c,user.adminuser_role);
               return(1);
               fclose(f);
               }
               
               }
               return(0);
               }


enum 
{
	Identifiant,
	Nom_Etablissement,
	region,
	capacite,
	N_Telephone,
	annee,
	mois,
	jour,
	COLUMNSSS,
};
	





// ajouter etablissement
void add_ets(Etablissement ets)
{
    FILE * f=fopen("etablissement.txt", "a+");
    if(f!=NULL)
       {  	fprintf(f," %s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day);
        	fclose(f);
		}
	
   
}



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// rechercher etablissement atelier GRUD
Etablissement search(char *filename, char * id) {
    Etablissement ets;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL) {
        while (tr == 0 && fscanf(f, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF) {
            if (strcmp(ets.id, id)==0) {
                tr = 1;
            }
        }
    }
    fclose(f);

    if (tr == 0) {
        // Set id to -1 to indicate not found
        strcpy(ets.id,"-1");
    }

    return ets;
}
////////////////////////////////////////////////////////////


int verife_phone(char *phone){
if (strlen(phone)==8){
	for (int i=0;i<8;i++){
		if(phone[i] <'0' || phone[i] >'9') {
			return 0;
		  }
	 }
	return 1;
	}
else 
	return 0;
}

//////////////////////////////////////////////



int verife_nom(char *ch){
if (strlen(ch)==0)
	return 0;
for (int i=0;i < strlen(ch);i++){
	if  (!((ch[i] >='A' && ch[i] <='Z') || (ch[i] >='a' && ch[i] <='z'))) { 
     		return 0;   
	}
 } 

return 1; 
}

///////////////////////////////////////////



int verife_cap(char *ch){
if (strlen(ch)==0)
	return 0;
for(int i=0;i < strlen(ch);i++){
	if ((ch[i] <'0') || (ch[i] >'9')){
		return 0;
	}
}

return 1;
}

/////////////////////////////////////////////////////



int verife_reg(char *reg)
{
if (strcmp(reg,"kasserine")==0 || strcmp(reg,"monastir")==0)
	return 1;
	
else 
	return 0;
}















int verife_id(char *id){
if (strlen(id)==3){
	for (int i=0;i<3;i++){
		if(id[i] <'0' || id[i] >'9') {
			return 0;
		  }
	 }
	return 1;
	}
else 
	return 0;
}

////////////////////////////////////////////////////


int ext_id(char *id){
    Etablissement ets;
    FILE *f = fopen("etablissement.txt", "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF) {
            if (strcmp(ets.id, id)==0) {
		fclose(f);
                return 1;
            }
        }
    }

    return 0;
}


////////////////////////////////////////////////////////




void delete_ets(char* id) {
    Etablissement ets;
    FILE *f = fopen("etablissement.txt", "r");
    FILE *f2 = fopen("new.txt", "w");
    if (f != NULL && f2 != NULL) {
        while (fscanf(f, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF) {
            if (strcmp(ets.id, id)!=0) {
                fprintf(f2, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("etablissement.txt");
    rename("new.txt", "etablissement.txt");
}
////////////////////////////////////////////////////////////////////////////////////////////////////


// modifier etablissement par identifiant
int edit_ets(char* id,Etablissement new_ets) 
{
    int tr = 0;
    Etablissement ets;
    FILE *f =fopen("etablissement.txt", "r");
    FILE *f2 =fopen("new.txt", "w");
    if (f!=NULL && f2!=NULL) {
        while (fscanf(f,"%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF) {
            if (strcmp(ets.id,id)==0) {
                fprintf(f2,"%s %s %s %s %s %s %s %s\n", new_ets.id, new_ets.name, new_ets.region,new_ets.capacite,new_ets.phone, new_ets.year, new_ets.month, new_ets.day);
                tr = 1;
            }else 
		if (strcmp(ets.id,id)!=0) {
                	fprintf(f2, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day);
            }
        }
    }
    fclose(f);
    fclose(f2);
    remove("etablissement.txt");
    rename("new.txt", "etablissement.txt");
    return tr;
}




/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






// Afficher tous etablissement 
void show_ets(char *nomFichier,GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char Id [30];
	char Nom [30];
	char Region [30];
	char Capacite [30];
	char Telephone [30];
	char Annee [30];
	char Mois [30];
	char Jour [30];
	store=NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Id ",renderer,"text",Identifiant,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Nom ",renderer,"text",Nom_Etablissement,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Region ",renderer,"text",region,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Capacite ",renderer,"text",capacite,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Telephone ",renderer,"text",N_Telephone,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Annee ",renderer,"text",annee,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Mois ",renderer,"text",mois,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" Jour ",renderer,"text",jour,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
}
		store=gtk_list_store_new (COLUMNSSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
		f=fopen(nomFichier,"r");
		if (f==NULL)
		{
			return;
		}
		else
		{ f= fopen(nomFichier,"a+");
				while(fscanf(f,"%s %s %s %s %s %s %s %s \n",Id,Nom,Region,Capacite,Telephone,Annee,Mois,Jour)!=EOF)
			{
		gtk_list_store_append (store, &iter);
		gtk_list_store_set(store,&iter,Identifiant,Id,Nom_Etablissement,Nom,region,Region,capacite,Capacite,N_Telephone,Telephone,annee,Annee,mois,Mois,jour,Jour, -1);
			}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
		g_object_unref (store);


		}
	
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////








// affichage etablissement par region et leurs nombres 
int ETSParRegion( char *reg)
{	
	Etablissement ets;
	FILE *f,*f2;
	f=fopen("regions.txt","w");
	f2=fopen("etablissement.txt","r");
	int tr=0;
	if((f!=NULL) && (f2!=NULL) ){
 	while(fscanf(f2, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF){
		
		if (strcmp (ets.region,reg)==0)
 	  	    {fprintf(f, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day);
			tr++;
			}
	}
	
	fclose(f);
	fclose(f2);
	return(tr);

}



}









//////////////////////////////////////////////////////////////////




/*


// affichage triées par capacité
void ETSTrieCapacite(char *nomFichier)
{
	FILE *f,*f2,*f4;
	f=fopen("cap.txt","w");
	f2=fopen(nomFichier,"r");
	f4=fopen("captriés.txt","w");
	int a=0;
	Etablissement ets;
	if ((f!=NULL) && (f2!=NULL) && (f4!=NULL)){
 	while(fscanf(f2, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF){
		int tr=0;
		char ti[30];
		while (fscanf(f,"%s",ti)!= EOF){
			if (strcmp(ti,ets.capacite)==0)
				tr++;
		}	
		if (tr==0){
			fprintf(f,"%s\n",ets.capacite);
			a++
	}
	fclose(f);
	while(1){
		int z=0;
		f=fopen("cap.txt","r");
		char ta[30],c[30]="0";
		for (int i=0;i<a;i++){
			fscanf(f,"%s",ta);			
			if(strcmp(ta,c)==1){
				strcpy(c,ta);
				z=1;
			}
		fclose(f);
		}
		fprintf(f4,"%s\n",c);
		f=fopen("cap.txt","r");
		FILE *f3 = fopen("new.txt", "w");
		char to[30];
		while (fscanf(f,"%s",to)!= EOF){
			if (strcmp(to,c)!=0){
				fprintf(f3,"%s \n",to);
			}
		}
    	fclose(f3);
    	fclose(f);
   	remove("cap.txt");
   	rename("new.txt", "cap.txt");
	if (z!=0)
		break;
	}
	fclose(f4);
	fclose(f2);
	f2=fopen(nomFichier,"r");
	FILE *f5=fopen("aff_fich.txt","w");
	f4=fopen("captriés.txt","r");
	char aff[30];
	while (fscanf(f4,"%s\n",aff)!= EOF){
		while(fscanf(f2, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF){
			if (strcmp(aff,ets.capacite)==0){
				fprintf(f5, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day);
			}
		}

	}
	fclose(f4);
	fclose(f2);
	fclose(f5);

}



/////////////////////////////////////////////////////


*/
		
// vider tableau 
				
void vider(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
	char id [30];
	char nom [30];
	char region [30];
	char cap [30];
	char tel [30];
	char annee [30];
	char mois [30];
	char jour [30];
	store=NULL;

	FILE *f;
	store=gtk_tree_view_get_model(liste);
	if (store==NULL){

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" id",renderer,"text",Identifiant,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" nom",renderer,"text",Nom_Etablissement,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" region",renderer,"text",region,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" cap",renderer,"text",capacite,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" tel",renderer,"text",N_Telephone,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" annee",renderer,"text",annee,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new (); 
		column = gtk_tree_view_column_new_with_attributes(" mois",renderer,"text",mois,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes(" jour",renderer,"text",jour,NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		}
	store=gtk_list_store_new (COLUMNSSS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	gtk_list_store_append (store, &iter);
	gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store));
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void ETSTrieCapacite_croissant() {
    int i, j, min, nb = 0;
    Etablissement* tab = NULL; 
    Etablissement ets, tampon;
    FILE* f = fopen("etablissement.txt", "r");
    FILE* f1 = fopen("captriecroi.txt", "w");
    if ((f!=NULL) && (f1!=NULL) ){
    while (fscanf(f, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF) {
        nb++;
        tab = (Etablissement*)realloc(tab, nb * sizeof(Etablissement));
        strcpy(tab[nb-1].id,ets.id);
        strcpy(tab[nb-1].name,ets.name);
        strcpy(tab[nb-1].region,ets.region);
        strcpy(tab[nb-1].capacite,ets.capacite);
        strcpy(tab[nb-1].phone,ets.phone);
        strcpy(tab[nb-1].year,ets.year);
        strcpy(tab[nb-1].month,ets.month);
        strcpy(tab[nb-1].day,ets.day);
    }
    for (i=0;i<nb-1;i++) {
        min=i;
        for (j=i+1;j<nb;j++) {
            if (strcmp(tab[j].capacite, tab[min].capacite)==-1)
                min=j;
        }
        tampon=tab[i];
        tab[i]=tab[min];
        tab[min]=tampon;
    }
    for (i=0;i<nb;i++) {
        fprintf(f1,"%s %s %s %s %s %s %s %s\n",tab[i].id,tab[i].name,tab[i].region,tab[i].capacite,tab[i].phone,tab[i].year,tab[i].month,tab[i].day);
    }
	}
    fclose(f);
    fclose(f1);
    free(tab);	 

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void ETSTrieCapacite_decroissant() 
{
    int i, j, min, nb = 0;
    Etablissement* tab = NULL; 
    Etablissement ets, tampon;
    FILE* f = fopen("etablissement.txt", "r");
    FILE* f1 = fopen("captriedecroi.txt", "w");
    if ((f!=NULL) && (f1!=NULL) ){
    while (fscanf(f, "%s %s %s %s %s %s %s %s\n",ets.id,ets.name,ets.region,ets.capacite,ets.phone,ets.year,ets.month,ets.day) != EOF) {
        nb++;
        tab = (Etablissement*)realloc(tab, nb * sizeof(Etablissement));
        strcpy(tab[nb-1].id,ets.id);
        strcpy(tab[nb-1].name,ets.name);
        strcpy(tab[nb-1].region,ets.region);
        strcpy(tab[nb-1].capacite,ets.capacite);
        strcpy(tab[nb-1].phone,ets.phone);
        strcpy(tab[nb-1].year,ets.year);
        strcpy(tab[nb-1].month,ets.month);
        strcpy(tab[nb-1].day,ets.day);
    }
    for (i=0;i<nb-1;i++) {
        min=i;
        for (j=i+1;j<nb;j++) {
            if (strcmp(tab[j].capacite, tab[min].capacite)==-1)
                min=j;
        }
        tampon=tab[i];
        tab[i]=tab[min];
        tab[min]=tampon;
    }
    for (i=0;i<nb;i++) {
        fprintf(f1,"%s %s %s %s %s %s %s %s\n",tab[nb-i-1].id,tab[nb-i-1].name,tab[nb-i-1].region,tab[nb-i-1].capacite,tab[nb-i-1].phone,tab[nb-i-1].year,tab[nb-i-1].month,tab[nb-i-1].day);
    }
    fclose(f);
    fclose(f1);

}
}















