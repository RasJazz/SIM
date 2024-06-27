/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
  Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ************************* stats.h *************************
*/ 
#ifndef STATS_H
#define STATS_H

#include <iostream>
#include <list>

class Stats {
private:
    double totalRequests;
    double deniedRequests;
    double totalFragments;

public:
    double totalNodesTraversed;

    Stats() : totalRequests(0), deniedRequests(0), totalFragments(0), totalNodesTraversed(0.0){}

    void logRequest(double);
    void logFragments(double, double);
    void printStats();
};
#endif
