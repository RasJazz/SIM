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
    // If allocation or deallocation is unsuccessful
    // record as denied request
    if(isSuccessful == -1) {
        deniedRequests++;
    }
}

void Stats::logFragments(double fragments, double memory) {
    fragments = fragments / memory;
    totalFragments += fragments;
}

void Stats::printStats() {
    // Summation of total fragments divided by the number of nodes in memory for all 10000 requests
    // Divided my total number of requests to get average number of fragments
    double averageFragments = totalFragments / totalRequests;
    // The number of nodes needed to find an available block of memory
    double averageNodesTraversed = totalNodesTraversed / totalRequests;
    // How many times the "OS" was unable to find a spot in memory for a process
    double allocationDeniedPercentage = deniedRequests / totalRequests * 100.0;

    std::cout << "Average Number of External Fragments: " << averageFragments << "\n";
    std::cout << "Average Allocation Time (nodes traversed): " << averageNodesTraversed << "\n";
    std::cout << "Percentage of Allocation Requests Denied: " << allocationDeniedPercentage << "%\n";
}