#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/prof.h"
#include "../include/user_prof.h"

#ifndef COLOR
    #define color(param) printf("\033[%sm",param)
#endif

#ifndef CLEAR_STDIN
    #define CLEAR_STDIN { int c; while((c = getchar()) != '\n' && c != EOF); }
#endif

typedef struct subject_s{
	char subject[5];       
	struct subject_s* next;    
} subject;

typedef struct etage_s{
	char etage[3]; 
    int salle[5];      
	struct etage* next;    
} subject;

typedef struct prof_s{
	char nom; 
    char firstname;
    int occupeted;
    char subject;
    int is_Admin;      
	struct prof_s* next;    
} prof;

typedef struct formations_s{
	char nom;     
    int salle;
    int occupeted;
	struct formations_s* next;    
} formations;
typedef struct creneau_s {
	int debut;
	int fin;
	int occupied;
typedef struct salle_s{
	creneau* C;
	int occupeted; 
    int numero;         
} salle;




