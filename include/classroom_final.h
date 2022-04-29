#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef struct prof_s *Prof;
typedef struct listProf_s * listProf;
typedef struct creneau *creneau;
typedef struct salle_s *salle;
typedef struct listSalle_s *listSalle;
listProf addprof(Prof , listProf );
void changeProf(Prof , listProf );
listProf removeProf(listProf );
_Bool isemptyP(listProf );
Prof creerprof(char ,char ,int , char );
void profdat(listProf );
void changeSalle(salle , listSalle );
bool sallelibre(salle , creneau );
salle creertabS(salle ,salle ,salle ,salle );
creneau creercreneau(int , int , int );
creneau creertabcreneau(creneau , creneau ,creneau ,creneau );
salle creersalle(int , creneau );
