#ifndef MACIERZ_HH
#define MACIERZ_HH

#include <iostream>
#include "Wektor.hh"

template<typename typ, int rozmiar>
class Macierz {
protected:         //Zeby bylo dostepne dla MacierzObr
  Wektor<typ, rozmiar> tab[rozmiar];

  typ dopelnienie(int x, int y) const;
public:
  Macierz() {for(int j=0;j<rozmiar;j++){for(int i=0;i<rozmiar;i++){this->tab[i][j]=0;}}};

  const Wektor<typ, rozmiar> & operator [] (int index) const;
  Wektor<typ, rozmiar> & operator [](int index);
  
  typ wyznacznik()const;

  Macierz<typ, rozmiar> operator +(const Macierz<typ, rozmiar> &B) const;
  Macierz<typ, rozmiar> operator -(const Macierz<typ, rozmiar> &B)const;
  Macierz<typ, rozmiar> operator *(const Macierz<typ, rozmiar> &B)const;
  Macierz<typ, rozmiar> operator *(typ B)const;
  Wektor<typ, rozmiar> operator *(const Wektor<typ, rozmiar> &W)const;

  bool operator ==(const Macierz<typ, rozmiar> &W2)const;
  bool operator !=(const Macierz<typ, rozmiar> &W2)const;

  Macierz<typ, rozmiar> ZamienKolumny(int k1, int k2)const;
  Macierz<typ, rozmiar> ZamienWiersze(int w1, int w2)const;

  Macierz<typ, rozmiar> transponuj() const;
  Macierz<typ, rozmiar> odwroc() const;
};

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, Macierz<typ, rozmiar> &Mac);

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<typ, rozmiar> &Mac);

template <typename typ, int rozmiar>
Macierz<typ, rozmiar> operator *(typ l, const Macierz<typ, rozmiar> M);

#endif
