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
    int totalRequests;
    int deniedRequests;
    int totalNodesTraversed;
    int totalFragments;

public:
    // const int minUnits;
    // const int maxUnits;

    Stats() : totalRequests(0), deniedRequests(0), totalNodesTraversed(0), totalFragments(0) {}

    void logRequest(int, bool);
    void logFragments(int);
    void printStats();
};
#endif
