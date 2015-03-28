#include "memory.h"

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
