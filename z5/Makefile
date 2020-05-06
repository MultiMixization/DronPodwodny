CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17 

__start__: sterowanie
	./sterowanie

sterowanie: obj/Dr3D_gnuplot_api.o obj/main.o
	g++ -o sterowanie obj/main.o obj/Dr3D_gnuplot_api.o -lpthread

obj/main.o: src/main.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o: src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

clear:
	rm -f obj/*.o
