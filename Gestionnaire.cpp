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
#include "Renseignement.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Gestionnaire::Ajouter(string referer, string cible)
{
    map<string,Renseignement*>::iterator position;
    map<string,Renseignement*>::const_iterator end = Table_Cibles->cend();
    position = Table_Cibles->find(cible);

    if(position == end)
    {
        Renseignement * rens = new Renseignement(referer);
        Table_Cibles->insert(pair<string,Renseignement*>(cible,rens));
    }
    else if (position != end)
    {
        (position->second) -> Ajouter(referer);
    } 
} //------Fin de Ajouter

void Gestionnaire::FindTen()
{   
    map<string,Renseignement*>::iterator element;
    map<string,Renseignement*>::iterator end;
    int max = 0;
    element = Table_Cibles -> begin();
    end = Table_Cibles -> end();
    while(element != end)
    {
        if((element->second)->getHit > max)
        {
            max = (element->second)->getHit -> first;
        }
    }
} //----Fin de FindTen
//pour afficher les 10 premiers il faut creer une autre map 

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
    Table_Cibles = new map <string,Renseignement*>;
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
