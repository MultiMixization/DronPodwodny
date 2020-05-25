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

Wektor3D operator *(const Wektor3D W, const MacierzObr M)
{
  Wektor3D temp;
  temp[0]=M[0][0]*W[0]+M[1][0]*W[1]+M[2][0]*W[2];
  temp[1]=M[0][1]*W[0]+M[1][1]*W[1]+M[2][1]*W[2];
  temp[2]=M[0][2]*W[0]+M[1][2]*W[1]+M[2][2]*W[2];
  return temp;
}

Wektor3D MacierzObr::Euler()
{
  double sy=sqrt(tab[0][0]*tab[0][0]+tab[1][0]*tab[1][0]);

  bool singular = sy<1e-6;

  Wektor3D temp;
  if(!singular)
    {
      temp[0]=atan2(tab[2][1],tab[2][2])*180/M_PI;
      temp[1]=atan2(-tab[2][0],sy)*180/M_PI;
      temp[2]=atan2(tab[1][0],tab[0][0])*180/M_PI;
    }
  else
    {
      temp[0]=atan2(-tab[1][2],tab[1][1])*180/M_PI;
      temp[1]=atan2(-tab[2][0],sy)*180/M_PI;
      temp[2]=0;
    }
  return temp;
}
