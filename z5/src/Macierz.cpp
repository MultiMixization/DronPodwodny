#include "Macierz.hh"

template<typename typ, int rozmiar>
const Wektor<typ, rozmiar> & Macierz<typ, rozmiar>::operator [](int index) const
{
  if(index<0 || index>=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return this->tab[index];
}

template<typename typ, int rozmiar>
Wektor<typ, rozmiar> & Macierz<typ, rozmiar>::operator [](int index)
{
  if(index<0 || index >=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return this->tab[index];
}

template<typename typ, int rozmiar>
typ Macierz<typ, rozmiar>::wyznacznik() const //Gauss
{
  Macierz<typ, rozmiar> Mtemp(*this);
  typ temp(1);
  for(int i=0;i<rozmiar;i++)
    {
      bool flaga=false;
      int j=i;
      while(!flaga && j<rozmiar)
	{
	  if(Mtemp[i][j]!=0)
	    {
	      if(i!=j)
		{
		  Mtemp=Mtemp.ZamienKolumny(i,j);
		  temp=temp*(-1);
		}
	      flaga=true;
	    }
	  j++;
	}
      if(!flaga)
	{
	  temp=0;
	  return temp;
	}
      for(int k=i+1;k<rozmiar;k++)
	{
	  Mtemp[k]=Mtemp[k]-Mtemp[i]*(Mtemp[k][i]/Mtemp[i][i]);
	}
    }
  for(int i=0;i<rozmiar;i++)
    {
      temp=temp*Mtemp[i][i];
    }
  return temp;
}

template<typename typ, int rozmiar>
typ Macierz<typ, rozmiar>::dopelnienie(int x, int y) const
{
  Macierz<typ, rozmiar-1> MPom;
  if(x<0 || x>=rozmiar || y<0 || y>=rozmiar)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }

  int b=0;
  for(int i=0;i<rozmiar;i++)
    {
      if(i!=x)
	{
	  int a=0;
	  for(int j=0;j<rozmiar;j++)
	    {
	      if(j!=y)
		{
		  MPom[a][b]=(*this)[i][j];
		  a++;
		}
	    }
	  b++;
	}
    }     //To powinno dac macierz po wykresleniu kolumny i wiersza

  if(x+y%2==0)
    {
      return MPom.wyznacznik();
    }
  else
    {
      return MPom.wyznacznik()*(-1);
    }
  }

template<typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::operator +(const Macierz<typ, rozmiar> &B) const
{
  Macierz<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      wynik[i]=(*this)[i]+B[i];
    }
  return wynik;
}

template<typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::operator -(const Macierz<typ, rozmiar> &B) const
{
  Macierz<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      wynik[i]=(*this)[i]-B[i];
    }
  return wynik;
}

template<typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::operator *(const Macierz<typ, rozmiar> &B) const
{
  Macierz<typ, rozmiar> MATrans((*this).transponuj());
  Macierz<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  temp[j][i]=temp[j][i]+MATrans[j]*B[i];
	}
    }
  return temp;
}

template<typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::operator *(const typ B) const
{
  Macierz<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      wynik[i]=(*this)[i]*B;
    }
  return wynik;
}

template<typename typ, int rozmiar>
Wektor<typ, rozmiar> Macierz<typ, rozmiar>::operator *(const Wektor<typ, rozmiar> &W) const
{
  Wektor<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  wynik[i]=wynik[i]+(*this)[j][i]*W[j];
	}
    }
  return wynik;
}

template<typename typ, int rozmiar>
bool Macierz<typ, rozmiar>::operator ==(const Macierz<typ, rozmiar> &W2)const
{
  for(int i=0;i<rozmiar;i++)
    {
      if((*this)[i]!=W2[i])
	{
	  return 0;
	}
    }
  return 1;
}

template<typename typ, int rozmiar>
bool Macierz<typ, rozmiar>::operator !=(const Macierz<typ, rozmiar> &W2)const
{
  return !(*this==W2);
}

template<typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::transponuj() const
{
  Macierz<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  temp[i][j]=(*this)[j][i];
	}
    }
  return temp;
}

template<typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::odwroc() const
{
  Macierz<typ, rozmiar> temp;
  typ Wyzn=(*this).wyznacznik();
  if(Wyzn==0)
    {
      std::cerr << "Wyznacznik 0." << std::endl;
      exit(4);
    }
  else
    {
      for(int i=0;i<rozmiar;i++)
	{
	  for(int j=0;j<rozmiar;j++)
	    {
	      temp[i][j]=(*this).dopelnienie(i,j)/Wyzn;
	    }
	}
    }
  return temp.transponuj();
}

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, Macierz<typ, rozmiar> &Mac)
{
  for(int i=0;i<rozmiar;i++)
    {
      Strm >> Mac[i];
    }
  return Strm;
}

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<typ, rozmiar> &Mac)
{
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  Strm << Mac.transponuj()[i][j];
	}
      Strm << std::endl;
    }
  return Strm;
}

template <typename typ, int rozmiar>
Macierz<typ, rozmiar> operator *(typ l, const Macierz<typ,rozmiar> M)
{
  return M*l;
}

template <typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::ZamienKolumny(int k1, int k2) const
{
  Macierz<typ, rozmiar> M2(*this);
  if(k1<0 || k1>=rozmiar || k2<0 || k2>=rozmiar)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  Wektor<typ, rozmiar> temp(M2[k1]);
  M2[k1]=M2[k2];
  M2[k2]=temp;
  return M2;
}

template <typename typ, int rozmiar>
Macierz<typ, rozmiar> Macierz<typ, rozmiar>::ZamienWiersze(int w1, int w2) const
{
  Macierz<typ, rozmiar> M2((*this).transponuj());
  if(w1<0 || w1>= rozmiar || w2<0 || w2>=rozmiar)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  Wektor<typ, rozmiar> temp(M2[w1]);
  M2[w1]=M2[w2];
  M2[w2]=temp;
  M2=M2.transponuj();
  return M2;
}
