/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
  Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ********************* first_fit.cpp ***********************
*/ 
#include "memory_management.h"
#include "stats.h"

int FirstFit::allocateMem(int processID, int units, Stats& nodesTraversed) {
    // The number of units requested by a process * the unit size (in KB)
    int requiredNodes = units * MemoryNode::nodeSize;
    double tempTraversed = 0.00;

    auto it = sysMemory.begin();

    // Loop tuntil the end of the memory list is reached
    while (it != sysMemory.end()) {
        tempTraversed++;

        // If the node encountered is empty, checks subsequent nodes to see if block is large enough for process
        if (it->processID == emptyNode) {
            int currentSlotSize = 0;
            auto currentSlotStart = it;

            while (it != sysMemory.end() && it->processID == emptyNode) {
                currentSlotSize += MemoryNode::nodeSize;
                ++it;
            }
            
            // If the current block size is as big as/bigger than the required nodes
            if (currentSlotSize >= requiredNodes) {
                // Assigns block with process ID until all nodes taken by process
                for (auto allocIt = currentSlotStart; allocIt != sysMemory.end() && units > 0; ++allocIt) {
                    if (allocIt->processID == emptyNode) {
                        allocIt->processID = processID;
                        units--;
                    }
                }

                // If all units are allocated, update memory available
                if (units == 0) {
                    nodesTraversed.totalNodesTraversed += tempTraversed;
                    return 1;
                }
            }
        } 
        // Block size was not sufficient
        // Advance to next node
        else {
            ++it;
        }
    }

    // If no blocks were found, return error code
    return -1;
}

int FirstFit::deallocateMem(int processID) {
    bool deallocated = false;

    // Searches all nodes for the process and deallocates the nodes taken by the process
    for (auto it = sysMemory.begin(); it != sysMemory.end(); ++it) {
        if (it->processID == processID) {
            it->processID = -1;
            deallocated = true;
        }
    }

    return deallocated ? 1 : -1;
}

int FirstFit::fragmentCount() {
    auto it = sysMemory.begin();
    int fragmentCount = 0;
  
    // Loop through memory list to find fragments of size 1 or 2
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

