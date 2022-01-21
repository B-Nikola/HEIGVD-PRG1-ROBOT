/*
 -----------------------------------------------------------------------------------
 Nom du fichier : main.cpp
 Nom du labo    : Labo 08 : Survivor
 Auteur(s)      : Bouattit Nikola & Slimani Walid
 Date creation  : 14.01.2022

 Description    : Le but du programme est de simuler des robots autonomes dans un
                  espaces données. Premièrement, l'utilisateur est invité à saisir
                  les la hauteur ainsi que la largeur du terrain de jeu ainsi que
                  le nombre de robots qui vont participer au jeu.

 Remarque(s)    : / aucune remarque

 Compilateur    : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <iostream>
#include <string>

#include "Survivor.h"

#include "annexe.h"

using namespace std;

int main()
{
//---------------------------------------------------------------
// Messages à afficher (français)
//---------------------------------------------------------------
   const string MSG_FIN_PROGRAMME  = "Appuyez sur ENTREE pour quitter le programme.";

//---------------------------------------------------------------
// Création du jeu et déroulement de la partie
//---------------------------------------------------------------
   Survivor jeu;
   jeu.start();

//-------------------------------------------------------------------
// Fin de programme
//-------------------------------------------------------------------
   cout << endl;     // Pour une lecture plus agréable dans la console
   terminerProgramme(MSG_FIN_PROGRAMME);

   return EXIT_SUCCESS;
}