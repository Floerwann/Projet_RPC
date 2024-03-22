#include "projet.h" // Inclure le fichier d'en-tête généré par rpcgen
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// Implémentation de la fonction ajouterCompte
struct AbonnementCompte * ajoutercompte_1_svc(struct AbonnementCompte *monCompte, struct svc_req *rqstp) {
    static struct AbonnementCompte result;

    strncpy(result.compte.nom, monCompte->compte->nom, sizeof(result.compte.nom) - 1);
    strncpy(result.compte.prenom, monCompte->compte->prenom, sizeof(result.compte.prenom) - 1);
    strncpy(result.compte.mail, monCompte->compte->mail, sizeof(result.compte.mail) - 1);
    strncpy(result.compte.paysResidence, monCompte->compte->paysResidence, sizeof(result.compte.paysResidence) - 1);
    result.compte.solde = monCompte->compte->solde;

    strncpy(result.abonnement.service, monCompte->abonnement->service, sizeof(result.abonnement.service) - 1);
    result.abonnement.prix = monCompte->abonnement->prix;
    result.abonnement.nbPlaces = monCompte->abonnement->nbPlaces;
    strncpy(result.abonnement.typePartage, monCompte->abonnement->typePartage, sizeof(result.abonnement.typePartage) - 1);
    strncpy(result.abonnement.typePaiement, monCompte->abonnement->typePaiement, sizeof(result.abonnement.typePaiement) - 1);
    printf('La fonction ajouterCompte est appelée\n');

    return &result;
}

// Implémentation de la fonction supprimerCompte
struct AbonnementCompte * supprimercompte_1_svc(struct AbonnementCompte *monComptet, struct svc_req *rqstp) {
    static struct AbonnementCompte result; 

    memset(&monCompte.compte, 0, sizeof(struct Compte));
    memset(&monCompte.abonnement, 0, sizeof(struct Abonnement));
    printf('La fonction supprimerCompte est appelée\n');
    return &result; // Retourner le résultat
}


// Implémentation de la fonction resilierAbonnement
struct AbonnementCompte * resilierabonnement_1_svc(struct AbonnementCompte *monCompte, struct svc_req *rqstp) {
    static struct AbonnementCompte result; 
    memset(&monCompte.abonnement, 0, sizeof(struct Abonnement));
    printf('La foncion resilierAbonnement est appelée\n');
    return &result; // Retourner le résultat
}


// Implémentation de la fonction ajouterSolde
struct AbonnementCompte * ajoutersolde_1_svc(struct AjoutSoldeParams *params, struct svc_req *rqstp) {
    static struct AbonnementCompte result; 
    if (params == NULL) {
        fprintf(stderr, "Erreur : Paramètres invalides\n");
        return NULL;
    }
    params->compte.compte.solde += params->montant;

    result = params->compte;

    return &result;
}


// Implémentation de la fonction afficherCompte
void afficherCompte_1_svc(const struct AbonnementCompte *monCompte) {
    if (monCompte != NULL) {
        printf("Nom: %s\n", monCompte->compte.nom);
        printf("Prénom: %s\n", monCompte->compte.prenom);
        printf("Mail: %s\n", monCompte->compte.mail);
        printf("Pays de résidence: %s\n", monCompte->compte.paysResidence);
        printf("Solde: %.2f\n", monCompte->compte.solde);
    } else {
        printf("Erreur : monCompte est NULL.\n");
    }
}


void afficherAbonnement_1_svc(const struct AbonnementCompte *monCompte) {
    if (monCompte != NULL) {
        printf("Service: %s\n", monCompte->abonnement.service);
        printf("Prix: %d\n", monCompte->abonnement.prix);
        printf("Nombre de places: %d\n", monCompte->abonnement.nbPlaces);
        printf("Type de partage: %s\n", monCompte->abonnement.typePartage);
        printf("Type de paiement: %s\n", monCompte->abonnement.typePaiement);
    } else {
        printf("Erreur : monCompte est NULL.\n");
    }
}

