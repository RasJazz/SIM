#include "routine.h"
#include "memory_management.h"

// BRAINSTORMING SECTION
/*
FIRST FIT AND BEST FIT
PAGE 190 in BOOK

Linked List will have 256 KB total, divided into 2 KB units
Process can request 3-10 Units (6-20 KB)

Each slot in memory gets:
- Process ID
- Value KB
*/


int main(){

    // Creating new memory object and initializing the max total memory available to 256 KB
    MemoryManagement memory(256);
    MemoryNode node(2, 1);
    // ******************* Change this to a Memory linked list ************************
    // populate list with nodes

    std::cout << "--- Total memory available: " << memory.totalMemoryAvailable << "KB ---\n\n";
    /* ******************************* FOR TESTING PURPOSES ********************************* */
    std::cout << "Allocating 3 units of memory\n";
    memory.memoryAvailable(3, node);
    std::cout << "--- Total memory available: " << memory.totalMemoryAvailable << "KB ---\n\n";

    std::cout << "Deallocating 10 units of memory\n";
    memory.memoryAvailable(-10, node);
    std::cout << "--- Total memory available: " << memory.totalMemoryAvailable << "KB ---\n\n";
    /* *********************************** END TESTING ************************************** */

    // ******************* For loop to create a process. Run 10,000 times ************************
    create_process(memory);

    // print stats
    print_stats();
    // nice exit message
    std::cout << "Ending program\n";
}