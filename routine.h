#ifndef ROUTINE_H
#define ROUTINE_H

// HEADER FILES TO USE
#include "memory_management.h"
#include "process.h"
// LIBRARIES
#include <ctime>
#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

const int numProcesses = 4;
const int numRequests = 100;
extern std::vector<pid_t> processes;

void create_process(MemoryManagement&, std::vector<pid_t>&);
void cleanup_process(std::vector<pid_t>&);
int randomNumber();
// create stats function
void print_stats();

#endif