#ifndef PRZEPROST_HH
#define PRZEPROST_HH

#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"
#include "MacierzObr.hh"
#include "Punkt.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

class PrzeszkodaProstopadloscian : public Przeszkoda, public Prostopadloscian{
protected:
public:
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A) : Prostopadloscian(A){}
  PrzeszkodaProstopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzObr M, const Punkt S, const Wektor3D R) : Prostopadloscian(A,M,S,R){}

  bool Kolizja(std::shared_ptr<DroneInterface> IntDron) override
  {
    if(IntDron->getSrodek().Wektor(getSrodek()).dlugosc()<getRef().dlugosc()+IntDron->getSrednica())
      {
	return true;
      }
    return false;
  }
};

#endif
