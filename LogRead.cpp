/*************************************************************************
                           LogRead  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Richoux LUdovic et Kattan Adonis
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <LogRead> (fichier LogRead.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "LogRead.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type LogRead::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

//-------------------------------------------- Constructeurs - destructeur
LogRead::LogRead ( const LogRead & unLogRead )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <LogRead>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


LogRead::LogRead (char * nomFic )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <LogRead>" << endl;
#endif
    nomFichier = new char[strlen(nomFic)];
    strcpy(nomFichier,nomFic);
    delete [] nomFic;
} //----- Fin de LogRead


LogRead::~LogRead ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <LogRead>" << endl;
#endif
    delete [] nomFichier;
} //----- Fin de ~LogRead


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

