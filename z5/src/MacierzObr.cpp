#include "MacierzObr.hh"

MacierzObr::MacierzObr(const Wektor3D kat)
  {
    (*this)=MacierzObr(kat[2], Wektor3D(0,0,1)) * MacierzObr(kat[1], Wektor3D(0,1,0)) * MacierzObr(kat[0], Wektor3D(1,0,0));
  }

MacierzObr::MacierzObr(const double kat, const wymiar wym)
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

MacierzObr::MacierzObr(const double kat, const Wektor3D os)
{
  double temp=kat/180*M_PI;

  double c=cos(temp);
  double s=sin(temp);
  double t=1-c;

  double Magnitude=sqrt(os[0]*os[0]+os[1]*os[1]+os[2]*os[2]);
  if(Magnitude==0)
    {
      std::cerr << "Wektor zerowy." << std::endl;
      exit(8);
    }
  double x=os[0]/Magnitude;
  double y=os[1]/Magnitude;
  double z=os[2]/Magnitude;

  tab[0][0]=c+x*x*t;
  tab[1][1]=c+y*y*t;
  tab[2][2]=c+z*z*t;

  tab[0][1]=x*y*t-z*s;
  tab[0][2]=x*z*t+y*s;

  tab[1][0]=y*x*t+z*s;
  tab[1][2]=y*z*t-x*s;

  tab[2][0]=z*x*t-y*s;
  tab[2][1]=z*y*t+x*s;
}

MacierzObr MacierzObr::Obrot(const double kat, const wymiar wym)
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
  Wektor3D temp;

  if(tab[0][2]>-1.0000001 && tab[0][2]<-0.999999)
    {
      temp[0]=0;
      temp[1]=M_PI/2;
      temp[2]=temp[0]+atan2(tab[1][0],tab[2][0]);
      return temp*180/M_PI;
    }
  else if(tab[0][2]>0.999999 && tab[0][2]<1.0000001)
    {
      temp[0]=0;
      temp[1]=-M_PI/2;
      temp[2]=-temp[0]+atan2(-tab[1][0],-tab[2][0]);
      return temp*180/M_PI;
    }
  else
    {
      temp[0]=-asin(tab[0][2]);
      temp[1]=atan2(tab[1][2]/cos(temp[0]),tab[2][2]/cos(temp[0]));
      temp[2]=atan2(tab[0][1]/cos(temp[0]),tab[0][0]/cos(temp[0]));
      return temp*180/M_PI;
    }
}
