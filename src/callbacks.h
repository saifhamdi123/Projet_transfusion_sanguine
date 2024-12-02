#include <gtk/gtk.h>
#include "gdps.h"



void
on_radiobuttonABm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonOm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonBm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonBp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonOp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonABp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Deconnexion_don_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_valider_don_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_buttonAjouter_don_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobuttonApp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonBpp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonOpp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonABpp_don_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAmm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonBmm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonOmm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonABmm_don_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Chercher_don_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_Modifier_don_don_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_buttonAfficher_don_trv_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);



void
on_buttonafficher2_don_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonAfficher1_don_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobuttonAp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonBp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonOp_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonABp_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonAm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonBm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonOm_don_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobuttonABm_don_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_supprimer2_don_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_checkbutton1Confirmer_don_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bouton_acceuil_rechercher_un_donneur_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bouton_acceuil_supprimer_un_donneur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_acceuil_modifier_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_acceuil_moyRDV_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_acceuil_filtrage_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_acceuil_ajouter_un_donneur_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_acceuil_affichage_donneurs_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_ajoutdonneur_ajouter_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_ajout_homme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ajout_femme_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_ajout_confirmerici_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bouton_ajoutdonneur_retour_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_ajoutdonneur_confirmer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_affichage_row_activated    (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bouton_affichage_filtrer_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_recherche_afficherdonneur_clicked
                                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_bouton_filtrage_afficher_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_filtrage_homme_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_filtrage_femme_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bouton_suppression_supprimer_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);



void
on_bouton_suppression_retour_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_modification_modifier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_moyRDV_confirmer_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_moyRDV_retour_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview_filtre_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bouton_contenufiltre_retour_clicked (GtkWidget      *w,
                                        gpointer         user_data);

void
on_treeview_affichagedonneur_row_activated
                                        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_bouton_affichagedonneur_retour_clicked
                                        (GtkWidget       *w,
                                        gpointer         user_data);

void
on_bouton_confirmation_suppression_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_annuler_suppression_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton_modifier_confirmerici_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_bouton_modifierRDV_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_modifier_retour_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_modifier_comfirmationmodif_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_espaceinfirmier_show                (GtkWidget      *widget,
                                        gpointer         user_data);

void
on_bouton_affichage_recherche_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_bouton_filtre_recherche_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_calendar1infirmier_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_calendar2infirmier_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data);

void
on_calendar3infirmier_day_selected              (GtkCalendar     *calendar,
                                        gpointer         user_data);


void
on_button1infirmier_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmationsuppression_close       (GtkDialog       *dialog,
                                        gpointer         user_data);

void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_affichage_un_donneur_show           (GtkWidget       *widget,
                                        gpointer         user_data);



void
on_comboboxentry1_sangtype_editing_done
                                        (GtkCellEditable *celleditable,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);



gint
on_spinbutton1_jour_input              (GtkSpinButton   *spinbutton,
                                        gdouble *new_value,
                                        gpointer         user_data);

gint
on_spinbutton1_mois_input              (GtkSpinButton   *spinbutton,
                                        gdouble *new_value,
                                        gpointer         user_data);

gint
on_spinbutton1_Annee_input             (GtkSpinButton   *spinbutton,
                                        gdouble *new_value,
                                        gpointer         user_data);



void
on_checkbutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_spinbutton24_change_value           (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data);

void
on_spinbutton25_change_value           (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data);

void
on_spinbutton26_change_value           (GtkSpinButton   *spinbutton,
                                        GtkScrollType    scroll,
                                        gpointer         user_data);



void
on_button20_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);





void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button10_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Recherche_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);




void
on_Actualiser_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Afficher_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_entry26_insert_int                  (GtkEditable     *editable,
                                        gchar           *new_text,
                                        gint             new_text_length,
                                        gpointer         position,
                                        gpointer         user_data);

void
on_confirmer_recher_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_GDPS_activate_default               (GtkWindow       *window,
                                        gpointer         user_data);

void
on_Affichage_activate_default          (GtkWindow       *window,
                                        gpointer         user_data);

void
on_fenetre_afficher_row_activated      (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_Confirmer_GDPS_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button9_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Console_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

/*void
on_button1_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);*/

void
on_lestypes_confirmer_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_lestypes_annuler_clicked            (GtkWidget       *button,
                                        gpointer         user_data);


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Urgence_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Ajouter_GDPS_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Annuler_modif_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Confirmer_modif_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Urgence2_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_confer_type_modif_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_confer_type_Ajou_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_confer_type_Ajou_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void
on_Modifier_GDB_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void
on_RetourAj_ver_Aff_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_RetourMod_ver_Aff_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_RetourSupp_ver_Aff_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_LeType_Annuler_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_Modif_recher_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Statistique_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_Statistique_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_calcul_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_Annulerletype_modif_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actualiser_stat_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_oui_confir_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Non_confir_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Aff_ret_aj_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_Aff_ret2_aj_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_Aff_ret2_mod_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Aff_ret_mod_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_gdps_treeview2_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gdps_treeview1_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gdps_Afficher_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_gdps_Actualiser_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_gdps_retour_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_gdps_radiobutton3_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gdps_radiobutton4_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gdps_radiobutton8_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gdps_radiobutton7_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_gdps_treeview3_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gdps_treeview2_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_gdps_treeview5_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);



void
on_treeview1_don_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


//***********************************************************************************---**********************--************************


void
on_adminuseraddentrymale_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminuseraddentryfemale_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminuseraddentrydoctor_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminuseraddentrydirector_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminaddnewstaffsubmit_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminuserchoice_changed             (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_adminviewmodify_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminviewdelete_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminusermodifyentrymale_toggled    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminusermodifyentryfemale_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminusermodifysubmit_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminusersubmitsearch_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminuserdeletebutton_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_adminuseraddentrynurse_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminusermodifyentrynurse_toggled   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminusermodifyentrydoctor_toggled  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminusermodifyentrydirector_toggled
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_adminusertreeview_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

/*void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);*/

void
on_treeviewshow_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_authsignin_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_authsignup_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_donorsubmit_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_donormale_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_donorfemale_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_percentagegender_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
void
on_button_admin_quit_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_admin_dcnx_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton_add__toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_add_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_admin_edit_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton_edit_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_admin_search_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview_show_ets_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_admin_show_clicked           (GtkWidget       *button,
                                        gpointer         user_data);



void
on_radiobutton_delete_oui_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_delete_non_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_delete_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_retour_add_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_retour_edit_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_retour_delete_clicked        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_retour_show_clicked          (GtkWidget       *button,
                                        gpointer         user_data);

void
on_refresh_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_afficher_region_clicked      (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_retoure_region_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton_ascendant_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_afficher_cap_clicked         (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton_descandant_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_retoure_capacite_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_espace_ajouter_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_espace_modifie_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_espace_affichage_clicked     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_espace_suppression_clicked   (GtkWidget       *button,
                                        gpointer         user_data);


void
on_button_retour_contact_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_send_ets_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_espace_contact_clicked       (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button70_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button90_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button60_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button80_clicked                     (GtkButton       *button,
                                        gpointer         user_data);


