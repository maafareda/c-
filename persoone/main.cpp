#include <iostream>
#include"perflib.h"
using namespace std;

int main()
{
    personne p1,p2;

    char nom[20],prenom[20];
    int age;

    cout<<"saisie le nom puis le prenom puis age "<<endl;
    cin>>nom;
    cin>>prenom;
    cin>>age;

    p2(nom,prenom,age);

    p1.affiche();
    p2.affiche();
}
