#ifndef SYSTEME_SOLAIRE_H
#define SYSTEME_SOLAIRE_H

#include <string>
#include <vector>
#include "coord.h"
#include "structs.h"

#include "objectif.h"
#include "situation.h"

#define TEMPS_MIN 2457023  // correspond au 1er janvier 2015
#define TEMPS_MAX 2469807 // correspond au 1er janvier 2050, date limite

class Systeme_Solaire
{
protected:
   std::vector<Planete*> _planetes;
   Situation _situation;
   Planete* _depart;
public:
   Objectif _objectif;

public:
   Systeme_Solaire();
   ~Systeme_Solaire();

   std::vector<Planete*> get_planets() const;
   Planete* add_planet(Planete* planete);
   Planete* add_planet(std::string nom, double gm, double rayon);
   Planete* add_depart(Planete* planete);
   Planete* add_depart(std::string nom, double gm, double rayon);
   void rmPlanet(Planete* planete);

   std::vector<Coord<3> > get_pos(Planete* planete);

   Dynamique& actualiser_dynamique(Dynamique& dyn);
   std::vector<Dynamique> calculer_trajectoire(Dynamique condition_initiale);
   double estimer_trajectoire(Dynamique condition_initiale);
   std::vector<Dynamique> optimiser_trajet(Dynamique condition_initiale); // cherche la meilleure trajectoire (condition_initiale est la base de la recherche)
};


#endif // SYSTEME_SOLAIRE_H
