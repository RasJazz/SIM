#include "routine.h"

void create_process(MemoryManagement& memory, std::vector<pid_t>& processes)
{
    for (int i = 0; i < numProcesses; i++){
        pid_t newProcess = fork();

        if (newProcess < 0) {
            std::cerr << "Error creating new process\n";
            std::exit(EXIT_FAILURE);
        }
        // Child process
        else if (newProcess == 0){
            std::cout << "New Child Process " << getpid() << "\n";
            processes.push_back(newProcess);
            exit(0);
        }
        else {
            continue;
        }
    }    
}

void cleanup_process(std::vector<pid_t>& processes)
{
    std::cout << "Waiting processes\n";
    for (pid_t pid : processes) {
        waitpid(pid, NULL, 0);
    }
}

void print_stats()
{
    std::cout << "Printing Stats\n";
}
