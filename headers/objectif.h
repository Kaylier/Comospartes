/* Explication rapide :
 *  Une orbite autours d'un astre est d'equation (polaire) r = p / (1+e*cos(angle))
 *  On visera une orbite circulaire, donc e=0
 *  et de rayon fixé p
 *  L'energie mecanique sur l'ellipse est constante, 
 *          Em/m = 1/2*v² - GM/r
 *  On va donc essayer de la rapprocher au max d'une energie ref
 *  Mais pour les distances lointaines, il faut privilegier la distance à la vitesse
 *  
 *  Pour une Em correcte, la vitesse doit avoir une direction correcte
 *  Proche de la cible, la vitesse doit etre orthogonale au rayon
 *  Loin, elle doit pointer vers la cible
 *
 * Ainsi : 
 *  Objectif(Em, r, tau) = facteur_Em(Em-emec) * 
 *                         facteur_vradial(v) * 
 *                         facteur_temps(t/tau_temps)
 *       où facteur_temps : t-> (1+t+t²/2+t³/6)*e^(-t)   (c'est une courbe cool de 1 à 0!)
 *        , facteur_Em : dE -> e^(-dE²/tau_emecanique²)
 *        , facteur_vradial : v -> 1-alpha + alpha*e^(-(vr - r + distance)²/(r*r+1))
 */
#ifndef OBJECTIF_H
#define OBJECTIF_H

#include <cmath>
#include "structs.h"
#include "situation.h"

class Objectif
{
protected:
   Planete* _ancre;
   Situation* situation;
   // parametrage de l'etat idéal
   double _emecanique; // Em ideal
   double _distance; // distance ideale
   // paramétrage de la tolérance de selection
   double _tau_em; // gere la décroissante exp de l'Em
   double _alpha_dist; // gere l'importance du facteur radial (entre 0 et 1)
   double _tau_temps; // constante de temps

public:
   Objectif();
   Objectif(Planete* ancre);
   Objectif(Planete* ancre, double Em, double distance=0);
   ~Objectif();

   Planete* getAncre() const;
   void definir(Planete* ancre, double Em, double distance=0);
   void definir(Planete* ancre, Dynamique ref);
   void parametrer(double tau_em, double alpha_dist, double tau_temps);

   double operator()(Dynamique satellite) const; // renvoi l'indice 

   static double meilleur(double a, double b);
   static double meilleur_indice();
   static double pire_indice();
};


#endif // OBJECTIF_H

