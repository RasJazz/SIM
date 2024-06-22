#include "routine.h"

void simulate_first_fit(MemoryManagement& memory)
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
        
        memory.nodesTraversed = memory.firstFitAlgorithm(10, newProcess);
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

void simulate_best_fit(MemoryManagement& memory)
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
        std::cout << "Allocating memory for Child process " << newProcess <<  " using Best Fit...\n";
        
        memory.nodesTraversed = memory.bestFitAlgorithm(10, newProcess);
        std::cout << "Nodes traversed: " << memory.nodesTraversed << "\n\n";
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

void print_stats()
{
    std::cout << "Printing Stats\n";
}
