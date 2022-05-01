#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
#include "../include/classroom.h"

typedef struct prof_s{
	char *nom; 
    char *firstname;
    int occupied;
    char *subject; 
	struct prof_s* next;    
}*Prof;

typedef struct listProf_s {
     Prof First;
     Prof Last;
     int taille;
 }*listProf;

typedef struct creneau {
    Prof prof;
    int debut;
    int fin;
    int occupied; 
}*creneau;


typedef struct salle_s{
	creneau *C;
    int numero;         
}* salle;


_Bool isemptyP(listProf L){
    if (L->taille==0){
        return true;
    }
    return false;
    }



listProf addprof(Prof prof, listProf L){
   assert(prof !=NULL);
       listProf l= malloc(sizeof(listProf));
   if (L==NULL){
       l->First=prof;
       l->Last=prof;
       l->taille=1;
       return l;
   }else if(L->taille==0){
       L->First =prof;
       L->Last=prof;
       L->taille=1;
       return L;
   }else{
       L->Last->next=prof;
       L->taille+=1;
       return L;
   }
   }
    void removeProf(Prof prof,listProf L){
        Prof k=L->First->next;
    while(k->next!=prof){
        k=k->next;
    }
    k->next=k->next->next;
    }
void changeProf(Prof prof, listProf L){
  assert(!isemptyP(L));
  Prof k=L->First->next;
  removeProf(prof, L);
  prof->next=k;
  L->First=prof;
}
    
_Bool profdispo(Prof prof){
    return(prof->occupied==0);
}




Prof creerprof(char *nom, char *firstname,char *subject){
    Prof p= malloc(sizeof(struct prof_s));
    p->nom=nom;
    p->firstname=firstname;
    p->occupied=0;
    p->subject=subject;
    p->next=NULL;
	return p;
}
void afficher_nom_prof(Prof prof){
    printf("%s\n",prof->nom);
}
void afficher_matiere_prof(Prof prof){
    printf("%s\n", prof->subject);
}


void profdat(listProf L){
    assert(L!=NULL);
    assert(L->taille!=0);
     FILE* fichier;
     fichier=fopen("prof.dat","w");
		Prof f=malloc(sizeof(Prof));
        struct json_object *nom;
    struct json_object *firstname;
    struct json_object *occupied;
    struct json_object *subject;

    while (L->First->next!=NULL){
        
        f->nom=L->First->nom;
        f->firstname=L->First->firstname;
        f->occupied=L->First->occupied;
        f->subject=L->First->subject;
        f->nom=&nom;
    /*printf("Nom:%s\n", json_object_get_string(&nom));
    printf("Nom:%s\n", json_object_get_string(&firstname));
    printf("Nom:%d\n", json_object_get_int(occupied));
    printf("Nom:%s\n", json_object_get_string(&subject));   
    */
    


    json_object_dotset_string(json_object, "f->firstname", firstname);
    json_object_dotset_string(json_object, "f->nom", nom);
    json_object_dotset_string(json_object, "f->subject", subject);
     json_object_dotset_string(json_object, "f->occupied", occupied);  
    L->First=L->First->next;
    }
    fclose(fichier);
    }


 bool sallelibre(salle s, creneau cr){
    assert(s!=NULL);
    for(int i=0;i<4;i++){
    if((s->C[i]->debut==cr->debut)&&(s->C[i]->fin==cr->fin)){    
        if (s->C[i]->occupied==0){
            return true;
        }
    }
    }
return false;
 }
 salle creertabS(salle S1,salle S2,salle S3,salle S4){
     salle S=malloc(4*sizeof(salle));
   S[0]=*S1;
   S[1]=*S2;
   S[2]=*S3;
   S[3]=*S4;
   return S;
 }
 
creneau creercreneau(int d, int f, int o){
    creneau c=malloc(sizeof(struct creneau));
    c->debut=d;
    c->fin=f;
    c->occupied=o;
    return c;
}
creneau creertabcreneau(creneau C1, creneau C2,creneau C3,creneau C4){
    creneau t=malloc(4*sizeof(creneau*));
    t[0]=*C1;
    t[1]=*C2;
    t[2]=*C3;
    t[3]=*C4;
    return t;
}
 salle creersalle(int num, creneau *C){
     salle s= malloc(sizeof(salle));
     s->numero=num;
     s->C=C;
    return s;
 }
 
 void afficher_listProf(){
	FILE* fichier;
	fichier=fopen("prof.dat","r");
		char c;
		c = fgetc(fichier);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fichier);
    }
    fclose(fichier);
 }

 void gerer_prof(int a, listProf L){

    if(a == 1){
        char nom;
        char  firstname;
        char  subject;
        scanf("Nom du prof %s \n", &nom);
        scanf("Prénom du prof %s \n", &firstname);
        scanf("Matière du prof %s \n", &subject);
        Prof new = creerprof(&nom, &firstname, &subject);
        addprof(new, L);
    }

    if(a == 2){
        char nom_m;
        scanf("Donnez le nom du prof à modifier %s", &nom_m);
        Prof k = malloc(sizeof(Prof));
        k->next=L->First;
        while(k->nom!=&nom_m){
            k=k->next;
            }
        if(k==NULL){
            printf("pas dans la liste!!!");
        }
        

        char  nom;
        char  firstname;
        int o;
        char  subject;
        scanf("Nouveau nom %s \n", &nom);
        scanf("Nouveau prénom %s \n", &firstname);
        scanf("Si occupé : 1, si libre : 0 %d \n", &o);
        scanf("Nouvelle matière %s \n", &subject);
        Prof new;
        new= malloc(sizeof(Prof));
        new->nom = &nom;
        new->firstname = &firstname;
        new->occupied = o;
        new->subject = &subject;
    }

    if(a == 3){
        char  nom_m;
        scanf("Donnez le nom du prof à supprimer %s", &nom_m);
        Prof new = L->First;
        while (new->nom != &nom_m){
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
        Prof newp = L->First;
        while (newp->nom != &nom_m){
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
        Prof newp = L->First;
        while (newp->nom != &nom_m){
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
        Prof newp = L->First;
        while (newp->nom != &nom_m){
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
    Prof newpp = L->First;
        while (newpp->nom != &newnom){
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
            printf("Salle %d :  -creneau:%d %d  -prof: %s %s   -etat: occupé\n", i,edt[i]->C[j]->debut,edt[i]->C[j]->fin, edt[i]->C[j]->prof->nom, edt[i]->C[j]->prof->firstname);

            }  else{
                 printf("Salle %d :  -creneau:%d %d  -prof: %s %s   -etat: libre\n",i,edt[i]->C[j]->debut,edt[i]->C[j]->fin, edt[i]->C[j]->prof->nom, edt[i]->C[j]->prof->firstname);
            }

            }


        }


    }
