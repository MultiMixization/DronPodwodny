#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "MacierzObr.hh"
#include "Wektor3D.hh"
#include "DronInterface.hh"
#include "Dr3D_gnuplot_api.hh"
#include <iostream>

class Przeszkoda{
protected:
public:
  virtual bool Kolizja(std::shared_ptr<DroneInterface> IntDron) = 0;
};

#endif
