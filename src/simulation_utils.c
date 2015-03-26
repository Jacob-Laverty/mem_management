#include "simulation_utils.h"

void set_input(char* input) {
  yyin = fopen(input, "r"); 
}

void set_output(char* output) {

}

int read_input() {
  return yylex();
}

char* get_token() {
  read_input();
  return yytext;
}

int get_token_value() {
  return read_input();
}

void write_to_output(char* output) {}

void debug(char* debug) {
#ifdef DEBUG
  printf("DEBUG: %s", debug);
#endif
}
