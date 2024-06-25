#include "memory_management.h"

int BestFit::allocateMem(int processID, int units) {
    // Convert units to KB
    int requiredNodes = units * MemoryNode::nodeSize; 
    // This takes the max units a process can ask for, increases it by 1, and multiplies by node size
    // This way a process can be allocated to nodes
    int bestSlotSize = (maxUnits + 1) * MemoryNode::nodeSize;

    // Iterator variables
    std::list<MemoryNode>::iterator bestSlotStart = sysMemory.end(); // Iterator for linked list
    // Loop through memory list using iterators
    auto it = sysMemory.begin();

    // while the list end has not been reached
    while (it != sysMemory.end()) {
        // Check if the current slot is free and large enough
        if (it->processID == emptyNode) {
            int currentSlotSize = 0;
            auto currentSlotStart = it;

            // Calculate the size of contiguous free memory slots
            // If we're not at the end of the list, the slot is free, and the slot size is less than
            // number nodes needed, temporarily save slot size
            while (it != sysMemory.end() && it->processID == emptyNode && currentSlotSize < requiredNodes) {
                currentSlotSize += MemoryNode::nodeSize;
                ++it;
            }

            // Check if this slot is the best fit so far
            if (currentSlotSize >= requiredNodes && currentSlotSize < bestSlotSize) {
                bestSlotSize = currentSlotSize;
                bestSlotStart = currentSlotStart;
            }

            // Move the iterator to the next node if not at the end
            if (it != sysMemory.end()) {
                ++it;
            }
        } 
        // Move to the next node if current node is not free
        else {
            ++it;
        }
    }

    // Allocate memory if a suitable slot was found
    if (bestSlotStart != sysMemory.end()) {
        for (auto it = bestSlotStart; it != sysMemory.end() && units > 0; ++it) {
            if (it->processID == emptyNode) {
                it->processID = processID;
                units--;
            }
        }

        // If all units are allocated, update memory available
        if (units == 0) {
            //memory.memoryAvailable(requiredNodes / MemoryNode::nodeSize);
            //std::cout << "Memory successfully allocated using Best Fit.\n" << "Total memory available: " << memory.totalMemoryAvailable << " KB\n";
            return 1;
        }
    }

    // Else, no slots available
    std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
    return -1;
}

int BestFit::deallocateMem(int processID) {
    bool deallocated = false;

    for (auto it = sysMemory.begin(); it != sysMemory.end(); ++it) {
        if (it->processID == processID) {
            it->processID = -1;
            deallocated = true;
        }
    }

    return deallocated ? 1 : -1;
}
