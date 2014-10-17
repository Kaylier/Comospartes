#include "../headers/objectif.h"

Objectif::Objectif() : _ancre(NULL), 
                       _emecanique(0), _distance(0), 
                       _tau_em(1), _alpha_dist(0.7), _tau_temps(1000)
{}
Objectif::Objectif(Planete* ancre) : _ancre(ancre), 
                                     _emecanique(0), _distance(0), 
                                     _tau_em(1), _alpha_dist(0.7), _tau_temps(1000)
{}
Objectif::Objectif(Planete* ancre, double Em, unsigned double distance) : 
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
void Objectif::definir(Planete* ancre, double Em, unsigned double distance)
{
   _ancre = ancre;
   _emecanique = Em;
   _distance = distance;
}
void Objectif::definir(Planete* ancre, Dynamique ref)
{
   _ancre = ancre;
   double v2 = ref.vitesse.norm2(); // *10^3/24/3600; pour convertion en m/s
   _emecanique = v2 /2 - ancre->gm / (ref.position - situation.getCinem(ancre, ref.temps)).norme();
   _distance = ancre->gm / v2;
}
void Objectif::parametrer(unsigned double tau_em, unsigned double alpha_dist, unsigned double tau_temps)
{
   _tau_em = tau_em;
   _alpha_dist = alpha_dist;
   _tau_temps = tau_temps;
}


double Objectif::operator()(Dynamique satellite)
{
   return 2.71^(-( (satellite.vitesse.norme2()/2 - ancre->gm/(satellite.position - situation.getCinem(ancre, satellite.temps)).norme()) / _tau_em )^2);
}


