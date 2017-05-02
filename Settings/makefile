
LINK_TARGET = disp

OBJS =  \
	main.o \
	menu.o \
	sett.o


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

main.o : menu.h
menu.o : sett.h



