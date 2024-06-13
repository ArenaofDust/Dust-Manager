#ifndef MEMORY_MANAGER_BEST_FIT_H
#define MEMORY_MANAGER_BEST_FIT_H

#include "memory_manager_base.h"
#include <list>
#include <string>

using namespace std;

// memory_manager_best_fit.h
//
// Class implementing a best fit memory manager

class MemoryManagerBestFit : public MemoryManagerBase {

    public:

        // Constructor.
        // This function initializes the data structure
        // that tracks the memory blocks
        MemoryManagerBestFit(int size);
        
        // Allocate the indicated amount of memory.
        // See the comments in memory_manager_base.h for details
        virtual int allocate(int size, std::string name);

        // Release the memory with the given name.
        // See the comments in memory_manager_base.h for details
        virtual bool release(std::string name);     
        
    private:

};

#endif