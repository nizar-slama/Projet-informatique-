#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/classroom.h"
#include "../include/cryptage.h"




int main(int argc,char *argv){

// initialisation
scrand(time(NULL));
int navigateur = -1;
char* mdp;
creneau c810 = creercreneau(8, 10, 0);
creneau c1012 = creercreneau(10, 12, 0);
creneau c1315 = creercreneau(13, 15, 0);
creneau c1517 = creercreneau(15, 17, 0);
creneau creaneaux = creertabcreneau (c810, c1012, c1315, c1517);
salle salle1 = creersalle(1,creneaux);
salle salle2 = creersalle(2,creneaux);
salle salle3 = creersalle(3,creneaux);
salle salle4 = creersalle(4,creneaux);

salle emploie_du_temps = creertabS(salle1, salle2, salle3, salle4);

listprof L;

// Parcours du menu

while (navigateur != 0){
  
    // Parcours du menu entre menu ADMIN et CLIENT
  
    printf("Vous êtes dans le menu principale. \n");
    printf("Pour acceder au menu ADMIN, entrer : 1 \n");
    printf("Pour acceder au menu CLIENT, entrer : 2 \n");
    printf("Apres chaque action fini sur le navigateur, si vous voulez arreter, entrer : 0 \n");
    scanf("%d \n",&i);
  
    // Verification du mont de passe pour le menu ADMIN ( répéter jusqu'à ce que le mot de passe soit correct )
  
    while(navigateur == 1){
        printf("Veuillez entrer le mot de passe : \n");
        scanf("%s \n", &mdp);
        if (mdp_correct(mdp) == true){
            navigateur == 9;
        }
        else{
            printf("Mot de passe inccorect. \n");
        }
    }

    while(navigateur == 9 || navigateur == 3 || navigateur ==4 || navigateur == 5){

        //Parcours du menu ADMIN, choisir l'action à executer
      
        printf("Vous êtes dans le menu ADMIN \n");
        printf("Pour la gestion des enseignants, entrer : 3 \n");
        printf("Pour la gestion des reservations, entrer : 4 \n");
        printf("Pour modifier le mot de passe, entrer : 5 \n");
        scanf("%d \n", &navigateur);

        if (navigateur == 3){
            int a;
            afficher_prof(L);
            printf("Pour ajouter un prof à cette liste, entrer : 1 \n");
            printf("Pour modifier un prof de cette liste, entrer : 2 \n");
            printf("Pour supprimer un prof de cette liste, entrer : 3 \n");
            scanf("%d \n",&a);
            gerer_prof(a,L);
        }
        if (navigateur == 4){
            int b;
            printf("Pour reserver une salle pour un prof, entrer : 1 \n");
            printf("Pour annuler une reservation, entrer : 2 \n");
            printf("Pour modifier une reservation, entrer : 3 \n");
            printf("Pour afficher la liste des salles reservees, entrer : 4 \n");
            scanf("%d \n",&b);
            gerer_reservation(b,emploie_du_temps,L);
        }
        if (navigateur == 5){
            printf("Entrer le nouveau mot de passe : \n");
            scanf("%s \n", &mdp);
            changer_mdp(mdp);
            navigateur == 0;
        }
    }

    while(navigateur == 2 || navigateur == 6 || navigateur == 7 || navigateur== 8){
      
        //Parcours du menu CLIENT, choisir l'action à executer
      
        printf("Vous etes dans le menu CLIENT");
        printf("Si vous voulez consulter l'emploie du temps par enseignant, entrer : 6 \n");
        printf("Si vous voulez consulter l'emploie du temps par formation, entrer : 7 \n");
        printf("Si vous voulez consulter l'emploie du temps par salle, entrer : 8 \n");
        scanf("%d \n",&navigateur);

        if( navigateur == 6){
            char* nomprof;
            afficher_prof(L);
            printf("Veuillez entrer le nom du proffesseur : \n");
            scanf("%s",&nomprof);
            afficher_edt_prof(nomprof);
            navigateur = 0;
        }
        if ( navigateur == 7){
            char* nompromo;
            afficher_promo();
            printf("Veuillez entrer le nom du promotion : \n");
            scanf("%s",&nompromo);
            afficher_edt_prof(nompromo);
            navigateur = 0;
        }
        if ( navigateur == 8){
            int numsalle;
            printf("Veuillez entrer le numero de la salle : \n");
            printf(" Salle 1 , Salle 2, Salle 3, ou Salle 4 \n");
            scanf("%d"; &numsalle);
            afficher_edt_salle(numsalle);
            navigateur = 0;
        }
    }
}
    return 0;
}