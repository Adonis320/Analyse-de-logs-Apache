/*************************************************************************
                           Gestionnaire  -  description
                             -------------------
    début                : 15 janvier 2019
    copyright            : (C) 2019 par Kattan Adonis & Richoux Ludovic
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
// Rôle de la classe <Gestionnaire>
// Cette classe permet de stocker les cibles et les "Renseignement"
// donc le nombre de hit total par cible, les refereurs et le nombre de hit
// par refereur et par cible. Elle possede des methodes qui permettent l'affichage
// des cibles et de leurs refereurs ainsi que le nombre de hits, une methode
// qui permet de recuperer les 10 premieres cibles les plus consultees, 
// ainsi qu'une methode qui permet de charger les informations d'un fichier .log
// et une autre methode qui permet de creer un fichier .dot
//
//------------------------------------------------------------------------

class Gestionnaire
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void Ajouter(string referer, string cible);
    // Mode d'emploi :  ajoute un refereur et une cible au gestionnaire
    //                  en fonction de la presence ou non 
    //                  de la cible et du refereur dans le gestionnaire 
    //
    // Contrat : aucun
    //

    void Afficher();
    // Mode d'emploi : affiche la cible et le nombre de hit total, fait appel 
    //                 a la methode Affiche() de Renseignement pour afficher
    //                 les refereurs et le nombre de hit par refereur 
    //
    // Contrat : aucun
    //
    
    void chargerLog(string nomFic, int optException, int optHeure, int heure);
    // Mode d'emploi : permet de charger un fichier.log dans le gestionnaire en 
    //                 fonction des parametres
    //
    // Contrat : aucun
    //
    
    void FindTen();
    // Mode d'emploi : permet d'afficher les 10 cibles les plus consultees
    //
    // Contrat : attention, supprime les 10 elements du gestionnaire, il faut
    //           donc utiliser cette methode en dernier (apres l'export en .dot)
    //

    void exportDot(string nomFic);
    // Mode d'emploi : exporte le gestionnaire dans un fichier .dot selon 
    //                 les conventions de graphviz
    //
    // Contrat : aucun
    //
    
//-------------------------------------------- Constructeurs - destructeur
    Gestionnaire ( );
    // Mode d'emploi : cree un gestionnaire
    //              
    // Contrat : aucun
    //

    virtual ~Gestionnaire ( );
    // Mode d'emploi : destructeur de gestionnaire
    //
    // Contrat : aucun
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
    map < string, Renseignement *>  *Table_Cibles;
};

//-------------------------------- Autres définitions dépendantes de <Gestionnaire>

#endif // GESTIONNAIRE_H
