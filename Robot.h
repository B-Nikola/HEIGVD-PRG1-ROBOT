/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Robot.h
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier est l'en tête de la classe Robot. Cette classe
                   permet de définir le comportement d'un robot. Ce dernier se
                   déplace uniquement en 2D (coordonnées x et y).

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef ROBOT_H
#define ROBOT_H

class Robot {
public :
//---------------------------------------------------------------
// Constructeur
//---------------------------------------------------------------
Robot(unsigned x, unsigned y);

//---------------------------------------------------------------
// Destructeur
//---------------------------------------------------------------
~Robot();

//---------------------------------------------------------------
// Méthode
//---------------------------------------------------------------
void deplacer();


private:
//---------------------------------------------------------------
// Paramètre privée
//---------------------------------------------------------------
unsigned x, y;
const unsigned id;
enum Deplacement {HAUT, BAS, GAUCHE, DROITE};

//---------------------------------------------------------------
// Paramètre static
//---------------------------------------------------------------
static unsigned next;
static unsigned total;
};

#endif //ROBOT_H