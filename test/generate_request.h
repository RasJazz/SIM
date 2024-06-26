/*
 ******************* Assignment #3: SIM ********************
 ******************* CS480, Summer 2024 ******************** 
 Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
 ***** Edoras #s: Aeron - CSSC4404; Jasmine - CSSC4427 ***** 
 ******************** generate_request.h ********************
*/ 
#ifndef GENERATE_REQUEST_H
#define GENERATE_REQUEST_H

#include <random>
#include <vector>

class Request {
    public:
        int processID;
        int unitsRequested;
        bool isAlloc; // true for allocation, false for deallocation
};

enum allocationRequests{ allocate, deallocate };

std::vector<Request> generateRequests(int);

#endif