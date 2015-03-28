#ifndef MEM_MANAGER_H
#define MEM_MANAGER_H
#include <stdlib.h>
#include <stdio.h>
#include "simulation_utils.h"
#include "memory.h"

typedef enum  {VSP, PAG, SEG} MemoryManagerPolicy;
typedef enum {FF, BF, WF} MemoryManagerPolicyParameter;

//Using a constant notation here becuase it wont
//change once its set.
static int MAX_SIZE;
typedef struct MemoryManagerStruct {
  int (*move_to_mem) (); 
  MemoryNode* (*seek) (int block_size);
  MemoryNode* (*clear_process) (int block_pid);
} MemoryManager;

//Start of memory
MemoryNode* mem_head;
//The policy
MemoryManagerPolicy mem_policy;
//The policy parameter
MemoryManagerPolicyParameter mem_policy_parameter;

void init_memory_manager();
void memory_manager_tick();
#endif
