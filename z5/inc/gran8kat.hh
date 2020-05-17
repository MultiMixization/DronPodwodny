#ifndef GRAN8KAT_HH
#define GRAN8KAT_HH

#include "Wektor.hh"
#include "Punkt.hh"
#include "Obiekt3D.hh"
#include "Dr3D_gnuplot_api.hh"

class gran8kat : public Obiekt3D{
protected:
  Wektor3D referencyjny;

  void licz_obrot(Punkt wierzcholki[]);

public:
  gran8kat() {};
  gran8kat(std::shared_ptr<drawNS::Draw3DAPI> A) {api=A;}
  gran8kat(std::shared_ptr<drawNS::Draw3DAPI> A, const Wektor3D R) {api=A; setRef(R);}
  gran8kat(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzObr M, const Punkt S, const Wektor3D R);
  gran8kat(std::shared_ptr<drawNS::Draw3DAPI> A, const double Ax, const double Ay, const double Az, const Punkt S, const Wektor3D R);

  void setRef(const Wektor3D & W) {referencyjny=W;}
  Wektor3D getRef() {return referencyjny;}
  
  void rysuj();
};

#endif
