/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Plateau.h
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier est l'en tête de la classe Plateau. Cette classe
                   permet de définir le comportement d'un plateau de jeu 2D.

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef PLATEAU_H
#define PLATEAU_H


class Plateau {
public :
//---------------------------------------------------------------
// Constructeur
//---------------------------------------------------------------
Plateau(unsigned largeur, unsigned hauteur);

//---------------------------------------------------------------
// Destructeur
//---------------------------------------------------------------
~Plateau();

//---------------------------------------------------------------
// Méthode
//---------------------------------------------------------------

private :
//---------------------------------------------------------------
// Paramètre privée
//---------------------------------------------------------------
const unsigned largeur;
const unsigned hauteur;

};


#endif //PLATEAU_H
