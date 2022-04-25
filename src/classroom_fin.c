#include <stdio.h>
//Filechainée #uwu
listProf* addprof(struct prof_s prof, listProf L){
   assert prof !=NULL;
       Prof* l= malloc(sizeof(struct s_prof));
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
       L->last->next=prof;
       L->taille+=1;
       return L;
   }
   }

Prof changeProf(struct prof_s prof, listProf L){
  assert !isEmptyP(L);
  Prof k=L->First->next;
  remove(L->First);
  prof->next=k;
  L->First=prof;
}
    
}
listProf removeProf(struct prof_s prof, listProf L){
    assert !(isEmptyP());
    if (L->taille==1){
        L->First=NULL;
        L->Last=NULL;
        L->taille=0;
    }else{
        L->First=L->First->next;
    }
    return L;
}
bool isEmptyP(lisProf L){
    if (L->taille==0){
        return True;
    }
    return False;
    }
bool isEmptyS(listSalle L){
    if(L->taille==0){
        return True;
    }
    return False;

    }
Prof addsalle(struct s_salle salle, listSalle L){
   assert salle !=NULL;
   if (L==NULL){
       listSalle* l= malloc(sizeof(struct listSalle));
       l->First=salle;
       l->Last=salle;
       l->taille=1;
       return l;
   }else if(L->taille==0){
       L->First =prof;
       L->Last=prof;
       L->taille=1;
       return L;
   }else{
       L->last->next=prof;
       L->taille+=1;
       return L;
   }
}

Salle changeSalle(struct salle_s salle, listSalle L){
  assert !isEmptyS(L);
  Salle k= L->First->next;
  remove(L->First)
  salle->next=k;
  L->First=salle;
}
struct listSalle{
    struct s_salle First;
    struct s_salle Last;
    int taille;
}