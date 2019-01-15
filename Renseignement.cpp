/*************************************************************************
                           Renseignement  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Richoux Ludovic et Kattan Adonis
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Renseignement> (fichier Renseignement.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Renseignement.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Renseignement::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//-------------------------------------------- Constructeurs - destructeur
Renseignement::Renseignement ( const Renseignement & unRenseignement )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Renseignement (constructeur de copie)


Renseignement::Renseignement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Renseignement


Renseignement::~Renseignement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Renseignement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

