#include <iostream>
#include <cmath>

#include "SolarSystem.h"

int main(int argc, char** argv)
{
   // Création du systeme
   Solar_system solar_system;
   solar_system.addStatic(Planet("Soleil", 1.3271244004193938e11, 6.963e5, 0, 0));
   solar.system.addPlanet("Mercure",22032.09, 2440)
   solar_system.addPlanet("Vénus", 324858.63, 6051.8)
   solar_system.addPlanet("Terre", 398600.440, 6371.01);
   solar_system.addPlanet("Mars", 42828.3, 3389.9);
   solar_system.addPlanet("Jupiter", 126686511, 66854);
   solar_system.addPlanet("Saturne", 37931207.8, 54364);
   solar_system.addPlanet("Uranus", 5793966, 24973);
   solar_system.addPlanet("Neptune", 6835107, 24342);




   // Initialisation
   std::cout << "Lapin" << std::endl;
	return 0;
}
