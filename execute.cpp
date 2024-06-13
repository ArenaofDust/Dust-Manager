// Main program for Memory Management
//
// This program will be run as follows:
//
// run_memory <algo> <memory_size> <input_file>
//    Where <algo> will be either "first_fit" or "best_fit", and
//          <size> is the number of bytes of memory to allocate
//          <input_file> contains a set of instructions


#include "memory_manager_base.h"
#include "memory_manager_first_fit.h"
#include "memory_manager_best_fit.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char ** argv)
{
    MemoryManagerBase * memory;   // Memory Manager that will be used 
    string algorithm;             // String choosing which memory manager to use
    int memory_size;              // Amount of memory to allocate

    // TODO: Process the command line arguments and populate the associated 
    //       variables. Validate that the algorithm is one of the supported 
    //       values and that the memory_size argument is > 0
    
    if(argc != 4) {
        cout << "Error: Not enough arguments" << endl;
        return -1;
    }    

    if(string(argv[1]) != "first_fit" && string(argv[1]) != "best_fit") {
       cout << "Error: Please input an appropriate algorithm" << endl;
       return -1;
    }
    if(atoi(argv[2]) <= 0) {
       cout << "Error: memory_size must be greater than zero" << endl;
       return -1;
    }
    else {
        algorithm = string(argv[1]);
        memory_size = atoi(argv[2]);
    }
    
    // Allocate a memory manager based on the
    // chosen algorithm.
    if (algorithm == "first_fit") {
        memory = (MemoryManagerBase *) new MemoryManagerFirstFit(memory_size);
    } else if (algorithm == "best_fit") {
        memory = (MemoryManagerBase *) new MemoryManagerBestFit(memory_size);
    } 
    
    // Print the initial memory setup
    memory->print();
    
    // Open the input file. 
    ifstream in(argv[3]);
   
    if (! in.good()) {
        cerr << "Failed to open file " << argv[3] << endl;
        return(6);
    }   

   
    bool released = false;
    while(in.good()) {
        // Process the input file one line at a time.

        // TODO: Read in the input line and take the action
        //       indicated on each line
        string function_call;
        string alloc_block_name;
        int alloc_size;
       
        /*while(in >> function_call >> alloc_size >> alloc_block_name) {
            if(function_call == "allocate" && alloc_size > 0 && alloc_block_name != "") {
              int location = memory->allocate(alloc_size, alloc_block_name);                  
              cout << "Memory allocated at position: " << location << endl;
            } 
            
        }

        while(in >> function_call >> alloc_block_name) {
                if(memory->release(alloc_block_name) == true) {
                    cout << "Memory block: " << alloc_block_name << " released" << endl;
                }
                else {
                    cout << "Memory block: " << alloc_block_name << " has not been released" << endl;
                }
        }
        cout << endl;
        */
        string line;
        while(getline(in, line)) {
            istringstream iss(line);
            iss >> function_call;
            if(function_call == "allocate") {
                iss >> alloc_size >> alloc_block_name;

                if(memory->allocate(alloc_size, alloc_block_name) != -1) {
                    cout << "Memory block " << alloc_block_name << ": Allocated" << endl;     
                }
                else {
                    cout << "Memory block " << alloc_block_name << ": Not allocated" << endl;  
                }
                iss.clear();
            }
            else if(function_call == "release") {
                iss >> alloc_block_name;
                if(memory->release(alloc_block_name)) {
                   cout << "Memory block " << alloc_block_name << ": released" << endl;
                }
                else {
                    cout << "Memory block " << alloc_block_name << ": has not been released" << endl;
                }
                
                iss.clear();
            }
        }
        cout << endl;
        
        // Print the current memory layout after each action is complete
        memory->print();
        cout << endl;

    }


    return 0;
}