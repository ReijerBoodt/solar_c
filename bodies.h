// Header file containing objects
#include "simulation.h"


body sun = {
    .name = "Sun",
    .mass = M_sun,
    .pos = {0, 0},
    .vel = {0, 0}
};

body earth = {
    .name = "Earth",
    .mass = M_earth,
    .pos = {AU, 0},
    .vel = {0, 0}
};

body moon = {
    .name = "Moon",
    .mass = M_moon,
    .pos = {lunar_distance, 0},
    .vel = {0, 1022}
}; 

body mercury = {
    .name = "Mercury",
    .mass = 0.55 * M_earth,
    .pos = {0.39 * AU, 0},
    .vel = {0, 0}
};

body venus = {
    .name = "Venus",
    .mass = 0.815 * M_earth,
    .pos = {0.72 * AU, 0},
    .vel = {0, 0}
};

body mars = {
    .name = "Mars",
    .mass = 0.107 * M_earth,
    .pos = {1.52 * AU, 0},
    .vel = {0, 0}
};

body jupiter = {
    .name = "Jupiter",
    .mass = 317.8 * M_earth,
    .pos = {5.20 * AU, 0},
    .vel = {0, 0}
};

body io = {
    .name = "Io",
    .mass = 0.015 * M_earth,
    .pos = {5.20 * AU, 0.0028 * AU},
    .vel = {0, 0}
};

body europa = {
    .name = "Europa",
    .mass = 0.008 * M_earth,
    .pos = {5.20 * AU, 0.0045 * AU},
    .vel = {0, 0}
};

body ganymede = {
    .name = "Ganymede",
    .mass = 0.025 * M_earth,
    .pos = {5.20 * AU, 0.0071 * AU},
    .vel = {0, 0}
};

body callisto = {
    .name = "Callisto",
    .mass = 0.018 * M_earth,
    .pos = {5.20 * AU, 0.0126 * AU},
    .vel = {0, 0}
};

body saturn = {
    .name = "Saturn",
    .mass = 95.2 * M_earth,
    .pos = {9.58 * AU, 0},
    .vel = {0, 0}
};

body uranus = {
    .name = "Uranus",
    .mass = 14.5 * M_earth,
    .pos = {19.22 * AU, 0},
    .vel = {0, 0}
};

body neptune = {
    .name = "Neptune",
    .mass = 17.1 * M_earth,
    .pos = {30.05 * AU, 0},
    .vel = {0, 0}
};

body pluto = {
    .name = "Pluto",
    .mass = 0.00218 * M_earth,
    .pos = {39.48 * AU, 0},
    .vel = {0, 0}
};

body solar_system[] = {
    sun,
    earth,
    moon,
    mercury,
    venus,
    mars,
    jupiter,
    io,
    europa,
    ganymede,
    callisto,
    saturn,
    uranus,
    neptune,
    pluto
};