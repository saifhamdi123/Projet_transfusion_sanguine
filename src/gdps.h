#ifndef GDPS_H_INCLUDED
#define GDPS_H_INCLUDED
#include<stdio.h>
#include <gtk/gtk.h>


typedef struct{
    char typesang[5];
    char quantitesang[10];
}Sang;
typedef struct {
    char Id_donneur[25] ;
    char Code_don [25];
    char Quantite_sang [25];
    char Type_sang[5] ;
    char Jour[25];
    char Mois[25];
    char Annee[25];
    char ets[25];
} Dons;

int ajouter_don( Dons );
void afficher_don(GtkWidget *liste);
int modifier_don( char[] , Dons);
int supprimer_don(char[] );
Dons chercher_don( char[] );
void supprimer_select(Dons d);


float Quantite_sang( char * , char[] );
void QuantitesTousTypes();
void AfficherQuantitesTousTypes(GtkWidget *liste);
Sang SangPlusRare();

int verifID(char id[]);
int verif_entier(char []);
int verif_unicite(char code[]);
int verif_quantitesang(char Q[]);
int Verif_ets(char ets[]);
//-------------------------------------------------------------------------------------------------------
int l;
char  w[50];
typedef struct
{
	char id[50];
	char name[50];
	char region[50];
	char capacite[50];
	char phone[50];
	char year[50];
	char month[50];
	char day[50];
}Etablissement;
typedef struct
{
    
    char adminuser_username[50];
    char adminuser_password[50];
    char adminuser_name[50];
    char adminuser_surname[50];
    char adminuser_role[50];
    char adminuser_phone[50];  
    char adminuser_email[50];
    char adminuser_gender[50];
    char adminuser_identification_card_number[50];  
    char adminuser_address[50];
    char adminuser_joindate[50];  
    char adminuser_region[50];
    char adminuser_date[50];
    } admin_user;

typedef struct 
{
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

} donneur;

typedef struct 
{
	char infirmier_ID_ETS[50];
	char infirmier_medecin[50];
	char infirmier_ID_RDV[50];    //ID_RDV = cin du donneur 
	int infirmier_heure_RDV;
	int infirmier_jour_RDV;
	int infirmier_mois_RDV;
	int infirmier_annee_RDV;
} RDV;






int infirmier_ajouter_information_generale(char * filename, donneur d);

int infirmier_ajouter_RDV(char * filename,RDV r);

int infirmier_modifier_RDV( char* filename, int cin,RDV b);

int infirmier_modifier_donneur( char* filename, int cin,donneur a );

int infirmier_supprimer_donneur(char * filename,char * filename1, int cin);

donneur infirmier_chercher(char* filename, int cin);

int listeRDV(char nomFichier[], int jour, int mois , int annee);

int nbETS( char nomFichier[]);

float moyRDV_ETS (char nomFichier[], int jour, int mois , int annee);

int ajouter_rdv(char * filename, RDV r);



int admin_user_add(char *filename,admin_user user);
int admin_user_verif(char *filename, char id[]);



void afficher_donneurs(GtkWidget *liste);

typedef struct {
    int Heure;
    int jour;
    int mois;
    int Annee;
} dated;

typedef struct {
    int idd;
    int qt_demande[8];  // chaque 2 cases pour un type
    int place[2];
    dated datedd;
    char idemail[100];
    char infosupp[400];  
    char demandeur[100];
    int urgency;  
} d_poche_de_sang;

int ajouterDemande(char *filename, d_poche_de_sang demandes);
int supprimerDemande(char *filename, int idDemande);
d_poche_de_sang chercherDemande(char *filename, int idDemande);
int modifierDemande(char *filename, d_poche_de_sang nouv, int idDemande);
int quantiteDemandee_type(char *nomFichier, char *type_sang);
void sang_demandee(char *filename, char sangDemande[]);
float pourcentage(char nomFichier[], int idd);
void ajouter_demande(d_poche_de_sang d);
void vider(GtkWidget *liste);
void afficher_demande(GtkWidget *liste);
int supprimerDemande2(char *filename, int idDemande, char idemail[], char demandeur[], int x, int y, int urgency, int Heure, int jour, int mois, int Annee);
d_poche_de_sang chercherDemande2(char *filename, int idDemande, char idemail[], char demandeur[], int x, int y, int urgency, int Heure, int jour, int mois, int Annee);

//*************************************************----*******************----*************************************************




int admin_user_add(char *filename,admin_user user);
 int admin_user_edit(char *filename, char id[50], admin_user new_user);
int admin_user_delete(char *filename, char id[50]);
admin_user admin_user_search(char *filename, char id[50]);
float admin_user_percentage(char *filename,float *percentagemale,float *percentagefemale) ;
int UserRole(char *filename, char *role);
int admin_user_verif(char *filename, char id[50]) ;
int is_valid_email(const char *str);
int is_numeric_string(const char *str, int length) ;
int is_alpha_string(const char *str) ;
int is_valid_username(const char *str) ;
int is_valid_password(const char *str);
int is_valid_id(const char *str);
int is_valid_phone(const char *str);
void show_user(char *file,GtkWidget *liste);
int userrolecheck(char a[50],char b[50],char c[50]);




void add_ets(Etablissement ets);
int edit_ets(char* id,Etablissement new_ets);// modifier un ets
Etablissement search(char *, char*);
void delete_ets(char* id);
int verife_phone(char *ch);// verifier si le nb de tlf est de taille 8 et composé seulement de chiffre ou non 
int verife_nom(char *ch);// verifier si le nom est composée seulement par des alphabet ou non 
int verife_cap(char *ch);// verifier si le cap est composée de chiffres ou non 
int verife_reg(char *reg);// verifier la region
int ext_id(char *id);// verifier l'existance du id ou non 
void vider(GtkWidget *liste);


void ETSTrieCapacite_decroissant();// trié les ets par cap decroissant
void show_ets(char *nomFichier,GtkWidget *liste);
void ETSTrieCapacite_croissant();// trié les ets par cap croissant
int ETSParRegion(char* reg);// trié par reg 
#endif // GDPS_H_INCLUDED
