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
    string getLine(unsigned int numLine);
    // Mode d'emploi :
    //      retourne la nième ligne du fichier nomfic
    // Contrat :
    //      ne fonctionne pas pour un numéro de ligne égal à 0

    unsigned int getNumberOfLines();
    // Mode d'emploi :
    //      retourne le nombre total de lignes dans monFichier 
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
	
	string nomFichier;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // LOGREAD_H

