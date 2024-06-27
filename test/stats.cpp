/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** stats.cpp ********************
*/ 
#include "stats.h"

void Stats::logRequest(double isSuccessful) {
    // Holds overall number of requests
    totalRequests++;
    // If allocation returned a value of -1
    // , record allocation unsuccessful
    
    if(isSuccessful == -1) {
        deniedRequests++;
    }
}

void Stats::logFragments(double fragments, double memory) {
    fragments = fragments / memory;
    totalFragments += fragments;
}

void Stats::printStats() {
    double averageFragments = totalFragments / totalRequests;
    double averageNodesTraversed = totalNodesTraversed / totalRequests;
    double allocationDeniedPercentage = deniedRequests / totalRequests * 100.0;

    std::cout << "Average Number of External Fragments: " << averageFragments << "\n";
    std::cout << "Average Allocation Time (nodes traversed): " << averageNodesTraversed << "\n";
    std::cout << "Percentage of Allocation Requests Denied: " << allocationDeniedPercentage << "%\n";
}

void Stats::addNodesTraversed() {
    totalNodesTraversed += 1.00;
}