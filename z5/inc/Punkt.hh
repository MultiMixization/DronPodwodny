#ifndef PUNKT_HH
#define PUNKT_HH

#include <iostream>

#include "Wektor3D.hh"

class Punkt{
protected:
  double wspl[3];  //Odpowiednio x,y,z

public:
  Punkt() {for(double &tmp: wspl) tmp=0;};
  Punkt(double xx, double yy, double zz) {wspl[0]=xx; wspl[1]=yy; wspl[2]=zz;};
  Punkt(const Punkt &P) {wspl[0]=P[0]; wspl[1]=P[1]; wspl[2]=P[2];};

  const double & operator [](int index) const;
  double & operator [](int index);

  bool operator ==(const Punkt P) const;
  bool operator !=(const Punkt P) const;

  Punkt Translacja(const Wektor3D W);
  Wektor3D Wektor(const Punkt P);
};
#endif
