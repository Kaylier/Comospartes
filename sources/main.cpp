#include <iostream>
#include <cmath>

#include "systeme_solaire.h"

int main(int argc, char** argv)
{
   // Création du systeme
   Systeme_Solaire system;
                   // nom       GM                      rayon       fixe=false
   system.add_planet("Soleil" , 1.3271244004193938e11 , 6.963e5   , true);
   system.add_depart("Terre"  , 398600.440            , 6371.01);
   system.add_planet("Mercure", 22032.09              , 2440);
   system.add_planet("Vénus"  , 324858.63             , 6051.8);
   system.add_planet("Mars"   , 42828.3               , 3389.9);
   system.add_planet("Jupiter", 126686511             , 66854);
   system.add_planet("Saturne", 37931207.8            , 54364);
   system.add_planet("Uranus" , 5793966               , 24973);
   system.add_planet("Neptune", 6835107               , 24342);
   

   std::vector<Dynamique> best_trajectoire_ever = system.optimiser_trajet();

   std::cout << "Lapin" << std::endl;
	return 0;
}
