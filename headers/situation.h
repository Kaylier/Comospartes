#include <map>

class Situation
   {
   protected:
      map<double, map<*Planete, Cinematique>> Position;
      double pas;

   public:
      Situation();
      Situation(double tInital, std::map<Planetes, Cinematique> sitInital);
      void ajouterTemps(double temps);

   };

double tempsmax (*Situation systeme);

