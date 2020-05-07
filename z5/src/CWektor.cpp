#include <iostream>

#include "Wektor.cpp"

template class Wektor<double,2>;
template std::istream& operator >> (std::istream &Strm, Wektor<double, 2> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 2> &Wek);
template Wektor<double,2> operator *(double a, const Wektor<double,2> &W2);

template class Wektor<double,3>;
template std::istream& operator >> (std::istream &Strm, Wektor<double, 3> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 3> &Wek);
template Wektor<double,3> operator *(double a, const Wektor<double,3> &W2);

template class Wektor<double,4>;
template std::istream& operator >> (std::istream &Strm, Wektor<double, 4> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 4> &Wek);
template Wektor<double,4> operator *(double a, const Wektor<double,4> &W2);

template class Wektor<double,5>;
template std::istream& operator >> (std::istream &Strm, Wektor<double, 5> &Wek);
template std::ostream& operator << (std::ostream &Strm, const Wektor<double, 5> &Wek);
template Wektor<double,5> operator *(double a, const Wektor<double,5> &W2);
