#include "Chauffeur.h"
#include <iostream>
using namespace std;

// executer une requete
MYSQL_RES* executer(MYSQL* conn, string req)
{
    mysql_query(conn, req.c_str());//req
    return mysql_store_result(conn);// stock req
}


// Petite pause
void pause()
{
    cout << "\nAppuyez sur Entree...";
    cin.ignore();
    cin.get();// entr
}


// Constructeur
Chauffeur::Chauffeur(MYSQL* c)
{
    conn = c;
    idChauffeur = -1;
}


// Connexion chauffeur
bool Chauffeur::seConnecter()
{
    string emailInput;
    string mdp;

    cout << "Email : ";
    cin >> emailInput;

    cout << "Mot de passe : ";
    cin >> mdp;

    string req =
        "SELECT id_chf FROM chauffeur "
        "WHERE email_chf='" + emailInput + "' AND mp_chf='" + mdp + "'";

    MYSQL_RES* res = executer(conn, req);

    if (res && mysql_num_rows(res) > 0)
    {
        MYSQL_ROW row = mysql_fetch_row(res);

        idChauffeur = atoi(row[0]);//dpr

        mysql_free_result(res); // lbr

        cout << "\nConnexion reussie.\n";
        return true;
    }

    cout << "\nEmail ou mot de passe incorrect.\n";
    return false;
}

// Afficher infos
void Chauffeur::afficherInfo()
{
    string req =
        "SELECT nom_chf, prenom_chf, telephone_chf "
        "FROM chauffeur WHERE id_chf=" + to_string(idChauffeur);

    MYSQL_RES* res = executer(conn, req); //exc req

    if (res)
    {
        MYSQL_ROW row = mysql_fetch_row(res);

        if (row)
        {
            cout << "\nBienvenue : " << row[0] << " " << row[1] << endl;
            cout << "Telephone : " << row[2] << endl;
        }

        mysql_free_result(res);
    }
}

// Voir trajets
void Chauffeur::voirMesTrajets()
{
    cout << "\n=== MES TRAJETS ===\n";

    string req =
        "SELECT t.lieu_dpr, t.destination "
        "FROM trajet t "
        "JOIN possede p ON t.id_traj = p.id_traj "
        "WHERE p.id_chf = " + to_string(idChauffeur);

    MYSQL_RES* res = executer(conn, req);

    if (res && mysql_num_rows(res) > 0)
    {
        MYSQL_ROW row;

        while ((row = mysql_fetch_row(res)))
        {
            cout << "Depart : " << row[0]
                 << " -> Destination : " << row[1]
                 << endl;
        }

        mysql_free_result(res);
    }
    else
    {
        cout << "Aucun trajet.\n";
    }

    pause();
}

// Menu principal
void Chauffeur::afficherMenu()
{
    int choix;

    do
    {
        cout << "\n===== MENU CHAUFFEUR =====\n";
        cout << "1. Voir mes trajets\n";
        cout << "2. Mes informations\n";
        cout << "3. Quitter\n";
        cout << "Choix : ";
        cin >> choix;

        if (choix == 1)
        {
            voirMesTrajets();
        }
        else if (choix == 2)
        {
            afficherInfo();
            pause();
        }
        else if (choix == 3)
        {
            cout << "Deconnexion...\n";
        }
        else
        {
            cout << "Choix invalide.\n";
        }

    } while (choix != 3);
}
