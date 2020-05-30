#ifndef SCENA_HH
#define SCENA_HH

#define FRAMETIME 33

#include <iostream>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <sys/select.h>

#include "Dr3D_gnuplot_api.hh"
#include "MacierzObr.hh"
#include "Wektor3D.hh"
#include "Punkt.hh"
#include "Dron.hh"
#include "DronInterface.hh"
#include "Przeszkoda.hh"
#include "PrzeszkodaProstopadloscian.hh"
#include "Plaszczyzna.hh"
#include "Woda.hh"

class scena{
protected:
  Dron dron;
  Woda woda;
  Plaszczyzna dno;

public:
  scena(std::shared_ptr<drawNS::Draw3DAPI> A) : dron(A), woda(A), dno(A) {}

  void inicjalizuj();
  
  void kontrola();

  void sprzatanie();
};

bool kbhit(); //Kod zapozyczony z neta

void delay(unsigned int msec);

#endif
