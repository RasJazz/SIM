#include "memory_management.h"

void MemoryManagement::printMemoryList() const
{
    std::cout << "--------------  Memory  --------------\n";
        for (const auto& node : systemMemory) {
            node.printNode();
        }
    std::cout << "-------------- END LIST --------------\n\n";
}



