// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main

#ifndef GAME_H
#define GAME_H

#include "../Drawing/Drawing.h"
#include "../Objects/Bomb.h"
#include "../Objects/Histogram.h"
#include "../Objects/Image.h"
#include "../Objects/Plane.h"
#include "../Utils/Log.h"
#include "../Utils/Options.h"
#include "../Scores/Scores.h"
#include "../Includes.h"

int waitInput(int timeout);
void drawBackground(struct s_histogram histogram, struct s_options options, int level, int score);
int checkBombCrash(struct s_bomb* bomb, struct s_histogram histogram, struct s_options options);
int checkPlaneCrash(struct s_plane* plane, struct s_histogram histogram);
int runLevel(int level, struct s_options options, int* score);
void runGame(struct s_options options);

#endif