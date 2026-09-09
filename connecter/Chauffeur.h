#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H

#include <mysql.h>
#include <string>
using namespace std;

class Chauffeur {
public:
    Chauffeur(MYSQL* conn);

    bool seConnecter();
    void afficherInfo();
    void afficherMenu();
    void voirMesTrajets();

private:
    MYSQL* conn;
    int idChauffeur;
    string nom;
    string prenom;
    string email;
    string telephone;
    string statut;

    void enregistrerLog(const string& statut); // entre cf <admin> act
};

#endif
