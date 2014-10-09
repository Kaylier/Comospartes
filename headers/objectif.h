#ifndef OBJECTIF_H
#define OBJECTIF_H

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
 *  Objectif(Em, r, tau) = (facteur_Em_proche(Em-emec) + facteur_Em_lointain(r)) * 
 *                         (facteur_direction_proche(v) + facteur_direction_lointain(v)) * 
 *                         facteur_temps(t/tau_temps)
 *       où facteur_temps : t-> (1+t+t²/2+t³/6)*e^(-t)   (c'est une courbe cool de 1 à 0!)
 *        , facteur_Em_proche : dE -> e^(-dE²/tau_emecanique²)
 *        (, facteur_Em_lointain : r -> -r/tau_distance / (1 + 10*tau_distance/r) ) faut voir pour celui la...
 *        , facteur_direction_proche : v -> ???
 *        , facteur_direction_lointain : v -> ??? v*OM (prdt scalaire, OM=vecteur cible-objet)
 */
class Planete;

class Objectif
{
protected:
   Planete *ancre;
   double emecanique;
   double distance;
   double tau_emecanique;
   double tau_distance;
   double tau_temps; // constante de temps

public:
   Objectif();
   ~Objectif();

   double operateur()(Dynamique satellite)

};

double objectif (*Dynamique satellite, *Planete arrivee, *situation sitPlanete, double emeca)
{



}

#endif // SYSTEME_SOLAIRE_H
