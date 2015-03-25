#include "simulation.h"

int main(int argc, char** argv) {
  char* input_location = NULL;
  char* output_location = NULL;

  int opterr = 0;

  int c;

  while((c = getopt(argc, argv, "f:o:")) != -1) {
    switch(c) {
      case 'f': 
        input_location = optarg;
        break;
      case 'o':
        output_location = optarg;
        break;
    }
  }

  initialize_simulation(input_location, output_location);
  return 0;
}
