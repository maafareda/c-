#ifndef COMPTE_H
#define COMPTE_H


class compte
{
    public:
        compte();
        compte(const int ,char *, char *,float  );
        ~compte();
        compte(const compte& );
        compte &operator=(const compte &);
        void depose(float );
        void retirer(float );
        void affiche();
        friend ostream &operator<<(ostream&,compte&);
        friend istream &operator>>(istream&,compte&);

    private:
        static int compteur;
        int id  ;
        char *nom;
        char *prenom;
        float solde ;
};

#endif // COMPTE_H
