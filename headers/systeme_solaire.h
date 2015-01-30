#ifndef SYSTEME_SOLAIRE_H
#define SYSTEME_SOLAIRE_H

#include <iostream>
#include <string>
#include <vector>
#include "coord.h"
#include "structs.h"

#define TEMPS_MIN 2457023//2457023  // correspond au 1er janvier 2015
#define TEMPS_MAX 2469807 //  2469807 // correspond au 1er janvier 2050, date limite

#define GM_TYPE 10E18
#define ERR_DT (0.05 * sqrt(GM_TYPE))

#include "objectif.h"
#include "situation.h"

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
   Systeme_Solaire(double tInitial, std::map<Planete*, Cinematique>& sitInital, double pasInitial=1./48);
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
