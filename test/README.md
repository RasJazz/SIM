# SIM

---

Created By: Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
Edoras: Aeron (CSSC4404); Jasmine (CSSC4427)
CS480, Summer 2024 
Assignment 3, README

---

### Overview

---

Sim is a program that simulates memory allocation/deallocation using four built in functions:
- **best_fit**
	- lets users allocate and deallocate memory based on the best fit algorithm and also uses the fragment_count class to count for fragments in memory.
- **first_fit**
	- lets users allocate and deallocate memory based on the first fit algorithm and also uses the fragment_count class to count for fragments in memory.
- **generate_request**
	- includes random number generation for allocation and deallocation.
- **stats**
	- gives results of statistics based on best fit and first fit.

### Files Included

---

Files/Folders included in `a3.zip`:
- `README.md`: Details on the program and how to run it
- `Makefile`: Makefile used to compile the `sim` executable
- `best_fit.cpp`: Function for best fit algorithm
- `first_fit.cpp`: Function for the first fit algorithm
- `generate_request.cpp`: Generates the numbers for the processes in allocation/deallocation
- `generate_request.h`: Header file for generate_request.cpp
- `main.cpp`: Main source file that outputs results for first fit and best fit based on the number of requests.
- `memory_management.h`: Header file for memory_management.cpp
- `stats.cpp`: Gives all the statistics for the best and first fit
- `stats.h`: Header file for stats.cpp

### Compile instructions

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

###### Create Test Executable File
1. While in folder `a3`, navigate to `/testdir`
2. Run command `make` to create the executable `sample_program`

###### Create Shell Executable File
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

(CHANGE ME)

### Design Decisions

---

###### Modular Design


The project is organized into multiple source files, each handling specific parts of the sim functionality. This modular design helps with code readability, maintainability, and the facilitation of easier debugging and testing.

###### Random Request Generation

Random values are generated for determining the amount of units per thread which are repeated that many times. The number generated is always between 3 to 10 but will not allocate if there is not enough memory.

###### Separate Memory Components for First Fit and Best Fit

First Fit and Best Fit are separate classes that are easier to modify without affecting the other because they are different algorithms.

### Other Features

---

- **(CHANGE ME)** (CHANGE ME)

### Known Bugs

---

- **Memory Fragmentation Not Correctly Merged:** The fragment_count function might return excessive fragmentation or have a lack of memory.

- **Incorrect Handling of Edge Cases in Allocation:** The allocation function has the possibility of not correctly handling edge cases like when the memory is full or only small fragments are available.


### Lessons Learned

---

- **Effective Collaboration and Teamwork:** Working in pairs for this assignment showed the need for clear communication and working together on tasks. We learned that regular code reviews and pair programming sessions on the Discord app can greatly enhance code quality and team productivity.There was a lot of debugging and problem solving done by us that required good teamwork.

- **Emphasis of Efficient Data Structures:** In this project, using a linked list for managing memory blocks was an effective choice since it allowed dynamic memory allocation/deallocation. It was not an easy task to figure out fragmentation and traversing the list for allocation requests.

- **Good Error Handling and Edge Case Management:** It is important in implementation to handle edge cases like fully occupied memory or unusable fragments which could lead to errors or crashes. Implementing error handling makes sure the code is stable.

- **Modularity and Separating Requirements:** Since we separated the memory management logic of First Fit and Best Fit from the request generation and stats components, the program was easier to get an understanding of for testing and modifications. The modular approach gives independent testing of each component and also provided clarity.
- **Documentation and Commenting:** Providing clear comments and documentation was very useful in organizing the code for more clarity so that both of us could understand the code.


### Code Creation

---

**Jasmine:**
- `(CHANGE ME)`
	- (CHANGE ME)
- `(CHANGE ME)`
	- (CHANGE ME)
- `(CHANGE ME)`
	- (CHANGE ME)
- `(CHANGE ME)`
	- (CHANGE ME)

**Aeron:**
- `(CHANGE ME)`
	- (CHANGE ME)
- `(CHANGE ME)`
	- (CHANGE ME)
