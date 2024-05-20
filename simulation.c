#include "simulation.h"

double dist_cubed (v2df a, v2df b) {
    v2df diff = a - b;
    return pow(diff[0]*diff[0] + diff[1]*diff[1], 3.f/2.f);
}

v2df calc_interaction_vector(body b1, body b2)
{
    return (b2.pos - b1.pos) * G  / dist_cubed(b1.pos, b2.pos);
}

void do_step(size_t n, body *bodies, float dt)
{
    // v2df interaction_vectors[n*(n-1)/2];
    // printf("%d\n", n*(n-1)/2);
    for (int i=0; i < n; i++) {
        for (int j=0; j<i;j++){
            // interaction_vectors[i*n + j] = calc_interaction_vector(bodies[i], bodies[j]);
            v2df interaction = calc_interaction_vector(bodies[i], bodies[j]);
            bodies[i].vel += interaction * bodies[j].mass * dt;
            bodies[j].vel -= interaction * bodies[i].mass * dt;
            // printf("%g\n", interaction[0]);
        }
    }

    for (int i=0; i < n; i++) {
        bodies[i].pos += bodies[i].vel * dt;
    }
}

void print_bodies_relative(size_t n, body *bodies) {
    puts("Printing relative to body 0.");
    for(int i=0; i<n;i++){
        printf("%s: [%g, %g]\n",
            bodies[i].name,
            (bodies[i].pos - bodies[0].pos)[0],
            (bodies[i].pos - bodies[0].pos)[1]
        );
    }
}

void print_bodies(size_t n, body *bodies) {
    for(int i=0; i<n;i++){
        printf("%s: [%g, %g]\n",
            bodies[i].name,
            bodies[i].pos[0],
            bodies[i].pos[1]
        );
    }
}

void shift_phase(size_t n, body *bodies, v2df shift) {
    for(int i=0; i<n;i++){
        float random_phase = 2 * M_PI;
        bodies[i].pos[0] *= cos(random_phase);
        bodies[i].pos[1] = sin(random_phase) * bodies[i].pos[0];
        // pos[0] initially stores the orbital radius
    }
}