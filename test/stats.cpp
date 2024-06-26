/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** stats.cpp ********************
*/ 
#include "stats.h"

void Stats::logRequest(int nodesTraversed, bool success) {
    totalRequests++;
    totalNodesTraversed += nodesTraversed;
    if (!success) deniedRequests++;
}

void Stats::logFragments(int fragments) {
    totalFragments += fragments;
}

void Stats::printStats() {
    double averageFragments = static_cast<double>(totalFragments) / totalRequests;
    double averageNodesTraversed = static_cast<double>(totalNodesTraversed) / totalRequests;
    double allocationDeniedPercentage = static_cast<double>(deniedRequests) / totalRequests * 100.0;

    std::cout << "Average Number of External Fragments: " << averageFragments << "\n";
    std::cout << "Average Allocation Time (nodes traversed): " << averageNodesTraversed << "\n";
    std::cout << "Percentage of Allocation Requests Denied: " << allocationDeniedPercentage << "%\n";
}