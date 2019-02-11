/*************************************************************************
                           Gestionnaire  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 Kattan Adonis & Richoux Ludovic
    e-mail               : ludovic.richoux@insa-lyon.fr
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

void Gestionnaire::Ajouter(string referer, string cible)
// Algorithme : Verifie l'existence de la cible, et en fonction verifie
//              fait appel a la methode ajouter de Renseignement
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
// Algorithme : parcourt tous les elements de la map et les affiche,
//              fait aussi appel a la methode Affiche() du second element
//              de la map 
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

void Gestionnaire::FindTen() 
// Algorithme : parcourt toute la Table_Cibles et trouve le max de nbHits,
//              refait un second parcours, affiche le max et la cible, puis le supprime
//              de la map
{   
    unsigned int nb_elements = Table_Cibles->size();
    unsigned int iterations = 10;
    if(nb_elements < 10) // 10 iterations si plus de 10 elements, sinon meme nb d'elements
    {
        iterations = nb_elements;
    }
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
        while(element != end && cond1 == 1) //on trouve les valeurs max de nbHitTotal
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
        while(element != end) // on cherche les cibles qui ont nbHitTotal = max
        {   
            if((element->second)->getHit() == max)
            {
                it++;
                cout << it << " /"<< element -> first << " (" << element->second->getHit() << " hits)" << endl;
                delete element->second;
                Table_Cibles->erase(element);
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
// Algorithme : en fonction des parametres, recupere une ligne du fichier, si conforme en cree
//              une instance dans la map
{
    LogRead log(nomFic);
    string s = log.getLine();
    Cutter cut ("");
    
    int charger;
    int heureLog;
    while (strcmp(s.c_str(), "") != 0)
    {
        cut.setlogLine(s);
        charger = 1;
        if(optException == true) // exclure les extensions
        {
            string extension = cut.getExtension();
            if(extension.compare("css") == 0 || extension.compare("js") == 0 || extension.compare("png") == 0 ||
            extension.compare("jpg") == 0 || extension.compare("gif") == 0 || extension.compare("bmp") == 0 ||
            extension.compare("ico") == 0) 
            {
                charger = 0;
            }
        }
        if (optHeure == true && charger == 1)
        {
            heureLog = cut.getHour();
            if (heureLog != heure)
            {
                charger = 0;
            }
        }
        if(charger == 1)
        {
            Ajouter(cut.getReferer(),cut.getCible());
        }
        s = log.getLine();
    }
} //-----Fin de chargerLog

void Gestionnaire::exportDot(string nomFic)
// Algorithme : parcourt la map, exporte dans un fichier.dot les cibles et les refereurs
//              puis le nombre de hits par couple de cibles-refereurs 
//
{
    ofstream outFile;
    outFile.open(nomFic, ios::out | ios::trunc);
    set <string> noms; //contient toutes les cibles et referers deja exportes
    char commas = 34; // commas: "
    if (outFile.is_open()) 
    {
        outFile << "digraph {" << endl;
        
        map<string,Renseignement*>::iterator deb, fin;
        deb = Table_Cibles->begin();
        fin = Table_Cibles->end();
        list<string>::iterator debRens, finRens;
        while(deb!=fin)
        {
            list <string> * listeReferer = new list <string> (deb->second->getReferer());
            // la liste qui contient tous les referers pour une cible donnee
            debRens = listeReferer->begin();
            finRens = listeReferer->end();
            set <string>::iterator pos, finNoms;
            finNoms = noms.end();
            pos = noms.find(deb->first);
            if(pos == finNoms)
            {
                outFile << commas << deb->first << commas <<";" << endl;
                noms.insert(deb->first);
            }
            while(debRens != finRens) // on ecrit les noeuds
            {
                pos = noms.find(*debRens);
                if(pos == finNoms)
                {
                    outFile << commas << *debRens << commas << ";" << endl;
                    noms.insert(*debRens);
                }
                outFile << commas << *debRens << commas << " -> " << commas << deb->first << commas <<" [label=" << commas;
                outFile << deb->second->getHitReferer(*debRens) << commas << "];" << endl;
                debRens++;
            }
            delete listeReferer;
            deb++;
        }
        outFile << "}" << endl;
    }
    else
    {
        cerr << "Erreur lors de l'ouverture du fichier .dot"<<endl;
    }
} //----- Fin de exportDot

//-------------------------------------------- Constructeurs - destructeur
Gestionnaire::Gestionnaire ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Gestionnaire>" << endl;
#endif
    Table_Cibles = new map <string,Renseignement*>;
} //----- Fin de Gestionnaire


Gestionnaire::~Gestionnaire ( )
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
