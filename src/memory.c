#include "memory.h"

void mb_init_memory_block() {
  memory_head = malloc(sizeof(MemoryNode*));
  memory_tail = malloc(sizeof(MemoryNode*));
}

void mb_insert(MemoryNode* node, MemoryBlock* block) {
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

void mb_remove(MemoryNode* node) {
  MemoryNode* p = node -> prev;
  MemoryNode* n = node -> next;

  p -> next = n;
  n -> prev = p;

  free(node);
}
