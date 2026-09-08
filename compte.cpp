#include "compte.h"
#include <cstring>
#include <iostream>

using namespace std;

int compte::compteur = 0;

// constructeur par défaut
compte::compte()
{
    id = ++compteur;

    nom = new char[20];
    prenom = new char[20];

    strcpy(nom, "");
    strcpy(prenom, "");
    solde = 0;
}

// constructeur paramétré
compte::compte(char *nom_, char *prenom_, float solde_)
{
    id = ++compteur;

    nom = new char[strlen(nom_) + 1];
    prenom = new char[strlen(prenom_) + 1];

    strcpy(nom, nom_);
    strcpy(prenom, prenom_);

    solde = solde_;
}

// constructeur de recopie
compte::compte(const compte &p)
{
    id = ++compteur;

    nom = new char[strlen(p.nom) + 1];
    prenom = new char[strlen(p.prenom) + 1];

    strcpy(nom, p.nom);
    strcpy(prenom, p.prenom);

    solde = p.solde;
}

// destructeur
compte::~compte()
{
    delete[] nom;
    delete[] prenom;
}

// opérateur =
compte &compte::operator=(const compte &c)
{
    if (this != &c)
    {
        delete[] nom;
        delete[] prenom;

        nom = new char[strlen(c.nom) + 1];
        prenom = new char[strlen(c.prenom) + 1];

        strcpy(nom, c.nom);
        strcpy(prenom, c.prenom);

        solde = c.solde;
    }
    return *this;
}

// dépôt
void compte::depose(float &montant)
{
    if (montant > 0)
        solde += montant;
    else
        cout << "error" << endl;
}

// retrait
void compte::retirer(float &montant)
{
    if (montant > 0 && montant <= solde)
        solde -= montant;
    else
        cout << "error" << endl;
}

// affiche
void compte::affiche()
{
    cout << "nom " << nom << endl;
    cout << "prenom " << prenom << endl;
    cout << "solde " << solde << endl;
}

// operator <<
ostream &operator<<(ostream &out, const compte &p)
{
    out << "ID: " << p.id
        << " Nom: " << p.nom
        << " Prenom: " << p.prenom
        << " Solde: " << p.solde;

    return out;
}

// operator >>
istream &operator>>(istream &in, compte &p)
{
    char nom_[30], prenom_[30];
    float solde;

    cout << "Nom: ";
    in >> nom_;

    cout << "Prenom: ";
    in >> prenom_;

    cout << "Solde: ";
    in >> solde;

    delete[] p.nom;
    delete[] p.prenom;

    p.nom = new char[strlen(nom_) + 1];
    p.prenom = new char[strlen(prenom_) + 1];

    strcpy(p.nom, nom_);
    strcpy(p.prenom, prenom_);

    p.solde = solde;
    p.id = ++compte::compteur;

    return in;
}
