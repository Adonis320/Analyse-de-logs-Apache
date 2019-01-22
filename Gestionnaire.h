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
#include <string>
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

    void Gestionnaire::Ajouter(Renseignement * rens, string cible);

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
    map < string, Renseignement * > Table_Cibles;
};

//-------------------------------- Autres définitions dépendantes de <Gestionnaire>

#endif // GESTIONNAIRE_H
