#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../include/classroom.h"


void gerer_prof(int a, listProf L){

    if(a == 1){
        char nom;
        char  firstname;
        int o;
        char  subject;
        scanf("Nom du prof %s \n", &nom);
        scanf("Prénom du prof %s \n", &firstname);
        scanf("Matière du prof %s \n", &subject);
        Prof new = creerprof(nom, firstname, subject,o);
        addprof(new, L);
    }

    if(a == 2){
        char nom_m;
        scanf("Donnez le nom du prof à modifier %s", &nom_m);
        if (L-> First -> nom == nom_m ){

        }
       

        while (new -> nom != nom_m){
            new = new -> next;
        }
        char  nom;
        char  firstname;
        int o;
        char  subject;
        scanf("Nouveau nom %s \n", &nom);
        scanf("Nouveau prénom %s \n", &firstname);
        scanf("Si occupé : 1, si libre : 0 %d \n", &o);
        scanf("Nouvelle matière %s \n", &subject);
        new->nom = nom;
        new->firstname = firstname;
        new->o = o;
        new->subject = subject;
    }

    if(a == 3){
        char  nom_m;
        scanf("Donnez le nom du prof à supprimer %s", &nom_m);
        Prof new = L->first;
        while (new->nom != nom_m){
            new = new->next;
        }
        removeProf(new, L);
    }
}

void gerer_reservation(int b, salle *edt, listProf L){
    
    if(b == 1){
        char  nom_m;
        int nums;
        int cr;
        scanf("Donnez le nom du prof qui reserve la salle %s", &nom_m);
        Prof newp = L->first;
        while (newp->nom != nom_m){
            newp = newp->next;
        }
        salle news;
        scanf("Donnez le numéro de la salle à reserver %d \n", &nums);
        for(int i=0;i<4;i++){
            if( edt[i]->numero == nums){
                news = edt[i];
            }
        }
        scanf("Sur quel créneau? 8-10 entrer : 0, 10-12h entrer 1, 13-15h entrer 2, 15-17h entrer 3 %d\n", &cr);
        news->C[cr]->prof = newp;
        news->C[cr]->occupied = 1;
    }

    if(b == 2){
        char  nom_m;
        int nums;
        int cr;
        scanf("Donnez le nom du prof qui reserve la salle %s", &nom_m);
        Prof newp = L->first;
        while (newp->nom != nom_m){
            newp = newp->next;
        }
        salle news;
        scanf("Donnez le numéro de la salle réservée %d \n", &nums);
        for(int i=0;i<4;i++){
            if( edt[i]->numero == nums){
                news = edt[i];
            }
        }
        scanf("Sur quel créneau? 8-10 entrer : 0, 10-12h entrer 1, 13-15h entrer 2, 15-17h entrer 3 %d\n", &cr);
        news->C[cr]->prof=newp;
        newp->occupied=0;
        news->C[cr]->occupied = 0;
    }
        


    if(b == 3){
      char  nom_m;
        int nums;
        int cr;
        scanf("Donnez le nom du prof qui reserve la salle %s", &nom_m);
        Prof newp = L->first;
        while (newp->nom != nom_m){
            newp = newp->next;
        }
        salle news;
        scanf("Donnez le numéro de la salle à reserver %d \n", &nums);
        for(int i=0;i<4;i++){
            if( edt[i]->numero == nums){
                news = edt[i];
            }
        }
        scanf("Sur quel créneau? 8-10 entrer : 0, 10-12h entrer 1, 13-15h entrer 2, 15-17h entrer 3 %d\n", &cr);
        news->C[cr]->prof = newp;
        news->C[cr]->occupied = 1;
    
    char newnom;
    

    scanf("donnez le nom du nouveau prof %s\n",&newnom);
    Prof newpp = L->first;
        while (newpp->nom != newnom){
            newpp = newpp->next;
        }
        if (newpp==NULL){
            printf("Prof pas dans la liste !!!");
        }else{

        news->C[cr]->prof=newpp;
        printf("opération effectuée !");
    }
    }

    if(b == 4){
        for (int i=0;i<4;i++){
            assert(edt[i]!=NULL);
            for(int j=0;j<4;j++)
            if(edt[i]->C[j]->occupied==1){
            printf("Salle %d :  -creneau:%d %d  -prof: %s %s   -etat: occupé\n", i,edt[i]->C[j]->debut,edt[i]->C[j]->fin);
            }  else{
                 printf("Salle %d :  -creneau:%d %d  -prof: %s %s   -etat: libre\n",i,edt[i]->C[j]->debut,edt[i]->C[j]->fi);
            }

            }


        }


    }
