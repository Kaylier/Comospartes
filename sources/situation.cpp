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
   double t = tempsproche(temps);

   while (std::abs(temps-t) > pas)
   {
      for (std::map<Planete*, Cinematique>::iterator it=Position[t].begin(); it!=Position[t].end();it++)
      {
          Planete* pactuelle = it->first;
          Cinematique nouvellecoord;
          //std::cout << " POs: " << Position[t][pactuelle].position[0] << std::endl;
          nouvellecoord.position = (Position[t][pactuelle].position)+(Position[t][pactuelle].vitesse*pas);
          nouvellecoord.vitesse = Position[t][pactuelle].vitesse+(getForce((Position[t][pactuelle].position),t, pactuelle)*pas);
          // std::cout << " POs2: " << Position[t][pactuelle].position[0] << std::endl;
          Position[t+pas].insert(std::make_pair(pactuelle,nouvellecoord)   );
          //std::cout << " Temps: " << t << " Planete: " << pactuelle->nom << " position: " << Position[t+pas][pactuelle].position[0] <<
          //" vitesse: " << nouvellecoord.vitesse[0] << std::endl << std::endl;
      }
       t=(t+pas);
   }

}


double Situation::tempsproche (double temps)
{
   double t=0;
   std::map<double, std::map<Planete*, Cinematique> >::iterator it=Position.begin();
   while((std::abs(t-temps) <= std::abs((it->first)-temps))&& (it!=Position.end()))
      {
        if ( std::abs(t-temps) > std::abs((it->first)-temps))
            {
               t=it->first;
            }
            it++;
      }
   return t;
}


Coord<3> Situation::getForce (Coord<3> objet, double temps, Planete* plan)
{
   Coord<3> VectForce;
   Coord<3> distance;
   for (std::map<Planete*, Cinematique>::iterator it=Position[temps].begin(); it!=Position[temps].end();it++)
   {
         Planete* pactuelle = it->first;

            if (plan == NULL || pactuelle != plan)
            {
               distance = (Position[temps][pactuelle].position-objet);
               VectForce += ((distance.normalize()*pactuelle->gm)/distance.norme2());
            }

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
       //std::cout << "planete = " << Position[t].find(planete)->second.position[0] << std::endl;
       //std::cout << " " << Position[t][lanete].position[0] << std::endl;
      }

      return vectpos;
}

Cinematique& Situation::getCinem (Planete* planete, double temps) //Fonction renvoie un vecteur de coord 3 d'une planete
{
   double t = tempsproche(temps);
   if (std::abs(t-temps)>pas)
   {
      ajouterTemps(temps);
   }
   return Position[t][planete];

}
