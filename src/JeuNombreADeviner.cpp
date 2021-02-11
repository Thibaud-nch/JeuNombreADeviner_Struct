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
#include <stdbool.h>
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
    joueurAcreer.nom = un_nom;
    joueurAcreer.nbPartiesJouees = 0;
    joueurAcreer.nbPartiesGagnees = 0;
    joueurAcreer.nbTentatives = 0;
    cout << "bienvenue dans le jeu " << joueurAcreer.nom << " !" << endl;
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    int a;
    srand (time(NULL));
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
        bool gagne = false;
        int i = 1;
        int nombre_a_deviner = TirerNombreMystere();

        while(i < 5 && gagne == false){
            // choix du nombre
            int a;
            cout << endl;
            cout << "Choisis un nombre entre 1 et 10 (compris) : " ;
            cin >> a ;
            cout << endl ;
            //test du nombre choisit
            if (  a > nombreADeviner  ){
                cout << "Le nombre a trouver est inferieur !" << endl;
            }else if( a < nombreADeviner ) {
                cout << "Le nombre a trouver est superieur !" << endl;
            } else if( a == nombreADeviner){
                cout << "Bien joue vous avez trouve le nombre mystere en " << i << " essais !" << endl;
                gagne = true ;
            }
            i++;
        }
        if(!gagne){ // ou i > 4
            cout << "Vous avez utilise vos 4 essais, GAME OVER :(" << endl;
        }
        MajResultatsJoueur(un_joueur, i-1, gagne);
}
// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
     joueur.nbTentatives += nbEssais;
     joueur.nbPartiesJouees += 1;
     if (gagne){
      joueur.nbPartiesGagnees++;
     }
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée:
// Paramètres de sortie:
// Paramètres d'entrée/sortie :

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais){
    nbsucces = joueur.nbPartiesGagnees;
    nbechec = joueur.nbPartiesJouees - joueur.nbPartiesGagnees;
    nbessais = joueur.nbTentatives;
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){
    return joueur.nom;
}

