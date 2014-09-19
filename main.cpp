#include <iostream>
#include <cmath>

#include "SolarSystem.h"

int main(int argc, char** argv)
{
   // Création du systeme
	Solar_system solar_system;
   solar_system.addStatic(Planet("Sun", 1.3271244004193938e11, 6.963e5, 0, 0));
   solar_system.addPlanet("Earth", 398600.440, 6371.01);

   // Initialisation
   std::cout << "Lapin" << std::endl;
	return 0;
}
