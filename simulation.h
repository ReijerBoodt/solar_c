#ifndef SIMULATION_INCLUDED
#define SIMULATION_INCLUDED

#include "constants.h"
#include "raylib.h"

#include <math.h>
#include <stdio.h>

// Vector type consisting of two doubles 
typedef double v2df __attribute__ ((vector_size (16)));

typedef struct body {
    char *name;
    Color color;
    double mass;
    v2df pos;
    v2df vel;
} body;

void do_step(size_t n, body *bodies, float dt);
void print_bodies_relative(size_t n, body *bodies);
void print_bodies(size_t n, body *bodies);
double dist_cubed(v2df a, v2df b);
v2df calc_interaction_vector(body b1, body b2);
#endif // SIMULATION_INCLUDED