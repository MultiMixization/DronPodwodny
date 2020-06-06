#include <iostream>
#include <math.h>

#include "Dr3D_gnuplot_api.hh"
#include "Wektor3D.hh"
#include "Obiekt3D.hh"
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
  int wybor=1;
  scena glowna;
  glowna.inicjalizuj();
  while(wybor!=0)
    {
      std::cout << "Wybierz nr drona do sterowania.(0 zakancza program)" << std::endl;
      std::cin >> wybor;
      if(wybor!=0)
	{
	    if(wybor!=1 && wybor!=2 && wybor!=3)
	      {
		std::cerr << "Brak drona o powyzszym numerze! Wybierz ponownie." << std::endl;
	      }
	    else
	      {
		glowna.kontrola(wybor-1);
	      }
	}
    }
  glowna.sprzatanie();
  std::cout << "-- Statystyka --" << std::endl;
  std::cout << "Stworzone Wektory3D: " << Wektor3D::getWszystkie() << std::endl;
  std::cout << "Zniszczone Wektory3D: " << Wektor3D::getZniszczone() << std::endl;
  std::cout << "Stworzone Obiekty3D: " << Obiekt3D::getWszystkie() << std::endl;
  std::cout << "Zniszczone Obiekty3D: " << Obiekt3D::getZniszczone() << std::endl;
  
  
  return 0;
}
