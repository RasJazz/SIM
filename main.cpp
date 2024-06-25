#include "routine.h"
#include "memory_management.h"
#include <random>

int main(){
    // Creating random number generator for units to allocate
    std::random_device rd; //seeding random number generator
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minUnits, maxUnits);
    int randomIndex = 0;
    // Creating new memory object and initializing the max total memory available to 256 KB
    MemoryManagement* firstFitMemory = new MemoryManagement(256);

    std::cout << "--- Total memory available: " << firstFitMemory->totalMemoryAvailable << "KB ---\n\n";

    // ******************* For loop to create a process. Run 10,000 times ************************
    // ************** NOTE: CURRENT LOOPS RUN 20 TIMES. CHANGE VAR IN ROUTINE_H ******************
    
    for (int i = 0; i < numRequests; i++) {
        // If the PID table is empty or if the request is not a multiple of 5, allocate process to memory
        std::cout << "Modulo result: " << (i + 1) % deallocationInterval << "\n\n";
        if (((i + 1) % deallocationInterval != 0 || firstFitMemory->processIDTable.empty())){
            firstFitMemory->unitsAllocated = distrib(gen);
            simulateFit(*firstFitMemory, FF);
        }
        // Deallocation occurs at the deallocationInterval
        else {
            // Set random number generator to generate a number between 0 and firstFit's PID table size
            distrib.param(std::uniform_int_distribution<>::param_type(0, firstFitMemory->processIDTable.size() - 1));
            
            randomIndex = distrib(gen);
            firstFitMemory->successRateDealloc += deallocateMem(*firstFitMemory, firstFitMemory->processIDTable[randomIndex]);
            //firstFitMemory->processIDTable.erase(firstFitMemory->processIDTable.begin() + randomIndex);

            // Set random number generator back to generate a number between 3 - 10 units
            distrib.param(std::uniform_int_distribution<>::param_type(minUnits, maxUnits));
        }   
    }

    std::cout << "-------------- FIRST FIT --------------\n";
    // firstFitMemory->printMemoryList();
    // /* ----------------------------- TESTING PROCESS ID TABLE PRINT OUT ----------------------*/
    // std::cout << "-------------- FIRST FIT PID TABLE --------------\n";
    // for(int i : firstFitMemory->processIDTable){
    //     std::cout << "Process: " << i << "\n";
    // }
    std::cout << "-------------- NUMBER DEALLOCATIONS --------------\n";
    std::cout << firstFitMemory->successRateDealloc << " were successful out of " << numRequests << " requests\n";

    MemoryManagement* bestFitMemory = new MemoryManagement(256);

    for (int i = 0; i < numRequests; i++) {
        // If the PID table is empty or if the request is not a multiple of 5, allocate process to memory
        if (((i + 1) % deallocationInterval != 0 || bestFitMemory->processIDTable.empty())){
            bestFitMemory->unitsAllocated = distrib(gen);
            simulateFit(*bestFitMemory, BF);
        }
        // Deallocation occurs at the deallocationInterval
        else {
            // Set random number generator to generate a number between 0 and bestFit's PID table size
            distrib.param(std::uniform_int_distribution<>::param_type(0, bestFitMemory->processIDTable.size() - 1));
            
            randomIndex = distrib(gen);
            bestFitMemory->successRateDealloc += deallocateMem(*bestFitMemory, bestFitMemory->processIDTable[randomIndex]);
            //bestFitMemory->processIDTable.erase(bestFitMemory->processIDTable.begin() + randomIndex);

            // Set random number generator back to generate a number between 3 - 10 units
            distrib.param(std::uniform_int_distribution<>::param_type(minUnits, maxUnits));
        }
    }

    float fff = numRequests/firstFitMemory->nodesTraversed;
    float bff = numRequests/bestFitMemory->nodesTraversed;
    std::cout << "-------------- FIRST FIT --------------\n";
    std::cout << "-------------- NUMBER SUCCESSFUL ALLOCATIONS --------------\n";
    std::cout << fff << " were successful out of " << numRequests << " requests\n";
    
    std::cout << "-------------- BEST FIT --------------\n";
    //bestFitMemory->printMemoryList();
    std::cout << "-------------- NUMBER SUCCESSFUL ALLOCATIONS --------------\n";
    std::cout << bff << " were successful out of " << numRequests << " requests\n";

    // /* ----------------------------- TESTING PROCESS ID TABLE PRINT OUT ----------------------*/
    // std::cout << "-------------- BEST FIT PID TABLE --------------\n";
    // for(int i : bestFitMemory->processIDTable){
    //     std::cout << "Process: " << i << "\n";
    // }

    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
    delete firstFitMemory;
    delete bestFitMemory;
}