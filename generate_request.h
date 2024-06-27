/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
  Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** generate_request.h *******************
*/ 
#ifndef GENERATE_REQUEST_H
#define GENERATE_REQUEST_H

#include <random>
#include <vector>
#include <set>

enum allocationRequests{ allocate, deallocate };

class Request {
    private:
        std::vector<Request> requests;
        std::set<int> allocatedProcesses;
    public:
        const int minUnits;
        const int maxUnits;
        int processID;
        int unitsRequested;
        bool isAlloc; // true for allocation, false for deallocation

        Request() : minUnits(3), maxUnits(10), processID(0), unitsRequested(0), isAlloc(0) {}    
        Request(int id, int units, bool alloc) 
            : minUnits(3), maxUnits(10), processID(id), unitsRequested(units), isAlloc(alloc) {}
        
        std::vector<Request> generateRequests(int);
};

#endif