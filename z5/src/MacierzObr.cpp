#include "MacierzObr.hh"

MacierzObr::MacierzObr(Wektor3D kat)
  {
    (*this)=MacierzObr(kat[2], z) * MacierzObr(kat[1], y) * MacierzObr(kat[0], x);
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

MacierzObr::MacierzObr(double kat, Wektor3D os)
{
  double temp=kat/180*M_PI;
  
  double c=cos(temp);
  double s=sin(temp);
  double t=1.0-c;

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

  double temp1=x*y*t;
  double temp2=z*s;

  tab[1][0]=temp1+temp2;
  tab[0][1]=temp1-temp2;
  
  temp1=x*z*t;
  temp2=y*s;

  tab[2][0]=temp1-temp2;
  tab[0][2]=temp1+temp2;

  temp1=y*z*t;
  temp2=x*s;

  tab[2][1]=temp1+temp2;
  tab[1][2]=temp1-temp2;
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
