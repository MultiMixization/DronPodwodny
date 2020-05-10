#ifndef DRON_HH
#define DRON_HH

#include "Punkt.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"

class Dron{
protected:
  Punkt pozycja;
  double predkosc;

  //Katy
  double pitch;
  double roll;
  double yaw;

  //Obiekty doloczone
  Prostopadloscian Korpus;
  Prostopadloscian Sruba1;
  Prostopadloscian Sruba2;

  Wektor3D rozmKor;   //Rozmiar korpusu
  Wektor3D rozmSrb1;  //Rozmiar silnika 1
  Wektor3D rozmSrb2;  //Rozmiar silnika 2

  //Wektory do srodkow obiektow dolaczonych
  Wektor3D WekSruba1;
  Wektor3D WekSruba2;

public:
  Dron();

  void setPozycja(Punkt P) {pozycja=P;}
  Punkt getPozycja() const {return pozycja;}
  
  void setPredkosc(double P) {predkosc=P;}
  double getPredkosc() const {return predkosc;}

  void setPitch(double P) {pitch=P;}
  double getPitch() const {return pitch;}

  void setRoll(double R) {roll=R;}
  double getRoll() const {return roll;}

  void setYaw(double Y) {yaw=Y;}
  double getYaw() const {return yaw;}

  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
  
  void wymaz(std::shared_ptr<drawNS::Draw3DAPI> api);
  int rysKor(std::shared_ptr<drawNS::Draw3DAPI> api);
  int rysSrb1(std::shared_ptr<drawNS::Draw3DAPI> api);
  int rysSrb2(std::shared_ptr<drawNS::Draw3DAPI> api);
};

#endif
