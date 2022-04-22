#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../include/classroom.h"
#include "../include/user_prof.h"
#include "../include/parson.h"

#ifndef CLEAR_STDIN
    #define CLEAR_STDIN { int c; while((c = getchar()) != '\n' && c != EOF); }
#endif

#ifndef COLOR
    #define color(param) printf("\033[%sm",param)
#endif

/**
 * @brief Structure user_account
 * 
 * Contient    
 *      - char * u_ID : Identifiant du fichier json associÃ© au compte   
 *      - int admin : 1 si le compte est admin, 0 sinon   
 *      - char * name : Nom de l'utilisateur   
 *      - char * firstname : Prenom de l'utilisateur   

 *      - Account first : Pointeur vers le premier compte de l'utilisateur (dÃ©but de la liste)   
 * 
 */
typedef struct prof_s{
	char nom[50]; 
    char firstname;
    int occupeted;
    char subject[20];
    int is_Admin;      
	struct prof_s* next;    
} prof;

//getters
int is_admin(prof prof){
    return (prof->admin);
}


char * get_name(prof prof){
    return (prof->name);
}

char * get_firstname(prof prof){
    return (prof->firstname);
}

char * get_subject(prof prof){
    return (prof -> subject)
}

char *get_formations(prof prof){
    return (prof -> formations)
}

int is_occupeted(prof prof){
    return (prof -> occupeted )
}

char * get_pwd(prof prof){
    return(prof -> pwd)
} 
