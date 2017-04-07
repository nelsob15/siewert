viewtest: main.o Views.o Event.o calendar.o
	g++ -std=c++0x main.o Views.o Event.o calendar.o -o viewtest

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Views.o: Views.cpp
	g++ -std=c++0x -c Views.cpp

Event.o: Event.cpp
	g++ -std=c++0x -c Event.cpp

calendar.o: calendar.cpp
	g++ -std=c++0x -c calendar.cpp

clean:
	rm -i *.o viewtest
