#ifndef BASE_DONNEES_H
#define BASE_DONNEES_H

#include <mysql.h>

class BaseDonnees {
public:
    MYSQL* conn;

    BaseDonnees();
    ~BaseDonnees();

    bool connecter();
    void deconnecter();
};

#endif
