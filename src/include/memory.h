#ifndef MEMORY_H
#define MEMORY_H
/*
 * The memory block file will contain all of the methods and fields for manipulating 
 * blocks of memory and the "main memory". The main memory will be a linked list containg
 * memory nodes. Inside of the memory nodes there will be memory blocks. The blocks are simply
 * a 64 bit integer that is bit packed. There will be accessor methods defined as macros to 
 * manipulate the 64 bit memory block
 */
#include <stdlib.h>
#include <stdio.h>
#include "memory_block.h"
#include "simulation_utils.h"

static int MAX_SIZE;
//Defining the node in the "memory linked list"
typedef struct MemoryNodeStruct {
  MemoryBlock* block;
  struct MemoryNodeStruct* next;
  struct MemoryNodeStruct* prev;
} MemoryNode;

//Head and tail of memory list
MemoryNode* memory_head;
MemoryNode* memory_tail;

//Operators for the memory list
void mem_insert(MemoryNode* node, MemoryBlock* block);
void mem_remove(MemoryNode* node);

void init_memory();
#endif
