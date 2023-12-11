// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023
#include "Bomb.h"

struct s_bomb initializeBomb(int isPowerup, int x, int y, struct s_options options, int level) {
    struct s_bomb bomb;

    bomb.x = x;
    bomb.y = y;
    bomb.speed = 1.0 +  ((float) level/2);
    bomb.isPowerup = isPowerup;
    bomb.character = isPowerup == 1 ? '!' : '*';
    bomb.isActive = 1;

    return bomb;
}

void drawBomb(sbomb bomb, int clear, soptions options) {
    char buffer[8];

    if(bomb.isActive != 1) return;
    if(options.colors == 1) changeCursorForegroundColor("blue");

    sprintf (buffer, "%c\n", bomb.character);

    if(clear == 1) {
        drawXYText(" \n", bomb.x, bomb.y);
    } else {
        drawXYText(buffer, bomb.x, bomb.y);
    }
    resetCursorColorsAndType();
}

void updateBombPosition(sbomb* bomb) {
    if(bomb->isActive == 1) {
        bomb->y = bomb->y + 0.5 * bomb->speed;
    }
    if(bomb->y >= (SCREEN_HEIGHT - 1)) bomb->isActive = 0;
}