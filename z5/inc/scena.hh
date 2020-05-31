#ifndef SCENA_HH
#define SCENA_HH

#define FRAMETIME 33
#define SIZE 30

#include <iostream>
#include <ncurses.h>
#include <math.h>
#include <unistd.h>
#include <sys/select.h>
#include <vector>
#include <memory>
#include <string>
#include <stdlib.h>

#include "Dr3D_gnuplot_api.hh"
#include "MacierzObr.hh"
#include "Wektor3D.hh"
#include "Punkt.hh"
#include "DronInterface.hh"
#include "Dron.hh"
#include "Przeszkoda.hh"
#include "PrzeszkodaProstopadloscian.hh"
#include "Dno.hh"
#include "Woda.hh"

class scena{
protected:
  std::vector<std::shared_ptr<DroneInterface>> Drony;
  std::vector<std::shared_ptr<Przeszkoda>> Przeszkody;

public:
  scena(){}

  void inicjalizuj();
  
  void kontrola(int nrDrona);

  void sprzatanie();
};

bool kbhit(); //Kod zapozyczony z neta

void delay(unsigned int msec);

#endif
