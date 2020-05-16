#include <iostream>

#define SIZE 10

#include <iostream>

#include "Dr3D_gnuplot_api.hh"
#include "Wektor3D.hh"
#include "MacierzObr.hh"
#include "Dron.hh"

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
  std::cin.tie(NULL); //Przyspiesz wyswietlanie tekstu co zwieksza responsywnosc
  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-SIZE,SIZE,-SIZE,SIZE,-SIZE,SIZE));
  api->change_ref_time_ms(0);
  
  Dron droniszcze(api);
  droniszcze.rysujAll();
  droniszcze.ruch();
  droniszcze.wymaz();
  return 0;
}
