#ifndef ROUTINE_H
#define ROUTINE_H

// HEADER FILES TO USE
#include "memory_management.h"
// LIBRARIES
#include <ctime>
#include <iostream>
#include <list>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

const int numProcesses = 4;
const int numRequests = 100;

void create_process(MemoryManagement&);
int randomNumber();
// create stats function
void print_stats();

#endif