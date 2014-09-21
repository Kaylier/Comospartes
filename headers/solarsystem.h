#ifndef SOLAR_SYSTEM_H
#define SOLAR_SYSTEM_H

#include <string>
#include <vector>
#include "Coord.h"

typedef double SGP; // Standard Gravitational Parameter, G*M
typedef double Distance;

/*struct Vect
{
   double x, y, z;
   double abs(){return sqrt(x*x+y*y+z*z);}
   double dir(){return Vect(x/abs(), y/abs(), z/abs());}
};*/ // Il faudrai définir un vrai vecteur
struct Planet
{
   std::string name;
   SGP gm;
   Distance rayon;
   Vect pos, v;
};

class Solar_system
{
protected:
   std::vector<Planet*> _static;
   std::vector<Planet*> _planet;

   Planet* _launchPlanet;
   Aim _aim; // Foncteur paramétrable dans le main

public:
   Solar_system();
   ~Solar_system();
   
   std::vector<Planet*> getStatics();
   Planet* addStatic(Planet* planet);
   void rmStatic(Planet* planet)

   std::vector<Planet*> getPlanets();
   Planet* addPlanet(Planet* planet);
   void rmPlanet(Planet* planet);

   Vect getGM(Vect pos); // 2 choix : prend en compte toutes les planetes, ou juste les spheres d'influence

   int sync(time); // synchronise les positions avec une base de donnée
   void update(int time); // Met a jour les positions des planetes
};

#endif // SOLAR_SYSTEM_H
