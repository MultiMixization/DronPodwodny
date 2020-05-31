#include "Dron.hh"

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> A, Punkt S, MacierzObr O)
{
  setApi(A);
  Sruba1.setApi(A);
  Sruba2.setApi(A);
  //Plywak1.setApi(A);
  //Plywak2.setApi(A);
  
  Srodek=S;
  PredkoscPrzod=0.00;
  PredkoscPitch=0.00;
  PredkoscYaw=0.00;
  PredkoscRoll=0.00;
  
  setOrientacja(O);
  
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

void Dron::ruch(char znak)
{
  //Wektor3D temp;
  //MacierzObr temp2;
  switch(znak)
    {
    case 'w':
      setPredkoscPrzod(getPredkoscPrzod()+ACCELERATION);
      break;
    case 's':
      setPredkoscPrzod(getPredkoscPrzod()-ACCELERATION);
      break;
    case 'a':
      setPredkoscYaw(getPredkoscYaw()+ANGLEACCELERATION);
      break;
    case 'd':
      setPredkoscYaw(getPredkoscYaw()-ANGLEACCELERATION);
      break;
    case 'r':
      setPredkoscPitch(getPredkoscPitch()-ANGLEACCELERATION);
      break;
    case 'f':
      setPredkoscPitch(getPredkoscPitch()+ANGLEACCELERATION);
      break;
    case 'e':
      setPredkoscRoll(getPredkoscRoll()-ANGLEACCELERATION);
      break;
    case 'q':
      setPredkoscRoll(getPredkoscRoll()+ANGLEACCELERATION);
      break;
    case ' ':
      setPredkoscPrzod(0);
      setPredkoscRoll(0);
      setPredkoscYaw(0);
      setPredkoscPitch(0);
      break;
    default:
      break;
    }
}

void Dron::updatePosition()
{
  MacierzObr temp;
  MacierzObr newYaw;
  MacierzObr newPitch;
  MacierzObr newRoll;
  Wektor3D vex={1,0,0};
  Wektor3D vey={0,1,0};
  Wektor3D vez={0,0,1};
  if(abs(getPredkoscPrzod())>0.0000001 || abs(getPredkoscRoll())>0.0000001 || abs(getPredkoscYaw())>0.0000001 || abs(getPredkoscPitch())>0.0000001)
    {
      newYaw=MacierzObr(getPredkoscYaw(),getOrientacja()*vez);
      newPitch=MacierzObr(getPredkoscPitch(),getOrientacja()*vey);
      newRoll=MacierzObr(getPredkoscRoll(),getOrientacja()*vex);
      //Wektor obrotu w pojedynczej klatce
      temp=getOrientacja()*(newYaw*newPitch*newRoll);
      setOrientacja(temp);

      setSrodek(getSrodek().Translacja(getOrientacja()*(getPredkoscPrzod()*vex)));
      
      wymaz();
      rysujAll();
    }
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
  Sruba1.setOrientacja(Orientacja*MacierzObr(90,y));
  Sruba1.setSrodek(Srodek.Translacja(Orientacja*WekSruba1));
  Sruba1.rysuj();
}

void Dron::rysSrb2()
{
  Sruba2.setOrientacja(Orientacja*MacierzObr(90,y));
  Sruba2.setSrodek(Srodek.Translacja(Orientacja*WekSruba2));
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
