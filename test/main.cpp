#include <iostream>
#include "memory_management.h"
#include "stats.h"
#include "generate_request.h"

#include <iostream>

int main() {
    const int numRequests = 20;
    int nodesTraversed;

    FirstFit firstFit;
    BestFit bestFit;

    auto requests = generateRequests(numRequests);

    for(const auto& request : requests){
        if(request.isAlloc){
            std::cout << "ALLOCATING PROCESS " << request.processID << "\n";
            nodesTraversed = firstFit.allocateMem(request.processID, request.unitsRequested);
            std::cout << "FIRST FIT Nodes traversed: " << nodesTraversed << "\n";

            nodesTraversed = bestFit.allocateMem(request.processID, request.unitsRequested);
            std::cout << "BEST FIT Nodes traversed: " << nodesTraversed << "\n";
        }
        else {
            std::cout << "DEALLOCATING\n"
;        }
        // if true, call allocation function

        // else, call deallocation function
    }

    std::cout << "-------------------- FIRST FIT ----------------------\n";
    for(auto node : firstFit.sysMemory){
        std::cout << "Node Address: " << node.nodeAddress << " Process ID: " << node.processID << "\n";
    }

    
    bestFit.allocateMem(5, 3);
}