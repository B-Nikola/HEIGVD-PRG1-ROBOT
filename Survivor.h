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

private :
//---------------------------------------------------------------
// Paramètre privée
//---------------------------------------------------------------
std::vector<Robot> robotsJoueurs;

//---------------------------------------------------------------
// Méthode privée
//---------------------------------------------------------------

// Nom       : InitialisationPartie
// But       : Cette fonction permet d'initialiser la partie. En outre, elle
//             permet de créer le plateau de jeu ainsi que le nombre de
//             robots participant à la partie. De plus, elle à pour but de
//             placer les robots sur le plateau de manière aléatoire.
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
void initialisationPartie();
//---------------------------------------------------------------------------

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

// Nom              : deplacementEstAutorisee
// But              : Cette fonction permet de s'assurer qu'un robot se déplace
//                    sur un position (x ,y) autorisée.
// Param plateau    : Plateau de jeu
// Return           : booléen indiquant que le déplacement effectué par le robot
//                    est autorisé
// Exception        : Lorsqu'un robot se trouve à côter d'un bord et qu'il se
//                    déplace contre ce bord, il doit corriger son déplacement et se
//                    déplacer dans la direction oposée
bool deplacementEstAutorisee(const Plateau& plateau);
//---------------------------------------------------------------------------

// Nom              : detruire
// But              : Cette fonction permet de définir comment les robots se font
//                    détruire. Lorsqu'un robot se déplace sur une case et qu'un
//                    autre robot se situe sur cette dernière, le robot qui s'est
//                    déplacé détruit l'autre.
// Param plateau    : Plateau de jeu
// Return           : / void
// Exception        : / aucune exception
void detruire(const Plateau& plateau);
//---------------------------------------------------------------------------

// Nom              : prochainTour
// But              : Cette fonction permet de jouer le prochain tour. Tous les
//                    robots vont se déplacer et se manger entre eux si possible
// Param plateau    : Plateau de jeu
// Return           : / void
// Exception        : / aucune exception
void prochainTour(const Plateau& plateau);
//---------------------------------------------------------------------------

};

#endif //SURVIVOR_H
