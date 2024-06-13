#include "memory_manager_base.h"
#include <string.h>
#include <iostream>

// Print the contents of memory
// This should print one line for each block of memory, including all the information
// associated with the block
//
// For example:
//
// start: 0 length: 5 name: A
// start: 5 length: 20 name: B


void MemoryManagerBase::print()
{
    // TODO: Cycle through all of the blocks and and print the information about each one
    //       on a single line.    
    for(auto it = m_blocks.begin(); it != m_blocks.end(); it++) {
        std::cout << "start: " << it->start << " length: " << it->block_size << " name: " << it->block_name << std::endl;
    }
}