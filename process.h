#ifndef PROCESS_H
#define PROCESS_H

#include <list>
#include <sys/wait.h>
#include <unistd.h>

struct Process {
    // LL to hold memory
    std::list<int> memoryAllocated;
    pid_t pid;

    Process(pid_t id) : pid(id) {}
};

#endif