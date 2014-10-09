#include "../headers/coord.h"

template<int T>
Coord::Coord()
{}
template<int T>
Coord::Coord(Coord<T>& v) : val(v.val)
{}
template<int T>
Coord::Coord(std::vector<double> v) : val(v)
{
   val.resize(T);
}
template<int T>
Coord::~Coord()
{}


template<int T>
Coord<T> Coord::operator+(const Coord<T>& v) const
{
   Coord<T> res(*this);
   for (int i=0 ; i < T ; ++i)
      res.val[i] += v[i];
   return res;
}
template<int T>
Coord<T> Coord::operator-(const Coord<T>& v) const
{
   Coord<T> res(*this);
   for (int i=0 ; i < T ; ++i)
      res.val[i] += v[i];
   return res;
}
template<int T>
Coord<T> Coord::operator-() const
{
   Coord<T> res(*this);
   for (int i=0 ; i < T ; ++i)
      res.val[i] = -res.val[i];
   return res;
}
template<int T>
double Coord::operator*(const Coord<T>& v) const
{
   double res=0;
   for (int i=0 ; i < T ; ++i)
      res += val[i] * v.val[i];
   return res;
}
template<int T>
Coord<T> Coord::operator*(double i) const
{
   Coord<T> res(*this);
   for (int i=0 ; i < T ; ++i)
      res.val[i] *= i;
   return res;
}
template<int T>
Coord<T> Coord::operator/(double i) const
{
   Coord<T> res(*this);
   for (int i=0 ; i < T ; ++i)
      res.val[i] /= i;
   return res;
}
template<>
Coord<3> Coord::operator^(const Coord<3>& v) const
{
   std::vector<double> res(3,0);
   res[0] = val[1] * v.val[2] - val[2] * v.val[1];
   res[1] = val[2] * v.val[0] - val[0] * v.val[2];
   res[2] = val[0] * v.val[1] - val[1] * v.val[0];
   return Coord<3>(res);
}


template<int T>
bool Coord::operator==(const Coord<T>& v) const
{
   bool res = true;
   for (int i=0 ; i < T && res; ++i)
      res &= val[i] == v.val[i];
   return res;
}
template<int T>
bool Coord::operator!=(const Coord<T>& v) const
{
   return not operator==(v);
}
template<int T>
bool Coord::operator<(const Coord<T>& v) const
{
   return norme() < v.norme();
}
template<int T>
bool Coord::operator>(const Coord<T>& v) const
{
   return norme() > v.norme();
}
template<int T>
bool Coord::operator<=(const Coord<T>& v) const
{
   return norme() <= v.norme();
}
template<int T>
bool Coord::operator>=(const Coord<T>& v) const
{
   return norme() >= v.norme();
}

template<int T>
bool Coord::operator!() const
{
   return norme() == 0;
}


template<int T>
Coord<T>& Coord::operator=(const Coord<T> v)
{
   bool res = true;
   for (int i=0 ; i < T && res; ++i)
      res &= val[i] == v.val[i];
   return *this;
}
template<int T>
Coord<T>& Coord::operator+=(const Coord<T> v)
{
   for (int i=0 ; i < T ; ++i)
      val[i] += v.val[i];
   return *this;
}
template<int T>
Coord<T>& Coord::operator-=(const Coord<T> v)
{
   for (int i=0 ; i < T ; ++i)
      val[i] -= v.val[i];
   return *this;
}
template<int T>
Coord<T>& Coord::operator*=(double i)
{
   for (int i=0 ; i < T ; ++i)
      val[i] *= i;
   return *this;
}
template<int T>
Coord<T>& Coord::operator/=(double i)
{
   for (int i=0 ; i < T ; ++i)
      val[i] /= i;
   return *this;
}
template<>
Coord<3>& Coord::operator^=(const Coord<3> v)
{
   return operator=(operator^(v));
}


template<int T>
double Coord::operator[](int i) const
{
   return (i<T)? val[i] : 0;
}


template<int T>
double Coord::norme() const
{
   double res=0;
   for (int i=0 ; i < T ; ++i)
      res += val[i] * val[i];
   return sqrt(res);
}
template<int T>
double Coord::norme2() const
{
   double res=0;
   for (int i=0 ; i < T ; ++i)
      res += val[i] * val[i];
   return res;
}
template<int T>
Coord<T> Coord::normalized() const
{
   return Coord<T>(*this).normalize();
}
template<int T>
Coord<T>& Coord::normalize()
{
   double norm = norme();
   for (int i=0 ; i < T ; ++i)
      val[i] /= norm;
   return *this;
}
/*template<int T>
Coord<T>& Coord::rotate(const Coord<T>& axe1, double angle)
{
   // TODO
   return *this;
}
template<int T>
Coord<T>& Coord::rotate(const Coord<T>& vecteur_rotation)
{
   // TODO
   return *this;
}*/


template<int T>
double Coord::angle(const Coord<T>& v1, const Coord<T>& v2)
{
   return acos( v1.operator*(v2) / v1.norme() / v2.norme() );
}
template<int T>
Coord<T> Coord::unit(int i)
{
   std::vector<double> v(T,0);
   if (i < T)
      v[i] = 1;
   return Coord<T>(v);
}

