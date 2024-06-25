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