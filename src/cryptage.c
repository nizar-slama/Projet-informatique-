#define _XOPEN_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <crypt.h>
#include "../include/user_account.h"
#include "../include/account.h"
#include "../include/encrypt.h"


/**
 * @brief Encrypte une chaine de caractere
 * 
 * @param string 
 * @return char* 
 */
char* encryptPassword(char* string){
    char * result;
    result = (char*)malloc(sizeof(char)*48);
    sprintf(result,"%s",(char*)crypt(string,"456b7016a916a4b178dd72b947c152b7,"));
    //printf(">>%s<<\n",result);
    return (result);
}

/**
 * @brief Verifie si le mot de passe est valide
 * 
 * @param password 
 * @param ua 
 * @return int 
 */
int passwordIsGood(char * password, User_account ua){
    return (strcmp(encryptPassword(password),get_pwd(ua))==0 ? 1 : 0);
}