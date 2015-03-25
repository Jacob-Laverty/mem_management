#include "simulation_utils.h"

void set_input(char* input) {
  yyin = fopen(input, "r"); 
}

void set_output(char* output) {

}

int read_input() {
  return yylex();
}

void write_to_output(char* output) {}

void debug(char* debug) {
#ifdef DEBUG
  printf("DEBUG: %s", debug);
#endif
}
