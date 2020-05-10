#ifndef MACIERZOBR_HH
#define MACIERZOBR_HH

#include <iostream>
#include <math.h>

#include "Macierz.hh"
#include "Wektor3D.hh"

enum wymiar{x, y, z};

class MacierzObr : public Macierz<double, 3>{
public:
  MacierzObr() : Macierz<double, 3>() {}
  MacierzObr(Wektor3D kat);
  MacierzObr(double kat, wymiar wym);
  MacierzObr(const Macierz<double, 3> M) : Macierz<double, 3>(M) {}

  MacierzObr Obrot(double kat, wymiar wym);
};

Wektor3D operator *(const Wektor3D W, const MacierzObr M); //Do obrotu wektora

#endif
