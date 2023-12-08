// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Options

#ifndef OPTIONS_H
#define OPTIONS_H

#include "../Utils/Log.h"
#include "../Includes.h"

typedef struct s_options {
    int difficulty;
    int planeType;
    int powerup;
    int colors;
    char name[256];
    int run;
    int quit;
    int help;
} soptions;

soptions getDefaultOptions();

#endif