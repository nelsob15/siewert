calendar: main.o Views.o Event.o calendar.o File.o Sett.o
	g++ -std=c++0x main.o Views.o Event.o calendar.o File.o Sett.o -o calendar

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Views.o: Views.cpp
	g++ -std=c++0x -c Views.cpp

Event.o: Event.cpp
	g++ -std=c++0x -c Event.cpp

calendar.o: calendar.cpp
	g++ -std=c++0x -c calendar.cpp

File.o: File.cpp
  g++ -std=c++0x -c File.cpp
  
Sett.o: Sett.cpp
  g++ -std=c++0x -c Sett.cpp

clean:
	rm -i *.o calendar
