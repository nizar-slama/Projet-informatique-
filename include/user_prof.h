#define __USER_PROF_H__

#include "../include/professeur.h"

/**
 * @brief Pointeur sur la structure user_account_s
 * 
 */
typedef struct prof_s *Prof;
typedef struct subject_s *Subject;

//getters
/**
 * @brief Recupere la variable isAdmin d'un utilisateur (1 si Vrai, 0 sinon)
 * 
 * @param uacc 
 * @return int 
 */
int is_admin(prof_s prof);
/**
 * @brief Retourne l'identifiant d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_subject(prof_s prof);
/**
 * @brief Retourne le nom d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_name(prof_s prof);
/**
 * @brief Retourne le prenom d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_firstname(prof_s prof);
/**
 * @brief Retourne le mot de passe (chiffré) d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_pwd(prof_s prof);
/**
 * @brief Retourne le premier compte d'un utilisateur (début de la liste)
 * 
 * @param uacc 
 * @return Account 
 */
char * get_subject(prof_s prof);

char **get_formations(prof_s prof);

int is_occupeted(prof_s prof);


/**
 * @brief Affiche les informations sur l'utilisateur
 * 
 * @param ua 
 */
void InfoProf(prof_s prof);


//Setters
/**
 * @brief Defini un Utilisateur
 * 
 * @param ID 
 * @param admin 
 * @param name 
 * @param firstname 
 * @param pwd 
 * @param subject
 * @return User_account 
 */
Prof set_Prof(int occupeted, int admin, char *name, char *firstname, char *pwd, char *subject);
/**
 * @brief Defini la variable isAdmin d'un utilisateur
 * 
 * @param uacc 
 * @param admin 
 */
void set_admin(prof_s prof, int admin);
/**
 * @brief Defini le nom d'un utilisateur
 * 
 * @param uacc 
 * @param name 
 */
void set_name(prof_s prof, char *name);
/**
 * @brief Defini le prenom d'un utilisateur
 * 
 * @param uacc 
 * @param firstname 
 */
void set_firstname(prof_s prof, char *firstname);
/**
 * @brief Defini le mot de passe d'un utilisateur
 * 
 * @param uacc 
 * @param pwd 
 */
void set_pwd(prof_s prof, char *pwd);
/**
 * @brief Defini l'identifiant d'un utilisateur
 * 
 * @param uacc 
 * @param ID 
 */
void set_subject(prof_s prof, char *subject);

/**
 * @brief Modifie le mot de passe
 * 
 * @param ua 
 */
Prof changeAdminPwd(prof_s prof);

//file management
/**
 * @brief Crée un identifiant d'utilisateur unique
 * 
 * @return char* 
 */
char * createProf(); 
/**
 * @brief Crée un utilisateur 
 * 
 * Crée un nouveau fichier .json nommé "ID.json" (dossier data/user_account) et le remplit avec les parametres.
 * Renvoit une nouvelle structure User_Account remplie avec les parametres
 * 
 * @param admin 
 * @param name 
 * @param firstname 
 * @param pwd 
 * @param subject 
 * @return User_account 
 */
Prof create_prof(char * subject, int admin, int occupeted, char *name, char *firstname, char *pwd, prof_s prof);

/**
 * @brief Ajoute les informations d'un utilisateur dans ListUser.dat
 * 
 * @param name 
 * @param firstname 
 * @param path 
 * @param pwd 
 */
void addProfInList(char * name, char * firstname, char * subject, char * pwd);

/**
 * @brief Recuperer les informations de l'utilisateur dans le fichier json associé
 * 
 * @param file 
 * @param isAdmin 
 * @return User_account 
 */
Prof charge_prof(char * file, int * isAdmin);