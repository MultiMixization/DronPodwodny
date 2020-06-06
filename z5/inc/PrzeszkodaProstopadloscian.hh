#ifndef PRZEPROST_HH
#define PRZEPROST_HH

#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"
#include "MacierzObr.hh"
#include "Punkt.hh"
#include "Dr3D_gnuplot_api.hh"
#include <math.h>
#include <stdlib.h>
#include <iostream>

class PrzeszkodaProstopadloscian : public Przeszkoda, public Prostopadloscian{
protected:
public:
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A) : Prostopadloscian(A){}
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzObr M, const Punkt S, const Wektor3D R) : Prostopadloscian(A,M,S,R){}

  bool Kolizja(std::shared_ptr<DroneInterface> IntDron) override
  {
    Wektor3D tempW=getOrientacja()*getRef();
    Punkt tempD=IntDron->getSrodek();
    Punkt tempC=getSrodek();

    if(!(abs(tempD[0]-tempC[0])<tempW[0]+IntDron->getSrednica()))
      {
	return false;
      }
    if(!(abs(tempD[1]-tempC[1])<tempW[1]+IntDron->getSrednica()))
      {
	return false;
      }
    if(!(abs(tempD[2]-tempC[2])<tempW[2]+IntDron->getSrednica()))
      {
	return false;
      }
    return true;
  }
};

#endif
