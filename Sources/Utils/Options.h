// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#ifndef OPTIONS_H
#define OPTIONS_H

#include "../Utils/Log.h"
#include "../Includes.h"

typedef struct s_options {
    int difficulty;
    int planeType;
    int powerup;
    int colors;
    char name[MAX_STRING_SIZE];
    int run;
    int quit;
    int help;
} soptions;

soptions getDefaultOptions();

#endif