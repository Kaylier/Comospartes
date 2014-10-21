#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>
#include "coord.h"

struct Cinematique
{
   Coord<3> position;
   Coord<3> vitesse;
};

struct Dynamique
{
   Coord<3> position;
   Coord<3> vitesse;
   double temps;
};

struct Planete
{
   std::string nom;
   double gm; // paramètre gravitationnel standard
   double rayon; // pour les collisions
   bool fixe;
};

#endif // STRUCTS_H
