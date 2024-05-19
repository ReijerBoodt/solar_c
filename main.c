#include "main.h"

int main (int argc, char *argv[]) {
    body bodies[] = {
        { "earth", M_earth, {0, 0},  {0, 0} },
        { "moon", M_moon, {lunar_distance, 0},  {0, 1022} }
    };

    puts("Before:");
    printf("The distance squared is: %g\n",
        pow(dist_cubed(bodies[0].pos, bodies[1].pos), 2.f/3.f)
    );
    print_bodies(2, bodies);

    int day = 60*60*24;
    int n_days = 14;
    for(int i=0;i<day*n_days;i++){
        do_step(2, bodies, 1.f);
        // if (i%day == 0){
        //     print_bodies(2, bodies);
        // }
    }
    printf("\nAfter %d days:\n", n_days);
    printf("The distance squared is: %g\n",
        pow(dist_cubed(bodies[0].pos, bodies[1].pos), 2.f/3.f)
    );
    print_bodies(2, bodies);
    print_bodies_relative(2, bodies);

    return 0;
}

void print_vector(v2df v){
    printf("[%f %f]\n", v[0], v[1]);
}