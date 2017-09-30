
OBJS = inv.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

p1 : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o inv

lab0.o:	inv.cpp
	g++ -Wall -c inv.cpp

clean:
	\rm *.o *~ inv
