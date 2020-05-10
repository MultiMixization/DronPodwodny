#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include <iostream>

#include "Wektor3D.hh"
#include "MacierzObr.hh"
#include "Punkt.hh"
#include "Dr3D_gnuplot_api.hh"

class Obiekt3D{
protected:
  MacierzObr Orientacja;
  Punkt Srodek;
  int id;
public:
  Obiekt3D(): id(-1) {}
  Obiekt3D(MacierzObr M, Punkt P) : Orientacja(M), Srodek(P), id(-1) {}
  
  void setOrientacja(const MacierzObr M) {Orientacja=M;};
  MacierzObr getOrientacja() const {return Orientacja;};

  void setSrodek(const Punkt P) {Srodek=P;};
  Punkt getSrodek() const {return Srodek;};

  int getID() {return id;}

  void zmaz(std::shared_ptr<drawNS::Draw3DAPI> api) {if(id!=-1)api->erase_shape(id);}
};

#endif
