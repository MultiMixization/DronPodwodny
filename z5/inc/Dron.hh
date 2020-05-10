#ifndef DRON_HH
#define DRON_HH

#define ACCELERATION 0.01
#define ANGLEACCELERATION 0.10
#define FRAMETIME 48   //W milisekundach

#include <unistd.h>
#include <ncurses.h>
#include <sys/select.h>
#include <math.h>

#include "Punkt.hh"
#include "Wektor3D.hh"
#include "Dr3D_gnuplot_api.hh"
#include "Prostopadloscian.hh"

class Dron{
protected:
  Punkt pozycja;
  double PredkoscPrzod;
  double PredkoscPitch;
  double PredkoscYaw;
  double PredkoscRoll;

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
  
  void setPredkoscPrzod(double P) {PredkoscPrzod=P;}
  double getPredkoscPrzod() const {return PredkoscPrzod;}

  void setPredkoscPitch(double P) {PredkoscPitch=P;}
  double getPredkoscPitch() const {return PredkoscPitch;}

  void setPredkoscYaw(double P) {PredkoscYaw=P;}
  double getPredkoscYaw() const {return PredkoscYaw;}

  void setPredkoscRoll(double P) {PredkoscRoll=P;}
  double getPredkoscRoll() const {return PredkoscRoll;}

  void setPitch(double P) {pitch=P;}
  double getPitch() const {return pitch;}

  void setRoll(double R) {roll=R;}
  double getRoll() const {return roll;}

  void setYaw(double Y) {yaw=Y;}
  double getYaw() const {return yaw;}

  void ruch(std::shared_ptr<drawNS::Draw3DAPI> api);

  void rysuj(std::shared_ptr<drawNS::Draw3DAPI> api);
  
  void wymaz(std::shared_ptr<drawNS::Draw3DAPI> api);
  int rysKor(std::shared_ptr<drawNS::Draw3DAPI> api);
  int rysSrb1(std::shared_ptr<drawNS::Draw3DAPI> api);
  int rysSrb2(std::shared_ptr<drawNS::Draw3DAPI> api);
};

bool kbhit(); //Kod zapozyczony z neta
void delay(unsigned int msec);

#endif
