Situation::Situation
{
}
Situation::Situation(double tInital, std::map<Planetes, Cinematique, double pasInit> sitInital): Position[tInitial](sitInitial), pas(pasInit)
{
}

Situation::ajouterTemps(double temps)
{

}

double tempsproche (*Situation systeme, double temps)
{
   double t=0;
   for (it=systeme.Position.begin(); it!=systeme.Position.end; it++)
      {
        if ( std::abs(t-temps) > std::abs((it->first)-temps))
            {
               t=it->first));
            }
      }
   return t;
}


