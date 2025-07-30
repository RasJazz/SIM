# SIM

Aeron Flores and Jasmine Rasmussen<br>
_CS480 Summer 2024_<br>
Assignment 3, README<br>

---

### Overview

---

Sim is a program that simulates memory allocation and deallocation on an operating system using a linked list. This program has a handful of built-in functions:
- **BestFit: allocateMem, deallocateMem, and fragmentCount**
	- lets users allocate and deallocate memory based on the best fit algorithm and also uses the fragmentCount class to count for fragments in memory
- **First Fit: allocateMem, deallocateMem, and fragmentCount**
	- lets users allocate and deallocate memory based on the first fit algorithm and also uses the fragmentCount class to count for fragments in memory
- **generateRequest**
	- includes random number generation for generating allocation and deallocation and number of units to be requested dynamically
- **stats**
	- produces the following for each memory model:
	    - Average External Fragments Each Request
		- Average Nodes Traversed Each Allocation
		- Percentage Allocation Requests Denied Overall

### Files Included

---

Files/Folders included in `a3.zip`:
- `README.md`: Details on the program and how to run it
- `Makefile`: Makefile used to compile the `sim` executable
- `best_fit.cpp`: Derived class of `MemoryManagement`; Contains functions for best fit allocation and deallocation algorithm and fragment count
- `first_fit.cpp`: Derived class of `MemoryManagement`; Contains functions for first fit allocation and deallocation algorithm and fragment count
- `generate_request.cpp`: Generates the process IDs and units requested for the processes; Also generates whether process is allocated or deallocated
- `generate_request.h`: Header file for `generate_request.cpp`
- `main.cpp`: Main source file that outputs results for first fit and best fit based on the number of requests.
- `memory_management.h`: Header file for `best_fit.cpp` and `first_fit.cpp`
- `stats.cpp`: Generates statistics for Best Fit and First fit memory models
- `stats.h`: Header file for `stats.cpp`

### Compilation instructions

---

##### Requirements:

To compile the program, **G++ v.4.8.5** (or a similar compiler) that compiles **C++11** is needed.

###### File Installation
1. Download `a3.zip` and extract the files to a directory of your choice.
2. Once finished, open your terminal and navigate to `a3`.
	To navigate to the directory: 
	- Windows Command Prompt (cmd)/PowerShell:  `cd Drive:\path\to\directory\a3`
	- MacOS: `cd /path/to/directory/a3`
	- Linux/UNIX: `cd /path/to/directory/a3`

###### Create Sim Executable File
1. Navigate to folder `/a3` 
2. Run command `make` to create the executable `sim`.

### Run Program

---

Program `sim` is ready to be used! Run the program using the following commands:
- Windows Command Prompt (cmd): `sim`
- Windows PowerShell: `.\sim`
- Linux/UNIX/MacOS: `sim`

***NOTE:*** 
Command `make clean` will remove any generated object files and executables.

### (EXAMPLE SECTION CHANGE ME)

---

```
------------------- FIRST FIT ---------------------
Average Number of External Fragments: 0.0216539
Average Allocation Time (nodes traversed): 14.7484
Percentage of Allocation Requests Denied: 30.92%
-------------------- BEST FIT ---------------------
Average Number of External Fragments: 0.0173031
Average Allocation Time (nodes traversed): 31.0846
Percentage of Allocation Requests Denied: 29.32%
```

### Design Decisions

---

###### Modular Design

The project is organized into multiple source files, each handling specific parts of the sim functionality. This modular design helps with code readability, maintainability, and the facilitation of easier debugging and testing.

###### Separate Memory Components for First Fit and Best Fit Functionality

First Fit and Best Fit builds upon the modular design by separating their logic and the data they send and receive. This makes it easier to modify each memory model without affecting others. They also utilize an abstract base class `MemoryManagement`. This design allows for future memory models to be implemented if need be.

###### Random Request Generation

Random values are generated for determining the amount of units of memory each process will request. Each unit of memory contains 2 KB of space and each process can request a minimum of 3 units up to a maximum of 10 units of memory. If there is no memory available, allocation requests are subsequently logged.

### Known Bugs

---

- **Memory Fragmentation Not Correctly Merged:** The fragment_count function might return excessive fragmentation or have a lack of memory.

- **Incorrect Handling of Edge Cases in Allocation:** The allocation function has the possibility of not correctly handling edge cases such as those where the memory is full or when small fragments are available.


### Lessons Learned

---

- **Effective Collaboration and Teamwork:** Working in pairs for this assignment showed the need for clear communication and working together on tasks. We learned that regular code reviews and pair programming sessions on the Discord app can greatly enhance code quality and team productivity. There was a lot of debugging and problem solving done by us that required good teamwork.

- **Emphasis of Efficient Data Structures:** In this project, using a linked list for managing memory blocks was an effective choice since it allowed dynamic memory allocation and deallocation. It was not an easy task to figure out fragmentation and traversing the list for allocation requests.

- **Good Error Handling and Edge Case Management:** It is important in implementation to handle edge cases like fully occupied memory or unusable fragments which could lead to errors or crashes. Implementing error handling makes sure the code is stable.

- **Modularity Using Inheritance:** By separating the logic of First Fit and Best Fit from the request generation and stats components, the program was easier to manage when modified and tested.

- **Soruce Control and Documentation:** The authors of this project chose to make use of source control tools such as Git and Github in order to handle the evolving nature of this program. This taught us that clear comments and documentation were useful in organizing the code for more clarity so that both of us could understand the code.
