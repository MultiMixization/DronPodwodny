#ifndef WODA_HH
#define WODA_HH

//#include <vector>
//#include <iostream>
//#include <string>

#include "Plaszczyzna.hh"
#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class Woda : public Plaszczyzna{
protected:
  double Noise;

public:
  Woda(std::shared_ptr<drawNS::Draw3DAPI> A, double P=9, double N=0.5) : Plaszczyzna(A, P), Noise(N) {};

  void rysuj();
};

#endif
