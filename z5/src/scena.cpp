#include "scena.hh"

void scena::inicjalizuj()
{
  dno.setPoziom(-9);
  woda.setPoziom(9);
  woda.rysuj();
  dno.rysuj();
  dron.rysujAll();
  delay(FRAMETIME);
}

void scena::kontrola()
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
	  dron.ruch(znak);
	}
      dron.updatePosition();
      flushinp();
      delay(FRAMETIME-15);
    }
  echo();
  endwin();
}

void scena::sprzatanie()
{
  dron.zmaz();
  woda.zmaz();
  dno.zmaz();
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
