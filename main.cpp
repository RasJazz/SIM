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
    // ******************* Change this to a Memory linked list ************************
    // populate list with nodes

    std::cout << "--- Total memory available: " << firstFitMemory->totalMemoryAvailable << "KB ---\n\n";
    /*/* ******************************* FOR TESTING PURPOSES *********************************
    std::cout << "Allocating 3 units of memory\n";
    //firstFitMemory->memoryAvailable(3);
    std::cout << "--- Total memory available: " << firstFitMemory->totalMemoryAvailable << "KB ---\n\n";
    std::cout << "Deallocating 10 units of memory\n";
    //firstFitMemory->memoryAvailable(-10);
    std::cout << "--- Total memory available: " << firstFitMemory->totalMemoryAvailable << "KB ---\n\n";
    *********************************** END TESTING ************************************** */

    // ******************* For loop to create a process. Run 10,000 times ************************
    // ************** NOTE: CURRENT LOOPS RUN 20 TIMES. CHANGE VAR IN ROUTINE_H ******************
    
    for (int i = 0; i < numRequests; i++) {
        // USE RAN GENERATOR?
        // if 0, call allocation
        firstFitMemory->unitsAllocated = distrib(gen);
        simulateFit(*firstFitMemory, FF);
        // else, if 1, call deallocation
    }

    MemoryManagement* bestFitMemory = new MemoryManagement(256);
    
    for (int i = 0; i < numRequests; i++) {
        bestFitMemory->unitsAllocated = distrib(gen);
        simulateFit(*bestFitMemory, BF);
    }

    std::cout << "-------------- FIRST FIT --------------\n";
    firstFitMemory->printMemoryList();
    std::cout << "-------------- BEST FIT --------------\n";
    bestFitMemory->printMemoryList();

    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
    delete firstFitMemory;
    delete bestFitMemory;
}