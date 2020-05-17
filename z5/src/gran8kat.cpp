#include "gran8kat.hh"

gran8kat::gran8kat(std::shared_ptr<drawNS::Draw3DAPI> A, const MacierzObr M, const Punkt S, const Wektor3D R)
{
  setApi(A);
  setSrodek(S);
  setRef(R);
  setOrientacja(M);
}

gran8kat::gran8kat(std::shared_ptr<drawNS::Draw3DAPI> A, const double Ax, const double Ay, const double Az, const Punkt S, const Wektor3D R)
{
  setApi(A);
  setSrodek(S);
  setRef(R);
  MacierzObr temp=MacierzObr(Az,z)*MacierzObr(Ay, y)*MacierzObr(Ax, x);
  setOrientacja(temp);
}

void gran8kat::licz_obrot(Punkt wierzcholki[])
{
  wierzcholki[0]=Srodek.Translacja(MacierzObr(0,z)*Orientacja*referencyjny);
  wierzcholki[1]=Srodek.Translacja(MacierzObr(45,z)*Orientacja*referencyjny);
  wierzcholki[2]=Srodek.Translacja(MacierzObr(90,z)*Orientacja*referencyjny);
  wierzcholki[3]=Srodek.Translacja(MacierzObr(135,z)*Orientacja*referencyjny);
  wierzcholki[4]=Srodek.Translacja(MacierzObr(180,z)*Orientacja*referencyjny);
  wierzcholki[5]=Srodek.Translacja(MacierzObr(225,z)*Orientacja*referencyjny);
  wierzcholki[6]=Srodek.Translacja(MacierzObr(270,z)*Orientacja*referencyjny);
  wierzcholki[7]=Srodek.Translacja(MacierzObr(315,z)*Orientacja*referencyjny);
  wierzcholki[8]=Srodek.Translacja(MacierzObr(0,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[9]=Srodek.Translacja(MacierzObr(45,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[10]=Srodek.Translacja(MacierzObr(90,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[11]=Srodek.Translacja(MacierzObr(135,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[12]=Srodek.Translacja(MacierzObr(180,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[13]=Srodek.Translacja(MacierzObr(225,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[14]=Srodek.Translacja(MacierzObr(270,z)*Orientacja*referencyjny.Odwroc(0,0,1));
  wierzcholki[15]=Srodek.Translacja(MacierzObr(315,z)*Orientacja*referencyjny.Odwroc(0,0,1));
}

void gran8kat::rysuj()
{
  Punkt wierzcholki[16];
  licz_obrot(wierzcholki);
  id=api->draw_polyhedron(std::vector<std::vector<drawNS::Point3D> > {
      {drawNS::Point3D(wierzcholki[0]), drawNS::Point3D(wierzcholki[1]), drawNS::Point3D(wierzcholki[2]), drawNS::Point3D(wierzcholki[3]), drawNS::Point3D(wierzcholki[4]), drawNS::Point3D(wierzcholki[5]), drawNS::Point3D(wierzcholki[6]), drawNS::Point3D(wierzcholki[7])},
	{drawNS::Point3D(wierzcholki[8]), drawNS::Point3D(wierzcholki[9]), drawNS::Point3D(wierzcholki[10]), drawNS::Point3D(wierzcholki[11]), drawNS::Point3D(wierzcholki[12]), drawNS::Point3D(wierzcholki[13]), drawNS::Point3D(wierzcholki[14]), drawNS::Point3D(wierzcholki[15])} 
    }, "red");
}
