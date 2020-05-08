#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(const Wektor3D R)
{
  referencyjny=R;
  licz_obrot();
}

Prostopadloscian::Prostopadloscian(const MacierzObr & M, const Punkt & S, const Wektor3D & R)
{
  Srodek=S;
  referencyjny=R;
  Orientacja=M;
  licz_obrot();
}

void Prostopadloscian::licz_obrot()
{
  wierzcholki[0]=Srodek.Translacja(Orientacja*referencyjny);
  wierzcholki[1]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(1,0,0));
  wierzcholki[2]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(1,1,0));
  wierzcholki[3]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(0,1,0));
  wierzcholki[4]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[5]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(1,0,1));
  wierzcholki[6]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(1,1,1));
  wierzcholki[7]=Srodek.Translacja(Orientacja*referencyjny.Odwroc(0,1,1));
}

int Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  int temp=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {
      {drawNS::Point3D(wierzcholki[0]), drawNS::Point3D(wierzcholki[1]), drawNS::Point3D(wierzcholki[4]), drawNS::Point3D(wierzcholki[3])},
	{drawNS::Point3D(wierzcholki[0]), drawNS::Point3D(wierzcholki[1]), drawNS::Point3D(wierzcholki[4]), drawNS::Point3D(wierzcholki[3])} 
    }, "red");

  return temp;
}
