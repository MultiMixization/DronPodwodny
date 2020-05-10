#include "Dron.hh"

Dron::Dron()
{
  pozycja={0,0,0};
  PredkoscPrzod=0;
  PredkoscPitch=0;
  PredkoscYaw=0;
  PredkoscRoll=0;
  
  pitch=0;
  roll=0;
  yaw=0;
  
  rozmKor={1,1,1};
  rozmSrb1={0.25,0.25,0.25};
  rozmSrb2={0.25,0.25,0.25};

  WekSruba1={rozmKor[0]-0.5,-(rozmKor[1]+0.25), 0};  //Wektory opisujace polozenie srub wzgledem centrum pojazdu(centrum korpusu)
  WekSruba2={-(rozmKor[0]-0.5),-(rozmKor[1]+0.25), 0};
}

void Dron::ruch(std::shared_ptr<drawNS::Draw3DAPI> api)
{
  char znak='x';
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  Wektor3D vel={0,1,0};
  initscr();
  WINDOW *okno=newwin(0,0,10,10);
  refresh();
  noecho();
  cbreak();
  nodelay(okno, TRUE);
  while(znak!=27)
    {
      znak='x';
      delay(10);
      if(kbhit())
	{
	  znak=getch();
	  switch(znak)
	    {
	    case 'w':
	      setPredkoscPrzod(getPredkoscPrzod()+ACCELERATION);
	      break;
	    case 's':
	      setPredkoscPrzod(getPredkoscPrzod()-ACCELERATION);
	      break;
	    case 'a':
	      setPredkoscYaw(getPredkoscYaw()-ANGLEACCELERATION);
	      break;
	    case 'd':
	      setPredkoscYaw(getPredkoscYaw()+ANGLEACCELERATION);
	      break;
	    case 'r':
	      setPredkoscPitch(getPredkoscPitch()+ANGLEACCELERATION);
	      break;
	    case 'f':
	      setPredkoscPitch(getPredkoscPitch()-ANGLEACCELERATION);
	      break;
	    case 'e':
	      setPredkoscRoll(getPredkoscRoll()+ANGLEACCELERATION);
	      break;
	    case 'q':
	      setPredkoscRoll(getPredkoscRoll()-ANGLEACCELERATION);
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
	  
      if(abs(getPredkoscPrzod())>0.0000001 || abs(getPredkoscRoll())>0.0000001 || abs(getPredkoscYaw())>0.0000001 || abs(getPredkoscPitch())>0.0000001)
	{
	  setPitch(getPitch()+getPredkoscPitch());
	  setYaw(getYaw()+getPredkoscYaw());
	  setRoll(getRoll()+getPredkoscRoll());
	  temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
	  setPozycja(getPozycja().Translacja(getPredkoscPrzod()*vel*temp));wymaz(api);
	  rysuj(api);
	  delay(FRAMETIME);
	}
    }
  echo();
  endwin();
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

bool kbhit()
{
  struct timeval tv;
  fd_set read_fd;

  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&read_fd);
  FD_SET(0,&read_fd);
  if(select(1, &read_fd, NULL, NULL, &tv) == -1)
    return 0;
  if(FD_ISSET(0,&read_fd))
    return 1;
  return 0;
}

void delay(unsigned int msec)
{
  clock_t goal =msec*CLOCKS_PER_SEC/1000+clock();
  while(goal>clock());
}
