#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include <iostream>

#include "Wektor.hh"
#include "Punkt.hh"
#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class Prostopadloscian : public Obiekt3D{
protected:
  Wektor3D referencyjny;      //referencyjny wektor prowadzacy od srodka do punktu referencyjnego(lewy, przedni, dolny)przy obrocie alfa=0

  void licz_obrot(Punkt wierzcholki[]);

public:
  Prostopadloscian() {};
  Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A) {api=A;}
  Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D R) {api=A; setRef(R);}
  Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzObr M, const Punkt S, const Wektor3D R);
  Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const double Ax, const double Ay, const double Az, const Punkt S, const Wektor3D R);
  
  void setRef(const Wektor3D & W) {referencyjny=W;}
  Wektor3D getRef() {return referencyjny;}
  
  void rysuj();
};

#endif
