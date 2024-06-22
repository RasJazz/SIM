#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include "memory_node.h"
#include <iostream>
#include <list>

class MemoryManagement{
    private:
        const int startingMemory; // 256 KB memory available to be given
    public:
        
        int totalMemoryAvailable;
        // LL to hold memory
        // std::list<MemoryNode> systemMemory;

        MemoryManagement(int memory) : startingMemory(memory), totalMemoryAvailable(startingMemory) {}
        ~MemoryManagement() {};

        // Change this function to be two separate functions
        // First function will be first fit
        // Second function will be best fit
        // maybe keep function
        void memoryAvailable(int units, MemoryNode node) { totalMemoryAvailable -= units * node.getNodeSize(); }
        
        int allocate_mem (int, int);
        int deallocate_mem (int);
        int fragment_count();
};

#endif