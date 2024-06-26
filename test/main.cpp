/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** main.cpp ********************
*/ 
#include <iostream>
#include "memory_management.h"
#include "stats.h"
#include "generate_request.h"

#include <iostream>

int main() {
    const int numRequests = 10000;
    int nodesTraversed;

    FirstFit firstFit;
    BestFit bestFit;

    auto requests = generateRequests(numRequests);

    for(const auto& request : requests){
        if(request.isAlloc){
            // std::cout << "---------------------------------------------------\n";
            // std::cout << "ALLOCATING PROCESS " << request.processID << "\n";
            // std::cout << "---------------------------------------------------\n";
            nodesTraversed = firstFit.allocateMem(request.processID, request.unitsRequested);
            // std::cout << "FIRST FIT Nodes traversed: " << nodesTraversed << "\n";

            nodesTraversed = bestFit.allocateMem(request.processID, request.unitsRequested);
            // std::cout << "BEST FIT Nodes traversed: " << nodesTraversed << "\n\n";
        }
        else {
            // std::cout << "---------------------------------------------------\n";
            std::cout << "DEALLOCATING PROCESS " << request.processID << "\n";
            // std::cout << "---------------------------------------------------\n";
            int success = firstFit.deallocateMem(request.processID);
            // std::cout << "FIRST FIT RETURN CODE: " << success << "\n";

            success = bestFit.deallocateMem(request.processID);
            // std::cout << "BEST FIT RETURN CODE: " << success << "\n\n";
;        }
        // if true, call allocation function

        // else, call deallocation function
    }

    // AT THE END, USE firstFit and bestFit to call the fragmentwhatever function
    // it will go down the list and count the number of fragments sizes 1 or 2
    
    std::cout << "-------------------- FIRST FIT ----------------------\n";
    for(auto node : firstFit.sysMemory){
        std::cout << "Node Address: " << node.nodeAddress << " Process ID: " << node.processID << "\n";
    }

    std::cout << "-------------------- BEST FIT ----------------------\n";
    for(auto node : bestFit.sysMemory){
        std::cout << "Node Address: " << node.nodeAddress << " Process ID: " << node.processID << "\n";
    }

    std::cout << "-------------------- FIRST FIT NUMBER OF FRAGMENTS ----------------------\n";
    std::cout << "Number of fragments: " << firstFit.fragmentCount() << "\n";
    std::cout << "-------------------- BEST FIT NUMBER OF FRAGMENTS ----------------------\n";
    std::cout << "Number of fragments: " << bestFit.fragmentCount() << "\n";
}