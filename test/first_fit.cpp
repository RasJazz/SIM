#include "memory_management.h"

int FirstFit::allocateMem(int processID, int units){
    std::cout << "Calling First fit\n";
    
    int requiredNodes = units * MemoryNode::nodeSize; // Convert units to KB

    // Iterator variables
    auto bestSlotStart = sysMemory.end(); // Iterator to store the start of the best fit slot
    int firstSlotSize = (maxUnits + 1) * MemoryNode::nodeSize; // Size of the first available slot found

    auto it = sysMemory.begin();
    while (it != sysMemory.end()) {
        if (it->processID == emptyNode) {
            int currentSlotSize = 0;
            auto currentSlotStart = it;

            while (it != sysMemory.end() && it->processID == emptyNode && currentSlotSize < requiredNodes) {
                currentSlotSize += MemoryNode::nodeSize;
                ++it;
            }

            if (currentSlotSize >= requiredNodes && currentSlotSize < firstSlotSize) {
                firstSlotSize = currentSlotSize;
                bestSlotStart = currentSlotStart;
                break;
            }

            if (it != sysMemory.end()) {
                ++it;
            }
        } else {
            ++it;
        }
    }

    if (bestSlotStart != sysMemory.end()) {
        // Allocate memory by setting processID for required number of units
        for (auto it = bestSlotStart; it != sysMemory.end() && units > 0; ++it) {
            if (it->processID == emptyNode) {
                it->processID = processID;
                units--;
            }
        }

        // If all units are allocated, update memory available
        if (units == 0) {
            // Calculate remaining memory available
            // memory.memoryAvailable(requiredNodes / MemoryNode::nodeSize);
            // std::cout << "Memory successfully allocated using First Fit. Total memory available: " << memory.totalMemoryAvailable << " KB\n";
            return 1;
        }
    }

    // Else, no slots available
    std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
    return -1;
}