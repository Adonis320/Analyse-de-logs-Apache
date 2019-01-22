/*************************************************************************
                           Renseignement  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Richoux Ludovic
    e-mail               : ludovic.richoux@insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Renseignement> (fichier Renseignement.h) ----------------
#if ! defined ( RENSEIGNEMENT_H )
#define RENSEIGNEMENT_H

//--------------------------------------------------- Interfaces utilisées
#include <map>
#include <list>
#include <string>
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Renseignement>
// Cette classe contient les informations concernant une cible donnée
//------------------------------------------------------------------------

class Renseignement
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void Affiche();
    // Mode d'emploi :
    //      Permet l'affichage du nombre de hit total ainsi que les 
    //      paires clés valeurs de la map
    // Contrat :
    //      Aucun

    void Ajouter(string referer);
    // Mode d'emploi
    //      Si le referer est déjà présent, on modifie le 
    //      nombre de hit, sinon on ajoute le referer
    //      et met à jour le nombre de hit total de la cible
    // contrat
    //      aucun

    unsigned int getHit();
    // Mode d'emploi
    //      renvoie le nombre de hit total
    // contrat:
    //      Aucun

    unsigned int getHitReferer(string referer);
    // Mode d'emploi :
    //      renvoie le nombre de hit associé au referer passé en paramètre
    //      renvoie 0 si le referer n'existe pas
    // contrat :
    //      aucun

    list<string> getReferer();
    // Mode d'emploi :
    //      récupère tous les referer et les place dans la liste
    // contrat : 
    //      aucun

//-------------------------------------------- Constructeurs - destructeur
    Renseignement (string referer);
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
	unsigned int nbHitTotal;
	map <string, int> * tabReferer;
};

//-------------------------------- Autres définitions dépendantes de <Renseignement>

#endif // RENSEIGNEMENT_H

