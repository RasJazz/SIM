#include "memory_management.h"
#include <limits>

// allocates num_units units of memory to a process whose id is process_id. 
int MemoryManagement::allocate_mem(int process_id, int num_units)
{
    int nodesTraversed = 0;
    std::cout << "Allocating " << num_units << " units of memory to Process " << process_id << "\n";
    
    // In main, subtract by this number

    // If successful, it returns the number of nodes traversed in the linked list
    return nodesTraversed; 
    // Otherwise, it returns -1.
    // return -1
}

// deallocates the memory allocated to the process whose id is process_id.
int MemoryManagement::deallocate_mem(int process_id)
{
    std::cout << "Deallocating memory from Process " << process_id << "\n";
    // if successful, returns 1 to be stored in MemoryManagement
    return 0;
    // otherwise –1.
}

int MemoryManagement::fragment_count()
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

// First fit
int MemoryManagement::firstFitAlgorithm(int units, int pid) {
    int requiredNodes = units * MemoryNode::nodeSize; // Convert units to KB
    int nodesTraversed = 0;

    // Iterator variables
    auto bestSlotStart = systemMemory.end(); // Iterator to store the start of the best fit slot
    int firstSlotSize = std::numeric_limits<int>::max(); // Size of the first available slot found

    auto it = systemMemory.begin();
    while (it != systemMemory.end()) {
        if (it->isFree()) {
            int currentSlotSize = 0;
            auto currentSlotStart = it;

            while (it != systemMemory.end() && it->isFree() && currentSlotSize < requiredNodes) {
                currentSlotSize += MemoryNode::nodeSize;
                ++it;
            }

            if (currentSlotSize >= requiredNodes && currentSlotSize < firstSlotSize) {
                firstSlotSize = currentSlotSize;
                bestSlotStart = currentSlotStart;
                nodesTraversed += units;
                break;
            }

            if (it != systemMemory.end()) {
                ++it;
            }
        } else {
            ++it;
        }
        nodesTraversed++;
    }

    if (bestSlotStart != systemMemory.end()) {
        // Allocate memory by setting nodeID for required number of units
        for (auto it = bestSlotStart; it != systemMemory.end() && units > 0; ++it) {
            if (it->isFree()) {
                it->nodeID = pid;
                units--;
            }
        }

        // If all units are allocated, update memory available
        if (units == 0) {
            memoryAvailable(requiredNodes / MemoryNode::nodeSize);
            std::cout << "Memory successfully allocated using First Fit. Total memory available: " << totalMemoryAvailable << " KB\n";
            return nodesTraversed;
        }
    }

    std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
    return -1;
}

// Best fit
int MemoryManagement::bestFitAlgorithm(int units, int pid) {
    // Convert units to KB
    int requiredNodes = units * MemoryNode::nodeSize; 
    int nodesTraversed = 0;
    int bestSlotSize = std::numeric_limits<int>::max();

    // Iterator variables
    std::list<MemoryNode>::iterator bestSlotStart = systemMemory.end(); // Iterator for linked list
    // Loop through systemMemory list using iterators
    auto it = systemMemory.begin();

    // while the list end has not been reached
    while (it != systemMemory.end()) {
        nodesTraversed++;
        // Check if the current slot is free and large enough
        if (it->isFree()) {
            int currentSlotSize = 0;
            auto currentSlotStart = it;

            // Calculate the size of contiguous free memory slots
            // If we're not at the end of the list, the slot is free, and the slot size is less than
            // number nodes needed, temporarily save slot size
            while (it != systemMemory.end() && it->isFree() && currentSlotSize < requiredNodes) {
                currentSlotSize += MemoryNode::nodeSize;
                ++it;
                nodesTraversed++;
            }

            // Check if this slot is the best fit so far
            if (currentSlotSize >= requiredNodes && currentSlotSize < bestSlotSize) {
                bestSlotSize = currentSlotSize;
                bestSlotStart = currentSlotStart;
            }

            // Move the iterator to the next node if not at the end
            if (it != systemMemory.end()) {
                ++it;
            }
        } 
        // Move to the next node if current node is not free
        else {
            ++it;
        }
    }

    // Allocate memory if a suitable slot was found
    if (bestSlotStart != systemMemory.end()) {
        for (auto it = bestSlotStart; it != systemMemory.end() && units > 0; ++it) {
            if (it->isFree()) {
                it->nodeID = pid;
                units--;
            }
        }

        // If all units are allocated, update memory available
        if (units == 0) {
            int allocatedNodes = requiredNodes / MemoryNode::nodeSize;
            memoryAvailable(allocatedNodes);
            std::cout << "Memory successfully allocated.\n" << "Total memory available: " << totalMemoryAvailable << " KB\n";
            return nodesTraversed - 1;
        }
    }

    // If no suitable slot was found
    std::cout << "Error: Not enough memory slots available for " << units << " units.\n";
    return -1;

}

