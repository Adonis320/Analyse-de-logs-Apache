/*************************************************************************
                           Cutter  -  description
                             -------------------
    début                : 19 janvier 2019
    copyright            : (C) 2019 par Ludovic Richoux
    e-mail               : ludovic.richoux@laposte.net
*************************************************************************/

//---------- Interface de la classe <Cutter> (fichier Cutter.h) ----------------
#if ! defined ( CUTTER_H )
#define CUTTER_H

//--------------------------------------------------- Interfaces utilisées
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Cutter>
//      La classe Cutter permet de récupérer certaines informations comme la date, 
//      la cible... depuis une ligne d'un log.
//------------------------------------------------------------------------

class Cutter
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getDate();
    // Mode d'emploi :
    //
    // Contrat :
    //

    string getCible();
    // Mode d'emploi
    //
    // contrat :
    //

    string getReferer();
    // Mode d'emploi
    //
    // contrat :
    //

//-------------------------------------------- Constructeurs - destructeur

    Cutter (string logLine );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Cutter ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    string log;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // CUTTER_H
