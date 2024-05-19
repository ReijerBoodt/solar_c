#include "main.h"
// #include ""

void quick_test_session(){
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
}

void graphics_version(){
    int n=2;
    body bodies[] = {
        { "earth", M_earth, {0, 0},  {0, 0} },
        { "moon", M_moon, {lunar_distance, 0},  {0, 200.f} }
    };

    int WINDOW_WIDTH = 1920;
    int WINDOW_HEIGHT = 1080;

    double LD_PER_WINDOW = 6.f;
    double SIMULATED_WINDOW_WIDTH = LD_PER_WINDOW * lunar_distance;
    double conversion = WINDOW_WIDTH / SIMULATED_WINDOW_WIDTH;

    // distance / ld * pixels_per_ld

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "solar_c (2024)");
    SetTargetFPS(600);

    int steps_per_frame = 100;

    while (!WindowShouldClose())
    {
        for(int i=0; i<steps_per_frame; i++){
            do_step(n, bodies, 1.f);
        }

        // if(IsKeyPressed(KEY_Q)) SetWindow
        if(IsKeyDown(KEY_X)){
            steps_per_frame += 1;
        }
        if(IsKeyDown(KEY_Z)){
            steps_per_frame -= 1;
        }

        BeginDrawing();
            ClearBackground(RAYWHITE);
            // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            for (int i=0; i<n; i++) {
                int x = WINDOW_WIDTH/2 + bodies[i].pos[0]*conversion;
                int y = WINDOW_HEIGHT/2 + bodies[i].pos[1]*conversion;
                DrawCircle(x, y, 3.f, RED);
            }
            DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
}

void print_vector(v2df v){
    printf("[%f %f]\n", v[0], v[1]);
}

int main (int argc, char *argv[]) {
    quick_test_session();
    graphics_version();
    return 0;
}