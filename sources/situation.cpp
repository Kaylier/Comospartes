Situation::Situation
{
}
Situation::Situation(double tInital, std::map<Planetes, Cinematique, double pasInit> sitInital): Position[tInitial](sitInitial), pas(pasInit)
{
}

void Situation::ajouterTemps(double temps)
{
   double t = tempsproche(temps);
   if(std::abs(temps-t<pas))
   {
      if (t<temps) {ajouterTemps(t+pas);
      }
      else {ajouterTemps(t-pas);
      }
   }
   else
   {
      for (it=Position.[t]begin(); it!=Position[t].end();it++)
      {
         *Planete pactuelle = Position[t][it];
          Cinematique nouvellecoord;
          nouvellecoord.position=pactuelle.position+(pactuelle.vitesse*pas);
          nouvellecoord.vitesse=pactuelle.vitesse+(getForce(pactuelle.position,temps)*pas);
          Position[temps][it]=nouvellecoord;
      }
   }
}


double Situation::tempsproche (double temps)
{
   double t=0;
   for (it=Position.begin(); it!=Position.end(); it++)
      {
        if ( std::abs(t-temps) > std::abs((it->first)-temps))
            {
               t=it->first));
            }
      }
   return t;
}


Coord<3> Situation::getForce (Coord<3> objet, double temps)
{
   Coord<3> VectForce([0,0,0]);
   Coord<3> distance([0,0,0]);
   for (i;t=Position[temps].begin(); it!Position[temps].end();it++)
   {
      distance = (Position[temps][it].position-objet);
      VectForce+=((it.gm*distance.normalize())/distance.norme2());
   }
   return VectForce;
}

Cinematique Situation::getCinem (*Planete planete, double temps)
{
   return Position[temps][planete];
}
