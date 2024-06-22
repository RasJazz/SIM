#include "routine.h"
#include "process.h"
#include "memory_management.h"

int main(){

    // Creating new memory object and initializing the max total memory available to 256 KB
    MemoryManagement memory(256);
    std::vector<pid_t> processes;

    std::cout << "--- Total memory available: " << memory.totalMemoryAvailable << "KB ---\n\n";
    // create processes
    create_process(memory, processes);

    for(Process process : processes){
        std::cout << "Processes " << getpid() << "\n";
    }
    // loop to allocate and deallocate memory
    cleanup_process(processes);
    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
}