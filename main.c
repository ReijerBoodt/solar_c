#include "main.h"
#include "bodies.h"

void quick_test_session(){
    // Define an array of bodies
    body bodies[] = {
        { "earth", M_earth, {0, 0},  {0, 0} },
        { "moon", M_moon, {lunar_distance, 0},  {0, 1022} }
    };

    // Print initial state of bodies
    puts("Before:");
    printf("The distance squared is: %g\n",
        pow(dist_cubed(bodies[0].pos, bodies[1].pos), 2.f/3.f)
    );
    print_bodies(2, bodies);

    int day = 60*60*24;
    int n_days = 14;
    for(int i=0;i<day*n_days;i++){
        // Perform simulation step
        do_step(2, bodies, 1.f);
    }

    // Print final state of bodies
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

// Actual drawing code
void graphics_version(){
    body *bodies = get_solar_system();
    size_t n = 15;

    int WINDOW_WIDTH = 1200;
    int WINDOW_HEIGHT = 800;

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
            // Perform simulation step
            do_step(n, bodies, 60.f);
        }

        // Adjust simulation speed
        if(IsKeyPressed(KEY_X)){
            steps_per_frame *= 1.25f;
        }
        if(IsKeyPressed(KEY_Z)){
            steps_per_frame /= 1.25f;
        }

        // Adjust zoom level
        if(IsKeyPressed(KEY_UP)){
            AU_PER_WINDOW /= 1.2f;
            set_conversion_factor(&conversion, AU_PER_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT);
        }
        if(IsKeyPressed(KEY_DOWN)){
            AU_PER_WINDOW *= 1.2f;
            set_conversion_factor(&conversion, AU_PER_WINDOW, WINDOW_WIDTH, WINDOW_HEIGHT);
        }

        // Select next/previous body
        if(IsKeyPressed(KEY_RIGHT)){
            selected_body = (selected_body + 1)  % n;
        }
        if(IsKeyPressed(KEY_LEFT)){
            selected_body = (selected_body - 1)  % n;
        }

        // Draw bodies
        BeginDrawing();
            ClearBackground(BLACK);

            for (int i=0; i<n; i++) {
                int x = WINDOW_WIDTH/2 + (bodies[i].pos - bodies[selected_body].pos )[0]*conversion;
                int y = WINDOW_HEIGHT/2 + (bodies[i].pos - bodies[selected_body].pos )[1]*conversion;
                DrawCircle(x, y, 3.f, RED);
            }
            
            // Display currently tracked body
            char *cur_sel_text = malloc(256*sizeof(char));
            snprintf(cur_sel_text, 256, "Currently tracking: %s", bodies[selected_body].name);
            DrawText(cur_sel_text, 0, 30, 20, WHITE);

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
