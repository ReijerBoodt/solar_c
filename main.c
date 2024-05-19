#include "main.h"

int main (int argc, char *argv[]) {
    // body earth = {"earth",10,0,0};
    // printf("De eerste body heet: %s\n", earth.name);
    body bodies[] = {
        { "earth", M_earth, {0, 0},  {0, 0} },
        { "moon", M_moon, {lunar_distance, 0},  {0, 0} }
    };

    printf("\nThe distance squared is: %g\n",
        pow(dist_cubed(bodies[0].pos, bodies[1].pos), 2.f/3.f)
    );
    
    puts("Before:");
    print_bodies(2, bodies);
    int day = 60*60*24;
    for(int i=0;i<day*29;i++){
        do_step(2, bodies, 1.f);
        if (i%10000 == 0){
            // print_bodies(2, bodies);
        }
    }
    puts("After:");
    print_bodies(2, bodies);

    printf("\nThe distance squared is: %g\n",
        pow(dist_cubed(bodies[0].pos, bodies[1].pos), 2.f/3.f)
    );

    v2df a = {1,1};
    v2df b = {-1,0};
    print_vector(a+b);
    print_vector(a /4);

    return 0;
}

void print_vector(v2df v){
    printf("[%f %f]\n", v[0], v[1]);
}