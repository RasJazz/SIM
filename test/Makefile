###########################################################
# Makefile for CS480, Summer 2024
# Assignment #3: SIM
# Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
# Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 
###########################################################
EXEC = sim
FILES = main.cpp best_fit.cpp first_fit.cpp generate_request.cpp stats.cpp
HEADERS = generate_request.h memory_management.h stats.h
CC = g++
LFLAGS = -g
CFLAGS = -g -c -std=c++11 -Wall
OBJECTS = $(FILES:.cpp=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJECTS)
	rm -f *.o

.cpp.o:
	$(CC) $(CFLAGS) $<

generate_request.o: generate_request.cpp generate_request.h
	$(CC) $(CFLAGS) generate_request.cpp

memory_management.o: best_fit.cpp first_fit.cpp memory_management.h
	$(CC) $(CFLAGS) best_fit.cpp first_fit.cpp

stats.o: stats.cpp stats.h 
	$(CC) $(CFLAGS) stats.cpp

clean:
	rm -f *.o $(EXEC)
#######################[ EOF: Makefile ]###################