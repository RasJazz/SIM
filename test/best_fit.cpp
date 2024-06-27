/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
  Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ********************** best_fit.cpp ***********************
*/ 
#include "memory_management.h"

int BestFit::allocateMem(int processID, int units, Stats& nodesTraversed) {
    // The number of units requested by a process * the unit size (in KB)
    int requiredNodes = units * MemoryNode::nodeSize; 
    // This takes the max units a process can ask for and multiplies by node size
    // This way a process can be allocated to nodes
    int smallestBlockSize = sysMemory.size() * MemoryNode::nodeSize;
    double tempTraversed = 0.0;
    
    auto it = sysMemory.begin();
    std::list<MemoryNode>::iterator smallestBlockStart = sysMemory.end(); // Iterator for linked list
    
    // Loop tuntil the end of the memory list is reached
    while (it != sysMemory.end()) {
        tempTraversed++;
        // Check if the current block is free and large enough
        if (it->processID == emptyNode) {
            int currentBlockSize = 0;
            auto currentBlockStart = it;

            // Calculate the size of contiguous free memory blocks
            // If we're not at the end of the list, the block is free, and the block size is less than
            // number nodes needed, temporarily save block size
            while (it != sysMemory.end() && it->processID == emptyNode && currentBlockSize <= requiredNodes) {
                currentBlockSize += MemoryNode::nodeSize;
                ++it;
            }

            // Checks if the block is smaller than previously saved
            if (currentBlockSize >= requiredNodes && currentBlockSize < smallestBlockSize) {
                smallestBlockSize = currentBlockSize;
                smallestBlockStart = currentBlockStart;
            }
        } 
        // Move to the next node if current node is not free
        else {
            ++it;
        }
    }

    // Allocate memory if a suitable block was found
    if (smallestBlockStart != sysMemory.end()) {
        // Assigns block with process ID until all nodes taken by process
        for (auto it = smallestBlockStart; it != sysMemory.end() && units > 0; ++it) {
            if (it->processID == emptyNode) {
                it->processID = processID;
                units--;
            }
        }

        // If all units are allocated, allocation was successful
        if (units == 0) {
            nodesTraversed.totalNodesTraversed += tempTraversed;
            return 1;
        }
    }

    // If no blocks were found, return error code
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

int BestFit::fragmentCount() {
    int fragmentCount = 0;

    // Loop through memory list to find fragments of size 1 or 2
    auto it = sysMemory.begin();
    while (it != sysMemory.end()) {
        // If node is empty, checks successor node
        if (it->processID == -1) {
            fragmentCount++;
            ++it; 
            
            // If successor node is not the end of the list and is empty
            if (it != sysMemory.end() && it->processID == -1) {
                // Skips over contiguous -1 nodes
                while (it != sysMemory.end() && it->processID == -1) {
                    ++it;
                }
            }
        } 
        // Otherwise, advance to next node
        else {
            ++it;
        }
    }
    return fragmentCount; 
}

