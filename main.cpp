#include "routine.h"
#include "memory_management.h"

// BRAINSTORMING SECTION
/*
FIRST FIT AND BEST FIT
PAGE 190 in BOOK

Linked List will have 256 KB total, divided into 2 KB units
Process can request 3-10 Units (6-20 KB)

Each slot in memory gets:
- Process ID
- Value KB
*/


int main(){

    // Creating new memory object and initializing the max total memory available to 256 KB
    MemoryManagement memory(256);
    // ******************* Change this to a Memory linked list ************************
    std::vector<pid_t> processes;

    std::cout << "--- Total memory available: " << memory.totalMemoryAvailable << "KB ---\n\n";
    
    // ******************* For loop to create a process. Run 10,000 times ************************
    create_process(memory, processes);

    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
}