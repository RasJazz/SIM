#include "routine.h"

void create_process(MemoryManagement& memory, std::vector<pid_t>& processes)
{
    // Fork a process
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
        std::cout << "New Parent Process " << getpid() << "\n";
    }

    waitpid(newProcess, NULL, 0);
}

int randomNumber()
{
    return 0;
}

void print_stats()
{
    std::cout << "Printing Stats\n";
}
