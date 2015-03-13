#include "../headers/systeme_solaire.h"

Systeme_Solaire::Systeme_Solaire()
{
   _depart = NULL;
}
Systeme_Solaire::Systeme_Solaire(double tInitial, std::map<Planete*, Cinematique>& sitInitial, double pasInitial) : _situation(tInitial, sitInitial, pasInitial)
{
   std::cout << "Création du systeme solaire..." << std::endl;
   for (std::map<Planete*, Cinematique>::iterator it = sitInitial.begin() ; it != sitInitial.end() ; ++it)
   {
      _planetes.push_back(it->first);
      std::cout << "\tPlanete " << _planetes.back()->nom
                << "\tgm=" << _planetes.back()->gm
                << "\trayon=" << _planetes.back()->rayon << std::endl;
   }
   _depart = NULL;
   std::cout << "systeme solaire crée avec succés (" << _planetes.size() << " planetes)" << std::endl;
}
Systeme_Solaire::~Systeme_Solaire()
{}

std::vector<Planete*> Systeme_Solaire::get_planets() const
{
   return _planetes;
}

Planete* Systeme_Solaire::set_depart(Planete* planete)
{
   _planetes.push_back(planete);
   _depart = planete;
   return planete;
}

std::vector<Coord<3> > Systeme_Solaire::get_pos(Planete* planete)
{
   _situation.getCinem(planete, TEMPS_MAX);
   return _situation.getPosis(planete);
}


Dynamique& Systeme_Solaire::actualiser_dynamique(Dynamique& dyn)
{
   Coord<3> force = _situation.getForce(dyn.position, _situation.tempsproche(dyn.temps), NULL);
   //double dt = TEMPS_MIN;
   double dt = ERR_DT / sqrt(force.norme() * dyn.vitesse.norme2());
   // ici, on peut peut-etre optimiser le TEMPS_MIN en un temps plus long si le satellite est loins des astres, cad si la force est faible
   dyn.vitesse += force*dt;
   dyn.position += dyn.vitesse*dt;
   dyn.temps += dt;
   return dyn;
}

std::vector<Dynamique> Systeme_Solaire::calculer_trajectoire(Dynamique condition_initiale)
{
   /* Fonction qui permet de récupérer une orbite
    * condition_initiale détermine la dynamique initiale du satellite dans
    * le référentiel de la planete de départ
    * (dans la pratique, condition_initiale.position = (0,0,0) )
    */
   Dynamique satellite;
      Cinematique cin_depart = _situation.getCinem(_depart, condition_initiale.temps);
      satellite.temps = condition_initiale.temps;
      satellite.position = cin_depart.position + condition_initiale.position;
      satellite.vitesse = cin_depart.vitesse + condition_initiale.vitesse;

   std::vector<Dynamique> resultat;
   resultat.push_back(satellite);

   while (satellite.temps < TEMPS_MAX)
   {
      actualiser_dynamique(satellite);
      resultat.push_back(satellite);
   }
   return resultat;
}

double Systeme_Solaire::estimer_trajectoire(Dynamique condition_initiale)
{
   /* Fonction à optimiser au maximum !!!
    * condition_initiale détermine la dynamique initiale du satellite dans
    * le référentiel de la planete de départ
    * (dans la pratique, condition_initiale.position = (0,0,0) )
    */
   Dynamique satellite;
      Cinematique cin_depart = _situation.getCinem(_depart, condition_initiale.temps);
      satellite.temps = condition_initiale.temps;
      satellite.position = cin_depart.position + condition_initiale.position;
      satellite.vitesse = cin_depart.vitesse + condition_initiale.vitesse;

   double best_indice = _objectif(satellite);
   double new_indice = 0;

   bool stop = false;
   while (!stop)
   {
      actualiser_dynamique(satellite);
      new_indice = _objectif(satellite);
      if (new_indice < best_indice)
         best_indice = new_indice;

      // Si on doit récupérer les coordonées du trajet, il faut les intercepter ici

      if (satellite.temps > TEMPS_MAX || new_indice > _objectif.pire_indice())
         stop = true;
   }
   return best_indice;
}

std::vector<Dynamique> optimiser_trajet(Dynamique condition_initiale)
{

}


