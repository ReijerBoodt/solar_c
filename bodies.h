// Header file containing objects
#include "simulation.h"

// Solar system data
body solar_system[] = {
    {
        .name = "Sun",
        .mass = M_sun,
        .pos = {0, 0},
        .vel = {0, 0}
    
    },
    {
        .name = "Earth",
        .mass = M_earth,
        .pos = {AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Moon",
        .mass = M_moon,
        .pos = {lunar_distance, AU},
        .vel = {AU, 1022}
    },
    {
        .name = "Mercury",
        .mass = 0.55 * M_earth,
        .pos = {0.39 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Venus",
        .mass = 0.815 * M_earth,
        .pos = {0.72 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Mars",
        .mass = 0.107 * M_earth,
        .pos = {1.52 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Jupiter",
        .mass = 317.8 * M_earth,
        .pos = {5.20 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Io",
        .mass = 0.015 * M_earth,
        .pos = {5.20 * AU, 0.0028 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Europa",
        .mass = 0.008 * M_earth,
        .pos = {5.20 * AU, 0.0045 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Ganymede",
        .mass = 0.025 * M_earth,
        .pos = {5.20 * AU, 0.0071 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Callisto",
        .mass = 0.018 * M_earth,
        .pos = {5.20 * AU, 0.0126 * AU},
        .vel = {0, 0}
    },
    {
        .name = "Saturn",
        .mass = 95.2 * M_earth,
        .pos = {9.58 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Uranus",
        .mass = 14.5 * M_earth,
        .pos = {19.22 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Neptune",
        .mass = 17.1 * M_earth,
        .pos = {30.05 * AU, 0},
        .vel = {0, 0}
    },
    {
        .name = "Pluto",
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

    return solar_system;
}