#include "generate_request.h"

std::vector<Request> generateRequests(int numRequests) {
    std::vector<Request> requests;
    std::default_random_engine generator;
    // Replace 3 and 10 with variables
    std::uniform_int_distribution<int> unitDistribution(3, 10);
    std::uniform_int_distribution<int> decisionDistribution(allocate, deallocate);

    for (int i = 0; i < numRequests; i++) {
        int processID = i + 1;
        int unitsRequested = unitDistribution(generator);
        bool isAlloc = decisionDistribution(generator);
        requests.push_back( { processID, unitsRequested, isAlloc } );
    }

    return requests;
}