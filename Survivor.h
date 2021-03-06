/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Survivor.h
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier est l'en tête de la classe Survivor. Cette classe
                   permet de gérer la totalité du jeu (terrain ainsi que règles).

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef SURVIVOR_H
#define SURVIVOR_H

#include <vector>    // Permet l'utilsation de vecteur

#include "Plateau.h" // Le jeu Survivor à besoins d'un plateau
#include "Robot.h"   // Les joueurs du Survivor sont des robots autonomes

class Survivor {
public :
//---------------------------------------------------------------
// Constructeur
//---------------------------------------------------------------
Survivor();

//---------------------------------------------------------------
// Destructeur
//---------------------------------------------------------------
~Survivor();

//---------------------------------------------------------------
// Méthode publique
//---------------------------------------------------------------

// Nom       : start
// But       : Cette fonction permet de démarrer, initiliaser et jouer une partie
//             du jeu Survivor.
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
void start();
//---------------------------------------------------------------


private :
//---------------------------------------------------------------
// Paramètre privée
//---------------------------------------------------------------
std::vector<Robot> robotsJoueurs;

//---------------------------------------------------------------
// Méthode privée
//---------------------------------------------------------------

// Nom       : ExplicationJeu
// But       : Cette fonction permet d'expliquer le but du jeu Survivor
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
void explicationJeu();
//---------------------------------------------------------------------------

// Nom       : ExplicationJeu
// But       : Cette fonction permet d'expliquer le but du jeu Survivor
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
Plateau creationPlateau();
//---------------------------------------------------------------------------

// Nom       : creationRobots
// But       : Cette fonction permet de créer des objets de type robot et de les
//             initialiser avec des coordonnées différentes.
// Param     : / aucun paramètre
// Return    : / void
// Exception : Le vecteur mit à jour est un paramètre privé de la classe Survivor
void creationRobots(const Plateau& plateau);
//---------------------------------------------------------------------------

// Nom       : estCoordonneeLibre
// But       : Cette fonction permet de contrôler que les robots créés ne
//             possèdent pas les mêmes coordonnées.
// Param x   : coordonnée x des robots
// Param y   : coordonnée y des robots
// Return    : bool indique que les robots n'ont pas été initialisé aux même
//             coordonnées.
// Exception : / aucune exception
bool estCoordonneeLibre(unsigned  x, unsigned  y) const;
//---------------------------------------------------------------------------

// Nom       : creationRobots
// But       : Cette fonction permet de créer des objets de type robot et de les
//             initialiser avec des coordonnées différentes.
// Param     : / aucun paramètre
// Return    : / void
// Exception : Le vecteur mit à jour est un paramètre privé de la classe Survivor
void affichage(const Plateau& plateau);
//---------------------------------------------------------------------------

// Nom              : deplacement
// But              : Cette fonction permet de déplacer un robot en vérifiant au
//                    préalable les directions dans les quels il peut se diriger.
// Param plateau    : Plateau de jeu
// Param robot      : Robot qui se déplace
// Return           : void
// Exception        : / aucune exception
void deplacement(const Plateau& plateau, Robot& robot);
//---------------------------------------------------------------------------

// Nom              : destruction
// But              : Cette fonction permet de détruire les robots lorsqu'il se
//                    chevauche.
// Param robot      : Plateau de jeu
// Param robot      : Robot uitliser pour effectuer la comparaison afin de savoir
//                    si la destruction doit avoir lieu.
// Return           : void
// Exception        : / aucune exception
void destruction(const Robot& robot);
//---------------------------------------------------------------------------

// Nom                   : tourDeJeu
// But                   : Cette fonction permet d'effectuer un tour de jeu. Chaque
//                         robot vont se déplacer. Si un robot se déplace sur une
//                         case et qu'un autre robot se situe sur cette derière,
//                         il est détuit.
// Param plateauSurvivor : Plateau de jeu initialisé
// Return                : void
// Exception             : / aucune exception
void jouerPartie(const Plateau& plateauSurvivor);

};

#endif //SURVIVOR_H