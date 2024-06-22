#ifndef PROCESS_H
#define PROCESS_H

//#include "memory_management.cpp"
#include <unistd.h>
#include <list>

struct Process {
    // LL to hold memory
    std::list<int> memoryAllocated;
    pid_t pid;

    Process(pid_t id) : pid(id) {}
};

#endif