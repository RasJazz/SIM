/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
  Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ************************ main.cpp *************************
*/ 
#include <iostream>
#include "memory_management.h"
#include "stats.h"
#include "generate_request.h"

#include <iostream>

int main() {
    const int numRequests = 10000;
    int returnCode;
    int success;

    Request generator;
    Stats ffStats;
    Stats bfStats;
    FirstFit firstFit;
    BestFit bestFit;

    // Pre-generated requests that contains the following:
    // *** whether a process should be allocated or deallocated
    // *** the number of units to allocate/deallocate
    // *** the generated process ID
    auto requests = generator.generateRequests(numRequests);

    for(const auto& request : requests){
        // If requested generated is allocation, allocate process to memory
        if(request.isAlloc){
            // Allocates a process using First Fit, then returns a code
            // Return code is saved in stats for First Fit
            returnCode = firstFit.allocateMem(request.processID, request.unitsRequested, ffStats);
            ffStats.logRequest(returnCode);
            ffStats.logFragments(firstFit.fragmentCount(), firstFit.sysMemory.size());

            // Allocates a process using Best Fit, then returns a code
            // Return code is saved in stats for Best Fit
            returnCode = bestFit.allocateMem(request.processID, request.unitsRequested, bfStats);
            bfStats.logRequest(returnCode);
            bfStats.logFragments(bestFit.fragmentCount(), bestFit.sysMemory.size());
        }
        // else, request generated was a deallocation
        else {
            // Deallocates a process for First Fit
            success = firstFit.deallocateMem(request.processID);
            ffStats.logRequest(success);
            // Deallocates a process for Best Fit
            success = bestFit.deallocateMem(request.processID);
            bfStats.logRequest(success);
        }
    }
    
    std::cout << "------------------- FIRST FIT ---------------------\n";
    ffStats.printStats();

    std::cout << "-------------------- BEST FIT ---------------------\n";
    bfStats.printStats();
}