#ifndef WEKTOR_HH
#define WEKTOR_HH

class Wektor{
  double x;
  double y;
  double z;

public:
  Wektor();
  Wektor(double xx, double yy, double zz);
  Wektor(const Wektor &W);

  const double & operator [](char wsp) const;
  double & operator [](char wsp);
  
  Wektor operator +(const Wektor &W2)const;
  Wektor operator -(const Wektor &W2)const;
  double operator *(const Wektor &W2)const;
  Wektor operator *(const double &l2)const;
  Wektor operator /(const double &l2)const;

  bool operator ==(const Wektor &W2)const;
  bool operator !=(const Wektor &W2)const;
};

Wektor operator *(double l1, Wektor &W2);

#endif
