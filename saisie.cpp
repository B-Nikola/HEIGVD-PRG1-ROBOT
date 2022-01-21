/*
 ---------------------------------------------------------------------------
 Nom du fichier  : saisie.cpp
 Nom du labo     : Labo 06 Crible
 Auteur(s)       : Cédric Rosat - Walid Slimani
 Date creation   : 19.11.2021

 Description     : Ce fichier définit le comportement des différentes fonctions de la
                   bibliothèque "saisie". Il contient les définitions des fonctions.
                   De plus, cette bibliothèque contient des fonctions "privées". Elles
                   sont utilisées afin de construire la fonction qui est "publique".

 Remarque(s)     : / aucune remarque

 / aucune modification

 Mingw-w64 g++ 11.2.0
 ---------------------------------------------------------------------------
*/

#include <iostream> // Permet d'afficher et de lire dans la console

#include "saisie.h" // Permettant d'effectuer des saisies contrôlées
#include "annexe.h" // Fonctions annexes au programme

using namespace std;

//---------------------------------------------------------------------------
// Fonctions privées de la librairie (prototype)
//---------------------------------------------------------------------------

// Nom       : erreurBuffer
// But       : Le but de la fonction est d'indiquer si le buffer est planté
// Return    : Booléen indiquant si le buffer est planté
// Exception : n/a
bool erreurBuffer();

//---------------------------------------------------------------------------

// Nom            : erreurBornes
// But            : Le but de la fonction est d'indiquer si la valeur en paramètre
//                  d'entrée se situe entre les bornes inférieures et supérieures
//                  (bornes comprises)
// Param borneInf : Définit la borne inférieure
// Param borneSup : Définit la borne supérieure
// Param saisie   : Valeur à contrôler
// Return         : Booléen indiquant si la valeur est dans l'intervalle autorisé
// Exception      : / aucune exception
bool erreurBornes(int borneInf, int borneSup, int saisie);

//---------------------------------------------------------------------------

// Nom            : erreurSaisieMultiples
// But            : Contrôle qu'il n'y ait eu qu'une seule saisie
// Return         : Booléen indiquant s'il y a eu plusieurs saisies
// Exception      : / aucune exception
bool erreurSaisieMultiples();

//---------------------------------------------------------------------------

// Nom             : afficherMessageSaisie
// But             : Le but de la fonction est d'afficher le message de saisie et
//                   d'y ajouter les bornes
// Param msgSaisie : Message à afficher
// Param borneInf  : Définit la borne inférieure
// Param borneSup  : Définit la borne supérieure
// Return          : / void
// Exception       : / aucune exception
void afficherMessageSaisie(const string& msgSaisie, int borneInf, int borneSup);

//---------------------------------------------------------------------------
// Fonctions publiques de la librairie
//---------------------------------------------------------------------------

int saisieUniqueControlee(int borneInf, int borneSup, const string& msgSaisie,
                          const string& msgErreur)
{
   int saisie;
   bool erreurSaisie;

   do
   {
      afficherMessageSaisie(msgSaisie, borneInf, borneSup);
      cin >> saisie;

      // Le buffer est vidé soit dans erreurBuffer, soit dans erreurSaisieMultiple
      erreurSaisie = erreurBuffer() or
                     erreurSaisieMultiples() or
                     erreurBornes(borneInf, borneSup, saisie);

   } while (erreurSaisie and cout << msgErreur << endl);

   return saisie;
}

//---------------------------------------------------------------------------
// Fonctions privées de la librairie (déclaration)
//---------------------------------------------------------------------------

bool erreurBuffer()
{
   if (cin.fail())
   {
      cin.clear();
      viderBuffer();
      return true;
   }
   return false;
}

//---------------------------------------------------------------------------

bool erreurBornes(int borneInf, int borneSup, int saisie)
{
   return saisie < borneInf or saisie > borneSup;
}

//---------------------------------------------------------------------------

bool erreurSaisieMultiples()
{
   string resteBuffer;
   getline(cin, resteBuffer);
   return resteBuffer != "";
}

//---------------------------------------------------------------------------

void afficherMessageSaisie(const string& msgSaisie, int borneInf, int borneSup)
{
   cout << msgSaisie<< " [" << borneInf << ".." << borneSup << "] :";
}