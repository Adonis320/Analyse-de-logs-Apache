/*************************************************************************
                           Cutter  -  description
                             -------------------
    début                : 19 janvier 2019
    copyright            : (C) 2019 par Ludovic Richoux
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Cutter> (fichier Cutter.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <string>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Cutter.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
string Cutter::getDate()
{
    int debutDate = log.find_first_of('[') + 1;
    int finDate = log.find_first_of(']',debutDate);
    int dateLength = finDate - debutDate;
    string date = log.substr(debutDate,dateLength);
    return date;
} //----- Fin de Méthode getDate

string Cutter::getCible()
{
    int debutReq = log.find_first_of('"') + 1;
    int finReq = log.find_first_of('"' , debutReq);

    int debutCible  = log.find_first_of('/', debutReq);
    int finCible = log.find_last_of(' ', finReq);

    int cibleLength = finCible - debutCible;
    string cible = log.substr(debutCible,cibleLength);
    return cible;
} //----- Fin de Méthode getCible

string Cutter::getReferer()
{
    int debutReq = log.find_first_of('"') + 1;
    int finReq = log.find_first_of('"' , debutReq);
    
    int debutReferer = log.find_first_of('"',finReq + 1) + 1;
    int finReferer = log.find_first_of('"', debutReferer);
    string referer = log.substr(debutReferer, finReferer - debutReferer);
    return referer;
} //----- Fin de Méthode getReferer

Cutter::Cutter (string logLine )
{
#ifdef MAP
    cout << "Appel au constructeur de <Cutter>" << endl;
#endif

    log = logLine;
} //----- Fin de Cutter


Cutter::~Cutter ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cutter>" << endl;
#endif
} //----- Fin de ~Cutter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
