/*************************************************************************
                           Renseignement  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Richoux Ludovic et Kattan Adonis
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Renseignement> (fichier Renseignement.h) ----------------
#if ! defined ( RENSEIGNEMENT_H )
#define RENSEIGNEMENT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Renseignement>
//
//
//------------------------------------------------------------------------

class Renseignement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

//-------------------------------------------- Constructeurs - destructeur
    Renseignement ( const Renseignement & UNRenseignement );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Renseignement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Renseignement ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Renseignement>

#endif // RENSEIGNEMENT_H

