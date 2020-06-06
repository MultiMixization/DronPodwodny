#include "Wektor3D.hh"

int Wektor3D::Wszystkie=0;
int Wektor3D::Zniszczone=0;

Wektor3D Wektor3D::Odwroc(bool xx, bool yy, bool zz) const
{
  Wektor3D temp=(*this);
  if(xx==true)
    {
      temp[0]=temp[0]*(-1);
    }
  if(yy==true)
    {
      temp[1]=temp[1]*(-1);
    }
  if(zz==true)
    {
      temp[2]=temp[2]*(-1);
    }
  return temp;
}
