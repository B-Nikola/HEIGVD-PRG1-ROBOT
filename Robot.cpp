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
// Déclaration des constantes
//---------------------------------------------------------------
const int UNITE = 1; // Indique de combien d'unité se déplace un robot

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
// Méthode publique
//---------------------------------------------------------------
void Robot::deplacer(Deplacement direction)
{
   switch (direction)
   {

      case HAUT:
      {
         y -= UNITE;
         break;
      }

      case BAS:
      {
         y += UNITE;
         break;
      }

      case GAUCHE:
      {
         x -= UNITE;
         break;
      }

      case DROITE:
      {
         x += UNITE;
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

Robot& Robot::operator=(const Robot& robAutre)
{
   x  = robAutre.x;
   y  = robAutre.y;

   const unsigned *ptr = &this->id;
   unsigned *ptemp = (unsigned*)ptr;

   *ptemp = robAutre.getId();
   return *this;
}

//---------------------------------------------------------------------------

bool Robot::operator==(const Robot& robAutre)
{
   return x == robAutre.x and  y  == robAutre.y;
}