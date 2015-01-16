#include "../headers/situation.h"


Situation::Situation()
{
}
Situation::Situation(double tInitial, std::map<Planete*, Cinematique> sitInitial, double pasInit): pas(pasInit)
{
   Position[tInitial]= sitInitial;
}

void Situation::ajouterTemps(double temps)
{
   std::cout << "coucou" << std::endl;
   std::cout << "temps = " << temps << std::endl;
   double t = tempsproche(temps);
   if(std::abs(temps-t)>=pas)
   {
      if (t<temps) {
         std::cout << "ajouter1 avec " << temps-pas << std::endl;
         ajouterTemps(temps-pas);
      }
      else {
         std::cout << "ajouter2 avec " << temps-pas << std::endl;
         ajouterTemps(temps+pas);
      }
   }
   else
   {
      for (std::map<Planete*, Cinematique>::iterator it=Position[t].begin(); it!=Position[t].end();it++)
      {
          Planete* pactuelle = it->first;
          Cinematique nouvellecoord;
          nouvellecoord.position = (Position[t][pactuelle].position)+(Position[t][pactuelle].vitesse*pas);
          nouvellecoord.vitesse = Position[t][pactuelle].vitesse+(getForce((Position[t][pactuelle].position),temps)*pas);
          Position[temps][pactuelle]= nouvellecoord;
      }
   }
}


double Situation::tempsproche (double temps)
{
   double t=0;
   for (std::map<double, std::map<Planete*, Cinematique> >::iterator it=Position.begin(); it!=Position.end(); it++)
      {
         if ( std::abs(t-temps) > std::abs((it->first)-temps))
            {
               t=it->first;
            }
      }
   return t;
}


Coord<3> Situation::getForce (Coord<3> objet, double temps)
{
   Coord<3> VectForce;
   Coord<3> distance;
   for (std::map<Planete*, Cinematique>::iterator it=Position[temps].begin(); it!=Position[temps].end();it++)
   {
      Planete* pactuelle = it->first;
      distance = (Position[temps][pactuelle].position-=objet);
      VectForce += ((distance.normalize()*pactuelle->gm)/distance.norme2());
   }
   return VectForce;
}

std::vector < Coord<3> > Situation::getPosis (Planete* planete)
{
    std::vector < Coord<3> > vectpos;
    double t = 0;
    for (std::map<double, std::map<Planete*, Cinematique> >::iterator it=Position.begin(); it!=Position.end(); it++)
      {
       t=it->first;
       vectpos.push_back(Position[t][planete].position);
      }

      return vectpos;
}

Cinematique& Situation::getCinem (Planete* planete, double temps) //Fonction renvoie un vecteur de coord 3 d'une planete
{
   double t = tempsproche(temps);
   if (std::abs(t-temps)>pas)
   {
      std::cout << "ajouter avec " << temps-pas << std::endl;
      ajouterTemps(temps);
      std::cout << "VICTOIRE !!!!!!!" << std::endl;
   }
   double d = tempsproche(t);
   return Position[d][planete];
}
