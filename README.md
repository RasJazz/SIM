# sim SHELL

---

Created By: Aeron Flores (826123084) and Jasmine Rasmussen (129935517)
Edoras: Aeron (CSSC4404); Jasmine (CSSC4427)
CS480, Summer 2024 
Assignment 3, README

------------------- DELETE THIS WHEN DONE -------------------

# TO-DO

- Figure out functionality of processes
    - We want to give them each a linked list that can exist for life of process
    - implement memory functions
        - ***allocate***
            - specifies the following:
                - process id of the process for which memory is requested
                - the number of memory units being requested
                - **assume that memory is requested for each process only once**
        - ***deallocate***
            - process id of the process whose memory has to be deallocated
            - assume that the entire memory allocated to a process is deallocated on a deallocation request
        - ***fragment***
            - returns the number of holes (fragments of sizes 1 or 2 units)
    - **NOTE: EACH PROCESS MUST BE 3-10 UNITS LONG (min 3 nodes, max 10 nodes)**

- Stats report
    1. average number of external fragments
    2. average allocation time in terms of the average number of nodes traversed in allocation
    3. the percentage of times an allocation request is denied
    - Generate stats for each individual process
    - Generate stats for all processes total

Run your simulation generating 10,000 requests using the request generation component, and for each request, invoke the appropriate function of the Memory component for each of the memory allocation/deallocation technique. After every request, update the three performance parameters for each of the techniques.

-------------------------------------------------------------

### Overview

---

Sim is a program that (CHANGE ME):
- **(CHANGE ME)**
	- (CHANGE ME)
- **(CHANGE ME)**
	- (CHANGE ME)

### Files Included

---

Files/Folders included in `a3.zip`:
- `README.md`: Details on the program and how to run it
- `Makefile`: Makefile used to compile the `sim` executable
- `(CHANGE ME).h`: (CHANGE ME)
- `(CHANGE ME).cpp`: (CHANGE ME)
- `(CHANGE ME).cpp`: (CHANGE ME)
- `(CHANGE ME).cpp`: (CHANGE ME)
- `(CHANGE ME)`: (CHANGE ME)
- `(CHANGE ME)`: (CHANGE ME)
- `(CHANGE ME)`: (CHANGE ME)

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

###### (CHANGE ME)

(CHANGE ME)

###### (CHANGE ME)

(CHANGE ME)

###### (CHANGE ME)

(CHANGE ME)

### Other Features

---

- **(CHANGE ME)** (CHANGE ME)

### Known Bugs

---

- **(CHANGE ME):** (CHANGE ME)

- **(CHANGE ME):** (CHANGE ME) 


### Lessons Learned

---

- **(CHANGE ME):** (CHANGE ME)

- **(CHANGE ME):** (CHANGE ME)

- **(CHANGE ME):** (CHANGE ME)

- **(CHANGE ME):** (CHANGE ME)


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