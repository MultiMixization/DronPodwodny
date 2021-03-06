#ifndef OBIEKT3D_HH
#define OBIEKT3D_HH

#include <iostream>

#include "Wektor3D.hh"
#include "MacierzObr.hh"
#include "Punkt.hh"
#include "Dr3D_gnuplot_api.hh"

class Obiekt3D{
protected:
  std::shared_ptr<drawNS::Draw3DAPI> api;
  MacierzObr Orientacja;
  Punkt Srodek;
  int id;

  static int Wszystkie;
  static int Zniszczone;
public:
  Obiekt3D() {Wszystkie++;};
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A) {api=A; id=-1; Wszystkie++;}
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, MacierzObr M, Punkt P) {api=A; Orientacja=M; Srodek=P; id=-1; Wszystkie++;}
  Obiekt3D(std::shared_ptr<drawNS::Draw3DAPI> A, Punkt S) {api=A; Srodek=S; id=-1; Wszystkie++;}
  ~Obiekt3D() {zmaz(); Zniszczone++;}

  static int getWszystkie(){return Wszystkie;}
  static int getZniszczone(){return Zniszczone;}
  
  void setOrientacja(const MacierzObr M) {Orientacja=M;};
  MacierzObr getOrientacja() const {return Orientacja;};

  void setSrodek(const Punkt P) {Srodek=P;};
  Punkt getSrodek() const {return Srodek;};

  void setApi(const std::shared_ptr<drawNS::Draw3DAPI> A) {api=A;}
  std::shared_ptr<drawNS::Draw3DAPI> getApi() const {return api;}

  int getID() {return id;}

  virtual void rysuj() = 0;

  void zmaz() {if(id!=-1)api->erase_shape(id); id=-1;}
};

#endif
