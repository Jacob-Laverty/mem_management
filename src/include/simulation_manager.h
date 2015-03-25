#ifndef SIM_MAN_H
#define SIM_MAN_H
#include <stdlib.h>
#include <stdio.h>
#include "timer.h"
#include "simulation_utils.h"

/*
 * The simulation manager class contains all of the structures that belong to the simulation but
 * should not be visible to each other. They will be accessible in the timer so that each pieve may have
 * its own tick function called.
 */



void initialize_simulation();
void cycle();
#endif
