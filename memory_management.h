#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include <iostream>

class MemoryManagement{
    private:
        const int startingMemory = 256; // 256 KB memory available to be given
        const int memoryUnit = 2; // 2 KB per memory unit
    public:
        int totalMemoryAvailable;

        MemoryManagement() : totalMemoryAvailable(startingMemory) {}
        ~MemoryManagement() {};

        // altering memory
        // rename this function
        void increaseMemory(int units) { totalMemoryAvailable -= units * memoryUnit; }
        
        int allocate_mem (int, int);
        int deallocate_mem (int);
        int fragment_count();
};

#endif