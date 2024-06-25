###########################################################
# Makefile for CS480, Summer 2024
# Assignment #3: XSH
# Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
# Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 
###########################################################
EXEC = sim
FILES = main.cpp memory_management.cpp routine.cpp
HEADERS = memory_management.h routine.h fit.h first_fit.h best_fit.h
CC = g++
LFLAGS = -g
CFLAGS = -g -c
OBJECTS = $(FILES:.cpp=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)
	rm -f *.o

.cpp.o:
	$(CC) $(CFLAGS) $< $@

memory_management.o: memory_management.cpp memory_management.h
	$(CC) $(CFLAGS) memory_management.cpp

routine.o: routine.cpp routine.h 
	$(CC) $(CFLAGS) routine.cpp 

main.o: main.cpp memory_management.h routine.h fit.h first_fit.h best_fit.h
	$(CC) $(CFLAGS) main.cpp -o main.o

clean:
	rm -f *.o $(EXEC)
#######################[ EOF: Makefile ]###################