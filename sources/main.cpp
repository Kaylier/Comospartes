#include <iostream>
#include <map>
#include <cmath>

#include "../headers/structs.h"
#include "../headers/systeme_solaire.h"
#include "../headers/simple_svg_1.0.0.hpp"

svg::Polyline vector_to_polyline(std::vector<Coord<3> > vect);
svg::Polyline dynamique_to_polyline(std::vector<Dynamique > vect);

int main(int argc, char** argv)
{
   // Création du systeme
   std::map<Planete*, Cinematique> planetes; // conteneur des planetes
   Planete* Soleil  = new Planete("Soleil" ,       9.906930564e20  , 6.963e5);
   Planete* Mercure = new Planete("Mercure",      164468670566400  ,  2440);
   Planete* Venus   = new Planete("Venus"  ,     2425056678604800  ,  6051.8);
   Planete* Terre   = new Planete("Terre"  ,     2975536340582400  ,  6371.01);
   Planete* Mars    = new Planete("Mars"   ,      319711546368000  ,  3389.9);
   //Planete* Jupiter = new Planete("Jupiter",   945709737154560000  , 66854);
   //Planete* Saturne = new Planete("Saturne",2.8315464897868797e17  , 54364);
   //Planete* Uranus  = new Planete("Uranus" ,    43251724431360000  , 24973);
   //Planete* Neptune = new Planete("Neptune",    5.102380035072e16  , 24766);

   planetes[Soleil]  = Cinematique( 4.25012e5 ,-1.27928e5,-2.05277e4, 5.94613e2, 4.83441e2,-1.45736e3);
   planetes[Mercure] = Cinematique( 5.08863e7 ,-3.05860e7,-7.13883e6, 1.34962e6, 3.79704e6, 1.86404e5);
   planetes[Venus]   = Cinematique( 8.26526e7 ,-7.13472e7,-5.74190e6, 1.96224e6, 2.27652e6,-8.20290e4);
   planetes[Terre]   = Cinematique(-2.51809e7 , 1.44727e8,-2.49803e4,-2.57492e6,-4.57601e5, 8.62686e1);
   planetes[Mars]    = Cinematique( 2.03257e8 ,-4.12617e7,-5.86079e6, 4.97083e5, 2.23146e6, 3.45389e4);
   //planetes[Jupiter] = Cinematique(-5.57510e8 , 5.67464e8, 1.01069e7,-8.18693e5,-7.37880e5, 2.13898e4);
   //planetes[Saturne] = Cinematique(-8.08623e8 ,-1.24915e9, 5.39015e7, 6.54975e5,-4.55960e5,-1.80870e4);
   //planetes[Uranus]  = Cinematique( 2.88822e9 , 7.85465e8,-3.45006e7,-1.58703e5, 5.40334e5, 4.04469e3);
   //planetes[Neptune] = Cinematique(   4.114e9 ,  -1.780e9,  -5.816e7,   1.833e5,   4.337e5,  -1.321e4);

   Systeme_Solaire system(TEMPS_MIN, planetes, 1./96);
   system.set_depart(Soleil);


   // PrÃ©paration du svg
   svg::Document doc("coucou.svg", svg::Layout(svg::Dimensions(1024, 1024), svg::Layout::BottomLeft, 1, svg::Point(512, 512)));

   bool continuer = true;
   while (continuer)
   {
      doc << svg::Circle(svg::Point(0,0), 20, svg::Fill(svg::Color(255, 200, 0)));
      doc << vector_to_polyline(system.get_pos(Soleil));
      doc << vector_to_polyline(system.get_pos(Mercure));
      doc << vector_to_polyline(system.get_pos(Venus));
      doc << vector_to_polyline(system.get_pos(Terre));
      doc << vector_to_polyline(system.get_pos(Mars));
      //doc << vector_to_polyline(system.get_pos(Jupiter));
      //doc << vector_to_polyline(system.get_pos(Saturne));
      //doc << vector_to_polyline(system.get_pos(Uranus));
      //doc << vector_to_polyline(system.get_pos(Neptune));
      
      // Lancement du satellite
      int x=0, y=0, z=0, vx=0, vy=0, vz=0;
      std::cout << "Quelles sont les coordonees du satellite? (x,y,z/vx,vy,vz)" << std::endl;
      std::cin >> x >> y >> z >> vx >> vy >> vz;
      std::cout << "Voulez-vous lancer un nouveau satellite (Y:1/N:0) " << std::endl;
      std::cin >> continuer;
      doc << dynamique_to_polyline(system.calculer_trajectoire(Dynamique(TEMPS_MIN,x,y,z, vx,vy,vz)));
      doc.save();
   }

   // lancer calcul
   //std::vector<Dynamique> best_trajectoire_ever = system.optimiser_trajet();
   
   // Libérations des planètes
   delete Soleil;
   delete Mercure;
   delete Venus;
   delete Terre;
   delete Mars;
   //delete Jupiter;
   //delete Saturne;
   //delete Uranus;
   //delete Neptune;

   std::cout << "Lapin" << std::endl;
	return 0;
}

svg::Polyline vector_to_polyline(std::vector<Coord<3> > vect)
{
   svg::Polyline res(svg::Stroke(1, svg::Color::Blue));
   for(int i=0, n=vect.size() ; i < n ; i+=40)
      {res << svg::Point(vect[i][0]/10e5, vect[i][1]/10e5);
       //  std::cout << vect[i][0] << "  " << vect[i][1] << std::endl;
   }return res;


}

svg::Polyline dynamique_to_polyline(std::vector<Dynamique > dyn)
{
   svg::Polyline res(svg::Stroke(1, svg::Color::Red));
   for(int i=0, n=dyn.size() ; i < n ; i+=10)
   {
      res << svg::Point(dyn[i].position[0]/10e5, dyn[i].position[1]/10e5);
      //std::cout << "sat : " << dyn[i].position[0] << ", " << dyn[i].position[1] << std::endl;
   }
   return res;
}

