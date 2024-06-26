/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** stats.h ********************
*/ 
#ifndef STATS_H
#define STATS_H

#include <iostream>

class Stats {
    private:
        /* data */
    public:
        int minUnits = 3;
        int maxUnits = 10;
};

void printStats();
#endif