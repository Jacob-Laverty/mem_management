#include "memory.h"

void init_memory() {
  int token;
  while((token = read_input()) != -1) {
    switch(token) {
      case MEMORY_SIZE:
        debug("Setting memory size\n");
        char* mem_size = get_token_value();
        MAX_SIZE = atoi(mem_size);
        break;
      case MEMORY_POLICY:
        break;
      case POLICY:
        break;
    }
  }
}

void mem_insert(MemoryNode* node, MemoryBlock* block) {
  MemoryNode* new = malloc(sizeof(MemoryNode*));
  new -> block = malloc(sizeof(MemoryBlock*));

  new -> block = block;

  MemoryNode* p = node;
  MemoryNode* n = node -> next;

  p -> next = new;
  n -> prev = new;

  new -> prev = p;
  new -> next = n;
}

void mem_remove(MemoryNode* node) {
  MemoryNode* p = node -> prev;
  MemoryNode* n = node -> next;

  p -> next = n;
  n -> prev = p;

  free(node);
}
