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
//---------------------------------------------------------------
// Enum
//---------------------------------------------------------------
enum Deplacement {HAUT, BAS, GAUCHE, DROITE};

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

// Nom             : deplacer
// But             : Cette fonction permet de déplacer les robots dans une direction.
// Param direction : Enum permettant de définir les directions possibles
// Return          : / void
// Exception       : La direction est choisi en fonction d'un enum "Deplacement".
//                   Les directions sont haut, bas, gauche et droite.
void deplacer(Deplacement direction);
//---------------------------------------------------------------------------

// Nom       : getAbscisse
// But       : Cette fonction permet de récupérer la coordonnées x (il s'agit
//             d'un getteur car la propriété "x" est privée).
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
unsigned getAbscisse() const;
//---------------------------------------------------------------------------

// Nom       : getOrdonnee
// But       : Cette fonction permet de récupérer la coordonnées y (il s'agit
//             d'un getteur car la propriété "y" est privée).
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
unsigned getOrdonnee() const;
//---------------------------------------------------------------------------

// Nom       : getId
// But       : Cette fonction permet de récupérer l'id du robot (il s'agit
//             d'un getteur car la propriété "id" est privée).
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
unsigned getId() const;
//---------------------------------------------------------------------------

private:
//---------------------------------------------------------------
// Paramètre privée
//---------------------------------------------------------------
unsigned       x, y;
const unsigned id;

//---------------------------------------------------------------
// Paramètre static
//---------------------------------------------------------------
static unsigned next;
static unsigned total;
};

#endif //ROBOT_H