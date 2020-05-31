#include <iostream>
#include <math.h>

#include "Dr3D_gnuplot_api.hh"
#include "Wektor3D.hh"
#include "MacierzObr.hh"
#include "Dron.hh"
#include "scena.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key()
{
  do{
    cout << "\n Press a key to continue..." << std::endl;
  }while(std::cin.get() != '\n');
}

int main()
{
  scena glowna;
  glowna.inicjalizuj();
  glowna.kontrola(0);
  glowna.sprzatanie();
  
  return 0;
}
