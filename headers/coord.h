#ifndef COORD_H
#define COORD_H

#include <vector>
#include <cmath>

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

   Coord<T> operator+(const Coord<T>& v) const;
   Coord<T> operator-(const Coord<T>& v) const;
   Coord<T> operator-() const; // renvoi le négatif
   double operator*(const Coord<T>& v) const; // produit scalaire...
   Coord<T> operator*(double i) const;
   Coord<T> operator/(double i) const;
   Coord<3> operator^(const Coord<3>& v) const; // normalement xor, peut etre traité en produit vectoriel

   bool operator==(const Coord<T>& v) const;
   bool operator!=(const Coord<T>& v) const;
   bool operator<(const Coord<T>& v) const; // a traiter en tant que norme
   bool operator>(const Coord<T>& v) const;
   bool operator<=(const Coord<T>& v) const;
   bool operator>=(const Coord<T>& v) const;

   bool operator!() const;
   
   Coord<T>& operator=(const Coord<T> v);
   Coord<T>& operator+=(const Coord<T> v);
   Coord<T>& operator-=(const Coord<T> v);
   Coord<T>& operator*=(double i);
   Coord<T>& operator/=(double i);
   Coord<3>& operator^=(const Coord<3> v);
   
   double operator[](int i) const;

   double norme() const;
   double norme2() const; // norme au carré, en cas de besoins pour éviter trop de calcul
   Coord<T> normalized() const; // renvoi le vecteur unitaire de même direction

   Coord<T>& normalize(); // *this = this->normalized
   Coord<T>& rotate(const Coord<T>& axe, double angle);
   Coord<T>& rotate(const Coord<T>& vecteur_rotation);

   static double angle(const Coord<T>& v1, const Coord<T>& v2);
   static Coord<T> unit(int i=0); // renvoi le vecteur unité sur la ieme dimension
};

#endif // COORD_H
