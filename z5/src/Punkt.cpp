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
