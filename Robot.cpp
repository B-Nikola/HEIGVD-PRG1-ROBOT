/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Robot.cpp
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier définit le comportement de la classe Robot. Il
                   contient les définitions des différentes méthodes.

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#include "Robot.h"

using namespace std;

//---------------------------------------------------------------
// Paramètre static
//---------------------------------------------------------------
unsigned Robot::next  = 1;
unsigned Robot::total = 0;

//---------------------------------------------------------------
// Constructeur
//---------------------------------------------------------------
Robot::Robot(unsigned x, unsigned y) : x(x), y(y), id(next)
{
   ++next;
   ++total;
}

//---------------------------------------------------------------
// Destructeur
//---------------------------------------------------------------
Robot::~Robot()
{
   --total;
}

//---------------------------------------------------------------
// Méthode
//---------------------------------------------------------------
void Robot::deplacer(Deplacement direction)
{

   switch (direction)
   {

      case HAUT:
      {
         y -= 1;
         break;
      }

      case BAS:
      {
         y += 1;
         break;
      }

      case GAUCHE:
      {
         x -= 1;
         break;
      }

      case DROITE:
      {
         x += 1;
         break;
      }
   }
}

//---------------------------------------------------------------------------

unsigned int Robot::getAbscisse() const
{
   return x;
}

//---------------------------------------------------------------------------

unsigned int Robot::getOrdonnee() const
{
   return y;
}

//---------------------------------------------------------------------------

unsigned int Robot::getId() const
{
   return id;
}

//---------------------------------------------------------------------------