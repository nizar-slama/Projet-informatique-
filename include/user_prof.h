#define __USER_PROF_H__


/**
 * @brief Pointeur sur la structure user_account_s
 * prof
 */
typedef struct prof_s *Prof;
//getters
/**
 * @brief Recupere la variable isAdmin d'un utilisateur (1 si Vrai, 0 sinon)
 * 
 * @param uacc 
 * @return int 
 */
int is_admin(Prof prof);
/**
 * @brief Retourne l'identifiant d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_subject(Prof prof);
/**
 * @brief Retourne le nom d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_name(Prof prof);
/**
 * @brief Retourne le prenom d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_firstname(Prof prof);
/**
 * @brief Retourne le mot de passe (chiffré) d'un utilisateur
 * 
 * @param uacc 
 * @return char* 
 */
char * get_pwd(Prof prof);
/**
 * @brief Retourne la matiere enseigne par un utilisateur 
 * 
 * @param prof
 * @return char*
 */
char * get_subject(Prof prof;

char **get_formations(Prof prof);

int is_occupeted(Prof prof);


/**
 * @brief Affiche les informations sur l'utilisateur
 * 
 * @param ua 
 */
void InfoProf(Prof prof);


//Setters
/**
 * @brief Defini un Utilisateur
 * 
 * @param admin 
 * @param name 
 * @param firstname 
 * @param pwd 
 * @param subject
 */
Prof set_Prof(int occupeted, int admin, char *name, char *firstname, char *pwd, char *subject);
/**
 * @brief Defini la variable isAdmin d'un utilisateur
 * 
 * @param uacc 
 * @param admin 
 */
void set_admin(Prof prof, int admin);
/**
 * @brief Defini le nom d'un utilisateur
 * 
 * @param uacc 
 * @param name 
 */
void set_name(Prof prof, char *name);
/**
 * @brief Defini le prenom d'un utilisateur
 * 
 * @param uacc 
 * @param firstname 
 */
void set_firstname(Prof prof, char *firstname);
/**
 * @brief Defini le mot de passe d'un utilisateur
 * 
 * @param uacc 
 * @param pwd 
 */
void set_pwd(Prof prof, char *pwd);
/**
 * @brief Defini l'identifiant d'un utilisateur
 * 
 * @param uacc 
 * @param ID 
 */
void set_subject(Prof prof, char *subject);

/**
 * @brief Modifie le mot de passe
 * 
 * @param ua 
 */
Prof changeAdminPwd(Prof prof);

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
Prof create_prof(char * subject, int admin, int occupeted, char *name, char *firstname, char *pwd, Prof prof);
