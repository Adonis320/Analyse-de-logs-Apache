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
#include <stdio.h>
#include <string>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Main.h"
#include "LogRead.h"
#include "Cutter.h"
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
  /* // Exemple de cutter
  LogRead log("test.log");
  string uneLigne = log.getLine(5);

  Cutter decoupe(uneLigne);
  string date = decoupe.getDate();
  cout << "test de découpe Date : " << endl << date << endl;
  
  string cible = decoupe.getCible();
  cout << "test de découpe Cible : " << endl << cible << endl;

  string referer = decoupe.getReferer();
  cout << "test de découpe Referer : " << endl << referer << endl;
  */

  return 0;

} //------ Fin de main

void printManual()
{
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
} //------ Fin de printManual

void gestionParam(int nb, char * arg [])
{
  int * tabOption = {0, 0, 0,  0};
                  // e, g, t, log
  int tabCondition = {0,     0};
                  // g-op, t-op
  int afficheManual1 = 0;
  int afficheManual2 = 0;
  if(nb == 1) // lancement sans parametres
  {
    printManual();
  }
  else
  { 
    for(int i = 1; i < nb; i++)
    {
      if(!strcmp(arg[i],"e")) // cas du parametre e
      {
        tabOption[0] = 1;
        if((i+1) < nb)
        {

        }
      }
      else if (!strcmp(arg[i],"g")
      {
        tabOption[1] = 1;
      }
      else if (!strcmp(arg[i], "t"))
      {
        tabOption[2] = 0;
      }
      else // cas ou le parametre est un .log ou un .dot ou un
      {
        if(paramIsFile == 1) //.log
        {
          //TODO 
          tabOption[3] = 1;
        }
        else if(paramIsFile == 2) //.dot (g - option)
        {
          tabCondition[0] = 1;
        }
        else // t- option
        {
          tabOption[1] = 1;
        }
      }
    }
    for(int i = 0; i < 4; i++)
    {
      //TODO
      for(int j = 0; j < 2; j++)
      {
      }
    }
  }
}

int paramIsFile (char * param) // 0- not file / 1- log / 2- dot
{
  int val = 0;
  int taille = strlen(param);
  int format = 0;
  char * parametre = new char [30];
  if(strlen(param) < 4) // (.log && .dot : size = 4 chars)
  {
    format = 0;
  } 
  else
  {
    for(int i = taille; i < taille-4; i--)
    {
      parametre[4-i] = param[i];
    }
    if(!strcmp(parametre,".log")
    {
      format = 1;
    }
    else if (!strcmp(parametre,".dot")
    {
      format = 2;
    }
    else //c'est autre chose
    {
      format = 0;
    }
  }
  delete [] parametre;
  return format;
} //----- Fin de paramIsFile
//type Nom ( liste de paramètres )
// Algorithme :
//
//{
//} //----- fin de Nom
