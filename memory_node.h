#ifndef MEMORY_NODE_H
#define MEMORY_NODE_H
#include <iostream>

class MemoryNode{
    private:
        // Address in memory
        int nodeAddress;
    public:
        // Node size in KB
        static const int nodeSize = 2;
        // ID -1 for free node, will hold Process ID
        int nodeID = -1;

        MemoryNode(int ID, int address) : nodeID(ID), nodeAddress(address) {}
        ~MemoryNode() {};

        int getNodeSize() const { return nodeSize; }
        bool isFree() const { return nodeID == -1; }
        void printNode() const {
            std::cout << "Address: " << nodeAddress << " Node ID: " << nodeID << ", Size: " << nodeSize << " KB\n";
        }
};

#endif