#ifndef SYSTEME_SOLAIRE_H
#define SYSTEME_SOLAIRE_H

#include <string>
#include <vector>
#include "coord.h"

struct Dynamique
{
   Coord<3> position;
   Coord<3> vitesse;
   double temp;
};

struct Planete
{
   std::string nom;
   double gm; // paramètre gravitationnel standard
   double rayon; // pour les collisions
   bool fixe;
};

class System_Solaire
{
protected:
   std::vector<Planete*> _planetes;
   // _positions_planetes; // une super classe gérant synchro avec base de donnée, calcul de position... à la demande !
   Planete* _depart;
   // _objectif; // fonction evaluant la proximité de l'objectif

public:
   Systeme_Solaire();
   ~Systeme_Solaire();
   
   std::vector<Planete*> get_planets();
   Planete* add_planet(Planete* planete);
   Planete* add_planet(std::string nom, double gm, double rayon, bool fixe=false);
   Planete* add_depart(Planete* planete);
   Planete* add_depart(std::string nom, double gm, double rayon, bool fixe=false);
   void rmPlanet(Planete* planet);

   double estimer_trajectoire(Dynamique condition_initiale);
   std::vector<Dynamique> optimiser_trajet(Dynamique condition_initiale); // cherche la meilleure trajectoire (condition_initiale est la base de la recherche)

protected: // Fonctions utiles en interne
   Coord<3> getForce(Coord<3> point, Planete astre); // renvoi la force d'un astre en un point
   Coord<3> getForce(Coord<3> point); // renvoi la force en point (prend tous les astres en compte)

};

#endif // SYSTEME_SOLAIRE_H
