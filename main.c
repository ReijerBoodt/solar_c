#include "main.h"
#include "bodies.h"
// #include ""

void quick_test_session(){
    body bodies[] = {
        { "earth", M_earth, {0, 0},  {0, 0} },
        { "moon", M_moon, {lunar_distance, 0},  {0, 1022} }
    };

    // body *bodies = get_solar_system();

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

void set_conversion_factor(double *conv, double AU_PER_WINDOW, int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    double SIMULATED_WINDOW_WIDTH = AU_PER_WINDOW * AU;
    *conv = WINDOW_WIDTH / SIMULATED_WINDOW_WIDTH;
}

void graphics_version(){
    // int n=2;
    // body bodies[] = {
    //     { "earth", M_earth, {0, 0},  {0, 0} },
    //     { "moon", M_moon, {lunar_distance, 0},  {0, 200.f} }
    // };
    body *bodies = get_solar_system();
    size_t n = 15;


    int WINDOW_WIDTH = 1920;
    int WINDOW_HEIGHT = 1080;

    double AU_PER_WINDOW = 2.5f;
    double conversion = 0;
    set_conversion_factor(&conversion, AU_PER_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT);

    int steps_per_frame = 500;
    unsigned int selected_body = 0;

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "solar_c (2024)");
    SetTargetFPS(165);
    while (!WindowShouldClose())
    {
        for(int i=0; i<steps_per_frame; i++){
            do_step(n, bodies, 60.f);
        }

        if(IsKeyDown(KEY_X)){
            steps_per_frame *= 1.025f;
        }
        if(IsKeyDown(KEY_Z)){
            steps_per_frame /= 1.025f;
        }

        if(IsKeyPressed(KEY_UP)){
            AU_PER_WINDOW /= 1.2f;
            set_conversion_factor(&conversion, AU_PER_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT);
        }
        if(IsKeyPressed(KEY_DOWN)){
            AU_PER_WINDOW *= 1.2f;
            printf("%f\n", AU_PER_WINDOW);
            set_conversion_factor(&conversion, AU_PER_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT);
        }

        if(IsKeyPressed(KEY_RIGHT)){
            selected_body = (selected_body + 1)  % n;
        }
        if(IsKeyPressed(KEY_LEFT)){
            selected_body = (selected_body - 1)  % n;
        }

        BeginDrawing();
            ClearBackground(BLACK);
            // DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

            for (int i=0; i<n; i++) {
                int x = WINDOW_WIDTH/2 + (bodies[i].pos - bodies[selected_body].pos )[0]*conversion;
                int y = WINDOW_HEIGHT/2 + (bodies[i].pos - bodies[selected_body].pos )[1]*conversion;

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