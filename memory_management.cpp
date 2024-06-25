#include "memory_management.h"

// deallocates the memory allocated to the process whose id is process_id.
int MemoryManagement::deallocateMem(int process_id)
{
    std::cout << "Deallocating memory from Process " << process_id << "\n";
    // if successful, returns 1 to be stored in MemoryManagement
    return 0;
    // otherwise –1.
}

int MemoryManagement::fragmentCount()
{
    // returns the number of holes (fragments of sizes 1 or 2 units).
    return 0;
}

void MemoryManagement::printMemoryList() const
{
    std::cout << "--------------  Memory  --------------\n";
        for (const auto& node : systemMemory) {
            node.printNode();
        }
    std::cout << "-------------- END LIST --------------\n\n";
}

