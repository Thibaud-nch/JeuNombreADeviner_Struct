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
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    cout << "Vous allez jouer pour deviner un nombre secret" << endl;
    string un_nom;
    TJoueur joueur;
    int nombreADeviner;
    nombreADeviner = TirerNombreMystere();
    cout << "Quel est ton nom ? : ";
    cin >> un_nom;

    InitJoueur(joueur, un_nom);


    JouerPartie (joueur, nombreADeviner );

    return 0;
}

