#include<time.h>
typedef struct tm Date;
typedef struct
{
    char rue[20];
    char ville[20];
}adress;
typedef struct
{
    char URL[50];
    char ad_mail_res[50];
}forum;

typedef struct
{
    char theme [50];
    Date date_crea;
    char ad_mail_anim[50];
    char tab_sites[3][50];
    int id_rub;
}rubrique;

typedef struct
{
    long num_ins,num_tel;
    char nom[30],prenom[30],ad_mail[50];
    adress ad;
    Date date_naiss;

}profil;

typedef struct
{
    char pseudo [50];
    Date date_pr_msg,date_dr_msg;
    int nombre_de_messages;
    int profil;
    profil prf;
}auteur;
struct message
{
    char title[50],texte[200];
    Date date_pub;
    int reponse;
    struct message*msg_rps;
    int id;
    int id_msg_or;
    auteur aut;
    int id_rb;

};
typedef struct message message;
struct liste_1
{
    message m;
    struct liste_1*suivant;
};
typedef struct liste_1*msg;
struct liste_2
{
    auteur aut;
    struct liste_2*suivant;
};
typedef struct liste_2*aut;
struct liste_3
{
    profil pf;
    struct liste_3*suivant;
};
typedef struct liste_3*prof;
struct liste_4
{
    rubrique rb;
    struct liste_4*suivant;
};
typedef struct liste_4*rub;
