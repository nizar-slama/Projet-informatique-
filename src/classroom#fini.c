//Filechainée #uwu
lisProf* addprof(struct prof_s prof){
   assert prof !=NULL;
       Prof* l= malloc(sizeof(struct s_prof));
   if (listProf==NULL){
       l->First=prof;
       l->Last=prof;
       l->taille=1;
       return l;
   }else if(listProf->taille==0){
       l->First =prof;
       l->Last=prof;
       l->taille=1;
       return l;
   }else{
       lisProf->last->next=prof;
       taille+=1;
       return listProf*;
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
listProf removeProf(struct prof_s prof){
    assert !(isEmptyP());
    if (listProf->taille==1){
        listProf->First=NULL;
        listProf->Last=NULL;
        listProf->taille=0;
    }else{
        listProf->First=listProf->First->next;
    }
    return listProf;
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
Prof addsalle(struct s_salle salle){
   assert salle !=NULL;
   if (listSalle==NULL){
       listSalle* l= malloc(sizeof(struct listSalle));
       l->First=salle;
       l->Last=salle;
       l->taille=1;
       return l;
   }else if(listSalle->taille==0){
       listSalle->First =prof;
       listSalle->Last=prof;
       listSalle->taille=1;
       return l;
   }else{
       listSalle->last->next=prof;
       taille+=1;
       return listSalle*;
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