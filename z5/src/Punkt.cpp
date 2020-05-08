#include "Punkt.hh"

const double & Punkt::operator [](int index) const
{
  if(index<0 || index>3)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  return wspl[index];
}

double & Punkt::operator [](int index)
{
  if(index<0 || index>3)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  return wspl[index];
}

Punkt Punkt::Translacja(const Wektor3D W)
{
  Punkt temp;

  temp[0]=(*this)[0]+W[0];
  temp[1]=(*this)[1]+W[1];
  temp[2]=(*this)[2]+W[2];

  return temp;
}
