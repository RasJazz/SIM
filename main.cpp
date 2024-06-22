#include "routine.h"
#include "process.h"
#include "memory_management.h"

int main(){

    MemoryManagement memory;
    std::cout << "Henlo World!\n";
    std::cout << "Total memory available: " << memory.totalMemoryAvailable << "\n";

    // create processes
    create_process();
    // loop to allocate and deallocate memory
    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
}