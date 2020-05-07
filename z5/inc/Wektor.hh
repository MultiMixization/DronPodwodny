#ifndef WEKTOR_HH
#define WEKTOR_HH

#include <iostream>
#include <cmath>

template <typename typ, int rozmiar>
class Wektor {
protected:
  typ tab[rozmiar];
  
public:
  Wektor<typ, rozmiar>(){for(typ &Wsp: tab) Wsp=0;};

  const typ & operator [](int index) const;
  typ & operator [](int index);
  
  Wektor<typ, rozmiar> operator +(const Wektor<typ, rozmiar> &W2)const;
  Wektor<typ, rozmiar> operator -(const Wektor<typ, rozmiar> &W2)const;
  typ operator *(const Wektor<typ, rozmiar> &W2)const;
  Wektor<typ, rozmiar> operator *(const typ &l2)const;
  Wektor<typ, rozmiar> operator /(const typ &l2)const;

  double dlugosc() const;

  bool operator ==(const Wektor<typ, rozmiar> &W2)const;
  bool operator !=(const Wektor<typ, rozmiar> &W2)const;

  Wektor<typ, rozmiar> swap(int w1, int w2) const;
};

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, Wektor<typ, rozmiar> &Wek);

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Wektor<typ, rozmiar> &Wek);

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> operator *(typ a, const Wektor<typ, rozmiar> &W2);

#endif
