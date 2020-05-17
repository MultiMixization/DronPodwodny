#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#define PLANEPOINT 10
#define PLANESKIP 5

#include <vector>
#include <iostream>
#include <string>

#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class Plaszczyzna : public Obiekt3D{
protected:
  double poziom;

public:
  Plaszczyzna(std::shared_ptr<drawNS::Draw3DAPI> A, double P=0) : Obiekt3D(A) {}

  void setPoziom(const double P) {poziom=P;}
  double getPoziom() const {return poziom;}

  void rysuj();
};

#endif
