
#define __CRYPTAGE_H__

#ifndef __USER_PROF_H__
	#include "../include/user_prof.h"
#endif

/**
 * @brief Verifie si le mot de passe est identique à celui de l'utilisateur
 * 
 * Retourne   
 * 		- 1 si les mots de passes sont identiques   
 * 		- 0 sinon
 * 
 * @param password 
 * @param ua 
 * @return int 
 */
int passwordIsGood(char * password, User_account ua);

/**
 * @brief Chiffre une chaine de caractere avec l'algorithme md5
 * 
 * @param string 
 * @return char* 
 */
char * encryptPassword(char * string);
