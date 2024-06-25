#include "routine.h"
#include "memory_management.h"
#include <random>

int main(){
    // Creating random number generator for units to allocate
    std::random_device rd; //seeding random number generator
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minUnits, maxUnits);
    
    // Creating new memory object and initializing the max total memory available to 256 KB
    MemoryManagement* firstFitMemory = new MemoryManagement(256);

    std::cout << "--- Total memory available: " << firstFitMemory->totalMemoryAvailable << "KB ---\n\n";

    // ******************* For loop to create a process. Run 10,000 times ************************
    // ************** NOTE: CURRENT LOOPS RUN 20 TIMES. CHANGE VAR IN ROUTINE_H ******************
    
    for (int i = 0; i < numRequests; i++) {
        // if (i % deallocationInterval == 0) {
        //     // generate random number between 0 and vector size
        //     deallocateMem(firstFitMemory->processIDTable[randomValue]);
        // }
        // else, allocate process
        firstFitMemory->unitsAllocated = distrib(gen);
        simulateFit(*firstFitMemory, FF);
    }

    MemoryManagement* bestFitMemory = new MemoryManagement(256);
    
    for (int i = 0; i < numRequests; i++) {
        // Deallocate process every x amount of times

        // else, allocate process
        bestFitMemory->unitsAllocated = distrib(gen);
        simulateFit(*bestFitMemory, BF);
    }

    std::cout << "-------------- FIRST FIT --------------\n";
    firstFitMemory->printMemoryList();
    std::cout << "-------------- BEST FIT --------------\n";
    bestFitMemory->printMemoryList();

    /* ----------------------------- TESTING PROCESS ID TABLE PRINT OUT ----------------------*/
    std::cout << "-------------- FIRST FIT PID TABLE --------------\n";
    for(int i : firstFitMemory->processIDTable){
        std::cout << "Process: " << i << "\n";
    }

    std::cout << "-------------- BEST FIT PID TABLE --------------\n";
    for(int i : bestFitMemory->processIDTable){
        std::cout << "Process: " << i << "\n";
    }

    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
    delete firstFitMemory;
    delete bestFitMemory;
}