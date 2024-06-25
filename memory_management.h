#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include "memory_node.h"
#include <list>

class MemoryManagement{
    private:
        const int startingMemory; // 256 KB memory available to be given
    public:
        int totalMemoryAvailable;
        int nodesTraversed;
        // LL to hold memory
        std::list<MemoryNode> systemMemory;
        // Constructor initializes linked list
        MemoryManagement(int memory) : startingMemory(memory), totalMemoryAvailable(startingMemory), nodesTraversed(0) {
            // Calculate number of nodes based on totalMemoryAvailable and nodeSize
            int numberOfNodes = totalMemoryAvailable / MemoryNode::nodeSize;

            // Populate the systemMemory list with nodes
            for (int i = 0; i < numberOfNodes; ++i) {
                systemMemory.emplace_back(-1, i * MemoryNode::nodeSize);
            }
        }
        // Destructor
        ~MemoryManagement() {};

        void memoryAvailable(int units) { totalMemoryAvailable -= units * MemoryNode::nodeSize; }
        void printMemoryList() const;
        int allocateMem(int, int);
        int deallocateMem (int);
        int fragmentCount();
        int firstFitAlgorithm(int, int);
        int bestFitAlgorithm(int, int);
};

#endif