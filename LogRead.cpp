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
using namespace std;

//------------------------------------------------------ Include personnel
#include "LogRead.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string LogRead::getLine()
{
    string ligne;
    char * tampon = new char [1000 +1];
    log.getline(tampon,1000);
    ligne = string(tampon);
    return ligne;
}//-------Fin de la méthode getLine

//-------------------------------------------- Constructeurs - destructeur

LogRead::LogRead (string nomFic )
{
#ifdef MAP
    cout << "Appel au constructeur de <LogRead>" << endl;
#endif
    log.open(nomFic.c_str());
    if(!log.is_open())
    {
        cerr << "Problème lors de l'ouverture du fichier, le fichier spécifié peut être inexistant" << endl;
    }
    
} //----- Fin de LogRead


LogRead::~LogRead ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <LogRead>" << endl;
#endif
    log.close();
} //----- Fin de ~LogRead


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

