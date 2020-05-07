#ifndef PUNKT_HH
#define PUNKT_HH

#include <iostream>

class Punkt{
  double wspl[3];  //Odpowiednio x,y,z

public:
  Punkt() {for(double &tmp: wspl) tmp=0;};
  Punkt(double xx, double yy, double zz) {wspl[0]=xx; wspl[1]=yy; wspl[2]=zz;};
  Punkt(const Punkt &P) {wspl[0]=P[0]; wspl[1]=P[1]; wspl[2]=P[2];};

  const double & operator [](int index) const;
  double & operator [](int index);
};
#endif
