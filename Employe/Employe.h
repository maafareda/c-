
#ifndef EMPLOYE_H
#define EMPLOYE_H

class Employe
{
public:
    Employe();
    Employe(const char*, const char*, const int&, const int&);
    Employe(const Employe &);
    virtual ~Employe();
    virtual double calcul_base_salaire() const = 0;
    virtual void afficher() const;
    double calcul_salaire() const;
    Employe & operator=(const Employe &);

protected:
    char* Nom;
    char* Prenom;
    int Age;
    int Anc;
};

#endif // EMPLOYE_H
