/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** first_fit.cpp ********************
*/ 
#include "memory_management.h"

int FirstFit::allocateMem(int processID, int units){
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
            return 1;
        }
    }

    // Else, no slots available
    std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
    return -1;
}

int FirstFit::deallocateMem(int processID) {
    bool deallocated = false;

    for (auto it = sysMemory.begin(); it != sysMemory.end(); ++it) {
        if (it->processID == processID) {
            it->processID = -1;
            deallocated = true;
        }
    }

    return deallocated ? 1 : -1;
}

int FirstFit::fragmentCount() {
    int fragmentCount = 0;
    // This function needs to iterate through a linked list 
    // , check the current node, the next node, and the next node's next node
    
    // Assuming sysMemory is a linked list of nodes
    auto current = sysMemory.begin();

    for (const auto& node : memoryList) {
        if (node.processID == -1 && (node.size == 1 || node.size == 2)) {
            fragmentCount++;
        }
    }

    return fragmentCount;

}
