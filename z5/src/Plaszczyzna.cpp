#include "Plaszczyzna.hh"

using std::string;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Plaszczyzna::rysuj()
{
  setOrientacja(MacierzObr(0,z)*MacierzObr(0,y)*MacierzObr(0,x));
  vector<vector<Point3D>> PD;
  
  for(int j=-wielkosc;j<=wielkosc; ++j)
    {
      vector<Point3D> PM;
      for(int i=-wielkosc; i<=wielkosc; ++i)
	{
	  Wektor3D tempW(getSrodek()[0]+i*PLANESKIP, getSrodek()[1]+j*PLANESKIP, getSrodek()[2]);
	  tempW=getOrientacja()*tempW;
	  PM.push_back(tempW);
	}
      PD.push_back(PM);
    }
  id=api->draw_surface(PD, "black");
}
