#include "BasseDonnees.h"
#include <iostream>
using namespace std;

BaseDonnees::BaseDonnees() {
    conn = NULL;
}

BaseDonnees::~BaseDonnees() {
    deconnecter();
}

bool BaseDonnees::connecter() {
    conn = mysql_init(NULL);
    if (conn == NULL) {
        cout << "Erreur: impossible d'initialiser MySQL" << endl;
        return false;
    }

    if (mysql_real_connect(conn, "127.0.0.1", "root", "200516","inteligents_transport_10", 3306, NULL , 0) == NULL)//req //user
        {
        cout << "Erreur de connexion: " << mysql_error(conn) << endl;
        mysql_close(conn);
        conn = NULL;
        return false;
    }
    return true;
}

void BaseDonnees::deconnecter() {
    if (conn != NULL) {
        mysql_close(conn);
        conn = NULL;
    }
}
