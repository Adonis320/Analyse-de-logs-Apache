/*************************************************************************
                           Main  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Kattan Adonis et Richoux Ludovic
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>
#include <list>
#include <cstring>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Main.h"
#include "LogRead.h"
#include "Cutter.h"
#include "Renseignement.h"
#include "Gestionnaire.h"
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
   /////////TEST POUR LE FINDTEN()
 /* Gestionnaire * a = new Gestionnaire(); 
  a->Ajouter("B","A");
  a->Ajouter("C","D");
  a->Ajouter("D","C");
 a->Ajouter("E","C"); 
  a->Ajouter("F","J");
  a->Ajouter("J","H");
  a->Ajouter("LOL","M");
  a->Ajouter("LOL","M");
  a->Ajouter("LOL","M");
  a->Ajouter("LOL","M");
  a->Ajouter("LOL","M");
  a->Ajouter("LOL","O");
  a->Ajouter("LOL","P");
  a->Ajouter("LOL","Q");
  a->Ajouter("LOL","R");
  a->Ajouter("LOL","S");
  a->Ajouter("LOL","Sddw");
  a->Ajouter("LOL","Sddw");
  a->Afficher();
  a->FindTen();
  delete a;
  */
 /*LogRead abc("anonyme.log");
 cout << abc.getNumberOfLines() << endl;*/
 Gestionnaire * a = new Gestionnaire;
 a->chargerLog("anonyme.log",0,0,0);
 a->FindTen();
  delete a;
  /* // Exemple de cutter
  
  /*Renseignement r("MonReferer");
  r.Ajouter("deuxiemeReferer");        cout <<"Ajout du referer "<<referer<<endl;
  r.Ajouter("TroisiemeReferer");
  r.Ajouter("deuxiemeReferer");

  unsigned int nbhit = r.getHit();
  unsigned int i = r.getHitReferer("deuxiemeReferer");
  unsigned int j = r.getHitReferer("kdchzc");

  /*LogRead log("test.log");
  string uneLigne = log.getLine(5);
  cout << "nb hit total : " << nbhit << endl << "nbhit deuxiemeReferer : " << i << endl;
  cout << "nbhit referer absent : " << j << endl;
  string nameLogFile;
  string nameDotFile;
  char tabParam[] = {'0','0','0'};
  int positionTabParam =0;
  int hour = -1; // heure laissée à -1 si pas de 

  bool requete = true;

  if(argc == 1 )        // pas de nom de fichier passé en paramètre
  {
    cout << *deb << endl;
    deb++;
  }*/


/*  LogRead log("anonyme.log");
  string uneLigne = log.getLine(8);
      requete = false;
  }
  else
  {
    for (int i = 1 ; i< argc ; ++i)
    {
      if(i == argc - 1) // permet de vérifier conformité du fichier .log donné en paramètre
      {
        if(strcmp((getExtension(argv[i])).c_str(),"log") != 0)
        {
          requete = false;
          break;
        }
        else
        {
          nameLogFile = argv[i];
        }
      } 
      else if(strcmp(argv[i], "-e") == 0) // test -e passé en paramètre
      {
        tabParam[positionTabParam] = 'e';
        positionTabParam++;
      }
      else if (strcmp (argv[i], "-g") == 0) // test -g passé en paramètre et cherche nom fichier
      {
        if( (i + 1) < argc -1 && strcmp((getExtension(argv[i + 1])).c_str(),"dot") == 0) // le suivant est un fichier .dot conforme
        {
          nameDotFile = argv[++i];
        }
        else if ( (i+1) < argc -1 && strcmp(getExtension(argv[i + 1]).c_str(),"" ) == 0)
        {
          nameDotFile = "Default.log";
        }
        else if ( (i+1 < argc -1))
        {
          requete = false;
          break;
        }

        tabParam[positionTabParam] = 'g';
        positionTabParam++;

  string referer = decoupe.getReferer();
  cout << "test de découpe Referer : " << endl << referer << endl;
  
  int hour = decoupe.getHour();
  cout << "On affiche l'heure : " << hour << endl;*/
  /*string extension = decoupe.getExtension();
  cout << "extension : " << extension << endl;*/


  /*if(argc == 1)
      }
      else if(strcmp (argv[i], "-t") == 0) // test -t passé en paramètre et chercher heure associée
      {
        string heure = argv[i+1];
        char dizaine = heure[0];
        char unite = heure[1];
        
        if (heure.size() != 2 || dizaine > '2' || dizaine < '0' || unite > '9' || unite < '0' ) // vérifie la conformité de l'heure 
        {
          requete =false;
          break;
        }
        else
        {
          tabParam[positionTabParam] = 't';
          positionTabParam++;
          hour = atoi(argv[++i]);
        }
        
      }
      else // option inconnue
      {
        requete = false;
        break;
      }
      
    }
  }
  
  if(!requete)
  {
    printManual();
  }
  else
  {
    requeteCatalogue (nameLogFile, tabParam, hour, nameDotFile);
  }
  
  return 0;
} //------ Fin de main

void printManual()
{
  cout << "-----MANUEL-------" << endl;
  /*cout << endl << "NAME" << endl;
  cout << "    analog - Analyse de log" << endl << endl;
  cout << "SYNOPSIS" << endl;
  cout << "    ./analog [OPTION]....Namefile.log" << endl << endl;
  cout << "DESCRIPTION" << endl;
  cout << "    -g Namefile.dot, --export-to-GraphViz-if-not-mentionned-export-in-default.log" << endl << endl;
  cout << "    -t HOUR (HH-2-DIGITS), --include-query-within-hour-hour+1" << endl << endl;
  cout << "    -e,        --exclude-image-css-javascript" << endl << endl;
  cout << "EXAMPLES" << endl;
  cout << "    ./analog nomFichier.log" << endl;
  cout << "               affiche sur la console les 10 documents les plus consultes dans nomFichier.log" << endl << endl;
  cout << "    ./analog -e -g nomFichier.dot nomFichier.log" << endl;
  cout << "               ignore les extensions image-css-javascript + generate GraphViz file" << endl << endl;
  cout << "AUTHORS" << endl;
  cout << "     Written by Ludovic RICHOUX and Adonis KATTAN" << endl << endl;*/
} //------ Fin de printManual

string getExtension (string nomFichier)
{
  // string:: npos si on trouve pas
  string extension;
  size_t position = nomFichier.find_last_of("."); 

  if(position == string::npos)
  {
    extension = "";
  }
  else
  {
    extension = nomFichier.substr(position + 1);
  }
    
  return extension;
}//--------- Fin de getExtension

void requeteCatalogue(string nomLog, char param[], int heure, string nomFichierGraph)
{
  // si les options sont pas demandées: hour =-1, nomFichierGraph ="", et tabParam = [0]
  cout << "execution de la requete avec param demandé" << endl;

}//---------- Fin de requete Catalogue