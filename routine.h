#ifndef ROUTINE_H
#define ROUTINE_H

#include "process.h"
#include <iostream>
#include <vector>
#include <unistd.h>

const int numProcesses = 4;
extern std::vector<Process*> processes;

void create_process();
void cleanup_process();
// create stats function
void print_stats();

#endif