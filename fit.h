#ifndef FIT_H
#define FIT_H

#include "memory_management.h"
#include <limits>

class Fit{
    public:
        virtual int allocateMem(int, int, MemoryManagement&) = 0;
        virtual ~Fit() {}
};
#endif