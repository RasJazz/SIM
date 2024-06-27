/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************* generate_request.cpp ******************
*/ 
#include "generate_request.h"
#include "stats.h"
#include <chrono>
#include <set>

std::vector<Request> Request::generateRequests(int numRequests) {
    // Creates two random number generators
    // The first choose a number between minUnits = 3 and maxUnits = 10
    // This is the amount of units a process will request from the "OS" for memory
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> unitDistributionStats(minUnits, maxUnits);
    std::uniform_int_distribution<int> decisionDistribution(0, 1); // 0 for deallocation, 1 for allocation

    // Loops for 10,000 requests
    for (int i = 0; i < numRequests; ++i) {
        int processID = i + 1;
        int unitsRequested = unitDistributionStats(generator);
        bool isAlloc;

        // If no processes are allocated, force allocation
        // Else, generates a random allocation/deallocation decision
        if (allocatedProcesses.empty()) {
            isAlloc = true; 
        } else {
            isAlloc = decisionDistribution(generator);
        }

        if (isAlloc) {
            requests.push_back({processID, unitsRequested, true});
            allocatedProcesses.insert(processID);
        } else {
            // Choose a random process ID from allocated processes for deallocation
            std::uniform_int_distribution<int> processDistribution(1, allocatedProcesses.size());
            auto it = allocatedProcesses.begin();
            std::advance(it, processDistribution(generator) - 1);
            int deallocProcessID = *it;

            requests.push_back({deallocProcessID, 0, false});
            allocatedProcesses.erase(deallocProcessID);
        }
    }

    return requests;
}