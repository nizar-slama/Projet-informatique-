#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

typedef struct prof_s{
	char nom; 
    char firstname;
    int occupied;
    char subject; 
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
	creneau C;
    int numero;         
}* salle;

 typedef struct listSalle_s {
  	salle First;
    salle Last;
    int taille;
}*listSalle;




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

void changeProf(Prof prof, listProf L){
  assert(!isEmptyP(L));
  Prof k=L->First->next;
  removeProf(L);
  prof->next=k;
  L->First=prof;
}
    
__BOOL profdispo(Prof prof){
    return(prof->occupied==0);
}


listProf removeProf( listProf L){
    assert(!(isEmptyP()));
    if (L->taille==1){
        L->First=NULL;
        L->Last=NULL;
        L->taille=0;
    }else{
        L->First=L->First->next;
    }
    return L;
}
_Bool isemptyP(listProf L){
    if (L->taille==0){
        return true;
    }
    return false;
    }

Prof creerprof(char nom,char firstname,int o, char subject){
    Prof p= malloc(sizeof(struct prof_s));
    p->nom=nom;
    p->firstname=firstname;
    p->occupied=o;
    p->subject=subject;
    p->next=NULL;
	return p;
}
void afficher_nom_prof(Prof prof){
    printf("%d\n",prof->name);
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
    while (L->First->next!=NULL){
        f->nom=L->First->nom;
        f->firstname=L->First->firstname;
        f->occupied=L->First->occupied;
        f->subject=L->First->subject;
        fprintf(fichier,"%s %s %d %s \n",f->nom,f->firstname,f->occupied,f->subject);         
        L->First=L->First->next;
    }
    fclose(fichier);
    }


 bool sallelibre(salle s, creneau cr){
    assert(s!=NULL);
    for(int i=0;i<4;i++){
    if((s->C[i].debut==cr->debut)&&(s->C[i].fin==cr->fin)){    
        if (s->C[i].occupied==0){
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
 salle creersalle(int num, creneau C){
     salle s= malloc(sizeof(salle));
     s->numero=num;
     s->C=C;
    return s;
 }
 
 void afficher_listProf(){
	FILE* fichier;
	fichier=fopen("prof.dat","r");
		char filename[100], c;
		c = fgetc(fichier);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fichier);
    }
    fclose(fichier);
 }

