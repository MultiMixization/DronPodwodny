#ifndef WODA_HH
#define WODA_HH

//#include <vector>
//#include <iostream>
//#include <string>

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include "Dr3D_gnuplot_api.hh"

class Woda : public Plaszczyzna, public Przeszkoda{
protected:
  double Noise;

public:
  Woda(std::shared_ptr<drawNS::Draw3DAPI> A, double P=10, int S=PLANEPOINT, double N=0.5) : Plaszczyzna(A, P, S), Noise(N) {};

  bool Kolizja(std::shared_ptr<DroneInterface> IntDron) override
  {
    if(IntDron->getSrodek()[2]>getSrodek()[2])
      {
	return true;
      }
    return false;
  }

  void rysuj() override;
};

#endif
