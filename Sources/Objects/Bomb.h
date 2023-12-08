// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main

#ifndef BOMB_H
#define BOMB_H

#include "../Drawing/Drawing.h"
#include "../Utils/Log.h"
#include "../Utils/Options.h"
#include "../Includes.h"

#define HAUTEUR 50

typedef struct s_bomb {
    float x;
    float y;
    float speed;
    int isPowerup;
    char character;
    int isActive;
} sbomb;

sbomb initializeBomb(int isPowerup, int x, int y, struct s_options options, int level);
void drawBomb(struct s_bomb bomb, int clear, struct s_options options);
void updateBombPosition(struct s_bomb* bomb);

#endif