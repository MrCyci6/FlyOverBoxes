// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Options
#include "Options.h"

soptions getDefaultOptions() {

    soptions options;

    options.difficulty = DEFAULT_DIFFICULTY;
    options.planeType = DEFAULT_PLANETYPE;
    options.powerup = DEFAULT_POWERUP;
    options.colors = DEFAULT_COLORS;
    options.run = 0;
    options.quit = 0;
    options.help = DEFAULT_HELP;
    strcpy(options.name, DEFAULT_NAME);

    return options;
}