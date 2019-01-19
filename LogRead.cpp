/*************************************************************************
                           LogRead  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Richoux LUdovic
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LogRead> (fichier LogRead.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LogRead.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string LogRead::getLine(unsigned int numLine)
{
    char * tampon = new char [500+1];
    ifstream log;
    log.open(nomFichier.c_str());
    string ligne;
    if(log.is_open())
    {
        for(unsigned int i=1; i<=numLine;++i)
        {
            log.getline(tampon,500);
        }
        ligne = string(tampon);
    }
    else
    {
        cerr << "Problème lors de l'ouverture du fichier" << endl;
    }
    delete [] tampon;
    return ligne;
}//-------Fin de la méthode getLine

//-------------------------------------------- Constructeurs - destructeur

LogRead::LogRead (string nomFic )
{
#ifdef MAP
    cout << "Appel au constructeur de <LogRead>" << endl;
#endif
    nomFichier = nomFic;
} //----- Fin de LogRead


LogRead::~LogRead ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <LogRead>" << endl;
#endif
} //----- Fin de ~LogRead


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

