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


void Objectif::definir(Planete* ancre, double Em, unsigned double distance)
{
   _ancre = ancre;
   _emecanique = Em;
   _distance = distance;
}
void Objectif::definir(Planete* ancre, Dynamique ref)
{
   // TODO
}
void Objectif::parametrer(unsigned double tau_em, unsigned double alpha_dist, unsigned double tau_temps)
{
   _tau_em = tau_em;
   _alpha_dist = alpha_dist;
   _tau_temps = tau_temps;
}


double Objectif::operator()
{
   return 0;
}


