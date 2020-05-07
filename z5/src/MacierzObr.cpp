#include "MacierzObr.hh"

MacierzObr::MacierzObr(Wektor3D kat)
  {
    (*this)=MacierzObr(kat[0], x) * MacierzObr(kat[1], y) * MacierzObr(kat[2], z);
  }

MacierzObr::MacierzObr(double kat, wymiar wym)
{
  double temp=kat/180*M_PI;   //M_PI z math.h
  switch (wym)
    {
    case x:
      tab[1][1]=cos(temp);                 //Schematy wziete z wikipedii
      tab[1][2]=sin(temp);
      tab[2][1]=-sin(temp);
      tab[2][2]=cos(temp);
      
      tab[0][2]=0;
      tab[0][1]=0;
      tab[2][0]=0;
      tab[1][0]=0;
      
      tab[0][0]=1;
      break;
    case y:
      tab[2][2]=cos(temp);
      tab[2][0]=sin(temp);
      tab[0][2]=-sin(temp);
      tab[0][0]=cos(temp);
      
      tab[1][0]=0;
      tab[2][1]=0;
      tab[0][1]=0;
      tab[1][2]=0;
      
      tab[1][1]=1;
      break;
    case z:
      tab[0][0]=cos(temp);
      tab[1][0]=-sin(temp);
      tab[0][1]=sin(temp);
      tab[1][1]=cos(temp);
      
      tab[2][0]=0;
      tab[2][1]=0;
      tab[0][2]=0;
      tab[1][2]=0;

      tab[2][2]=1;
      break;
    }
}

MacierzObr MacierzObr::Obrot(double kat, wymiar wym)
{
  double temp=kat/180*M_PI;   //M_PI z math.h
  switch (wym)
    {
    case x:
      tab[1][1]=cos(temp);                 //Schematy wziete z wikipedii
      tab[1][2]=sin(temp);
      tab[2][1]=-sin(temp);
      tab[2][2]=cos(temp);
      
      tab[0][2]=0;
      tab[0][1]=0;
      tab[2][0]=0;
      tab[1][0]=0;
      
      tab[0][0]=1;
      break;
    case y:
      tab[2][2]=cos(temp);
      tab[2][0]=sin(temp);
      tab[0][2]=-sin(temp);
      tab[0][0]=cos(temp);
      
      tab[1][0]=0;
      tab[2][1]=0;
      tab[0][1]=0;
      tab[1][2]=0;
      
      tab[1][1]=1;
      break;
    case z:
      tab[0][0]=cos(temp);
      tab[1][0]=-sin(temp);
      tab[0][1]=sin(temp);
      tab[1][1]=cos(temp);
      
      tab[2][0]=0;
      tab[2][1]=0;
      tab[0][2]=0;
      tab[1][2]=0;
      
      tab[2][2]=1;
      break;
    }
  return (*this);
}
