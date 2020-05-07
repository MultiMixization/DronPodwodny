#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>

#include "Wektor.hh"
#include "Punkt.hh"
#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class Prostopadloscian : public Obiekt3D{
  Punkt wierzcholki[8];      //Uzywane tylko do rysowania

public:

  void odswiez();
  int rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif
