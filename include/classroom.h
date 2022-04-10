#define __PROFESSEUR_H__
#ifndef __USER_PROF_H__
    #include "../include/user_prof.h"
#endif

typedef struct professeur_s *Prof;
typedef struct salle_s *Salle;
typedef struct formations_s *Formation;


char * get_subject(Prof prof);

/**
 * @brief Retourne le type d'un compte
 * 
 * @param acc 
 * @return char* 
 */
char * get_type_account(Account acc);


/**
 * @brief Retourne le compte suivant du compte
 * 
 * @param ac 
 * @return Account 
 */
Account getNextAccount(Account ac);