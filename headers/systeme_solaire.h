#ifndef SYSTEME_SOLAIRE_H
#define SYSTEME_SOLAIRE_H

#include <iostream>
#include <string>
#include <vector>
#include "coord.h"
#include "structs.h"

#include "objectif.h"
#include "situation.h"

#define TEMPS_MIN 0//2457023  // correspond au 1er janvier 2015
#define TEMPS_MAX 496//2469807 // correspond au 1er janvier 2050, date limite

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
   Systeme_Solaire(double tInitial, std::map<Planete*, Cinematique> sitInital, double pasInitial=1./48);
   ~Systeme_Solaire();

   std::vector<Planete*> get_planets() const;
   Planete* set_depart(Planete* planete);

   std::vector<Coord<3> > get_pos(Planete* planete);

   Dynamique& actualiser_dynamique(Dynamique& dyn);
   std::vector<Dynamique> calculer_trajectoire(Dynamique condition_initiale);
   double estimer_trajectoire(Dynamique condition_initiale);
   std::vector<Dynamique> optimiser_trajet(Dynamique condition_initiale); // cherche la meilleure trajectoire (condition_initiale est la base de la recherche)
};


#endif // SYSTEME_SOLAIRE_H

