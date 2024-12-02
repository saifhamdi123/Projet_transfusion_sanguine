#include <stdio.h>
#include <stdlib.h>
#include "gdps.h"
#include <string.h>



int main() {
    int k,qt;
    char result[5];
    float pour;
    d_poche_de_sang d,d2,drecher;
    d.datedd.Annee = 2002;
    d.datedd.Heure = 1200;
    d.datedd.jour = 10;
    d.datedd.mois = 10;
    strcpy(d.demandeur, "etab1");
    d.idd = 19928032;
    strcpy(d.idemail, "pqsdqsd@qs.com");
    strcpy(d.infosupp, "qsdqsdqsdqpppp");
    d.place[0] = 190;
    d.place[1] = 200;
    d.qt_demande[0] = 0;
    d.qt_demande[1] = 100;
    d.qt_demande[2] = 200;
    d.qt_demande[3] = 300;
    d.qt_demande[4] = 0;
    d.qt_demande[5] = 0;
    d.qt_demande[6] = 200;
    d.qt_demande[7] = 100;
    d.urgency = 0;

    d2.datedd.Annee = 2003;
    d2.datedd.Heure = 530;
    d2.datedd.jour = 29;
    d2.datedd.mois = 12;
    strcpy(d2.demandeur, "etab2123456789");
    d2.idd = 1200005;
    strcpy(d2.idemail, "hmmmmmm@mm.com");
    strcpy(d2.infosupp, "qsfdghdsd12345");
    d2.place[0] = 300;
    d2.place[1] = 500;
    d2.qt_demande[0] = 0;
    d2.qt_demande[1] = 0;
    d2.qt_demande[2] = 0;
    d2.qt_demande[3] = 0;
    d2.qt_demande[4] = 0;
    d2.qt_demande[5] = 0;
    d2.qt_demande[6] = 0;
    d2.qt_demande[7] = 100;
    d2.urgency = 0;
/*    supprimerDemande("/home/yosri/Bureau/Projets/projet2/src/gdps.txt", 1200005);
*/

    /*drecher = chercherDemande("/home/yosri/Bureau/Projets/projet2/src/gdps.txt", 19928032);
    printf("%d\n", drecher.place[0]);*/
    /*if (ajouterDemande("/home/yosri/Bureau/Projets/projet2/src/gdps.txt", d)) {
        printf("Demande ajoutée avec succès.\n");
    } else {
        printf("Erreur lors de l'ajout de la demande.\n");
    }*/
    /*k=modifierDemande("/home/yosri/Bureau/Projets/projet2/src/gdps.txt",d2, 19928032);
    printf("%d \n",k);*/

    qt=quantiteDemandee_type("/home/yosri/Bureau/Projets/projet2/src/gdps.txt", "O-");
    printf("%d \n",qt);
    sang_demandee("/home/yosri/Bureau/Projets/projet2/src/gdps.txt", result);
    printf("%s \n", result);
    pour=pourcentage("/home/yosri/Bureau/Projets/projet2/src/gdps.txt",1200005);
    printf("%f \n",pour);
    /*ajouter_demande(d2);*/
    
    return 0;
}
