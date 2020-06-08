#include <iostream>
#include <math.h>

#include "Wektor3D.hh"
#include "Obiekt3D.hh"
#include "scena.hh"

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
