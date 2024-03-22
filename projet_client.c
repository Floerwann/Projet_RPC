#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "projet.h" // Inclure le fichier d'en-tête généré par rpcgen



void client_1(char * host){

    CLIENT *clnt;

    struct AbonnementCompte monCompte; 
    struct AbonnementCompte *result_ajoutCompte;
    struct AbonnementCompte *result_resilierAbonnement;
    struct AbonnementCompte *result_supprimerCompte;

    struct AjoutSoldeParams params;
    params.compte = monCompte;
    struct AjoutSoldeParams *result_ajouterSolde;

    #ifndef	DEBUG
        clnt = clnt_create (host, GESTION_COMPTE, GESTION_COMPTE_V1, "udp");
        if (clnt == NULL) {
            clnt_pcreateerror (host);
            exit (1);
        }
    #endif	/* DEBUG */



    // Exemple d'appel de la fonction ajouterCompte

    monCompte.compte.nom = "Tanguy";
    monCompte.compte.prenom = "Axel";
    monCompte.compte.mail = "Axel.Tanguy@example.com";
    monCompte.compte.paysResidence = "France";
    monCompte.compte.solde = 1000.0;
    // Remplissage des données de l'abonnement
    monCompte.abonnement.service = "Spotify";
    monCompte.abonnement.prix = 18;
    monCompte.abonnement.nbPlaces = 2;
    monCompte.abonnement.typePartage = "Privé";
    monCompte.abonnement.typePaiement = "Carte de crédit";


    // Appel de la fonction distante ajouterCompte
    result_ajoutCompte = ajoutercompte_1(&monCompte, clnt);
    if (result_ajoutCompte == NULL) {
        clnt_perror(clnt, "call failed:");
    }

    // Appel de la fonction distante resilierCompte
    result_resilierAbonnement = resilierabonnement_1(&monCompte, clnt);
    if (result_resilierAbonnement == NULL) {
        clnt_perror(clnt, "call failed:");
    }

    // Appel de la fonction distante ajouterSolde
    result_ajouterSolde = ajoutersolde_1(&params, clnt);
    if (result_ajouterSolde == NULL) {
        clnt_perror(clnt, "call failed:");
    }




    // Appel de la fonction distante suppremierCompte
    result_supprimerCompte = supprimercompte_1(&monCompte, clnt);
    if (result_supprimerCompte == NULL) {
        clnt_perror(clnt, "call failed:");
    }


    // Libération des ressources du client RPC
    clnt_destroy(clnt);
    
    return 0;

}

int main(int argc, char *argv[]) {
    char *host; // Nom du serveur RPC

    // Vérification de l'adresse du serveur RPC
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    host = argv[1];
    client_1(host);
    exit(0);
}