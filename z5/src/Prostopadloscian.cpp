#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzObr M, const Punkt S, const Wektor3D R)
{
  setApi(A);
  setSrodek(S);
  setRef(R);
  setOrientacja(M);
}

Prostopadloscian::Prostopadloscian(std::shared_ptr<drawNS::Draw3DAPI> A, const double Ax, const double Ay, const double Az, const Punkt S, const Wektor3D R)
{
  setApi(A);
  setSrodek(S);
  setRef(R);
  MacierzObr temp=MacierzObr(Az,z)*MacierzObr(Ay, y)*MacierzObr(Ax, x);
  setOrientacja(temp);
}

void Prostopadloscian::licz_obrot(Punkt wierzcholki[])
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

void Prostopadloscian::rysuj()
{
  Punkt wierzcholki[8];
  licz_obrot(wierzcholki);
  id=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {
      {drawNS::Point3D(wierzcholki[0]), drawNS::Point3D(wierzcholki[1]), drawNS::Point3D(wierzcholki[2]), drawNS::Point3D(wierzcholki[3])},
	{drawNS::Point3D(wierzcholki[4]), drawNS::Point3D(wierzcholki[5]), drawNS::Point3D(wierzcholki[6]), drawNS::Point3D(wierzcholki[7])} 
    }, "red");
}
