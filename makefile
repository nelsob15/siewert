
LINK_TARGET = calendar

OBJS =  \
	main.o \
	calendar.o \
	Menu.o \
	Settings.o\
  Synch.o\
  Event.o\
  View.o


REBUILDABLES = $(OBJS) $(LINK_TARGET)

all : $(LINK_TARGET)
	echo All done

clean : 
	rm -f $(REBUILDABLES)
	echo Clean done

$(LINK_TARGET) : $(OBJS)
	g++ -g -Wall -o $@ $^

%.o : %.cpp
	g++ -g -Wall -o $@ -c $<

main.o : Menu.h
menu.o : calendar.h Event.h Synch.h View.h Settings.h
View.o : calendar.h



