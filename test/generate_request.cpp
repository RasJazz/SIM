/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** generate_request.cpp ********************
*/ 
#include "generate_request.h"
#include "stats.h"
#include <chrono>
#include <set>
// std::vector<Request> generateRequests(int numRequests) {
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//     std::vector<Request> requests;
//     std::default_random_engine generator(seed);
//     // Replace 3 and 10 with variables
//     std::uniform_int_distribution<int> unitDistribution(Stats().minUnits, Stats().maxUnits);
//     std::uniform_int_distribution<int> decisionDistribution(allocate, deallocate);

//     for (int i = 0; i < numRequests; i++) {
//         int processID = i + 1;
//         int unitsRequested = unitDistribution(generator);
//         bool isAlloc = decisionDistribution(generator);
//         requests.push_back( { processID, unitsRequested, isAlloc } );
//     }

//     return requests;
// }

std::vector<Request> Request::generateRequests(int numRequests) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> unitDistributionStats(minUnits, maxUnits);
    std::uniform_int_distribution<int> decisionDistribution(0, 1); // 0 for deallocation, 1 for allocation

    // std::vector<Request> requests;
    // std::set<int> allocatedProcesses;

    for (int i = 0; i < numRequests; ++i) {
        int processID = i + 1;
        int unitsRequested = unitDistributionStats(generator);
        bool isAlloc;

        if (allocatedProcesses.empty()) {
            isAlloc = true; // If no processes are allocated, force allocation
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