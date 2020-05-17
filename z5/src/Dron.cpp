#include "Dron.hh"

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> A)
{
  setApi(A);
  Sruba1.setApi(A);
  Sruba2.setApi(A);
  
  Srodek={0,0,0};
  PredkoscPrzod=0;
  PredkoscPitch=0;
  PredkoscYaw=0;
  PredkoscRoll=0;
  
  pitch=0;
  roll=0;
  yaw=0;
  
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  setOrientacja(temp);
  
  setRef({2,1,1});
  rozmSrb1={0.25,0.25,0.25};
  rozmSrb2={0.25,0.25,0.25};

  WekSruba1={-referencyjny[0]-0.25,(referencyjny[1]-0.4), 0};  //Wektory opisujace polozenie srub wzgledem centrum pojazdu(centrum korpusu)
  WekSruba2={-referencyjny[0]-0.25,-(referencyjny[1]-0.4), 0};
}

void Dron::ruch(char znak)
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
  Wektor3D vex={1,0,0};
  if(abs(getPredkoscPrzod())>0.0000001 || abs(getPredkoscRoll())>0.0000001 || abs(getPredkoscYaw())>0.0000001 || abs(getPredkoscPitch())>0.0000001)
    {
      setPitch(getPitch()+getPredkoscPitch());
      setYaw(getYaw()+getPredkoscYaw());
      setRoll(getRoll()+getPredkoscRoll());
      temp=MacierzObr(yaw,z)*MacierzObr(pitch,y)*MacierzObr(roll,x);
      setOrientacja(temp);
      
      setSrodek(getSrodek().Translacja(getPredkoscPrzod()*vex*getOrientacja()));
      
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
  Sruba1.setRef(rozmSrb1);
  Sruba1.setOrientacja(Orientacja*MacierzObr(90,y));
  Sruba1.setSrodek(Srodek.Translacja(WekSruba1*Orientacja));
  Sruba1.rysuj();
}

void Dron::rysSrb2()
{
  Sruba2.setRef(rozmSrb2);
  Sruba2.setOrientacja(Orientacja*MacierzObr(90,y));
  Sruba2.setSrodek(Srodek.Translacja(WekSruba2*Orientacja));
  Sruba2.rysuj();
}
