#include "Dron.hh"

Dron::Dron(std::shared_ptr<drawNS::Draw3DAPI> A)
{
  setApi(A);
  Sruba1.setApi(A);
  Sruba2.setApi(A);
  //Plywak1.setApi(A);
  //Plywak2.setApi(A);
  
  Srodek={0,0,0};
  PredkoscPrzod=0.00;
  PredkoscPitch=0.00;
  PredkoscYaw=0.00;
  PredkoscRoll=0.00;
  
  pitch=0.00;
  roll=90.00;
  yaw=0.00;
  
  MacierzObr temp=MacierzObr(yaw,z)*MacierzObr(pitch,y)*MacierzObr(roll,x);
  setOrientacja(temp);
  
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
  Wektor3D temp;
  MacierzObr temp2;
  //Katy Taita-Bryana konwencja zyx
  switch(znak)
    {
    case 'w':
      setPredkoscPrzod(getPredkoscPrzod()+ACCELERATION);
      break;
    case 's':
      setPredkoscPrzod(getPredkoscPrzod()-ACCELERATION);
      break;
    case 'a':
      temp={0,0,1};
      temp=getOrientacja()*temp;
      temp2=MacierzObr(temp[2],z)*MacierzObr(temp[1],y)*MacierzObr(temp[0],x);
      setPredkoscYaw(getPredkoscYaw()-temp2.Euler()[2]*ANGLEACCELERATION);
      setPredkoscPitch(getPredkoscPitch()-temp2.Euler()[1]*ANGLEACCELERATION);
      setPredkoscRoll(getPredkoscRoll()-temp2.Euler()[0]*ANGLEACCELERATION);
      break;
    case 'd':
      temp={0,0,1};
      temp=getOrientacja()*temp;
      temp2=MacierzObr(temp[2],z)*MacierzObr(temp[1],y)*MacierzObr(temp[0],x);
      setPredkoscYaw(getPredkoscYaw()+temp2.Euler()[2]*ANGLEACCELERATION);
      setPredkoscPitch(getPredkoscPitch()+temp2.Euler()[1]*ANGLEACCELERATION);
      setPredkoscRoll(getPredkoscRoll()+temp2.Euler()[0]*ANGLEACCELERATION);
      break;
    case 'r':
      temp={0,1,0};
      temp=getOrientacja()*temp;
      temp2=MacierzObr(temp[2],z)*MacierzObr(temp[1],y)*MacierzObr(temp[0],x);
      setPredkoscYaw(getPredkoscYaw()-temp2.Euler()[2]*ANGLEACCELERATION);
      setPredkoscPitch(getPredkoscPitch()-temp2.Euler()[1]*ANGLEACCELERATION);
      setPredkoscRoll(getPredkoscRoll()-temp2.Euler()[0]*ANGLEACCELERATION);
      break;
    case 'f':
      temp={0,1,0};
      temp=getOrientacja()*temp;
      temp2=MacierzObr(temp[2],z)*MacierzObr(temp[1],y)*MacierzObr(temp[0],x);
      setPredkoscYaw(getPredkoscYaw()+temp2.Euler()[2]*ANGLEACCELERATION);
      setPredkoscPitch(getPredkoscPitch()+temp2.Euler()[1]*ANGLEACCELERATION);
      setPredkoscRoll(getPredkoscRoll()+temp2.Euler()[0]*ANGLEACCELERATION);
      break;
    case 'e':
      temp={1,0,0};
      temp=getOrientacja()*temp;
      temp2=MacierzObr(temp[2],z)*MacierzObr(temp[1],y)*MacierzObr(temp[0],x);
      setPredkoscYaw(getPredkoscYaw()-temp2.Euler()[2]*ANGLEACCELERATION);
      setPredkoscPitch(getPredkoscPitch()-temp2.Euler()[1]*ANGLEACCELERATION);
      setPredkoscRoll(getPredkoscRoll()-temp2.Euler()[0]*ANGLEACCELERATION);
      break;
    case 'q':
      temp={1,0,0};
      temp=getOrientacja()*temp;
      temp2=MacierzObr(temp[2],z)*MacierzObr(temp[1],y)*MacierzObr(temp[0],x);
      setPredkoscYaw(getPredkoscYaw()+temp2.Euler()[2]*ANGLEACCELERATION);
      setPredkoscPitch(getPredkoscPitch()+temp2.Euler()[1]*ANGLEACCELERATION);
      setPredkoscRoll(getPredkoscRoll()+temp2.Euler()[0]*ANGLEACCELERATION);
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
