#include <iostream>

#include"Macierz.cpp"

template class Macierz<double, 3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 3> &Mac);
template Macierz<double, 3> operator *(double l, const Macierz<double, 3> M);

template class Macierz<double, 4>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 4> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 4> &Mac);
template Macierz<double, 4> operator *(double l, const Macierz<double, 4> M);

template class Macierz<double, 5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 5> &Mac);
template Macierz<double, 5> operator *(double l, const Macierz<double, 5> M);
