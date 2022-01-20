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

#include "Survivor.h"

using namespace std;

int main()
{
   Survivor jeu;
   jeu.start();

   return EXIT_SUCCESS;
}