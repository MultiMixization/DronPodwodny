#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>

#include "Wektor.hh"
#include "Punkt.hh"
#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class Prostopadloscian : public Obiekt3D{
  Punkt wierzcholki[8];      //Uzywane tylko do rysowania
  Wektor3D referencyjny;      //referencyjny wektor prowadzacy od srodka do punktu referencyjnego(lewy, przedni, dolny)przy obrocie alfa=0

public:
  Prostopadloscian(const Wektor3D R);
  Prostopadloscian(const MacierzObr & M, const Punkt & S, const Wektor3D & R);

  void licz_obrot();
  
  int rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif
