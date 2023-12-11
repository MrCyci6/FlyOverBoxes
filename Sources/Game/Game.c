// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023
#include "Game.h"

int waitInput(int timeout){
    struct timeval waitingTime;
    fd_set descriptorSet;
    int input = 0;

    // Setup input param and timeout
    FD_ZERO(&descriptorSet);
    FD_SET(0, &descriptorSet);
    waitingTime.tv_sec = 0;
    waitingTime.tv_usec = timeout;

    // Wait for user input

    if(select(1, &descriptorSet, NULL, NULL, &waitingTime) != 0){
        fgetc(stdin);
        input = 1;
    }

    // Wait remaining time (if input)
    usleep(waitingTime.tv_usec);

    return input;
}

void drawBackground(struct s_histogram histogram, struct s_options options, int level, int score) {
    resetCursorColorsAndType();

    if(options.colors) changeCursorForegroundColor("blue");
    drawXYRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, BORDER_CHAR, 1, 1);

    if(options.colors) changeCursorForegroundColor("magenta");
    drawXYHistogram(histogram, 2, SCREEN_HEIGHT);

    if(options.colors) changeCursorForegroundColor("red");
    drawXYText(options.name, 3, 2);

    char s[150];
    sprintf(s, "Score: %d\n", score);
    drawXYText(s, SCREEN_WIDTH - strlen(s), 2);

    char l[150];
    sprintf(l, "Level: %d\n", level);
    drawCenteredText(l, 2);
}

int checkBombCrash(struct s_bomb* bomb, struct s_histogram histogram, struct s_options options) {
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

int checkPlaneCrash(struct s_plane* plane, struct s_histogram histogram) {
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

int runLevel(int level, struct s_options options, int* score) {
    struct s_histogram histogram;
    if(options.difficulty == 1) {
        histogram = generateHistogram(WIDTH_LEVEL1, HEIGHT_LEVEL123, 'I');
    } else if(options.difficulty == 2) {
        histogram = generateHistogram(WIDTH_LEVEL2, HEIGHT_LEVEL123, 'I');
    } else {
        histogram = generateHistogram(WIDTH_LEVEL3, HEIGHT_LEVEL123, 'I');
    }

    struct s_plane plane;
    plane = initializePlane(options, level);

    struct s_bomb bomb;
    bomb.isPowerup = 0;
    bomb.isActive = 0;

    if(options.powerup && (rand()%5) == 1){
        bomb.isPowerup = 1;
    }
    else{
        bomb.isPowerup = 0;
    }

    drawBackground(histogram, options, level, *score);

    while(1) {
        drawPlane(plane, 0, options);
        drawBomb(bomb, 0, options);

        if (waitInput (50000) == 1 && !bomb.isActive) {
            bomb = initializeBomb(bomb.isPowerup,
                                  plane.x + plane.image.width / 2,
                                  plane.y + plane.image.height,
                                  options, level);
        }

        if(checkBombCrash(&bomb, histogram, options)) {
            *score = *score + options.difficulty * (level + 1) * BASE_SCORE;
            drawBackground(histogram, options, level, *score);
            if(bomb.isPowerup) {
                drawCenteredText("POWERUP\n", 3);
            }
        }

        if(checkPlaneCrash(&plane, histogram)) return 1;
        if(isEmpty(histogram)) return 0;

        drawPlane(plane, 1, options);
        updatePlanePosition(&plane);

        if(bomb.isActive) {
            drawBomb(bomb, 1, options);
            updateBombPosition(&bomb);
        }
    }
}

void runGame(struct s_options options) {
    int level = 0, score = 0, stop = 0;

    while(stop != 1) {
        stop = runLevel(level, options, &score);
        level++;

        char str[150];
        sprintf(str, "Press any key for step to level  %d\n", level);
        drawCenteredText(str, SCREEN_HEIGHT - 15);
        fgetc(stdin);
    }
}