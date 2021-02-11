/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <stdbool.h>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    // variables de jeu
    string un_nom;
    string choix;
    int nombreADeviner;
    TJoueur joueur;
    int nbsucces;
    int nbechec;
    int nbessais;

    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    cout << "Quel est ton nom ? : ";
    cin >> un_nom ;
    cout << endl;

    InitJoueur(joueur, un_nom);
    // boucle de jeu
    do {
        // jeu
        cout << "let's go !" << endl ;
        nombreADeviner = TirerNombreMystere();
        JouerPartie(joueur, nombreADeviner);
        // demande d'une nouvelle partie
        cout << "Voulez vous jouez une autre partie ?   o/n " << endl << "Oui tapez o | Sinon tapez autre chose :) " << endl;
        cin >> choix;
    } while(choix == "o");
    cout << "Merci d'avoir joue a la prochaine " << Nom(joueur) << endl;

    // recuperation des donnees du joueur
    // affichage du resultat
    ResultatsJoueur(joueur, nbsucces, nbechec, nbessais);
    cout << "Vous avez joue " << (nbsucces + nbechec) << " parties ! " << endl;
    cout << "Vous avez gagne " << nbsucces << " parties ! " << endl;
    cout << "Vous avez perdu " << nbechec << " parties ! " << endl;
    cout << "Avec un total de " << nbessais << " essais ! " << endl;

    return 0;
}


