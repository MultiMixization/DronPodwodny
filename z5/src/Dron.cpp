#include "Dron.hh"

Dron::Dron()
{
  pozycja={0,0,0};
  predkosc=0;
  
  pitch=0;
  roll=0;
  yaw=0;
  
  rozmKor={1,1,1};
  rozmSrb1={0.25,0.25,0.25};
  rozmSrb2={0.25,0.25,0.25};

  WekSruba1={rozmKor[0]-0.5,-(rozmKor[1]+0.25), 0};  //Wektory opisujace polozenie srub wzgledem centrum pojazdu(centrum korpusu)
  WekSruba2={-(rozmKor[0]-0.5),-(rozmKor[1]+0.25), 0};
}

void Dron::rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  wymaz(api);
  rysKor(api);
  rysSrb1(api);
  rysSrb2(api);
}

void Dron::wymaz(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  Korpus.zmaz(api);
  Sruba1.zmaz(api);
  Sruba2.zmaz(api);
}

int Dron::rysKor(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  Korpus.setSrodek(pozycja);
  Korpus.setRef(rozmKor);
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  Korpus.setOrientacja(temp);
  int id=Korpus.rysuj(api);
  
  return id;
}

int Dron::rysSrb1(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  Sruba1.setRef(rozmSrb1);
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  Sruba1.setOrientacja(temp);
  Sruba1.setSrodek(pozycja.Translacja(WekSruba1*temp));
  
  return Sruba1.rysuj(api);
}

int Dron::rysSrb2(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  Sruba2.setRef(rozmSrb2);
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  Sruba2.setOrientacja(temp);
  Sruba2.setSrodek(pozycja.Translacja(WekSruba2*temp));
  
  return Sruba2.rysuj(api);
}
