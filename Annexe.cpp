/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Annexe.cpp
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier définit le comportement des différentes fonctions de la
                   bibliothèque "Annexe" qui contient des fonctions utilisées dans
                   tout le projet.

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <iostream> // Permet d'afficher et de lire dans la console
#include <limits>   // Permet d'avoir les caractéristiques des types arithmétiques.

#include "Annexe.h" // Fonctions annexes au programme

using namespace std;

void viderBuffer()
{
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
//---------------------------------------------------------------------------

int genereChiffreAleatoire(int min, int max)
{
   // Initialisation du générateur si première fois
   static bool first = true;

   if (first)
   {
      srand( (unsigned)time(NULL));
      first = false;
   }

   // Génération du caractère
   return rand() % (max - min) + min;
}