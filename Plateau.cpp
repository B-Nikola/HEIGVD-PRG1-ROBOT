/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Plateau.cpp
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier définit le comportement de la classe Plateau. Il
                   contient les définitions des différentes méthodes.

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#include "Plateau.h"

using namespace std;

//---------------------------------------------------------------
// Constructeur
//---------------------------------------------------------------
Plateau::Plateau(unsigned largeur, unsigned hauteur) : largeur(largeur),
                                                       hauteur(hauteur) {}

//---------------------------------------------------------------
// Destructeur
//---------------------------------------------------------------
Plateau::~Plateau() {}

//---------------------------------------------------------------
// Méthode
//---------------------------------------------------------------
