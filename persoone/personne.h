#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <cstring>
using namespace std;

class personne
{
    public:
        personne();
        personne(char *,char*,int*);
        void affiche()const;
        ~personne();



    private:
        char *nom,*prenom;
        int age;
};

#endif // PERSONNE_H
