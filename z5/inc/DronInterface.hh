#ifndef DRONEINTERFACE_HH
#define DRONEINTERFACE_HH

#include "Punkt.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include <unistd.h>
#include <iostream>

class DroneInterface{
protected:
public:

  virtual Punkt getSrodek() = 0;
  virtual double getSrednica() = 0;

  virtual void setPredkoscPrzod(double P) = 0;
  virtual double getPredkoscPrzod() = 0;

  virtual void ruch(char znak) = 0;
  virtual void updatePosition() = 0;
  virtual void rysujAll() = 0;
  virtual void wymaz() = 0;
};

#endif
