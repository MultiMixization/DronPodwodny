#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "MacierzObr.hh"
#include "Wektor3D.hh"
#include "DronInterface.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

class Preszkoda{
protected:
public:
  virtual bool Kolizja(std::shared_ptr<DronInterface> IntDron) = 0;
};

#endif
