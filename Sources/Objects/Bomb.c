// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main
#include "Bomb.h"

sbomb initializeBomb(int isPowerup, int x, int y, soptions options, int level) {
    sbomb bomb;

    bomb.x = (float) x;
    bomb.y = (float) y;
    bomb.speed = 1 +  ((float) level/2);
    bomb.character = isPowerup == 1 ? '!' : '*';
    bomb.isActive = 1;

    return bomb;
}

void drawBomb(sbomb bomb, int clear, soptions options) {
    char buffer[8];

    if(bomb.isActive != 1) return;
    if(options.colors == 1) changeCursorBackgroundColor("blue");

    sprintf (buffer, "%c\n", bomb.character);

    if(clear == 1) {
        drawXYText(" \n", bomb.x, bomb.y);
    } else {
        drawXYText(buffer, bomb.x, bomb.y);
    }
}

void updateBombPosition(sbomb* bomb) {
    if(bomb->isActive == 1) {
        bomb->y = bomb->y + 0.5 * bomb->speed;
    }
    if(bomb->y >= (SCREEN_HEIGHT - 1)) bomb->isActive = 0;
}