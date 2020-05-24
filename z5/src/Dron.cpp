#include "Dron.hh"

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> A)
{
  setApi(A);
  Sruba1.setApi(A);
  Sruba2.setApi(A);
  
  Srodek={0,0,0};
  PredkoscPrzod=0.00;
  PredkoscPitch=0.00;
  PredkoscYaw=0.00;
  PredkoscRoll=0.00;
  
  pitch=90.00;
  roll=0.00;
  yaw=0.00;
  
  MacierzObr temp=MacierzObr(yaw,z)*MacierzObr(pitch,y)*MacierzObr(roll,x);
  setOrientacja(temp);
  
  setRef({2,1,1});
  rozmSrb={0.25,0.25,0.25};

  WekSruba1={-getRef()[0]-0.25,(getRef()[1]-0.4), -0.25};  //Wektory opisujace polozenie srub wzgledem centrum pojazdu(centrum korpusu)
  WekSruba2={-getRef()[0]-0.25,-(getRef()[1]-0.4), -0.25};
}

void Dron::ruch(char znak)
{
  double argYaw;
  double argPitch;
  double argRoll;
  switch(znak)
    {
    case 'w':
      setPredkoscPrzod(getPredkoscPrzod()+ACCELERATION);
      break;
    case 's':
      setPredkoscPrzod(getPredkoscPrzod()-ACCELERATION);
      break;
    case 'a':
      argPitch=pitch*M_PI/180;
      argYaw=yaw*M_PI/180;
      argRoll=roll*M_PI/180;
      setPredkoscRoll(getPredkoscRoll()-ANGLEACCELERATION*cos(argYaw)*sin(argPitch));
      setPredkoscPitch(getPredkoscPitch()+ANGLEACCELERATION*cos(argYaw)*sin(argRoll));
      setPredkoscYaw(getPredkoscYaw()+ANGLEACCELERATION*cos(argRoll)*cos(argPitch));  //cos(pi/2)!=0 Whyyyy?
      break;
    case 'd':
      argPitch=pitch*M_PI/180;
      argYaw=yaw*M_PI/180;
      argRoll=roll*M_PI/180;
      setPredkoscRoll(getPredkoscRoll()+ANGLEACCELERATION*cos(argYaw)*sin(argPitch));
      setPredkoscPitch(getPredkoscPitch()-ANGLEACCELERATION*cos(argYaw)*sin(argRoll));
      setPredkoscYaw(getPredkoscYaw()-ANGLEACCELERATION*cos(argRoll)*cos(argPitch));
      break;
    case 'r':
      argPitch=pitch*M_PI/180;
      argYaw=yaw*M_PI/180;
      argRoll=roll*M_PI/180;
      setPredkoscRoll(getPredkoscRoll()+ANGLEACCELERATION*cos(argPitch)*sin(argYaw));
      setPredkoscPitch(getPredkoscPitch()+ANGLEACCELERATION*cos(argRoll)*cos(argYaw));
      setPredkoscYaw(getPredkoscYaw()+ANGLEACCELERATION*cos(argPitch)*sin(argRoll));
      break;
    case 'f':
      argPitch=pitch*M_PI/180;
      argYaw=yaw*M_PI/180;
      argRoll=roll*M_PI/180;
      setPredkoscRoll(getPredkoscRoll()-ANGLEACCELERATION*cos(argPitch)*sin(argYaw));
      setPredkoscPitch(getPredkoscPitch()-ANGLEACCELERATION*cos(argRoll)*cos(argYaw));
      setPredkoscYaw(getPredkoscYaw()-ANGLEACCELERATION*cos(argPitch)*sin(argRoll));
      break;
    case 'e':
      argPitch=pitch*M_PI/180;
      argYaw=yaw*M_PI/180;
      argRoll=roll*M_PI/180;
      setPredkoscRoll(getPredkoscRoll()-ANGLEACCELERATION*cos(argPitch)*cos(argYaw));
      setPredkoscPitch(getPredkoscPitch()-ANGLEACCELERATION*cos(argRoll)*sin(argYaw));
      setPredkoscYaw(getPredkoscYaw()-ANGLEACCELERATION*cos(argRoll)*sin(argPitch));
      break;
    case 'q':
      argPitch=pitch*M_PI/180;
      argYaw=yaw*M_PI/180;
      argRoll=roll*M_PI/180;
      setPredkoscRoll(getPredkoscRoll()+ANGLEACCELERATION*cos(argPitch)*cos(argYaw));
      setPredkoscPitch(getPredkoscPitch()+ANGLEACCELERATION*cos(argRoll)*sin(argYaw));
      setPredkoscYaw(getPredkoscYaw()+ANGLEACCELERATION*cos(argRoll)*sin(argPitch));

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
      temp=MacierzObr(getYaw(),z)*MacierzObr(getPitch(),y)*MacierzObr(getRoll(),x);
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
  Sruba1.setRef(rozmSrb);
  Sruba1.setOrientacja(Orientacja*MacierzObr(90,y));
  Sruba1.setSrodek(Srodek.Translacja(Orientacja*WekSruba1));
  Sruba1.rysuj();
}

void Dron::rysSrb2()
{
  Sruba2.setRef(rozmSrb);
  Sruba2.setOrientacja(Orientacja*MacierzObr(90,y));
  Sruba2.setSrodek(Srodek.Translacja(Orientacja*WekSruba2));
  Sruba2.rysuj();
}
