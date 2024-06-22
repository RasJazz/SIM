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