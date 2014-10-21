#include "../headers/systeme_solaire.h"

Systeme_Solaire::Systeme_Solaire()
{
   _depart = NULL;
}
Systeme_Solaire::~Systeme_Solaire()
{
   for (int i=0 ; i < _planetes.size() ; ++i)
      if (_planetes[i])
         delete _planetes[i];
   if (_depart)
      delete _depart;
}

std::vector<Planete*> Systeme_Solaire::get_planets() const
{
   return _planetes;
}
Planete* Systeme_Solaire::add_planet(Planete* planete)
{
   _planetes.push_back(planete);
   return planete;
}
Planete* Systeme_Solaire::add_planet(std::string nom, double gm, double rayon, bool fixe)
{
   Planete* planete = new Planete;
   planete->nom = nom;
   planete->gm = gm;
   planete->rayon = rayon;
   planete->fixe = fixe;
   _planetes.push_back(planete);
   return planete;
}
Planete* Systeme_Solaire::add_depart(Planete* planete)
{
   _planetes.push_back(planete);
   _depart = planete;
   return planete;
}
Planete* Systeme_Solaire::add_depart(std::string nom, double gm, double rayon, bool fixe)
{
   Planete* planete = new Planete;
   planete->nom = nom;
   planete->gm = gm;
   planete->rayon = rayon;
   planete->fixe = fixe;
   _planetes.push_back(planete);
   _depart = planete;
   return planete;
}
void Systeme_Solaire::rmPlanet(Planete* planete)
{
   for (int i=0 ; i < _planetes.size() ; ++i)
      if (_planetes[i] == planete)
      {
         _planetes.erase(_planetes.begin()+i);
         i--;
      }
}

double Systeme_Solaire::estimer_trajectoire(Dynamique condition_initiale)
{
   double best_indice=_objectif.pire_indice();
   
   while (true)
   {
      // calcule la dynamique suivante en prenant en compte les astres proches
   }
   return best_indice;
}


