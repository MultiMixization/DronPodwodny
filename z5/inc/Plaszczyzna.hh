#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#define PLANEPOINT 10
#define PLANESKIP 5

#include <vector>
#include <iostream>
#include <string>
#include <iostream>

#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class Plaszczyzna : public Obiekt3D{
protected:
  int wielkosc;

public:
  Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> A, double P=0, int S=PLANEPOINT) : Obiekt3D(A, Punkt(0,0,P)){wielkosc=S;}

  void setWielkosc(const int P) {wielkosc=P;}
  double getWielkosc() const {return wielkosc;}

  virtual void rysuj() override;
};

#endif
