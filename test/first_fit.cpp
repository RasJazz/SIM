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

    auto it = sysMemory.begin();
    while (it != sysMemory.end()) {
        if (it->processID == emptyNode) {
            int currentSlotSize = 0;
            auto currentSlotStart = it;

            while (it != sysMemory.end() && it->processID == emptyNode) {
                currentSlotSize += MemoryNode::nodeSize;
                ++it;
            }

            // Allocate memory if the slot is large enough
            if (currentSlotSize >= requiredNodes) {
                for (auto allocIt = currentSlotStart; allocIt != sysMemory.end() && units > 0; ++allocIt) {
                    if (allocIt->processID == emptyNode) {
                        allocIt->processID = processID;
                        units--;
                    }
                }

                // If all units are allocated, update memory available
                if (units == 0) {
                    return 1;
                }
            }
        } else {
            ++it;
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
    auto it = sysMemory.begin();
    while (it != sysMemory.end()) {
        if (it->processID == -1) {
            fragmentCount++;
            ++it; // Move to next node
            if (it != sysMemory.end() && it->processID == -1) {
                // Skip over contiguous -1 nodes
                while (it != sysMemory.end() && it->processID == -1) {
                    ++it;
                }
            }
        } else {
            ++it;
        }
    }

    return fragmentCount;

}

