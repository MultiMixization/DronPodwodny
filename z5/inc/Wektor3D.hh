#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH

#include <iostream>
#include <math.h>

#include "Wektor.hh"

class Wektor3D : public Wektor<double, 3>{
protected:
  static int Wszystkie;
  static int Zniszczone;
public:
  static int getWszystkie(){return Wszystkie;}
  static int getZniszczone(){return Zniszczone;}
  
  Wektor3D() : Wektor<double, 3>() {++Wszystkie;}
  Wektor3D(const Wektor3D & W) : Wektor<double, 3>(W) {++Wszystkie;}
  Wektor3D(double xx, double yy, double zz) {tab[0]=xx; tab[1]=yy; tab[2]=zz; ++Wszystkie;}
  Wektor3D(const Wektor<double, 3> W) : Wektor<double, 3>(W){++Wszystkie;}

  ~Wektor3D(){++Zniszczone;}

  Wektor3D Odwroc(bool xx, bool yy, bool zz) const;
};

#endif
