#include "Wektor.hh"

template <typename typ, int rozmiar>
const typ & Wektor<typ, rozmiar>::operator [](int index) const
{
  if(index<0 || index >=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return tab[index];
}

template <typename typ, int rozmiar>
typ & Wektor<typ, rozmiar>::operator [](int index)
{
  if(index<0 || index >=rozmiar)
    {
      std::cerr << "Poza Zakresem." << std::endl;
      exit(1);
    }
  return tab[index];
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> Wektor<typ, rozmiar>::operator +(const Wektor<typ, rozmiar> & W2) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]+W2[i];
    }
  return temp;
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> Wektor<typ, rozmiar>::operator -(const Wektor<typ, rozmiar> & W2) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]-W2[i];
    }
  return temp;
}

template <typename typ, int rozmiar>
typ Wektor<typ, rozmiar>::operator *(const Wektor<typ, rozmiar> & W2) const
{
  typ wynik(0.0);
  for(int i=0;i<rozmiar;i++)
    {
      wynik=wynik+((*this)[i]*W2[i]);
    }
  return wynik;
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> Wektor<typ, rozmiar>::operator *(const typ & ls) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]*ls;
    }
  return temp;
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> Wektor<typ, rozmiar>::operator /(const typ & ls) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]/ls;
    }
  return temp;
}


template <typename typ, int rozmiar>
double Wektor<typ, rozmiar>::dlugosc() const
{
  double sum=0;
  for(int i=0;i<rozmiar;i++)
    {
      sum=(*this)[i]*((*this)[i])+sum;
    }
  return sqrt(sum);
}

template <typename typ, int rozmiar>
bool Wektor<typ, rozmiar>::operator ==(const Wektor<typ, rozmiar> &W2) const
{
  for(int i=0;i<rozmiar;i++)
    {
      if(abs((*this)[i]-W2[i])>0.000000001)
	{
	  return 0;
	}
    }
  return 1;
}

template <typename typ, int rozmiar>
bool Wektor<typ, rozmiar>::operator !=(const Wektor<typ, rozmiar> &W2) const
{
  return !((*this)==W2);
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> Wektor<typ, rozmiar>::swap(int w1, int w2) const
{
  Wektor<typ, rozmiar> W(*this);
  if(w1<0 || w1>=rozmiar || w2<0 || w2>=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  typ temp(W[w1]);
  W[w1]=W[w2];
  W[w2]=temp;
  return W;
}


template <typename typ, int rozmiar>
std::istream &operator >> (std::istream &Strm, Wektor<typ, rozmiar> &Wek)
{
  for(int i=0;i<rozmiar;i++)
    {
      Strm >> Wek[i];
    }
  return Strm;
}

template <typename typ, int rozmiar>
std::ostream &operator << (std::ostream &Strm, const Wektor<typ, rozmiar> &Wek)
{
  for(int i=0;i<rozmiar;i++)
    {
      Strm << Wek[i] << " ";
    }
  return Strm;
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> operator *(typ a, const Wektor<typ, rozmiar> &W2)
{
  return W2*a;
}
