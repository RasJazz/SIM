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

// FF = First Fit, BF = Best Fit
enum fitType{ FF = 0, BF = 1};
const int numProcesses = 4;
const int numRequests = 20;

void simulateFit(MemoryManagement&, int);
// create stats function
void print_stats();

#endif