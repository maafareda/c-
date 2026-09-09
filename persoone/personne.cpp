#include "personne.h"
#include <iostream>
#include <cstring>

using namespace std;

personne::personne()
{
    age = 0;

    nom = new char[20];
    prenom = new char[20];

    strcpy(nom, "inconnu");
    strcpy(prenom, "inconnu");
}

personne::personne(char *nom1, char *prenom1, int age1)
{
    nom = new char[20];
    prenom = new char[20];

    strcpy(nom, nom1);
    strcpy(prenom, prenom1);

    age = age1;
}

void personne::affiche() const
{
    cout << "nom : " << nom << endl;
    cout << "prenom : " << prenom << endl;
    cout << "age : " << age << endl;
}

personne::~personne()
{
    cout << "destruction de " << nom << endl;

    delete[] nom;
    delete[] prenom;
}
