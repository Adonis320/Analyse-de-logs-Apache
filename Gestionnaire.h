/*************************************************************************
                           Gestionnaire  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Gestionnaire> (fichier Gestionnaire.h) ----------------
#if ! defined ( GESTIONNAIRE_H )
#define GESTIONNAIRE_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include "Renseignement.h"
#include <cstring>
#include "Cutter.h"
#include "LogRead.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Xxx>
//
//
//------------------------------------------------------------------------

class Gestionnaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Ajouter(string referer, string cible);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void Afficher();
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void chargerLog(string nomFic, int optException, int optHeure, int heure);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    void FindTen();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void exportDot(string nomFic);
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs
  //  Xxx & operator = ( const Xxx & unXxx );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Gestionnaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Gestionnaire ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map < string, Renseignement * > * Table_Cibles;
};

//-------------------------------- Autres définitions dépendantes de <Gestionnaire>

#endif // GESTIONNAIRE_H
