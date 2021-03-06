#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
#include <string>
#include "coord.h"

struct Cinematique
{
   Cinematique() : position(Coord<3>()), vitesse(Coord<3>()) {}
   Cinematique(const Cinematique& cin) : position(cin.position), vitesse(cin.vitesse) {}
   Cinematique(Coord<3> pos, Coord<3> vit) : position(pos), vitesse(vit) {}
   Cinematique(double x, double y, double z, double vx=0, double vy=0, double vz=0)
   {
      std::vector<double> pos;pos.push_back(x); pos.push_back(y);pos.push_back(z);
      std::vector<double> vit;vit.push_back(vx);vit.push_back(vy);vit.push_back(vz);
      position = pos;
      vitesse = vit;
   }
   Coord<3> position;
   Coord<3> vitesse;
};

struct Dynamique
{
   Dynamique() : position(Coord<3>()), vitesse(Coord<3>()), temps(0) {}
   Dynamique(const Dynamique& dyn) : position(dyn.position), vitesse(dyn.vitesse), temps(dyn.temps) {}
   Dynamique(Coord<3> pos, Coord<3> vit, double tps) : position(pos), vitesse(vit), temps(tps) {}
   Dynamique(double tps, double x, double y, double z, double vx=0, double vy=0, double vz=0)
   {
      temps = tps;
      std::vector<double> pos;pos.push_back(x); pos.push_back(y);pos.push_back(z);
      std::vector<double> vit;vit.push_back(vx);vit.push_back(vy);vit.push_back(vz);
      position = pos;
      vitesse = vit;
   }
   Coord<3> position;
   Coord<3> vitesse;
   double temps;
};

struct Planete
{
   Planete(std::string _nom, double _gm, double _rayon) : nom(_nom), gm(_gm), rayon(_rayon) {}
   std::string nom;
   double gm; // paramètre gravitationnel standard
   double rayon; // pour les collisions
};

#endif // STRUCTS_H
