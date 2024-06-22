#ifndef MEMORY_NODE_H
#define MEMORY_NODE_H

#include "memory_management.h"

class MemoryNode{
    private:
        int nodeAddress;
    public:
        const int nodeSize = 2; // 2 KB node size
        int nodeID = -1;

        MemoryNode(int ID, int address) : nodeID(ID), nodeAddress(address) {}
        ~MemoryNode() {};

        int getNodeSize() const { return nodeSize; }
};

#endif