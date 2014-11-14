#include "../headers/objectif.h"

Objectif::Objectif() : _ancre(0)

{}
Objectif::Objectif(Situation* sit, Planete* ancre) : situation(sit), _ancre(ancre), _emecanique(0)
{}
Objectif::Objectif(Situation* sit, Planete* ancre, double Em) : situation(sit), _ancre(ancre), _emecanique(Em)
{}
Objectif::~Objectif()
{}


Planete* Objectif::getAncre() const
{
   return _ancre;
}
void Objectif::definir(Planete* ancre, double Em)
{
   _ancre = ancre;
   _emecanique = Em;
}
void Objectif::definir(Planete* ancre, Dynamique ref)
{
   _ancre = ancre;
   Cinematique planeteref = situation->getCinem(ancre, ref.temps);
   double v2 = (ref.vitesse - planeteref.vitesse).norme2(); // *10^3/24/3600; pour convertion en m/s
   double r = (ref.position - planeteref.position).norme();
   _emecanique = v2 /2 - _ancre->gm / r;
}


double Objectif::operator()(Dynamique satellite) const
{
   Cinematique planete = situation->getCinem(_ancre, satellite.temps);
   double r = (satellite.position - planete.position).norme();
   double v2 = (satellite.vitesse - planete.vitesse).norme2();
   /*
   double vr = (satellite.position - planete.position) // le vecteur planete-satellite
             * (satellite.vitesse - planete.vitesse); // moins la vitesse de la planete pour se placer dans le ref de la planete
   double dem = satellite.vitesse.norme2()/2 - ancre->gm/r  - _emecanique;
   double t = satellite.temps/_tau_temps;

   return pow(2.71, - dem*dem/_tau_em/_tau_em) // facteur Em
       *  (1+t+t*t/2+t*t*t/6)*pow(2.71, -t) // facteur temps
       *  (1-_alpha_dist + _alpha_dist*pow(2.71, (-(vr-r+_distance)/(r*r+1))) ); // facteur v radial
   */
   return std::abs( v2 /2 - _ancre->gm / r - _emecanique);
}

double Objectif::meilleur(double a, double b)
{
   return (a < b)? a : b;
}
double Objectif::meilleur_indice()
{
   return 0;
}
double Objectif::pire_indice()
{
   return 1E300; //; DBL_MAX;
}


