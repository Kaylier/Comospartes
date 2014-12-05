#ifndef SITUATION_H
#define SITUATION_H
#include <map>
#include "coord.h"
#include "structs.h"


class Situation
   {
   protected:
      std::map<double, std::map<Planete*, Cinematique> > Position; //Système
      double pas;

   public:
      Situation();
      Situation(double tInital, std::map<Planete*, Cinematique> sitInital, double pasInitial);
      double tempsproche(double temps);
      void ajouterTemps(double temps); //Ajoute l'ensemble des coordonées à un temps voulu
      Coord<3> getForce (Coord<3>, double temps);// Forces s'appliquant en un point
      std::vector < Coord<3> > getPosis (Planete* planete);
      Cinematique& getCinem (Planete* planete, double temps);

   };


#endif
