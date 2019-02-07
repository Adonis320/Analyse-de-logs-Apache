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
#include <fstream>
#include <set>
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
        while(element != end)
        {   
            if(Table_Cibles->size() == 1)
            {   
                it ++;
                cout << it << " /"<< element -> first << " (" << element->second->getHit() << " hits)" << endl;
                delete element->second;
                Table_Cibles->erase(element);
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
} //----Fin de FindTen


void Gestionnaire::chargerLog(string nomFic, int optException, int optHeure, int heure)
{
    LogRead monLogRead(nomFic);
    unsigned int nbLignes = monLogRead.getNumberOfLines();
    unsigned int charger = 1;
    for(unsigned int i = 1; i < nbLignes; i++)
    {   
        charger = 1;
        Cutter monCutter(monLogRead.getLine(i));
        if(optException != 0)
        {
            string extension = monCutter.getExtension();
            if(extension.compare("html") != 0) //ATTENTION est-ce qu'on garde autre chose que html ?
            {
                charger = 0;
            }
        }
        if (optHeure != 0 && charger == 1)
        {
            int heureLog = monCutter.getHour();
            if (heureLog != heure)
            {
                charger = 0;
            }
        }
        if(charger == 1)
        {
            Ajouter(monCutter.getReferer(),monCutter.getCible());
        }
    }
} //-----Fin de chargerLog

void Gestionnaire::exportDot(string nomFic)
{
    ofstream outFile;
    outFile.open(nomFic, ios::out | ios::trunc);
    set <string> noms;
    if (outFile.is_open()) 
    {
        outFile << "digraph {" << endl;
        
        map<string,Renseignement*>::iterator deb, fin;
        deb = Table_Cibles->begin();
        fin = Table_Cibles->end();
        while(deb!=fin)
        {
            //TODO 
            // IL Faut exporter tous les referants et les cibles dans le fichier + 
            // faire les nodes, je pense utiliser deux iterators, et stocker les cibles 
            // et les referants dans un set pour eviter les redondances
         /*   if(noms.find(deb->first) == end)
            {
                outFile << deb->first <<";" << endl;
                noms.insert(deb->first);
            }
            deb++; */
        }
        outFile << "}" << endl;
    }
    else
    {
        cout << "Erreur lors de l'ouverture du fichier .dot"<<endl;
    }
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
