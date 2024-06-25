#include "generate_request.h"
#include "stats.h"
#include <chrono>

std::vector<Request> generateRequests(int numRequests) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::vector<Request> requests;
    std::default_random_engine generator(seed);
    // Replace 3 and 10 with variables
    std::uniform_int_distribution<int> unitDistribution(Stats().minUnits, Stats().maxUnits);
    std::uniform_int_distribution<int> decisionDistribution(allocate, deallocate);

    for (int i = 0; i < numRequests; i++) {
        int processID = i + 1;
        int unitsRequested = unitDistribution(generator);
        bool isAlloc = decisionDistribution(generator);
        requests.push_back( { processID, unitsRequested, isAlloc } );
    }

    return requests;
}