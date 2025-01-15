#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

#define COLOR_RESET   "\x1b[0m"
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_WHITE   "\x1b[37m"

void welcome_page() {
    printf(COLOR_GREEN "Bienvenue dans l'application Forum!\n\n" COLOR_RESET);
    printf("Veuillez choisir une option pour continuer.\n");
}

void display_menu() {
    printf(COLOR_YELLOW "\n--- Menu ---\n" COLOR_RESET);
    printf("1. Saisir un forum\n");
    printf("2. Saisir une rubrique\n");
    printf("3. Saisir un message\n");
    printf("4. Saisir un auteur\n");
    printf("5. Saisir un profil\n");
    printf("6. Afficher un forum\n");
    printf("7. Afficher une rubrique\n");
    printf("8. Afficher un message\n");
    printf("9. Afficher un auteur\n");
    printf("10. Afficher un profil\n");
    printf("11. Quitter\n");
    printf("Votre choix: ");
}

void clear_screen() {
    printf("\033[H\033[J");
}

adress saisie_ad() {
    adress ad;
    printf("Saisir le rue: ");
    scanf("%19s", ad.rue);
    printf("Saisir la ville: ");
    scanf("%19s", ad.ville);
    return ad;
}

forum saisie_fr() {
    forum fr;
    printf("*** Saisir Forum ***\n");
    printf("Saisir l'adresse internet: ");
    scanf("%49s", fr.URL);
    printf("Saisir l'adresse email du responsable: ");
    scanf("%49s", fr.ad_mail_res);
    return fr;
}

rubrique saisie_rb(int *nb_rb) {
    rubrique rb;
    printf("*** Saisir Rubrique ***\n");
    printf("Donner le theme: ");
    scanf("%49s", rb.theme);
    printf("Donner l'adresse email de son animateur: ");
    scanf("%49s", rb.ad_mail_anim);
    printf("Donner le jour, le mois et l'annee de creation: ");
    scanf("%d %d %d", &rb.date_crea.tm_mday, &rb.date_crea.tm_mon, &rb.date_crea.tm_year);
    for (int i = 0; i < 3; i++) {
        printf("Donner le site n%d: ", i + 1);
        scanf("%49s", rb.tab_sites[i]);
    }
    rb.id_rub = *nb_rb;
    (*nb_rb)++;
    return rb;
}

profil saisie_pf() {
    profil pf;
    printf("*** Saisir Profil ***\n");
    printf("Donner le numero d'inscription: ");
    scanf("%ld", &pf.num_ins);
    printf("Donner votre nom: ");
    scanf("%99s", pf.nom);
    printf("Donner votre prenom: ");
    scanf("%99s", pf.prenom);
    printf("Donner le numero de telephone: ");
    scanf("%ld", &pf.num_tel);
    printf("Donner l'adresse email: ");
    scanf("%99s", pf.ad_mail);
    pf.ad = saisie_ad();
    printf("Donner le jour, le mois de naissance: ");
    scanf("%d %d %d", &pf.date_naiss.tm_mday, &pf.date_naiss.tm_mon, &pf.date_naiss.tm_year);
    return pf;
}

auteur saisie_at() {
    auteur at;
    printf("*** Saisir Auteur ***\n");
    printf("Donner ton pseudo: ");
    scanf("%49s", at.pseudo);
    printf("Donner le jour, le mois et l'année du premier message poste: ");
    scanf("%d %d %d", &at.date_pr_msg.tm_mday, &at.date_pr_msg.tm_mon, &at.date_pr_msg.tm_year);
    printf("Donner le jour, le mois et l'annee du dernier message: ");
    scanf("%d %d %d", &at.date_dr_msg.tm_mday, &at.date_dr_msg.tm_mon, &at.date_dr_msg.tm_year);
    printf("Donner le nombre de messages postes: ");
    scanf("%d", &at.nombre_de_messages);
    printf("Avez-vous un profil ? Saisir 1 si oui, 0 sinon: ");
    scanf("%d", &at.profil);
    if (at.profil == 1) {
        at.prf = saisie_pf();
    }
    return at;
}

message saisie_msg(int *nb_msg) {
    message msg;
    printf("*** Saisir Message ***\n");
    printf("Donner le titre: ");
    scanf("%49s", msg.title);
    printf("Donner le texte: ");
    scanf("%199s", msg.texte);
    printf("Auteur:\n");
    msg.aut = saisie_at();
    printf("Donner le jour, le mois et l'annee de publication: ");
    scanf("%d %d %d", &msg.date_pub.tm_mday, &msg.date_pub.tm_mon, &msg.date_pub.tm_year);
    printf("Taper 1 si c'est une reponse: ");
    scanf("%d", &msg.reponse);
    msg.id = *nb_msg;
    (*nb_msg)++;
    if (msg.reponse != 1) {
        msg.id_msg_or = 0;
    } else {
        printf("Donner le numero du message original: ");
        scanf("%d", &msg.id_msg_or);
    }
    printf("Donner le numero de la rubrique: ");
    scanf("%d", &msg.id_rb);
    return msg;
}

void aff_forum(forum f) {
    printf("~FORUM~\n");
    printf("L'adresse internet du forum est: %s\n", f.URL);
    printf("L'adresse mail du responsable est: %s\n", f.ad_mail_res);

}

void aff_rubrique(rubrique r) {
    printf("~RUBRIQUE~\n");
    printf("Le theme du rubrique est: %s\n", r.theme);
    printf("La date de creation est: %d/%d/%d\n", r.date_crea.tm_mday, r.date_crea.tm_mon, r.date_crea.tm_year);
    printf("L'adresse email de l'animateur est: %s\n", r.ad_mail_anim);
    printf("Les sites internet relatifs sont: %s, %s, %s\n", r.tab_sites[0], r.tab_sites[1], r.tab_sites[2]);
}

void aff_messg(message m) {
    printf("~MESSAGE~\n");
    printf("Le titre est: %s\n", m.title);
    printf("Le texte est: %s\n", m.texte);
    printf("La date de publication: %d/%d/%d\n", m.date_pub.tm_mday, m.date_pub.tm_mon, m.date_pub.tm_year);
    printf("Auteur: %s\n", m.aut.pseudo);
    if (m.reponse == 0) {
        printf("Le message n'est pas une reponse.\n");
    } else {
        printf("Le message est une reponse.\n");
    }
}

void aff_auteur(auteur a) {
    printf("~AUTEUR~\n");
    printf("Le pseudo est: %s\n", a.pseudo);
    printf("La date du premier message poste: %d/%d/%d\n", a.date_pr_msg.tm_mday, a.date_pr_msg.tm_mon, a.date_pr_msg.tm_year);
    printf("La date du dernier message poste: %d/%d/%d\n", a.date_dr_msg.tm_mday, a.date_dr_msg.tm_mon, a.date_dr_msg.tm_year);
    printf("Le nombre de messages postes: %d\n", a.nombre_de_messages);
    if (a.profil == 1) {
        printf("Cet auteur a un profil.\n");
    } else {
        printf("Cet auteur n'a pas de profil.\n");
    }
}

void aff_profil(profil p) {
    printf("~PROFIL~\n");
    printf("Le numero d'inscription est: %ld\n", p.num_ins);
    printf("Le nom est: %s\n", p.nom);
    printf("Le prenom est: %s\n", p.prenom);
    printf("L'adresse est: %s, %s\n", p.ad.rue, p.ad.ville);
    printf("La date de naissance est: %d/%d/%d\n", p.date_naiss.tm_mday, p.date_naiss.tm_mon, p.date_naiss.tm_year);
    printf("L'adresse email est: %s\n", p.ad_mail);
    printf("Le numéro de telephone est: %ld\n", p.num_tel);
}

int main(void) {
    int choice;
    int nb_msg = 1;
    int nb_rb = 1;
    forum fr;
    rubrique rb;
    message msg;
    auteur at;
    profil pf;

    welcome_page();

    do {
        display_menu();
        scanf("%d", &choice);
        getchar(); // to consume the newline character after the number

        switch (choice) {
            case 1:
                fr = saisie_fr();
                break;
            case 2:
                rb = saisie_rb(&nb_rb);
                break;
            case 3:
                msg = saisie_msg(&nb_msg);
                break;
            case 4:
                at = saisie_at();
                break;
            case 5:
                pf = saisie_pf();
                break;
            case 6:
                aff_forum(fr);
                break;
            case 7:
                aff_rubrique(rb);
                break;
            case 8:
                aff_messg(msg);
                break;
            case 9:
                aff_auteur(at);
                break;
            case 10:
                aff_profil(pf);
                break;
            case 11:
                printf("Quitter l'application.\n");
                break;
            default:
                printf("Option invalide. Veuillez choisir une option valide.\n");
        }
    } while (choice != 11);

    return 0;
}
