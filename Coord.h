#ifndef COORD_H
#define COORD_H

#include <vector>

template<int T>
class Coord
{
protected:
   std::vector<double> val;
   
public:
   Coord();
   Coord(Coord<T>& v);
   Coord(std::vector<double> v);
   ~Coord();

   Coord<T> operator+(Coord<T> v);
   Coord<T> operator-(Coord<T> v);
   Coord<T> operator-(); // renvoi le négatif
   Coord<T> operator*(Coord<T> v);
   Coord<T> operator/(Coord<T> v);
   Coord<T> operator*(double i);
   Coord<T> operator/(double i);
   Coord<T> operator^(Coord<T> v); // normalement xor, peut etre traité en produit vectoriel

   bool operator==(Coord<T> v);
   bool operator=!(Coord<T> v);
   bool operator<(Coord<T> v); // a traiter en tant que norme
   bool operator>(Coord<T> v);
   bool operator<=(Coord<T> v);
   bool operator>=(Coord<T> v);

   bool operator!();
   
   Coord<T>& operator=(Coord<T> v);
   Coord<T>& operator+=(Coord<T> v);
   Coord<T>& operator-=(Coord<T> v);
   Coord<T>& operator*=(Coord<T> v);
   Coord<T>& operator/=(Coord<T> v);
   Coord<T>& operator*=(double i);
   Coord<T>& operator/=(double i);
   Coord<T>& operator^=(Coord<T> v);
   
   double& operator[](int i);

   double norme();
   Coord<T> normalized(); // vecteur unitaire de même direction

   Coord<T>& normalize();
   Coord<T>& rotate(Coord<T> axe, double angle);

   static double angle(Coord<T> v1, Coord<T> v2);
   static double scalaire(Coord<T> v1, Coord<T> v2); // produit scalaire
   static Coord<T> unit(int i); // renvoi le vecteur unité sur la ieme dimension
};

#endif // COORD_H
