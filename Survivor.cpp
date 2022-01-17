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
             DESCRIPTION        = "Ce programme simule un jeu de survie joue par "
                                  "des robots autonomes. Pour survire, ils doivent"
                                  " detruire les autres robots. Le dernier gagne.",
             MSG_SAISIE_LARGEUR = "Veuillez saisir la largeur du plateau",
             MSG_SAISIE_HAUTEUR = "Veuillez saisir la hauteur du plateau",
             MSG_SAISIE_N_ROBOT = "Veuillez saisir le nombre de robots",
             MSG_ERREUR         = "Erreur de saisie...",
             MSG_FIN_PROGRAMME  = "Appuyez sur ENTREE pour quitter le programme.";

//---------------------------------------------------------------
// Déclaration des constantes
//---------------------------------------------------------------
const int NBR_ROBOT_MIN   = 1,
          NBR_ROBOT_MAX   = 9,
          LARG_HAUT_MIN   = 10,
          LARG_HAUT_MAX   = 1000,
          ORIGINE_PLATEAU = 0;

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
   // Explication du jeu
   explicationJeu();

   // Création du plateau de jeu
   Plateau plateauSurvivor = creationPlateau();

   // Création des robots qui vont jouer la partie
   creationRobots(plateauSurvivor);

   // Affichage des robots sur le plateau
   affichage(plateauSurvivor);
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

Plateau Survivor::creationPlateau()
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

void Survivor::creationRobots(const Plateau& plateau)
{
   // Déclaration d'une constante
   const unsigned BORD = 1;

   // Saisie utilisateur permettant de définir le nombre robots joueueurs
   unsigned nbrRobots = saisieUniqueControlee(NBR_ROBOT_MIN,       NBR_ROBOT_MAX,
                                              MSG_SAISIE_N_ROBOT, MSG_ERREUR);

   // Création des robots et initialisation des robots
   for(size_t i = 0; i < nbrRobots; ++i)
   {
      unsigned x = genereChiffreAleatoire(ORIGINE_PLATEAU,
                                          plateau.getLargeur() - BORD);

      unsigned y = genereChiffreAleatoire(ORIGINE_PLATEAU,
                                          plateau.getHauteur() - BORD);

      while(!estCoordonneeLibre(x, y))
      {
         x = genereChiffreAleatoire(ORIGINE_PLATEAU,
                                    plateau.getLargeur() - BORD);

         y = genereChiffreAleatoire(ORIGINE_PLATEAU,
                                    plateau.getHauteur() - BORD);
      }

      robotsJoueurs.emplace_back(Robot(x, y));
   }
}

//---------------------------------------------------------------------------

bool Survivor::estCoordonneeLibre(unsigned  x, unsigned  y) const
{
   for(const Robot& r : robotsJoueurs)
   {
      if(r.getOrdonnee() == y && r.getAbscisse() == x)
      {
         return false;
      }
   }
   return true;
}

//---------------------------------------------------------------

void Survivor::affichage(const Plateau& plateau)
{
   // Déclaration de constantes
   const int           DEPART_AFFICHAGE = '0'; // Permet d'afficher l'ID
   const unsigned char MUR_HORIZONTAL   = '-'; // Bordure supéreiure et inféreieure
   const unsigned char MUR_VERTICAL     = '|'; // Bordure latérale
   const unsigned char ESPACE_VIDE      = ' '; // Affiche un espace vide (pas de
                                               // robots)
   const unsigned      DECALAGE_MUR     = 2;   // Permet d'avoir des murs
                                               // perpendiculaires

   // Permet d'afficher le terrain sans les robots
   string bordureHorizontale(plateau.getLargeur() + DECALAGE_MUR,MUR_HORIZONTAL);
   cout << bordureHorizontale << endl;

   // Affichage des ID des robots
   string ligneTerrain;
   for(size_t i = 0; i < plateau.getHauteur(); ++i)
   {
      ligneTerrain += MUR_VERTICAL;
      ligneTerrain += string(plateau.getLargeur(), ESPACE_VIDE);
      ligneTerrain += MUR_VERTICAL;
      ligneTerrain += '\n';
   }

   // Affichage de l'ID des robots
   string ligneRobot = ligneTerrain;
   for(const Robot& r : robotsJoueurs)
   {
      // Pour Y : On récupère la coordonnée Y puis on la multiplie à la large du
      //          plateau + 3 (les deux bords ainsi que le '\n' après le mur
      //          vertical de gauche).
      // Pour X : On récupère la coordonnée X puis on fait plus 1 car il faut
      //          prendre en compte le mur de gauche.
      ligneRobot[(r.getOrdonnee()) * (plateau.getLargeur() + 3)
                + r.getAbscisse() + 1] = DEPART_AFFICHAGE + r.getId();
   }
   cout << ligneRobot << bordureHorizontale;
}

//---------------------------------------------------------------

bool deplacementEstAutorisee(const Plateau& plateau)
{

}

//---------------------------------------------------------------

void detruire(const Plateau& plateau)
{

}

//---------------------------------------------------------------

void prochainTour(const Plateau& plateau)
{

}