#include "lts.h"

void init_lts() {
  //Use calloc here. It takes longer but it will zero out the memory.
  //Since we are using bit packing for the memory block we kinda need the entire
  //space to be zero-d
  zero = (MemoryBlock*) calloc(MAX_PROCESSES, sizeof(MemoryBlock*));
  int token;
  while((token = read_input()) != -1) {
    switch(token) {
      case LEX_EOF:
        break;
    }
  }
}

void send_to_memory() {}

void lts_tick() {}
