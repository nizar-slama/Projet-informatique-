#define __CLASSROOM_H__
#ifndef __USER_PROF_H__
    #include "../include/user_prof.h"
#endif

typedef struct prof_s *Prof;
typedef struct salle_s *Salle;
typedef struct formations_s *Formation;
typedef struct etage_s *Etage


Prof addProf(prof_s prof);
Prof changeProf(prof_s prof);
Prof removeProf(prof_s prof);
char ListProf(prof_s prof);

Salle addSalle(salle_s salle);
Salle changeSalle(salle_s salle);
char Listsalle(salle_s salle);
