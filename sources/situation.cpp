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
          std::cout << "iterat " << &*Position[t].begin() << std::endl;
          nouvellecoord.position = (Position[t][pactuelle].position)+(Position[t][pactuelle].vitesse*pas);
          nouvellecoord.vitesse = Position[t][pactuelle].vitesse+(getForce((Position[t][pactuelle].position),t+pas, pactuelle)*pas);
          std::cout << "Pos: " <<  Position[t][pactuelle].position[0] << std::endl;
          Position[t+pas][pactuelle]= nouvellecoord;


          std::cout << " Temps: " << t << " Planete: " << pactuelle->nom << " position: " << Position[t+pas][pactuelle].position[0] <<
          " vitesse: " << nouvellecoord.vitesse[0] << std::endl << std::endl;
      }

      t=t+pas;
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


Coord<3> Situation::getForce (Coord<3> objet, double temps, Planete* plan)
{
   Coord<3> VectForce;
   Coord<3> distance;
   for (std::map<Planete*, Cinematique>::iterator it=Position[temps].begin(); it!=Position[temps].end();it++)
   {

         Planete* pactuelle = it->first;
         distance = (Position[temps][pactuelle].position-=objet);
            if (plan == NULL || pactuelle != plan)
            {
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
