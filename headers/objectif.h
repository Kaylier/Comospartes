
class objectif
{
<<<<<<< HEAD
protected:
   Planete* _ancre;
   Situation* situation;
   // parametrage de l'etat idéal
   double _emecanique; // Em ideal
   unsigned double _distance; // distance ideale
   // paramétrage de la tolérance de selection
   unsigned double _tau_em; // gere la décroissante exp de l'Em
   unsigned double _alpha_dist; // gere l'importance du facteur radial (entre 0 et 1)
   unsigned double _tau_temps; // constante de temps

public:
   Objectif();
   Objectif(Planete* ancre);
   Objectif(Planete* ancre, double Em, unsigned double distance=0);
   ~Objectif();
=======
   private:
     Planete *arrivee;
     double emecanique;
     double distance;
>>>>>>> 16b8e8ddf89dadd3e2e62f037a5deddc0a5931a2

   public:
      objectif();
      double operateur()(Dynamique satellite)

<<<<<<< HEAD
   double operator()(Dynamique satellite); // renvoi l'indice 
=======
>>>>>>> 16b8e8ddf89dadd3e2e62f037a5deddc0a5931a2

};


