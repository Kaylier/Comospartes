/* Explication rapide :
 *  Une orbite autours d'un astre est d'equation (polaire) r = p / (1+e*cos(angle))
 *  On visera une orbite circulaire, donc e=0
 *  et de rayon fixé p
 *  mais en fait osef...
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
 *
 *
 * AUTRE RAISONNEMENT : 
 * dans le ref de l'astre en cours, il y a 6 param a prendre en compte : position et vitesse
 * par invariance par rotation, la position se résume au rayon
 *                           et la vitesse se résume à une vitesse radiale et une vitesse orthoradiale
 *          On définira plutot la vitesse par sa composante radiale et sa norme
 * On se retrouve à 3 paramètres : r, vr et v
 * r et v permettent de définir Em, qui doit se rapprocher d'une réference
 * vr ne sert en fait a pas grand chose...
 *
 * ainsi, l'indice est calculé par facteur_Em*facteur_temps
 *   avec
 *       facteur_Em qui varie de 0 à +inf : dEm=Em-Emref -> 1/dEm²
 *       facteur_temps qui varie de 1 à 0 :  t/tau -> (1+t+t²/2+t³/6)*e^(-t)
 *   facteur_temps est optionnel comme on arrete les calculs de toute facons
 *
 * DERNIER RAISONEMENT : 
 *    en fait, chercher a maximiser 1/dEm² revient a minimiser abs(dEm)...
 *    donc l'indice peut être simplement abs(dEm) avec 0 comme perfect et +inf comme pourris
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

public:
   Objectif();
   Objectif(Situation* sit, Planete* ancre);
   Objectif(Situation* sit, Planete* ancre, double Em);
   ~Objectif();

   Planete* getAncre() const;
   void definir(Planete* ancre, double Em);
   void definir(Planete* ancre, Dynamique ref);

   double operator()(Dynamique satellite) const; // renvoi l'indice 

   static double meilleur(double a, double b);
   static double meilleur_indice();
   static double pire_indice();
};


#endif // OBJECTIF_H

