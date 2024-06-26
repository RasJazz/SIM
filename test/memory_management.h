/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** memory_management.h ********************
*/ 
#ifndef MEMORY_MANAGEMENT_H
#define MEMORY_MANAGEMENT_H

#include "stats.h"
#include <iostream>
#include <list>

struct MemoryNode {
    static constexpr int nodeSize = 2;
    int nodeAddress;
    int processID;

    MemoryNode(int address, int pid) : nodeAddress(address), processID(pid) {}
};

class MemoryManagement {
    private:
        const int startingMemory = 256; // 256 KB memory available to be given
    public:
        std::list<MemoryNode> systemMemory;
        int emptyNode;
        int totalMemoryAvailable;
        
        MemoryManagement () : totalMemoryAvailable(startingMemory), emptyNode(-1) {
            int nodeSize = MemoryNode::nodeSize;

            for (int i = 0; i < startingMemory/nodeSize; i++){
                systemMemory.emplace_back(i * nodeSize, emptyNode);
            }
        }
        
        virtual int allocateMem(int, int) = 0;
        virtual int deallocateMem(int) = 0;
        virtual int fragmentCount() = 0;

        virtual ~MemoryManagement() {}
};

class FirstFit : public MemoryManagement, public Stats {
    public:
        std::list<MemoryNode> sysMemory;
        FirstFit () : MemoryManagement() {
            sysMemory = MemoryManagement::systemMemory;
        };
        ~FirstFit() {};

        int allocateMem(int, int) override;
        int deallocateMem(int) override;
        int fragmentCount() override;

};

class BestFit : public MemoryManagement, public Stats {
    public:
        std::list<MemoryNode> sysMemory;
        BestFit () : MemoryManagement() {
            sysMemory = MemoryManagement::systemMemory;
        };
        ~BestFit() {};

        int allocateMem(int, int) override;
        int deallocateMem(int) override;
        int fragmentCount() override;

};

#endif