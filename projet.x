struct Compte {
    char nom[10];
    char prenom[20];
    char mail[30];
    char paysResidence[20];
    float solde;
};

struct Abonnement {
    char service[20];
    int prix;
    int nbPlaces;
    char typePartage[15];
    char typePaiement[15];
};

struct AjoutSoldeParams {
    struct AbonnementCompte compte;
    float montant;
};

struct AbonnementCompte {
    struct Compte compte;
    struct Abonnement abonnement;
};


program GESTION_COMPTE {
    version GESTION_COMPTE_V1 {
        struct AbonnementCompte ajouterCompte(struct AbonnementCompte) = 1;
        struct AbonnementCompte supprimerCompte(struct AbonnementCompte) = 2;
        struct AbonnementCompte resilierAbonnement(struct AbonnementCompte) = 3;
        struct AbonnementCompte ajouterSolde(struct AjoutSoldeParams) = 4;
        void afficherCompte(struct AbonnementCompte) = 5;
        void afficherAbonnement(struct AbonnementCompte) = 6;
        
    } = 1;
} = 0x20000001;