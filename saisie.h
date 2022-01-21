/*
 ---------------------------------------------------------------------------
 Nom du fichier  : saisie.h
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Met à disposition des fonctions de saisie qui s'assurent que les
                   conditions de saisie soient respectées.

                   / aucune remarque

                   / aucune modification

 Remarque(s)     : Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#ifndef SAISIE_H
#define SAISIE_H

#include <string> // Permet l'utilisation de strings

// Nom       : saisieValeur
// But       : Contrôle la saisie utilisateur
//             Recommence tant que les conditions suivantes ne sont pas respectées :
//             - saisie du même type que le retour de la fonction
//             - saisie unique (un seul élément saisit)
//             - saisie dans les bornes
// Param min : Définit la borne inférieure
// Param max : Définit la borne supérieure
// Param msg : Affiche un message d'erreur si les conditions ne sont pas respectées
// Return    : Valeur saisie contrôlée
// Exception : / aucune exception
int saisieUniqueControlee(int borneInf, int borneSup, const std::string& msgSaisie,
                          const std::string& msgErreur);

#endif //SAISIE_H