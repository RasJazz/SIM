#include <iostream>
#include "memory_management.h"
#include "stats.h"
#include "generate_request.h"

#include <iostream>

int main() {
    const int numRequests = 20;

    FirstFit firstFit;
    BestFit bestFit;
    auto requests = generateRequests(numRequests);

    for(const auto& request : requests){
        std::cout << request.isAlloc << "\n";
    }
    
    firstFit.allocateMem(4, 3);
    bestFit.allocateMem(5, 3);
}