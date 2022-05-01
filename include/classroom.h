#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>


typedef struct prof_s *Prof;
typedef struct listProf_s * listProf;
typedef struct creneau *creneau;
typedef struct salle_s *salle;
listProf addprof(Prof , listProf );
void changeProf(Prof , listProf );
void removeProf(Prof, listProf );
_Bool isemptyP(listProf );
Prof creerprof(char *,char *, char *);
void profdat(listProf );
_Bool sallelibre(salle , creneau );
salle creertabS(salle ,salle ,salle ,salle );
creneau creercreneau(int , int , int );
creneau creertabcreneau(creneau , creneau ,creneau ,creneau );
salle creersalle(int , creneau *);
void gerer_prof(int , listProf);
void gerer_reservation(int , salle* , listProf);