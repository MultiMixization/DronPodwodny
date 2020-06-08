#include "Dron.hh"

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> A, Punkt S, MacierzObr O)
{
  setApi(A);
  Sruba1.setApi(A);
  Sruba2.setApi(A);
  //Plywak1.setApi(A);
  //Plywak2.setApi(A);
  
  Srodek=S;
  setOrientacja(O);
  PredkoscPrzod=0.00;
  setAngleRotation(MacierzObr(Wektor3D(0,0,0)));
  
  setRef({2,1,1});

  Sruba1.setRef({0.25,0.25,0.25});
  Sruba2.setRef({0.25,0.25,0.25});
  //Plywak1.setRef({0.25,0.25,2});
  //Plywak2.setRef({0.25,0.25,2});

  WekSruba1={-getRef()[0]-0.25,(getRef()[1]-0.4), -0.25};  //Wektory opisujace polozenie srub wzgledem centrum pojazdu(centrum korpusu)
  WekSruba2={-getRef()[0]-0.25,-(getRef()[1]-0.4), -0.25};

  //WekPlywak1={0,getRef()[1],-getRef()[2]};
  //WekPlywak2={0,-getRef()[1],-getRef()[2]};
}

void Dron::ruch(const char znak)
{
  switch(znak)
    {
    case 'w':
      setPredkoscPrzod(getPredkoscPrzod()+ACCELERATION);
      break;
    case 's':
      setPredkoscPrzod(getPredkoscPrzod()-ACCELERATION);
      break;
    case 'a':
      setAngleRotation(getAngleRotation()*MacierzObr(ANGLEACCELERATION,getOrientacja()*Wektor3D(0,0,1)));
      break;
    case 'd':
      setAngleRotation(getAngleRotation()*MacierzObr(-ANGLEACCELERATION,getOrientacja()*Wektor3D(0,0,1)));
      break;
    case 'r':
      setAngleRotation(getAngleRotation()*MacierzObr(ANGLEACCELERATION,getOrientacja()*Wektor3D(0,1,0)));
      break;
    case 'f':
      setAngleRotation(getAngleRotation()*MacierzObr(-ANGLEACCELERATION,getOrientacja()*Wektor3D(0,1,0)));
      break;
    case 'e':
      setAngleRotation(getAngleRotation()*MacierzObr(-ANGLEACCELERATION,getOrientacja()*Wektor3D(1,0,0)));
      break;
    case 'q':
      setAngleRotation(getAngleRotation()*MacierzObr(ANGLEACCELERATION,getOrientacja()*Wektor3D(1,0,0)));
      break;
    case ' ':
      setPredkoscPrzod(0);
      setAngleRotation(MacierzObr(Wektor3D(0,0,0)));
      break;
    case 'z':
      setAngleRotation(MacierzObr(Wektor3D(0,0,0)));
      break;
    default:
      break;
    }
}

void Dron::updatePosition()
{
  //if(abs(getPredkoscPrzod())>0.0000001 || getAngleRotation()!=MacierzObr(Wektor3D(0,0,0)))
  //{
  setOrientacja(getOrientacja()*getAngleRotation());
  setSrodek(getSrodek().Translacja(getOrientacja()*(getPredkoscPrzod()*Wektor3D(1,0,0))));
  
  wymaz();
  rysujAll();
      //}
  //Jest bug ktory po kazdej klatce przywraca orientacje do polozenia startowego. Nie wiem dlaczego. Mam dosc.
}

void Dron::rysujAll()
{
  rysuj();
  rysSrb1();
  rysSrb2();
}

void Dron::wymaz()
{
  zmaz();
  Sruba1.zmaz();
  Sruba2.zmaz();
}

void Dron::rysSrb1()
{
  Sruba1.setOrientacja(getOrientacja()*MacierzObr(90,y));
  Sruba1.setSrodek(Srodek.Translacja(getOrientacja()*WekSruba1));
  Sruba1.rysuj();
}

void Dron::rysSrb2()
{
  Sruba2.setOrientacja(getOrientacja()*MacierzObr(90,y));
  Sruba2.setSrodek(Srodek.Translacja(getOrientacja()*WekSruba2));
  Sruba2.rysuj();
}
/*

void Dron::rysPlywak1()
{
  Plywak1.setOrientacja(Orientacja*MacierzObr(90,y));
  Plywak1.setSrodek(Srodek.Translacja(Orientacja*WekPlywak1));
  Plywak1.rysuj();
}

void Dron::rysPlywak2()
{
  Plywak2.setOrientacja(Orientacja*MacierzObr(90,y));
  Plywak2.setSrodek(Srodek.Translacja(Orientacja*WekPlywak2));
  Plywak2.rysuj();
}
*/

bool Dron::Kolizja(std::shared_ptr<DroneInterface> IntDron)
{
  if(IntDron->getSrodek()==getSrodek())
    {
      return false;
    }
  if(IntDron->getSrodek().Wektor(getSrodek()).dlugosc()<getRef().dlugosc()+IntDron->getSrednica())
    {
      return true;
    }
  return false;
}
