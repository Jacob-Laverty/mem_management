#ifndef LTS_H
#define LTS_H

#include <stdlib.h>
#include <stdio.h>

#include "simulation_utils.h"
#include "memory_block.h"

MemoryBlock* zero;

void init_lts();
void send_to_memory();
void lts_tick();
#endif
