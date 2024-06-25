#ifndef BEST_FIT_H
#define BEST_FIT_H

#include "fit.h"

class BestFit : Fit{
    public:
        int allocateMem(int processID, int units, MemoryManagement& memory) override{
            // Convert units to KB
            int requiredNodes = units * MemoryNode::nodeSize; 
            int nodesTraversed = 0;
            // This takes the max units a process can ask for, increases it by 1, and multiplies by node size
            // This way a process can be allocated to nodes
            int bestSlotSize = (maxUnits + 1) * MemoryNode::nodeSize;;

            // Iterator variables
            std::list<MemoryNode>::iterator bestSlotStart = memory.systemMemory.end(); // Iterator for linked list
            // Loop through memory list using iterators
            auto it = memory.systemMemory.begin();

            // while the list end has not been reached
            while (it != memory.systemMemory.end()) {
                nodesTraversed++;
                // Check if the current slot is free and large enough
                if (it->isFree()) {
                    int currentSlotSize = 0;
                    auto currentSlotStart = it;

                    // Calculate the size of contiguous free memory slots
                    // If we're not at the end of the list, the slot is free, and the slot size is less than
                    // number nodes needed, temporarily save slot size
                    while (it != memory.systemMemory.end() && it->isFree() && currentSlotSize < requiredNodes) {
                        currentSlotSize += MemoryNode::nodeSize;
                        ++it;
                    }

                    // Check if this slot is the best fit so far
                    if (currentSlotSize >= requiredNodes && currentSlotSize < bestSlotSize) {
                        bestSlotSize = currentSlotSize;
                        bestSlotStart = currentSlotStart;

                        if (currentSlotSize == requiredNodes) {
                            nodesTraversed += (currentSlotSize / MemoryNode::nodeSize);
                            break;
                        }
                    }

                    // Move the iterator to the next node if not at the end
                    if (it != memory.systemMemory.end()) {
                        ++it;
                    }
                } 
                // Move to the next node if current node is not free
                else {
                    ++it;
                }
            }

            // Allocate memory if a suitable slot was found
            if (bestSlotStart != memory.systemMemory.end()) {
                for (auto it = bestSlotStart; it != memory.systemMemory.end() && units > 0; ++it) {
                    if (it->isFree()) {
                        it->nodeID = processID;
                        units--;
                    }
                }

                // If all units are allocated, update memory available
                if (units == 0) {
                    // Add process ID to table
                    memory.processIDTable.push_back(processID);

                    memory.memoryAvailable(requiredNodes / MemoryNode::nodeSize);
                    std::cout << "Memory successfully allocated using Best Fit.\n" << "Total memory available: " << memory.totalMemoryAvailable << " KB\n";
                    return nodesTraversed - 1;
                }
            }

            // Else, no slots available
            std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
            return -1;
        }
};

#endif