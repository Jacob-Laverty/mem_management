#include "lts.h"

void init_lts() {
  int dma = 0;
  switch(mem_policy) {
    case VSP:
      debug("MAX_PROCESSES\n");
      dma = MAX_PROCESSES;
      break;
    case PAG:
      debug("MAX_PROCESSES\n");
      dma = MAX_PROCESSES;
    case SEG:
      debug("MAX_PROCESSES*MAX_SEGMENTS\n");
      dma = MAX_PROCESSES*MAX_SEGMENTS;
  }
  //Allocate space for all the processes
  block_ptr = (MemoryBlock*) calloc(dma, sizeof(MemoryBlock*));
  int token;
  char* buffer;
  while((token = read_input()) != -1) {
    switch(token) {
      case PID:
        if(*block_ptr != 0) {
          debug("Space not clean, moving ptr\n");
          buffer = NULL;
          debug("Last block: \n");

          long foo = MB_PID(*block_ptr);
          asprintf(&buffer, "PID: %lu\n", foo);
          debug(buffer);

          foo = 0;
          buffer = NULL;
          foo = MB_ADDRESS(*block_ptr);
          asprintf(&buffer, "ADDRESS: %lu\n", foo);
          debug(buffer);

          foo = 0;
          buffer = NULL;
          foo = MB_ARRIVAL(*block_ptr);
          asprintf(&buffer, "ARRIVAL: %lu\n", foo);
          debug(buffer);

          foo = 0;
          buffer = NULL;
          foo = MB_LIFETIME(*block_ptr);
          asprintf(&buffer, "LIFETIME: %lu\n", foo);
          debug(buffer);
          
          block_ptr++;
        }
        buffer = NULL;
        long pid = atoi(get_token());
        asprintf(&buffer, "Process Id: %lu\n", pid);
        debug("Setting PID\n");
        debug(buffer);
        *block_ptr = SET_PID(*block_ptr, pid);
        break;
      case ARRIVAL:
        debug("Setting arrival time\n");
        buffer = NULL;
        long arrival = atoi(get_token());
        asprintf(&buffer, "Arrival time: %lu\n", arrival);
        debug(buffer);
        *block_ptr = SET_ARRIVAL(*block_ptr, arrival);
        break;
      case LIFETIME:
        debug("Setting lifetime in memory\n");
        buffer = NULL;
        long lifetime = atoi(get_token());
        asprintf(&buffer, "Lifetime: %lu\n", lifetime);
        debug(buffer);
        *block_ptr = SET_LIFETIME(*block_ptr, lifetime);
        break;
      case ADDRESS:
        debug("Setting address space\n");
        switch(mem_policy) {
          case VSP:
            debug("Setting one contingous process\n");
            buffer = NULL;
            long addr = atoi(get_token());
            asprintf(&buffer, "Address: %lu\n", addr);
            debug(buffer);
            *block_ptr = SET_ADDRESS(*block_ptr, addr);
            break;
          case PAG:
            debug("Setting one contiguous process that will be paged\n");
            SET_ADDRESS(*block_ptr, 0);
            break;
          case SEG:
              debug("Getting multiple segments\n");
              break;
        }
      case LEX_EOF:
        debug("End of input file\n");
        break;
    }
  }
}

void send_to_memory() {}

void lts_tick() {}
