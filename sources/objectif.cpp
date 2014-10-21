#include "../headers/objectif.h"

Objectif::Objectif() : _ancre(0), 
                       _emecanique(0), _distance(0), 
                       _tau_em(1), _alpha_dist(0.7), _tau_temps(1000)
{}
Objectif::Objectif(Planete* ancre) : _ancre(ancre), 
                                     _emecanique(0), _distance(0), 
                                     _tau_em(1), _alpha_dist(0.7), _tau_temps(1000)
{}
Objectif::Objectif(Planete* ancre, double Em, double distance) : 
                                     _ancre(ancre), 
                                     _emecanique(Em), _distance(distance), 
                                     _tau_em(1), _alpha_dist(0.7), _tau_temps(1000)
{}
Objectif::~Objectif()
{}


Planete* Objectif::getAncre()
{
   return _ancre;
}
void Objectif::definir(Planete* ancre, double Em, double distance)
{
   _ancre = ancre;
   _emecanique = Em;
   _distance = distance;
}
void Objectif::definir(Planete* ancre, Dynamique ref)
{
   _ancre = ancre;
   double v2 = ref.vitesse.norme2(); // *10^3/24/3600; pour convertion en m/s
   _emecanique = v2 /2 - ancre->gm / (ref.position - situation->getCinem(ancre, ref.temps)).norme();
   _distance = ancre->gm / v2;
}
void Objectif::parametrer(double tau_em, double alpha_dist, double tau_temps)
{
   _tau_em = tau_em;
   _alpha_dist = alpha_dist;
   _tau_temps = tau_temps;
}


double Objectif::operator()(Dynamique satellite)
{
   Cinematique planete = situation->getCinem(ancre, satellite.temps).position;
   double vr = (satellite.position - planete.position) // le vecteur planete-satellite 
             * (satellite.vitesse - planete.vitesse); // moins la vitesse de la planete pour se placer dans le ref de la planete
   double r = (satellite.position - planete.position).norme();
   double dem = satellite.vitesse.norme2()/2 - ancre->gm/r  - _emecanique;
   double t = satellite.temps/_tau_temps;

   return pow(2.71, - dem*dem/_tau_em/_tau_em) // facteur Em
       *  (1+t+t*t/2+t*t*t/6)*pow(2.71, -t) // facteur temps
       *  (1-_alpha_dist + _alpha_dist*pow(2.71, (-(vr-r+_distance)/(r*r+1))) ); // facteur v radial 
}


