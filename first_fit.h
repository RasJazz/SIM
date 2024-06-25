#ifndef FIRST_FIT_H
#define FIRST_FIT_H

#include "fit.h"

class FirstFit : Fit{
    public:
        int allocateMem(int processID, int units, MemoryManagement& memory) override {
            int requiredNodes = units * MemoryNode::nodeSize; // Convert units to KB
            int nodesTraversed = 0;

            // Iterator variables
            auto bestSlotStart = memory.systemMemory.end(); // Iterator to store the start of the best fit slot
            int firstSlotSize = (maxUnits + 1) * MemoryNode::nodeSize; // Size of the first available slot found

            auto it = memory.systemMemory.begin();
            while (it != memory.systemMemory.end()) {
                if (it->isFree()) {
                    int currentSlotSize = 0;
                    auto currentSlotStart = it;

                    while (it != memory.systemMemory.end() && it->isFree() && currentSlotSize < requiredNodes) {
                        currentSlotSize += MemoryNode::nodeSize;
                        ++it;
                    }

                    if (currentSlotSize >= requiredNodes && currentSlotSize < firstSlotSize) {
                        firstSlotSize = currentSlotSize;
                        bestSlotStart = currentSlotStart;
                        nodesTraversed += units;
                        break;
                    }

                    if (it != memory.systemMemory.end()) {
                        ++it;
                    }
                } else {
                    ++it;
                }
                nodesTraversed++;
            }

            if (bestSlotStart != memory.systemMemory.end()) {
                // Allocate memory by setting nodeID for required number of units
                for (auto it = bestSlotStart; it != memory.systemMemory.end() && units > 0; ++it) {
                    if (it->isFree()) {
                        it->nodeID = processID;
                        units--;
                    }
                }

                // If all units are allocated, update memory available
                if (units == 0) {
                    memory.memoryAvailable(requiredNodes / MemoryNode::nodeSize);
                    std::cout << "Memory successfully allocated using First Fit. Total memory available: " << memory.totalMemoryAvailable << " KB\n";
                    return nodesTraversed;
                }
            }

            std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
            return -1;
        }
};
#endif