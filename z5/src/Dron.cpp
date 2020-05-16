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
  
  setRef({1,1,1});
  rozmSrb1={0.25,0.25,0.25};
  rozmSrb2={0.25,0.25,0.25};

  WekSruba1={referencyjny[0]-0.5,-(referencyjny[1]+0.25), 0};  //Wektory opisujace polozenie srub wzgledem centrum pojazdu(centrum korpusu)
  WekSruba2={-(referencyjny[0]-0.5),-(referencyjny[1]+0.25), 0};
}

void Dron::ruch()
{
  char znak='x';
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  Wektor3D vel={0,1,0};
  initscr();
  WINDOW *okno=newwin(20,50,0,0);
  refresh();
  box(okno, 0, 0);
  mvwprintw(okno, 1, 1, "Sterowanie dronem");
  wrefresh(okno);
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
	  setOrientacja(temp);
	  
	  setSrodek(getSrodek().Translacja(getPredkoscPrzod()*vel*getOrientacja()));
	  wymaz();
	  rysujAll();
	  delay(FRAMETIME);
	}
      flushinp();
    }
  echo();
  endwin();
}

void Dron::rysujAll()
{
  MacierzObr temp=MacierzObr(pitch,x)*MacierzObr(roll,y)*MacierzObr(yaw,z);
  setOrientacja(temp);
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
  Sruba1.setOrientacja(Orientacja);
  Sruba1.setSrodek(Srodek.Translacja(WekSruba1*Orientacja));
  Sruba1.rysuj();
}

void Dron::rysSrb2()
{
  Sruba2.setRef(rozmSrb2);
  Sruba2.setOrientacja(Orientacja);
  Sruba2.setSrodek(Srodek.Translacja(WekSruba2*Orientacja));
  Sruba2.rysuj();
}

bool kbhit()
{
  struct timeval tv;
  fd_set fds;

  tv.tv_sec=0;
  tv.tv_usec=0;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds);
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &fds);
}

void delay(unsigned int msec)
{
  clock_t goal =msec*CLOCKS_PER_SEC/1000+clock();
  while(goal>clock());
}
