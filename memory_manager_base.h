#ifndef MEMORY_MANAGER_BASE_H
#define MEMORY_MANAGER_BASE_H

#include <list>
#include <string>
#include <algorithm>

// memory_manager_base.h
//
// Base class of a Memory manager.

class MemoryManagerBase {

    public:

        // Allocate memory
        // This is a pure virtual function; it will be implemented in the 
        // derived classes.
        //
        // Arguments:
        //      size: Number of bytes to allocate
        //      name: The name of the segment being allocated
        // Returns the location of the allocated memory in the block that is managed by 
        // this class.
   
virtual int allocate(int size, std::string name) = 0;

        // Release memory
        // This is a pure virtual function; it will be implemented in the 
        // derived classes. 
        //
        // Arguments:
        //      name: The name of the segment to be released

        // Returns true if the memory is successfully released, false otherwise
        virtual bool release(std::string name) = 0;    // Name of the memory location to release


        // Print the contents of memory
        virtual void print();
    
    // The below items are protected (rather than private) so they can be 
    // accessed by the derived classes.

    protected:
        
        // Data structure to keep track of allocated memory
        struct memory_block {
            // TODO: Define the data members in this structure that will keep track
            //       of the available blocks of memory.
            int block_size;
            std::string block_name;
            bool is_full;
            int start;
        }; 
        
        // List of blocks of memory
        std::list<struct memory_block> m_blocks;
};

#endif