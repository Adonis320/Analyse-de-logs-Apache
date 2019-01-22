/*************************************************************************
                           Gestionnaire  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Gestionnaire> (fichier Gestionnaire.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Gestionnaire.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Gestionnaire::Ajouter(Renseignement * rens, string cible)
{
    iterator it_recherche = mymap.find(cible);

    if(it_recherche = )
     
}

//------------------------------------------------- Surcharge d'opérateurs
///Xxx & Xxx::operator = ( const Xxx & unXxx )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Gestionnaire::Gestionnaire ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Gestionnaire>" << endl;
#endif
} //----- Fin de Gestionnaire


Gestionnaire::~Gestionnaire ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Gestionnaire>" << endl;
#endif
} //----- Fin de ~Gestionnaire


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
