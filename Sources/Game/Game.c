// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main
#include "Game.h"

int waitInput(int timeout) {
    struct timeval waitingTime;
    fd_set descriptorSet;
    int input = 0;

    FD_ZERO (&descriptorSet);
    FD_SET (0, &descriptorSet);
    waitingTime.tv_sec = 0;
    waitingTime.tv_usec = 100000;

    if (select (1, &descriptorSet, NULL, NULL, &waitingTime) != 0)
    {
        fgetc (stdin);
        input = 1;
    }

    usleep (waitingTime.tv_usec);
    return input;
}

void drawBackground(shistogram histogram, soptions options, int level, int score) {
    resetCursorColorsAndType();

    if(options.colors == 1) changeCursorForegroundColor("blue");
    drawXYRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, BORDER_CHAR, 1, 1);

    if(options.colors == 1) changeCursorForegroundColor("magenta");
    drawXYHistogram(histogram, 2, SCREEN_HEIGHT);

    if(options.colors == 1) changeCursorForegroundColor("red");
    drawXYText(options.name, 3, 2);

    char s[150];
    sprintf(s, "Score: %d\n", score);
    drawXYText(s, SCREEN_WIDTH - strlen(s), 2);

    char l[150];
    sprintf(l, "Level: %d\n", level);
    drawCenteredText(l, 2);
}

int checkBombCrash(sbomb* bomb, shistogram histogram, soptions options) {
    if(bomb->isActive == 0) return 0;

    int binNumber = XYIntersectHistogram(bomb->x, bomb->y, histogram);
    if(binNumber == -1) {
        return 0;
    } else {
        if(bomb->isPowerup == 1) {
            clearBin(binNumber, &histogram);
        } else {
            decrementBin(binNumber, 1, &histogram);
        }
        bomb->isActive = 0;
        if(options.powerup == 1 && rand()%5 == 0) {
            bomb->isPowerup = 1;
        } else {
            bomb->isPowerup = 0;
        }

        return 1;
    }
}

int checkPlaneCrash(splane* plane, shistogram histogram) {
    if(plane->orientation == 1) {
        if(XYIntersectHistogram(plane->x + plane->image.width, plane->y + plane->image.height, histogram) != -1) {
            return 1;
        } else {
            return 0;
        }
    } else {
        if(XYIntersectHistogram(plane->x, plane->y + plane->image.height, histogram) != -1) {
            return 1;
        } else {
            return 0;
        }
    }
}

int runLevel(int level, soptions options, int* score) {
    shistogram histogram;
    if(options.difficulty == 1) histogram = generateHistogram(WIDTH_LEVEL1, HEIGHT_LEVEL123, 'I');
    if(options.difficulty == 2) histogram = generateHistogram(WIDTH_LEVEL2, HEIGHT_LEVEL123, 'I');
    if(options.difficulty == 3) histogram = generateHistogram(WIDTH_LEVEL3, HEIGHT_LEVEL123, 'I');

    splane plane;
    plane = initializePlane(options, level);

    sbomb bomb;
    bomb.isPowerup = 0;
    bomb.isActive = 0;
    drawBackground(histogram, options, level, *score);

    while(1) {
        drawPlane(plane, 0, options);
        drawBomb(bomb, 0, options);

        if (waitInput (500000) == 1 && !bomb.isActive)
            bomb = initializeBomb (bomb.isPowerup,
                                   plane.x + plane.image.width/2,
                                   plane.y + plane.image.height,
                                   options, level);

        drawPlane(plane, 1, options);
        drawBomb(bomb, 1, options);

        updatePlanePosition(&plane);
        updateBombPosition(&bomb);

        if(checkBombCrash(&bomb, histogram, options) == 1) {
            *score = *score + options.difficulty * (level + 1) * BASE_SCORE;
            drawBackground(histogram, options, level, *score);
            if(bomb.isPowerup == 1) {
                drawCenteredText("POWERUP\n", 3);
            }
        }

        if(checkPlaneCrash(&plane, histogram)) return 1;
        if(isEmpty(histogram)) return 0;
    }
}

void runGame(soptions options) {
    int level = 0;
    int score = 0;
    int stop;

    while(stop != 1) {
        stop = runLevel(level, options, &score);
        level++;
        drawCenteredText("Press any key to continue", SCREEN_HEIGHT - 3);
        fgetc(stdin);
    }
}