/*************************************************************************
                           LogRead  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Ludovic Richoux et Kattan Adonis
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier LogRead.h) ----------------
#if ! defined ( LOGREAD_H )
#define LOGREAD_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogRead>
//
//
//------------------------------------------------------------------------

class LogRead
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
    LogRead ( const LogRead & unLogRead );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    LogRead (char * nomFic );
    // Mode d'emploi :
    // 
    // Contrat :
    //		Aucun

    virtual ~LogRead ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
	char * nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LOGREAD_H

