
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
 *      - char * subject : la mateiere de l'utilisateur  
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
int is_admin(Prof prof){
    return (prof->admin);
}


char * get_name(Prof prof){
    return (prof->name);
}

char * get_firstname(Prof prof){
    return (prof->firstname);
}

char * get_subject(Prof prof){
    return (prof -> subject)
}


char *get_formations(Prof prof){
    return (prof -> formations)
}

int is_occupeted(Prof prof){
    return (prof -> occupeted )
}

char * get_pwd(Prof prof){
    return(prof -> pwd)
} 




void InfoUser(Prof pr){
    if(is_admin(pr)==1){
        printf("--------------------------\n| ADMINISTRATEUR %s\n| \tNom : %s\n| \tPrenom : %s\n| \tMatiere : %s\n|Formation : %s\n--------------------------\n",

        get_name(pr),
        get_firstname(pr)),
        get_subject(pr),
        get_formations(pr);

    }else{
        printf("--------------------------\n| Utilisateur %s\n| \tNom : %s\n| \tPrenom : %s\n| \tMatiere : %s\n|Formation : %s\n--------------------------\n",
        get_name(pr),
        get_firstname(pr),
        get_subject(pr),
        get_formations(pr);

    }
    
}

//Setters

User_account setUser(int admin, char * name, char * firstname, char *get_subject, char * pwd){
    Prof pr = NULL;
    pr = (Prof)malloc(sizeof(struct prof_s)); 
    set_admin(pr, admin);
    set_firstname(pr,firstname);
    set_name(pr,name);
    set_subject(pr,subject);
    set_formations(pr,formations)
    set_pwd(pr,pwd);
    set_Prof(pr,NULL);

    return pr;
}

void set_admin(Prof prof, int admin){
    prof->admin = admin;
}

void set_name(Prof prof, char * name){
    strcpy(prof->name,name);
}

void set_firstname(Prof prof, char *firstname){
    strcpy(prof->firstname,firstname);
}

void set_pwd(Prof prof, char *pwd){
    strcpy(prof->pwd,pwd);
}

void set_subject(Prof prof){
     strcpy(prof->subject, subject);
}

void set_formations(Prof prof){
    strcpy(prof->formations, formations);
}



User_account changePwd(Prof prof){
    int isPasswordGood = 0;
    char newpwd[32];
    char newpawdConfirm[32];

    while(isPasswordGood<=0 && isPasswordGood!=-3){ //Check if password is good
        printf("Nouveau mot de passe : ");
        scanf("%s",newpwd);
        CLEAR_STDIN
        printf("Confirmez le mot de passe : ");
        scanf("%s",newpawdConfirm);
        CLEAR_STDIN
        if(strcmp(newpwd,newpawdConfirm)==0)
            isPasswordGood=1;            
        if(isPasswordGood<=0){
            color("31");
            printf("\n/!\\ Mots de passe non identiques /!\\\n");
            color("0");
            if(2+isPasswordGood>0)
              printf("Il vous reste %d essais \n",2+isPasswordGood);
            isPasswordGood--;
        }

        if(isPasswordGood==-3){
            color("31");
            printf("\nEchec\n");
            color("0");
            return prof;
        }
            
    }
    
    // Remove the user's line in ListUser.dat
    FILE * fileIN;
    FILE * fileOUT;
    char line[128] = "";
    char lineF[128] = "";

    char name[32];
    char firstname[32];
    char pwd[64];
    char subject[64];
    char formation[64];
    char json[64] = "data/user_account/";

    strcpy(name,get_name(prof));
    strcpy(firstname,get_firstname(prof));
    strcpy(subject,get_subject(prof));
    strcpy(formation,get_formations(prof));
    strcpy(pwd,get_pwd(prof));
    
    char * nameF;
    char * firstnameF;
    char * subjectF;
    char * formationF;
    char * pwdF;
    char * jsonF;

    int isEquals = 1;

    fileIN = fopen("data/user_account/listProf.dat","r");
    fileOUT = fopen("data/user_account/listProfOUT.dat","w");

    if(fileIN != NULL){
        while (fgets(line, 128, fileIN) != NULL){
            strcpy(lineF,line);
            for(int i=0; ((i<4) && isEquals == 1);i++){
                switch(i){
                    case 0:
                        nameF = strtok(line, ",");
                        if(strcmp(name, nameF) != 0){
                            isEquals = 0;
                        }
                        break;
                    case 1:
                        firstnameF=strtok(NULL, ",");
                        if(strcmp(firstname, firstnameF) != 0){
                            isEquals = 0;
                        }
                        break;
                    
                    case 2:
                        subjectF = strtok(NULL, ",");
                        if(strcmp(subject, subjectF) != 0){
                            isEquals = 0;
                        }
                        break;
                    case 4:
                        formationsF = strtok(NULL, ",");
                        if(strcmp(formation, formationF) != 0){
                            isEquals = 0;
                        }
                        break;
                    case 5:
                        jsonF = strtok(NULL, ",");
                        if(strcmp(json, jsonF) != 0){
                            isEquals = 0;
                        }
                        break;
                    case 6:
                        pwdF = strtok(NULL, " ");
                        if(strcmp(pwd, pwdF) != 0){
                            isEquals = 0;
                        }
                        break;
                }
                
            }
            if(isEquals == 0){
                fprintf(fileOUT,"%s",lineF);
            }
            isEquals=1;
        }

    }else{
        error("Impossible d'ouvrir le fichier.");
    }
    fclose(fileIN);
    fclose(fileOUT);

    remove("data/user_account/listProf.dat");
    rename("data/user_account/listProfOUT.dat","data/user_account/listProf.dat");

    prof = create_prof(is_admin(prof),get_name(prof),get_firstname(prof),get_subject(prof),get_formations(prof),encryptPassword(newpwd));
    addUserInList(get_name(prof),get_firstname(prof),get_subject(prof),get_formations(prof) encryptPassword(newpwd));

    return prof;
}

//file management


Prof create_prof(int admin, char *name, char *firstname, char *subject , char *formations, char *pwd){



    //Remplissage du json

    JSON_Value *root_value = json_value_init_object();
    JSON_Object *root_object = json_value_get_object(root_value);
    char *serialized_string = NULL;
    FILE *jsonF = NULL;

    jsonF = fopen(path, "w+"); //Open json File
    json_object_dotset_number(root_object, "user_account.admin", (double)admin);
    json_object_dotset_string(root_object, "user_account.firstname", firstname);
    json_object_dotset_string(root_object, "user_account.name", name);
    json_object_dotset_string(root_object, "user_account.subject", subject);
    json_object_dotset_string(root_object, "user_account.formations", formations);
    json_object_dotset_string(root_object, "user_account.pwd", pwd);

    
    serialized_string = json_serialize_to_string_pretty(root_value);
    fprintf(jsonF,"%s",serialized_string);
    fclose(jsonF);
    json_free_serialized_string(serialized_string);
    json_value_free(root_value);

    //Ajout du compte dans la liste des users


    return prof;
}

void addProfInList(char * name, char * firstname, char * ID, char * pwd){
    FILE *listProf = NULL;
    char path[64]= "";
    listProf = fopen("data/user_account/listProf.dat","a");
    fprintf(listProf,"%s,%s,%s,%s,%s,%s\n",name,firstname,path,subject,formations,pwd);
    fclose(listProf);
}

//charge the infos of the json into the user_account struct
Prof charge_prof(char * file, int * isAdmin){
    //size attribution for the struct
    Prof prof= NULL;
    Prof first = NULL;
    Prof prof = NULL;
    prof = (Prof)malloc(sizeof(struct prof_s)); 
    int isSuppr = 0;

    

    JSON_Value *root_value;
    JSON_Object *root_object;
    char elt[32];
    JSON_Array * list;

    /* parsing json */
    root_value = json_parse_file(file);
    root_object = json_value_get_object(root_value);

    // User
    prof = (int)json_object_dotget_number(root_object, "user_account.admin"),
            (char*)json_object_dotget_string(root_object, "user_account.name"),
            (char*)json_object_dotget_string(root_object, "user_account.firstname"),
            (char*)json_object_dotget_string(root_object, "user_account.subject"),
            (char*)json_object_dotget_string(root_object, "user_account.formations"),
            (char*)json_object_dotget_string(root_object, "user_account.pwd"));

    //Liste des accounts
    list = json_value_get_array(json_object_dotget_value(root_object,"user_account.List_account"));
  
   for (int i = 0; i < json_array_get_count(list); i++) {
        strcpy(elt,json_array_get_string(list, i));    
        // Comptes
        if(i==0){
            first = setAccount(elt);
        }
        else{
            prof = setAccount(elt);        
            addNewAccount(first,prof);
        }
    }

    first = verifSuppr(first, &isSuppr); //Si un compte a été supprimé
    if(isSuppr==1){
        prof = create_prof(,is_admin(prof),get_name(prof),get_firstname(prof),get_subject(prof),get_formations(prof),get_pwd(prof),first);
    }

    if(first!=NULL){
        setAccountFirst(uacc,first);
    }

    if(is_admin(prof)==1){
        (*isAdmin)=1;
        if(strcmp("45VWJbfUGfRqM",get_pwd(prof))==0){
            color("31");
            printf("-------------------------\n");
            printf("|  /!\\  ATTENTION  /!\\  |\n");
            printf("|    Pour des raisons   |\n");
            printf("|      de securite      |\n");
            printf("|  Veuillez changer de  |\n");
            printf("|      mot de passe     |\n");
            printf("-------------------------\n");
            color("0");
        }
    }

    json_value_free(root_value);

    return prof;
}