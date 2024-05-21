// Header file containing objects
#include "simulation.h"

// Solar system data
body solar_system[] = {
    {
        .name = "Sun",
        .color = YELLOW,
        .mass = M_sun,
        .pos = {0, 0},
        .vel = {0, 0}
    
    },
    {
        .name = "Earth",
        .color = BLUE,
        .mass = M_earth,
        .pos = {AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Moon",
        .color = GRAY,
        .mass = M_moon,
        .pos = {AU, lunar_distance},
        .vel = {0, 0}
    },
    {
        .name = "Mercury",
        .color = RED,
        .mass = 0.55 * M_earth,
        .pos = {0.39 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Venus",
        .color = ORANGE,
        .mass = 0.815 * M_earth,
        .pos = {0.72 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Mars",
        .color = MAROON,
        .mass = 0.107 * M_earth,
        .pos = {1.52 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Jupiter",
        .color = BEIGE,
        .mass = 317.8 * M_earth,
        .pos = {5.20 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Io",
        .color = GREEN,
        .mass = 0.015 * M_earth,
        .pos = {5.20 * AU, 0.0028 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Europa",
        .color = PURPLE,
        .mass = 0.008 * M_earth,
        .pos = {5.20 * AU, 0.0045 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Ganymede",
        .color = VIOLET,
        .mass = 0.025 * M_earth,
        .pos = {5.20 * AU, 0.0071 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Callisto",
        .color = PINK,
        .mass = 0.018 * M_earth,
        .pos = {5.20 * AU, 0.0126 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Saturn",
        .color = MAGENTA,
        .mass = 95.2 * M_earth,
        .pos = {9.58 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Uranus",
        .color = SKYBLUE,
        .mass = 14.5 * M_earth,
        .pos = {19.22 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Neptune",
        .color = DARKBLUE,
        .mass = 17.1 * M_earth,
        .pos = {30.05 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Pluto",
        .color = RED,
        .mass = 0.00218 * M_earth,
        .pos = {39.48 * AU, 0},
        .vel = {0, 0}
    }
};

double get_orbital_speed(double parent_mass, double radius) {
    return sqrt(G * parent_mass / radius);
}

body *get_solar_system () {
    size_t n = sizeof(solar_system) / sizeof(solar_system[0]);

    // Speed around the sun
    for (int i=1; i<n; i++) {
        solar_system[i].vel[1] = get_orbital_speed(
            M_sun, solar_system[i].pos[0]
        );
    }

    // Speed of moons around Jupiter
    for (int i=7; i<=10; i++) {
        solar_system[i].vel[0] = get_orbital_speed(
            M_jupiter, solar_system[i].pos[1]
        );
    }

    // Speed of moon around Earth
    solar_system[2].vel[0] = get_orbital_speed(
        M_earth, solar_system[2].pos[1]
    );

    FILE *fprandom = fopen("/dev/urandom", "rb");
    short randint;
    for (int i=1; i<n; i++) {
        fread(&randint, sizeof(randint), 1, fprandom);

        double normalized_value = randint / pow(2, 8*sizeof(randint)) / 20 + 1;

        solar_system[i].vel *= normalized_value;
        printf("%d\n", randint);
    }
    fclose(fprandom);

    return solar_system;
}