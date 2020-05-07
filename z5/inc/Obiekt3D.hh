#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include <iostream>

#include "Wektor.hh"
#include "Wektor3D.hh"
#include "Macierz.hh"
#include "MacierzObr.hh"
#include "Punkt.hh"

class Obiekt3D{
protected:
  MacierzObr Orientacja;
  Punkt Srodek;
public:
  void setOrientacja(const Wektor3D W) {Orientacja=W;};
  MacierzObr getOrientacja() const {return Orientacja;};

  void setSrodek(const Punkt P) {Srodek=P;};
  Punkt getSrodek() const {return Srodek;};
};

#endif
