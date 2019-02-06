/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Kattan Adonis et Richoux Ludovic
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Main> (fichier Main.h) -------------------
#if ! defined ( MAIN_H )
#define MAIN_H

//------------------------------------------------------------------------
// Rôle du module <Main>
//
//
//------------------------------------------------------------------------

/////////////////////////////////////////////////////////////////  INCLUDE
//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques

int main(int argc, char * argv[]);
//Mode d'emploi :
//
// Contrat
//    aucun

void printManual();
//Mode d'emploi :
//      Affiche le caalogue avec la liste des options
// Contrat
//    aucun

string getExtension( string nomFichier);
// Mode d'emploi :
//
// Contrat
//

void requeteCatalogue(string nomLog, char param[], int heure, string nomFichierGraph);
// Mode d'emploi
//
// Contrat
//

#endif // MAIN_H