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

void set_conversion_factor(double *conv, double AU_per_window, int WINDOW_WIDTH, int WINDOW_HEIGHT)
{
    double SIMULATED_WINDOW_WIDTH = AU_per_window * AU;
    *conv = WINDOW_WIDTH / SIMULATED_WINDOW_WIDTH;
}

bool m_IsKeyPressed(int key) {
    return IsKeyPressed(key) || IsKeyPressedRepeat(key);
}

void graphics_version(){

    // Bodies in the sim
    body *bodies = get_solar_system();
    size_t n = 15;

    // Variables governing the sim
    int steps_per_frame = 5;
    int dt = 60;
    double AU_per_window = 2.5f;
    unsigned int selected_body = 0;
    bool paused = false;
    double elapsed_time = 0.f;

    // Window initialization, rendering necessities
    int WINDOW_WIDTH = 1200;
    int WINDOW_HEIGHT = 800;
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "solar_c (2024)");
    WINDOW_WIDTH = GetMonitorWidth(GetCurrentMonitor());
    WINDOW_HEIGHT = GetMonitorHeight(GetCurrentMonitor());

    double conversion = 0;
    set_conversion_factor(&conversion, AU_per_window, WINDOW_WIDTH, WINDOW_HEIGHT);
    
    SetWindowState(FLAG_FULLSCREEN_MODE);
    SetTargetFPS(165);
    
    while (!WindowShouldClose())
    {
        for(int i=0; i<steps_per_frame && !paused; i++){
            do_step(n, bodies, dt);
            elapsed_time += dt;
        }

        if(m_IsKeyPressed(KEY_X)){
            steps_per_frame *= 1.25;
        }
        if(m_IsKeyPressed(KEY_Z)){
            steps_per_frame /= 1.25;
        }

        if(m_IsKeyPressed(KEY_UP)){
            AU_per_window /= 1.2;
            set_conversion_factor(&conversion, AU_per_window, WINDOW_WIDTH, WINDOW_HEIGHT);
        }
        if(m_IsKeyPressed(KEY_DOWN)){
            AU_per_window *= 1.2;
            printf("%f\n", AU_per_window);
            set_conversion_factor(&conversion, AU_per_window, WINDOW_WIDTH, WINDOW_HEIGHT);
        }

        if(m_IsKeyPressed(KEY_RIGHT)){
            selected_body = (selected_body + 1)  % n;
        }
        if(m_IsKeyPressed(KEY_LEFT)){
            selected_body = (selected_body - 1)  % n;
        }

        if(m_IsKeyPressed(KEY_SPACE)){
            paused = !paused;
        }

        if(m_IsKeyPressed(KEY_T)){
            dt *= -1;
        }

        if(m_IsKeyPressed(KEY_ONE) && IsKeyDown(KEY_LEFT_CONTROL)) {
            if (bodies[0].mass > 0){
                bodies[0].mass = 0;
            } else {
                bodies[0].mass = M_sun;
            }
        }

        BeginDrawing();
            ClearBackground(BLACK);

            for (int i=0; i<n; i++) {
                int x = WINDOW_WIDTH/2 + (bodies[i].pos - bodies[selected_body].pos )[0]*conversion;
                int y = WINDOW_HEIGHT/2 + (bodies[i].pos - bodies[selected_body].pos )[1]*conversion;
                
                if (x > 0 && x < WINDOW_WIDTH && y > 0 && y<WINDOW_HEIGHT){
                    DrawCircle(x, y, 3.f, bodies[i].color);
                }
            }
            
            // Draw tracked body
            char *cur_sel_text = malloc(256*sizeof(char));
            snprintf(cur_sel_text, 256, "Currently tracking: %s", bodies[selected_body].name);
            DrawText(cur_sel_text, 0, 30, 20, WHITE);

            // Draw elapsed time
            char *elapsed_time_text = malloc(256*sizeof(char));
            snprintf(elapsed_time_text, 256, "Elapsed time (days): %08.5e", elapsed_time / (60.0*24.0));
            DrawText(elapsed_time_text, 0, 60, 20, WHITE);

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
