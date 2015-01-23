#include <iostream>
#include <map>
#include <cmath>

#include "../headers/structs.h"
#include "../headers/systeme_solaire.h"
#include "../headers/simple_svg_1.0.0.hpp"

svg::Polyline vector_to_polyline(std::vector<Coord<3> > vect);

int main(int argc, char** argv)
{
   // Création du systeme
   std::map<Planete*, Cinematique> planetes; // conteneur des planetes
   Planete* ptest1 = new Planete("Sun", 9.906930564e20, 6.963e5);
   Planete* ptest2 = new Planete("Neptune", 5.102380035072e16, 24766);
   planetes[ptest1] = Cinematique(4.129e5, -1.434e5, -2.023e4, 6.138e2, 7.752e2, -1.477e1);
   planetes[ptest2] = Cinematique(4.114e9, -1.780e9, -5.816e7, 1.833e5, 4.337e5, -1.321e4);

   Systeme_Solaire system(TEMPS_MIN, planetes, 1./48);
   system.set_depart(ptest1);
   /*
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
   */
   // lancer calcul

   //std::vector<Dynamique> best_trajectoire_ever = system.optimiser_trajet();

   // Génération de svg
   svg::Document doc("coucou.svg", svg::Layout(svg::Dimensions(1024, 1024), svg::Layout::BottomLeft, 1, svg::Point(512, 512)));

   doc << svg::Circle(svg::Point(0,0), 20, svg::Fill(svg::Color(255, 200, 0)));
   doc << vector_to_polyline(system.get_pos(ptest1));
   doc << vector_to_polyline(system.get_pos(ptest2));

   doc.save();

   // Libérations des planètes
   delete ptest1;
   delete ptest2;
   std::cout << "Lapin" << std::endl;
	return 0;
}

svg::Polyline vector_to_polyline(std::vector<Coord<3> > vect)
{
   svg::Polyline res(svg::Stroke(1, svg::Color::Blue));
   for(int i=0, n=vect.size() ; i < n ; ++i)
      res << svg::Point(vect[i][0]/10e8, vect[i][1]/10e8);
   return res;
}

