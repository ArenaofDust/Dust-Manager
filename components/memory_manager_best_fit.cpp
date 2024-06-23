#include "memory_manager_best_fit.h"
#include <string>

using namespace std;

MemoryManagerBestFit::MemoryManagerBestFit(int size)
{
    
    // Set up the list of memory blocks with the info for this initial
    // unallocated block.
    memory_block b;
    
    // TODO: Fill in the appropriate values here based on the data elements
    //       you added in the header file.
    b.block_size = size;
    b.is_full = false;
    b.block_name = "";
    b.start = 0;

    // Add the block to the list of blocks
    m_blocks.push_back(b);
}

//100: 1-> 0 -> 19 2->20->49 3->50->100
//block_size = 20 - 80
//new_block_size = 0 - 20


// Allocate a block of memory of the given size
// Find the unallocated block that has the best fit
// for the number of bytes being allocated.
int MemoryManagerBestFit::allocate(int size, string name) 
{
    // TODO: Implement the allocate logic as follows:
    //
    //       Find the smallest unallocated block that is at least
    //       as big as the number of bytes to be implemented.
    //
    //       If the block to be assigned is exactly the same size as
    //       the amount needed, set its data values to indicate that it
    //       is assigned.
    //
    //       If the block to be assigned is bigger than the number of bytes
    //       needed, split the block, leaving one block exactly the same size
    //       as needed, and a second block with the rest of the original.
    //       Add the new remainder block to the list of blocks.
    //
    //       Return the location of the block that was allocated.
    //       If no suitable location can be found to store the new block,
    //       return -1
    //50 / 5, 20, 10, 10, 15 / 
    if(!m_blocks.empty()) {
        int new_block_size = INT_MAX;
        for(auto it = m_blocks.begin(); it != m_blocks.end(); it++) {
            if(it->is_full == false) {
                if(it->block_size == size) {
                    it->is_full = true;
                    it->block_name = name;

                    return it->start; 
                }
                else if(it->block_size > size) {
                    new_block_size = min(new_block_size, it->block_size - size);
                }
            }
        }
        for(auto it = m_blocks.begin(); it != m_blocks.end(); it++) {
            if(it->is_full == false) {
                if(it->block_size - size == new_block_size) {
                    it->block_size = size;
                    it->block_name = name;
                    it->is_full = true;

                    //Creating new block
                    memory_block remain;
                    remain.block_size = new_block_size;
                    remain.is_full = false;
                    remain.block_name = "";
                    remain.start = it->block_size;

                    //Pushing back new block
                    m_blocks.push_back(remain);

                    

                    return it->start;;
                }
            }
        }
    }
    return -1;
}



// Release memory
bool MemoryManagerBestFit::release(string name) 
{
    // TODO: Implement the "release" logic as follows:
    //
    //       Find the block with the indicated name
    //
    //       Change the name of the block to "" to indicate that it is not allocated.
    //
    //       Return true if the block was released, or false otherwise
     if(!m_blocks.empty()) {
        for(auto it = m_blocks.begin(); it != m_blocks.end(); it++) {
            if(it->block_name == name) {
                it->block_name = "";

                return true;
            }
        }
    }
    //Print allocate
    return false;
}
