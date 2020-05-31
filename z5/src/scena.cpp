#include "scena.hh"

void scena::inicjalizuj()
{
  std::shared_ptr<drawNS::Draw3DAPI> api(new drawNS::APIGnuPlot3D(-SIZE,SIZE,-SIZE,SIZE,-SIZE,SIZE,-1));
  api->change_ref_time_ms(0);

  std::shared_ptr<Dno> dno=std::make_shared<Dno>(api,-25,SIZE);
  Przeszkody.push_back(dno);
  dno->rysuj();
  
  std::shared_ptr<Woda> woda=std::make_shared<Woda>(api,25,SIZE);
  Przeszkody.push_back(woda);
  woda->rysuj();

  std::shared_ptr<Dron> dron0=std::make_shared<Dron>(api, Punkt(0,0,0), MacierzObr(0,z));
  Drony.push_back(dron0);
  Przeszkody.push_back(dron0);
  dron0->rysujAll();

   std::shared_ptr<Dron> dron1=std::make_shared<Dron>(api, Punkt(10,0,0), MacierzObr(90,z));
  Drony.push_back(dron1);
  Przeszkody.push_back(dron1);
  dron1->rysujAll();
  
  delay(FRAMETIME);
}

void scena::kontrola(int nrDrona=0)
{
  char znak='x';
  initscr();
  WINDOW *okno=newwin(3,20,0,0);
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
      delay(15);
      if(kbhit())
	{
	  znak=getch();
	  Drony[nrDrona]->ruch(znak);
	}
      for(auto elem : Przeszkody)
	{
	  if(elem->Kolizja(Drony[nrDrona]))
	    {
	      Drony[nrDrona]->setPredkoscPrzod(-Drony[nrDrona]->getPredkoscPrzod());
	    }
	}
      Drony[nrDrona]->updatePosition();
      flushinp();
      delay(FRAMETIME-15);
    }
  echo();
  endwin();
}

void scena::sprzatanie()
{
  delay(FRAMETIME);
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
