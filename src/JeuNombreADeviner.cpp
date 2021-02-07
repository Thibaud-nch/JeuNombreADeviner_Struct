/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"




// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée :
// Paramètres de sortie :
// Paramètres d'entrée/sortie :

void InitJoueur(TJoueur &joueurAcreer, string un_nom)
{
    TJoueur joueur;
    joueurAcreer = joueur;
    joueur.nom = un_nom;
    joueur.nbPartiesJouees = 0;
    joueur.nbPartiesGagnees = 0;
    joueur.nbTentatives = 0;
    cout << "bienvenue dans le jeu " << joueur.nom << " !" << endl;
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    int a;
    a = rand() % 10 + 1;
    return a;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void JouerPartie(TJoueur &un_joueur, int nombreADeviner)
{
    for (int i = 1; i < 5; i++ ){

        int a;
        cout << "Choisis un nombre entre 1 et 10 (compris) : ";
        cin >> a ;
            if (  a > nombreADeviner  ){
                cout << "Le nombre a trouver est inferieur !" << endl;
            }else if( a < nombreADeviner) {
                cout << "Le nombre a trouver est superieur !" << endl;
            }

            else if( a == nombreADeviner && i == 1){
                cout << "Bien joue vous avez trouve le nombre mystere en " << i << " essai !";
                break;

            }
            else if( a == nombreADeviner && i > 1){
                cout << "Bien joue vous avez trouve le nombre mystere en " << i << " essais !";
                break;

            }
            else if( a != nombreADeviner && i == 4){
                cout << "Vous avez utilise vos 4 essais, GAME OVER :(";
                break;

            }
    }

}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void MajResultatsJoueur(TJoueur joueur, int nbEssais, bool gagne)
{
   // A COMPLETER
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    // A COMPLETER
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

