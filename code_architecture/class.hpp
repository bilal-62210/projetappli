#pragma once
#include <iostream>
using namespace std;
#include <sql.h>

class appli
{
    public:
        virtual void creer(void)=0;
        virtual void modifier(void)=0;
        virtual void supprimer(void)=0;
        virtual void afficher(void)=0;


};

class personnel : appli
{
    private:
    string nom;
    string prenom;
    #define __DATE__ date;
    string superieurh;

    public:
        virtual void creer(void);
        virtual void modifier(void);
        virtual void supprimer(void);
        virtual void afficher(void);
        
};

class client : appli
{
    private:
        string adresse_livraison;
        string adresse_facturation;
        int numero_client;
         string nom;
         string prenom;
        #define __DATE__ date;
    public:
        virtual void creer(void);
        virtual void modifier(void);
        virtual void supprimer(void);
        virtual void afficher(void);
        void remise(void);

};

class commande : appli
{
    protected:
        string reference;
        #define __DATE__ date_livraison;
        #define __DATE__ date_emission;
        #define __DATE__ date_paiement;
        string moyen_paiement;
        int solde_reglement;
        int reference_article;
        string nom_article;
        int quantite;
        float montant_ht;
        float montant_tva;
        float montant_ttc;

    public:
        virtual void creer(void);
        virtual void modifier(void);
        virtual void supprimer(void);
        virtual void afficher(void);
        
};

class facture : commande
{
    private:
    string nom_societe;
    string adresse_societe;
    int code_client;
    
    public:
    void envoi_facture(void);
};

class stock : appli

{
    private:
    int prix_ht;
    int reference;
    string designation;
    int quantite;
    int seuil_reaprovisionnement;
    int taux_tva;
};


