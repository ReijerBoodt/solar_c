// Header file containing objects
#include "simulation.h"

// Solar system data
body solar_system[] = {
    { // Sun
        .name = "Sun",
        .mass = M_sun,
        .pos = {0, 0},
        .vel = {0, 0}
    
    }, 
    { // Earth
        .name = "Earth",
        .mass = M_earth,
        .pos = {AU, 0},
        .vel = {0, 0}
    },
    { // Moon
        .name = "Moon",
        .mass = M_moon,
        .pos = {lunar_distance, AU},
        .vel = {AU, 1022}
    },
    { // Mercury
        .name = "Mercury",
        .mass = 0.55 * M_earth,
        .pos = {0.39 * AU, 0},
        .vel = {0, 0}
    },
    { // Venus
        .name = "Venus",
        .mass = 0.815 * M_earth,
        .pos = {0.72 * AU, 0},
        .vel = {0, 0}
    },
    { // Mars
        .name = "Mars",
        .mass = 0.107 * M_earth,
        .pos = {1.52 * AU, 0},
        .vel = {0, 0}
    },
    { // Jupiter
        .name = "Jupiter",
        .mass = 317.8 * M_earth,
        .pos = {5.20 * AU, 0},
        .vel = {0, 0}
    },
    { // Io
        .name = "Io",
        .mass = 0.015 * M_earth,
        .pos = {5.20 * AU, 0.0028 * AU},
        .vel = {0, 0}
    },
    { // Europa
        .name = "Europa",
        .mass = 0.008 * M_earth,
        .pos = {5.20 * AU, 0.0045 * AU},
        .vel = {0, 0}
    },
    { // Ganymede
        .name = "Ganymede",
        .mass = 0.025 * M_earth,
        .pos = {5.20 * AU, 0.0071 * AU},
        .vel = {0, 0}
    },
    { // Callisto
        .name = "Callisto",
        .mass = 0.018 * M_earth,
        .pos = {5.20 * AU, 0.0126 * AU},
        .vel = {0, 0}
    },
    { // Saturn
        .name = "Saturn",
        .mass = 95.2 * M_earth,
        .pos = {9.58 * AU, 0},
        .vel = {0, 0}
    },
    { // Uranus
        .name = "Uranus",
        .mass = 14.5 * M_earth,
        .pos = {19.22 * AU, 0},
        .vel = {0, 0}
    },
    { // Neptune
        .name = "Neptune",
        .mass = 17.1 * M_earth,
        .pos = {30.05 * AU, 0},
        .vel = {0, 0}
    },
    { // Pluto
        .name = "Pluto",
        .mass = 0.00218 * M_earth,
        .pos = {39.48 * AU, 0},
        .vel = {0, 0}
    }
};

double get_orbital_speed(double parent_mass, double radius) {
    return sqrt(G * parent_mass / radius);
}

// Set initial velocities for solar system
body *get_solar_system () {
    size_t n = sizeof(solar_system) / sizeof(solar_system[0]);

    // Speed around the sun
    for (int i=1; i<n; i++) {
        solar_system[i].vel[1] = -get_orbital_speed(
            M_sun, solar_system[i].pos[0]
        );
    }

    // Speed of moons around Jupiter
    for (int i=7; i<=10; i++) {
        solar_system[i].vel[0] = -get_orbital_speed(
            M_jupiter, solar_system[i].pos[1]
        );
    }

    // Speed of moon around Earth
    solar_system[2].vel[0] = -get_orbital_speed(
        M_earth, solar_system[2].pos[1]
    );

    return solar_system;
}