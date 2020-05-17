#include "Plaszczyzna.hh"
#include <iostream>

using std::string;
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;

void Plaszczyzna::rysuj()
{
  setOrientacja(MacierzObr(0,z)*MacierzObr(0,y)*MacierzObr(0,x));
  vector<vector<Point3D>> PD;

  for(int j=-PLANEPOINT;j<=PLANEPOINT; ++j)
    {
      vector<Point3D> PM;
      for(int i=-PLANEPOINT; i<=PLANEPOINT; ++i)
	{
	  Wektor3D tempW(i*PLANESKIP, j*PLANESKIP, poziom);
	  tempW=getOrientacja()*tempW;
	  PM.push_back(tempW);
	}
      PD.push_back(PM);
    }
  id=api->draw_surface(PD, "black");
}
