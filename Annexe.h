/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Annexe.h
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier définit le comportement des différentes fonctions de la
                   bibliothèque "annexe" qui contient des fonctions qui sont
                   utilisées dans tout le projet et qui ne sont pas spécifique à
                   une classe ou à une librairie.

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#ifndef ANNEXE_H
#define ANNEXE_H

// Nom       : viderBuffer
// But       : Cette fonction permet de vider le buffer.
// Param     : / aucun paramètre
// Return    : / void
// Exception : / aucune exception
void viderBuffer();
//---------------------------------------------------------------------------

// Nom       : genereChiffreAleatoire
// But       : Cette fonction permet de générer un chiffre de manière aléatoire.
//             Ce chiffre est compris entre la borne min et la borne max
// Param min : Borne inférieure
// Param max : Borne supérieure
// Return    : / void
// Exception : / aucune exception
int genereChiffreAleatoire(int min, int max);
//---------------------------------------------------------------------------

#endif //ANNEXE_H
