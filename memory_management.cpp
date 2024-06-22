#include "memory_management.h"

// allocates num_units units of memory to a process whose id is process_id. 
int MemoryManagement::allocate_mem(int process_id, int num_units)
{
    int nodesTraversed = 0;
    std::cout << "Allocating " << num_units << " units of memory to Process " << process_id << "\n";
    
    // In main, subtract by this number

    // If successful, it returns the number of nodes traversed in the linked list
    return nodesTraversed; 
    // Otherwise, it returns -1.
    // return -1
}

// deallocates the memory allocated to the process whose id is process_id.
int MemoryManagement::deallocate_mem(int process_id)
{
    std::cout << "Deallocating memory from Process " << process_id << "\n";
    // if successful, returns 1 to be stored in MemoryManagement
    return 0;
    // otherwise –1.
}

int MemoryManagement::fragment_count()
{
    // returns the number of holes (fragments of sizes 1 or 2 units).
    return 0;
}

// FIRST FIT ALGORITHM:
//      have variable to save first available spot
//          FOR LOOP: 
//              Search through linked list
//              if there is a spot, check next x amount of nodes
//                  if all nodes free
//                  save location
//          END FOR
//      place process in the location

// BEST FIT ALGORITHM:
//      memorySlot = infinity
//      counter = 0
//          FOR LOOP: Search through entire linked list
//              if there is a spot, check next x amount of nodes
//                  if all nodes free AND counter < memorySlot
//                      memorySlot = counter
//                      save locations    
//          END FOR
//      place process in the location