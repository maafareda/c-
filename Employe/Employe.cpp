#include "Employe.h"
#include<iostream>
#include<cstring>
Employe::Employe()
{
    Nom=new char[20];
    Prenom=new char[20];
    Age=0;
    Anc=0;
}

Employe::Employe(const char*nom_,const char*Prenom_,const int&Age_,const int &Anc_)
{
    Nom=new char[strlen(nom_)+1];
    strcpy(Nom,nom_);
    Prenom=new char[strlen(Prenom_)+1];
    strcpy(Nom,Prenom_);

    Age=Age_;

    Anc=Anc_;
}

Employe::Employe(const Employe&v)
{
    Nom=new char[strlen(v.Nom)+1];
    strcpy(Nom,v.Nom);
    Prenom=new char[strlen(v.Prenom)+1];
    strcpy(Prenom,v.Prenom);
    Age=v.Age;
    Anc=v.Anc;
}

Employe::~Employe()
{
    delete[]Nom;
    delete[]Prenom;
}

Employe &Employe::operator=(const Employe&v)
{
     delete[]Nom;//libere memoir
     Nom=new char[strlen(v.Nom)+1];
     strcpy(Nom,v.Nom);
     delete[]Prenom;
     Prenom=new char[strlen(v.Prenom)+1];
     strcpy(Nom,v.Prenom);
     Age=v.Age;
     Anc=v.Anc;
     return*this;//retourne le objet que il cree
}

double Employe::calcul_salaire()const//const  les obj peux les utulise soit const ou pas
{
    double s=calcul_base_salaire();
    for(int i=0;i<Anc;i++)
    {
        s+=s*0.1;
    }
    return s;
}
    double s=calc
}

void Employe::afficher()
{
    cout<<Nom<<endl;
    cout<<Prenom<<endl;
    cout<<Age<<endl;
    cout<<Anc<<endl;
    cout<<calcul_salaire<<endl;
}

