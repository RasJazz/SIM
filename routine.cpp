#include "routine.h"
#include "first_fit.h"
#include "best_fit.h"

void simulateFit(MemoryManagement& memory, int fitType)
{
    // Fork a process
    pid_t newProcess = fork();

    if (newProcess < 0) {
        std::cerr << "Error creating new process\n";
        std::exit(EXIT_FAILURE);
    }
    // Child process
    else if (newProcess == 0){
        std::cout << "Child Process " << getpid() << " started\n\n";
        //sleep(1);
        exit(0);
    }
    else {
        std::cout << "Parent Process " << getpid() << " is waiting...\n";
        waitpid(newProcess, NULL, 0);
        std::cout << "Allocating memory for Child process " << newProcess;
        
        int nodesTraversed = 0;

        //change first parameter to randnum between 3 and 10
        if(fitType == 0){
            std::cout << " using First Fit...\n";
            
            FirstFit ffobj;

            nodesTraversed = ffobj.allocateMem(newProcess, memory.unitsAllocated, memory);
            //tempNode = memory.firstFitAlgorithm(10, newProcess);
        }
        else {
            std::cout << " using Best Fit...\n";

            BestFit bfobj;

            nodesTraversed = bfobj.allocateMem(newProcess, memory.unitsAllocated, memory);
            //tempNode = memory.bestFitAlgorithm(10, newProcess);
        }
        
        memory.nodesTraversed = nodesTraversed;
        std::cout << "Nodes traversed: " << memory.nodesTraversed << "\n";
        // std::cout << "Units allocated: " << memory.unitsAllocated << "\n\n";
        // memory.printMemoryList();
        // if (success) {
        //     std::cout << "Memory successfully allocated for process ID: " << newProcess << "\n";
        //     memory.printMemoryList();
        // } 
        // else {
        //     std::cerr << "Failed to allocate memory for process ID: " << newProcess << "\n";
        // }
    }
}

// deallocates the memory allocated to the process whose id is process_id.
int deallocateMem(int processID)
{
    std::cout << "Deallocating memory from Process " << processID << "\n";
    // if successful, returns 1 to be stored in MemoryManagement
    return 0;
    // otherwise –1.
}

int fragmentCount()
{
    // returns the number of holes (fragments of sizes 1 or 2 units).
    return 0;
}

void print_stats()
{
    std::cout << "Printing Stats\n";
}
