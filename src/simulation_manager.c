#include "simulation_manager.h"

void initialize_simulation(char* input, char* output) {
  set_output(output);
  set_input(input);
  init_timer();
  init_lts();
}

void cycle() {
  timer_tick();
}


