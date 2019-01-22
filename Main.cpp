/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <list>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Main.h"
#include "LogRead.h"
#include "Cutter.h"
#include "Renseignement.h"
///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
int main (int argc, char* argv[])
{   
  
  /*Renseignement r("MonReferer");
  r.Ajouter("deuxiemeReferer");
  r.Ajouter("TroisiemeReferer");
  r.Ajouter("deuxiemeReferer");

  unsigned int nbhit = r.getHit();
  unsigned int i = r.getHitReferer("deuxiemeReferer");
  unsigned int j = r.getHitReferer("kdchzc");

  cout << "nb hit total : " << nbhit << endl << "nbhit deuxiemeReferer : " << i << endl;
  cout << "nbhit referer absent : " << j << endl;

  list<string> referer = r.getReferer();
  list<string>::const_iterator deb,fin;
  deb = referer.cbegin();
  fin = referer.cend();

  while(deb!=fin)
  {
    cout << *deb << endl;
    deb++;
  }*/


  LogRead log("anonyme.log");
  string uneLigne = log.getLine(8);

  Cutter decoupe(uneLigne);
  string cible = decoupe.getCible();
  cout << "test de découpe Date : " << endl << cible << endl;

  string extension = decoupe.getExtension();
  cout << "extension : " << extension << endl;


  /*if(argc == 1)
  {
    printManual();
  }
    for(int i = 0; i < argc; i++)
    {

    }*/
    return 0;
}

void printManual(){
  cout << endl << "NAME" << endl;
  cout << "    analog - Analyse de log" << endl << endl;
  cout << "SYNOPSIS" << endl;
  cout << "    ./analog [OPTION]....FILE" << endl << endl;
  cout << "DESCRIPTION" << endl;
  cout << "    -g FILE, --export-to-GraphViz             " << endl << endl;
  cout << "    -t HOUR, --include-query-within-hour-hour+1" << endl << endl;
  cout << "    -e,        --exclude-image-css-javascript" << endl << endl;
  cout << "EXAMPLES" << endl;
  cout << "    ./analog nomFichier.log" << endl;
  cout << "               affiche sur la console les 10 documents les plus consultes dans nomFichier.log" << endl << endl;
  cout << "    ./analog -e -g nomFichier.dot nomFichier.log" << endl;
  cout << "               ignore les extensions image-css-javascript + generate GraphViz file" << endl << endl;
  cout << "AUTHORS" << endl;
  cout << "     Written by Ludovic RICHOUX and Adonis KATTAN" << endl << endl;
}
//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom
