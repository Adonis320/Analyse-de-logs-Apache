/*************************************************************************
                           LogRead  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Ludovic Richoux
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier LogRead.h) ----------------
#if ! defined ( LOGREAD_H )
#define LOGREAD_H

//--------------------------------------------------- Interfaces utilisées
#include <cstring>
#include <fstream>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <LogRead>
// La classe LogRead permet l'ouverture d'un fichier .log et permet de
// récupérer une ligne particulière de celui ci.
//------------------------------------------------------------------------

class LogRead
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    string getLine();
    // Mode d'emploi :
    //      retourne la nbLigne ième ligne du fichier nomfic, et une string vide 
    //      si on atteint la fin du fichier
    // Contrat :
    //      

//-------------------------------------------- Constructeurs - destructeur

    LogRead (string nomFic );
    // Mode d'emploi :
    //      créer un logRead
    // Contrat :
    //		Aucun

    virtual ~LogRead ( );
    // Mode d'emploi :
    //      détruit le LogRead courant
    // Contrat :
    //      aucun

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	
	ifstream log;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LOGREAD_H

