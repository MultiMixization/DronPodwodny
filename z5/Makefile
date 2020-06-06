CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17 

__start__: sterowanie
	./sterowanie

sterowanie: obj/gran8kat.o obj/Woda.o obj/Plaszczyzna.o obj/Scena.o obj/Dron.o obj/Prostopadloscian.o obj/Wektor3D.o obj/Obiekt3D.o obj/MacierzObr.o obj/Wektor.o obj/Macierz.o obj/Punkt.o  obj/Dr3D_gnuplot_api.o obj/main.o
	g++ -o sterowanie obj/main.o obj/Dr3D_gnuplot_api.o obj/Punkt.o obj/Wektor.o obj/Wektor3D.o obj/Obiekt3D.o obj/Macierz.o obj/MacierzObr.o obj/Prostopadloscian.o obj/Dron.o obj/Scena.o obj/Plaszczyzna.o obj/Woda.o obj/gran8kat.o -lpthread -lncurses

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

inc/Dr3D_gnuplot_api.hh: inc/Draw3D_api_interface.hh
	touch inc/Dr3D_gnuplot_api.hh

obj/Punkt.o: src/Punkt.cpp inc/Punkt.hh
	g++ ${CPPFLAGS} -o obj/Punkt.o src/Punkt.cpp

obj/Wektor.o: src/Wektor.cpp src/CWektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/CWektor.cpp

obj/Macierz.o: src/Macierz.cpp src/CMacierz.cpp inc/Macierz.hh
	g++ ${CPPFLAGS} -o obj/Macierz.o src/CMacierz.cpp

obj/Wektor3D.o: src/Wektor3D.cpp inc/Wektor3D.hh
	g++ ${CPPFLAGS} -o obj/Wektor3D.o src/Wektor3D.cpp

obj/Obiekt3D.o: src/Obiekt3D.cpp inc/Obiekt3D.hh
	g++ ${CPPFLAGS} -o obj/Obiekt3D.o src/Obiekt3D.cpp

obj/MacierzObr.o: src/MacierzObr.cpp inc/MacierzObr.hh
	g++ ${CPPFLAGS} -o obj/MacierzObr.o src/MacierzObr.cpp

obj/Prostopadloscian.o: src/Prostopadloscian.cpp inc/Prostopadloscian.hh 
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Dron.o: src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Scena.o: src/scena.cpp inc/scena.hh
	g++ ${CPPFLAGS} -o obj/Scena.o src/scena.cpp

obj/Plaszczyzna.o: src/Plaszczyzna.cpp inc/Plaszczyzna.hh
	g++ ${CPPFLAGS} -o obj/Plaszczyzna.o src/Plaszczyzna.cpp

obj/Woda.o: src/Woda.cpp inc/Woda.hh
	g++ ${CPPFLAGS} -o obj/Woda.o src/Woda.cpp

obj/gran8kat.o: src/gran8kat.cpp inc/gran8kat.hh
	g++ ${CPPFLAGS} -o obj/gran8kat.o src/gran8kat.cpp

clear:
	rm -f obj/*.o
