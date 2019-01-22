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
void Cutter::setlogLine(string uneLigne)
{
    logLine = uneLigne;
}//---------- Fin de la méthode setlogLine

string Cutter::getDate()
{
    int debutDate = logLine.find_first_of('[') + 1;
    int finDate = logLine.find_first_of(' ',debutDate);
    int dateLength = finDate - debutDate;
    string date = logLine.substr(debutDate,dateLength);
    return date;
} //----- Fin de Méthode getDate

string Cutter::getCible()
{
    int debutReq = logLine.find_first_of('"') + 1;
    int finReq = logLine.find_first_of('"' , debutReq);

    int debutCible  = logLine.find_first_of('/', debutReq);
    int finCible = logLine.find_last_of(' ', finReq);

    int cibleLength = finCible - debutCible;
    string cible = logLine.substr(debutCible,cibleLength);
    return cible;
} //----- Fin de Méthode getCible

string Cutter::getReferer()
{
    int debutReq = logLine.find_first_of('"') + 1;
    int finReq = logLine.find_first_of('"' , debutReq);
    
    int debutReferer = logLine.find_first_of('"',finReq + 1) + 1;
    int finReferer = logLine.find_first_of('"', debutReferer);
    string referer = logLine.substr(debutReferer, finReferer - debutReferer);
    return referer;
} //----- Fin de Méthode getReferer

int Cutter::getHour()
{
    string date = getDate();
    cout << date << endl;
    string hour = date.substr(12,2);
    int heure = stoi(hour);
    return heure;
}//----- Fin de la méthode getHour

string Cutter::getExtension()
{
    string cible = getCible();
    int positionPoint = cible.find_last_of('.') + 1;
    int posFinChaine = cible.size();

    string extension = cible.substr(positionPoint, posFinChaine-positionPoint);
    return extension;
}//----- Fin de la méthode getExtension

//----------------------------------------------------- Constructeurs - Destructeurs
Cutter::Cutter (string lignelog )
{
#ifdef MAP
    cout << "Appel au constructeur de <Cutter>" << endl;
#endif

    logLine = lignelog;
} //----- Fin de Cutter


Cutter::~Cutter ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Cutter>" << endl;
#endif
} //----- Fin de ~Cutter


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
