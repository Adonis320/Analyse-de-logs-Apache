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
#include <cstring>
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
    map<string,Renseignement*>::iterator end = Table_Cibles->end();
    position = Table_Cibles->find(cible);

    if(position == end)
    {
        Renseignement * rens = new Renseignement(referer);
        Table_Cibles->insert(pair<string,Renseignement*>(cible,rens));
    }
    else
    {   
        position->second-> Ajouter(referer);
    }
} //------Fin de Ajouter

void Gestionnaire::Afficher()
{
    map<string,Renseignement*>::iterator debut;
    map<string,Renseignement*>::iterator fin;
    debut = Table_Cibles->begin();
    fin =  Table_Cibles->end();
    while(debut != fin)
    {
        cout << "Cible : " << debut->first <<endl;
        debut->second->Affiche();
        debut++;
    }
} //-----Fin de Afficher

void Gestionnaire::FindTen() //ATTENTION ON SUPPRIME LES 10 elements
{   
    unsigned int nb_elements = Table_Cibles->size();
    cout<<"TAILLE = "<< nb_elements << endl;
    unsigned int iterations = 10;
    if(nb_elements < 10)
    {
        iterations = nb_elements;
    }
    cout <<"ITER = " << iterations << endl;
    map<string,Renseignement*>::iterator element;
    map<string,Renseignement*>::iterator end;
    unsigned int max = 0;
    element = Table_Cibles -> begin();
    end = Table_Cibles -> end();
  
    int cond1 = 1;
    int cond2 = 1;
    unsigned int it = 0;
    while(it < iterations)
    {  
        element = Table_Cibles->begin();
        end = Table_Cibles -> end();
        max = 0;
        while(element != end && cond1 == 1)
        {   
            if((element->second)->getHit() >= max)
            {
                max = (element->second)->getHit();
            }
            element++;
            if(Table_Cibles->size() == 1)
            {
                cond1 = 0;
            }

        }
        element = Table_Cibles->begin();
        while(element != end && cond2 == 1)
        {   
            if(Table_Cibles->size() == 1)
            {   
                it ++;
                cout << it << " /"<< element -> first << " (" << element->second->getHit() << " hits)" << endl;
                delete element->second;
                Table_Cibles->erase(element);
                cond2 = 0;
                break;
            }
            if((element->second)->getHit() == max)
            {
                it++;
                cout << it << " /"<< element -> first << " (" << element->second->getHit() << " hits)" << endl;
                delete element->second;
                Table_Cibles->erase(element);
                element = Table_Cibles->begin();
                end = Table_Cibles -> end();
                if(it >= iterations)
                {
                    break;
                }
            }
            if(it >= iterations)
            {
                break;
            }
            element++;
        }
    }
    //on a mis les 10 ou x elements dans une nouvelle map + on les a retire de la map initiale
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
    map<string,Renseignement*>::iterator deb, fin;
    deb = Table_Cibles->begin();
    fin = Table_Cibles->end();
    while(deb != fin)
    {
        delete deb->second;
        deb++;
    }
    delete Table_Cibles;
} //----- Fin de ~Gestionnaire


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
