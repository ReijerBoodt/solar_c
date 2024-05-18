#include <stdio.h>
#include <math.h>

typedef struct Body {
    // Name
    double mass;
    double r_orbit;
    double semi_major_axis;
    double semi_minor_axis;

} Body;

int main (int argc, char *argv[]) {
    printf("hoer\n");
    Body earth = {10,0,0,0};
    return 0;
}