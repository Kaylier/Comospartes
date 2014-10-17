#include <map>

class Situation
   {
   protected:
      map<double, map<*Planete, Cinematique>> Position; //Système
      double pas;

   public:
      Situation();
      Situation(double tInital, std::map<Planetes, Cinematique> sitInital);
      double tempsproche(double temps);
      void ajouterTemps(double temps); //Ajoute l'ensemble des coordonées à un temps voulu
      Coord<3> getForce (Coord<3>, double temps);// Forces s'appliquant en un point
      Cinematique getCinem (*Planete planete, double temps);

   };

double tempsmax (*Situation systeme);


