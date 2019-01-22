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
void Renseignement::Affiche()
{
    cout << "nb de hit total : " << nbHitTotal << endl;
    map<string,int>::iterator debut, fin;
    
    debut = tabReferer->begin();
    fin = tabReferer->end();

    while(debut!=fin)
    {
        cout << debut->first << " " << debut->second << endl;
        debut++;
    }

    cout << endl;
} //----- Fin de Méthode Affiche

void Renseignement::Ajouter(string referer)
{
    map<string,int>::iterator position;
    map<string,int>::const_iterator end = tabReferer->cend();
    position = tabReferer->find(referer);

    if(position == end)
    {
        tabReferer->insert(pair<string, int>(referer,1));
    }
    else
    {
        position->second = position->second + 1;
    }
    nbHitTotal++;
}//------ Fin de la méthode Ajouter

unsigned int Renseignement::getHit()
{
    return nbHitTotal;
}//----- Fin de la méthode getHit

//-------------------------------------------- Constructeurs - destructeur

Renseignement::Renseignement (string referer)
{
#ifdef MAP
    cout << "Appel au constructeur de <Renseignement>" << endl;
#endif
    nbHitTotal = 1;
    tabReferer = new map<string,int>;
    tabReferer->insert(pair<string, int>(referer,1));
} //----- Fin de Renseignement


Renseignement::~Renseignement ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Renseignement>" << endl;
#endif
    delete tabReferer;

} //----- Fin de ~Renseignement


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

