/*
 -----------------------------------------------------------------------------------
 Nom du fichier  : Survivor.cpp
 Nom du labo     : Labo 08 : Survivor
 Auteur(s)       : Bouattit Nikola & Slimani Walid
 Date creation   : 14.01.2022

 Description     : Ce fichier définit le comportement de la classe Survivor. Il
                   contient les définitions des différentes méthodes.

 Remarque(s)     : / aucune remarque

 Modification(s) : / aucune modification

 Compilateur     : Mingw-w64 g++ 11.2.0
 -----------------------------------------------------------------------------------
*/

#include <string>     // Permet l'utilisation de strings
#include <iostream>   // Permet d'afficher et de lire sur la console

#include "Survivor.h" // Classe Permettant de générer une partie du jeu Survivor
#include "Plateau.h"  // Classe permettant de créer un plateau de jeu

#include "saisie.h"   // bibliothèque possédant une fonction de saisie contrôlée
#include "annexe.h"   // bibliothèque possédant diverses fonctions annexes

using namespace std;

//---------------------------------------------------------------
// Messages à afficher (français)
//---------------------------------------------------------------
const string TITRE              = "Survivor",
             DESCRIPTION        = "Ce programme simule un jeu de survie joué par des "
                                  "robots autonomes. Pour survire, ils doivent détruire "
                                  "les autres robots. Le dernier gagne.",
             MSG_SAISIE_LARGEUR = "Veuillez saisir la largeur du plateau",
             MSG_SAISIE_HAUTEUR = "Veuillez saisir la hauteur du plateau",
             MSG_SAISIE_N_ROBOT = "Veuillez saisir le nombre de robots qui vont "
                                  "jouer la partie",
             MSG_ERREUR         = "Erreur de saisie...",
             MSG_FIN_PROGRAMME  = "Appuyez sur ENTREE pour quitter le programme.";

//---------------------------------------------------------------
// Déclaration des constantes
//---------------------------------------------------------------
const int NBR_ROBOT_MIN = 1,
          NBR_ROBOT_MAX = 9,
          LARG_HAUT_MIN = 10,
          LARG_HAUT_MAX = 1000;

//---------------------------------------------------------------
// Constructeur
//---------------------------------------------------------------
Survivor::Survivor()
{
   initialisationPartie();
}

//---------------------------------------------------------------
// Destructeur
//---------------------------------------------------------------
Survivor::~Survivor() {}

//---------------------------------------------------------------
// Méthode public
//---------------------------------------------------------------

//---------------------------------------------------------------------------

//---------------------------------------------------------------
// Méthode privée
//---------------------------------------------------------------
void Survivor::initialisationPartie()
{
   // Création du plateau de jeu
   Plateau plateauSurvivor = creationPlateau();

   // Création des robots qui vont jouer la partie
   creationRobots();
}

//---------------------------------------------------------------------------

void Survivor::explicationJeu()
{
   cout << endl   // Permet plus de lisibilité dans la console
        << TITRE       << endl
        << DESCRIPTION << endl
        << endl;  // Permet plus de lisibilité dans la console
}

//---------------------------------------------------------------------------

Plateau &Survivor::creationPlateau()
{
   // Saisie utilisateur permettant de définir la largeur du plateau
   unsigned largeur = saisieUniqueControlee(LARG_HAUT_MIN,      LARG_HAUT_MAX,
                                            MSG_SAISIE_LARGEUR,MSG_ERREUR);

   // Saisie utilisateur permettant de définir la hauteur du plateau
   unsigned hauteur = saisieUniqueControlee(LARG_HAUT_MIN,      LARG_HAUT_MAX,
                                            MSG_SAISIE_HAUTEUR,MSG_ERREUR);

   // Création du plateau de jeu
   Plateau plateauJeu(largeur, hauteur);
   return plateauJeu;
}

//---------------------------------------------------------------------------

void Survivor::creationRobots()
{
   // Saisie utilisateur permettant de définir le nombre robots joueueurs
   unsigned nbrRobots = saisieUniqueControlee(NBR_ROBOT_MIN,       NBR_ROBOT_MAX,
                                              MSG_SAISIE_N_ROBOT, MSG_ERREUR);

   // Création des robots et initialisation des robots
   for(size_t i = 0; i < nbrRobots; ++i)
   {
      unsigned x = genereChiffreAleatoire(LARG_HAUT_MIN,LARG_HAUT_MAX);
      unsigned y = genereChiffreAleatoire(LARG_HAUT_MIN,LARG_HAUT_MAX);

      while(!estCoordonneeLibre(x, y))
      {
         x = genereChiffreAleatoire(LARG_HAUT_MIN,LARG_HAUT_MAX);
         y = genereChiffreAleatoire(LARG_HAUT_MIN,LARG_HAUT_MAX);
      }

      robotsJoueurs.emplace_back(Robot(x, y));
   }
}

//---------------------------------------------------------------------------

bool Survivor::estCoordonneeLibre(unsigned int x, unsigned int y) const
{
   for(const Robot& r : robotsJoueurs)
   {
      if(r.getOrdonnee() == x && r.getAbscisse() == y)
      {
         return false;
      }
   }
   return true;
}









void Survivor::affichage(const Plateau& plateau)
{
   string ligne0(plateau.getLargeur()+2,'-');
   cout << string (plateau.getLargeur()+2,'-') << endl;

   for (size_t i = 0; i < plateau.getHauteur(); ++i) {
      string ligneX = "|";
      ligneX += string(creationPlateau().getLargeur(),' ');

      for (size_t y = 0; i < robotsJoueurs.size(); ++i) {
         if ( i == robotsJoueurs.at(y).getOrdonnee()){
            ligneX.at(i) = (char)robotsJoueurs.at(y).getId();
         }
         ligneX += '|';
      }
      cout << ligneX << endl;
   }
   cout << ligne0 << endl;
}

