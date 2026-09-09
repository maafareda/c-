#include <iostream>
#include "BasseDonnees.h"
#include "Chauffeur.h"

using namespace std;

int main() {

    BaseDonnees db;

    cout << "GESTION CHAUFFEURS\n";

    if (!db.connecter()) {
        cout << "Erreur de connexion\n";
        return 1;
    }

    Chauffeur chf(db.conn);

    if (chf.seConnecter()) {

        chf.afficherInfo();
        chf.afficherMenu();

    } else {
        cout << "Connexion chauffeur echouee\n";
    }

    return 0;
}
