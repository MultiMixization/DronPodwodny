#ifndef DRONEINTERFACE_HH
#define DRONEINTERFACE_HH

#include "Preszkoda.hh"
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

  virtual void setOrientacja(const MacierzObr M) = 0;
  virtual MacierzObr getOrientacja() = 0;
  virtual void setPredkoscPrzod(double P) = 0;
  virtual double getPredoscPrzod() = 0;
  virtual void setPredkoscPitch(double P) = 0;
  virtual double getPredkoscPitch() = 0;
  virtual void setPredkoscYaw(double P) = 0;
  virtual double getPredkoscYaw() = 0;
  virtual void setPredkoscRoll(double P) = 0;
  virtual double getPredksocRoll() = 0;

  virtual void ruch(char znak) = 0;
  virtual void rysujAll() = 0;
  virtual void wymaz() = 0;
};

#endif
