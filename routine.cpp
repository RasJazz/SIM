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
        std::cout << "Allocating memory for Child process " << newProcess <<  " using First Fit...\n";
        
        int tempNode = 0;

        //change first parameter to randnum between 3 and 10
        if(fitType == 0){
            FirstFit ffobj;

            tempNode = ffobj.allocateMem(newProcess, 10, memory);
            //tempNode = memory.firstFitAlgorithm(10, newProcess);
        }
        else {
            BestFit bfobj;

            tempNode = bfobj.allocateMem(newProcess, 10, memory);
            //tempNode = memory.bestFitAlgorithm(10, newProcess);
        }
        
        memory.nodesTraversed = tempNode;
        std::cout << "Nodes traversed: " << memory.nodesTraversed << "\n\n";
        //memory.printMemoryList();
        // if (success) {
        //     std::cout << "Memory successfully allocated for process ID: " << newProcess << "\n";
        //     memory.printMemoryList();
        // } 
        // else {
        //     std::cerr << "Failed to allocate memory for process ID: " << newProcess << "\n";
        // }
    }
}

void print_stats()
{
    std::cout << "Printing Stats\n";
}
