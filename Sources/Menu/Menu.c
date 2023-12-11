// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023
#include "Menu.h"

void displayDifficultyOption(int difficulty, int y) {
    int x;

    x = getCenteredTextStart ("Difficulty: 1 - 2 - 3");
    setCursorPosition (x, y);

    drawText ("Difficulty: ");
    if (difficulty == 1)
    {
        changeCursorType ("reverse");
        drawText ("1");
        resetCursorColorsAndType ();
    }
    else
        drawText ("1");
    drawText (" - ");

    if (difficulty == 2)
    {
        changeCursorType ("reverse");
        drawText ("2");
        resetCursorColorsAndType ();
    }
    else
        drawText ("2");
    drawText (" - ");

    if (difficulty == 3)
    {
        changeCursorType ("reverse");
        drawText ("3");
        resetCursorColorsAndType ();
    }
    else
        drawText ("3");
}

void displayPlaneTypeOption(int planeType, int y) {
    int x;

    x = getCenteredTextStart ("Plane type: 1 - 2");
    setCursorPosition (x, y);

    drawText ("Plane type: ");
    if (planeType == 1)
    {
        changeCursorType ("reverse");
        drawText ("1");
        resetCursorColorsAndType ();
    }
    else
        drawText ("1");
    drawText (" - ");

    if (planeType == 2)
    {
        changeCursorType ("reverse");
        drawText ("2");
        resetCursorColorsAndType ();
    }
    else
        drawText ("2");
}

void displayPowerupOption(int powerup, int y) {
    int x;

    x = getCenteredTextStart ("Powerup: Yes - No");
    setCursorPosition (x, y);

    drawText ("Powerup: ");
    if (powerup == 1)
    {
        changeCursorType ("reverse");
        drawText ("Yes");
        resetCursorColorsAndType ();
    }
    else
        drawText ("Yes");
    drawText (" - ");

    if (powerup == 0)
    {
        changeCursorType ("reverse");
        drawText ("No");
        resetCursorColorsAndType ();
    }
    else
        drawText ("No");
}

void displayColorsOption(int colors, int y) {
    int x;

    x = getCenteredTextStart ("Colors: Yes - No");
    setCursorPosition (x, y);

    drawText ("Colors: ");
    if (colors == 1)
    {
        changeCursorType ("reverse");
        drawText ("Yes");
        resetCursorColorsAndType ();
    }
    else
        drawText ("Yes");
    drawText (" - ");

    if (colors == 0)
    {
        changeCursorType ("reverse");
        drawText ("No");
        resetCursorColorsAndType ();
    }
    else
        drawText ("No");
}

void displayNameOption(char* name, int y) {
    char names[MAX_STRING_SIZE];
    sprintf(names, "Name: %s", name);

    drawCenteredText(names, y);
}

void displayHelp() {
    drawXYText ("Help:", 2, SCREEN_HEIGHT + 2);
    drawXYText ("-----", 2, SCREEN_HEIGHT + 3);
    drawXYText("set difficulty 1|2|3 -> change the difficulty", 6, SCREEN_HEIGHT + 4);
    drawXYText("set planetype 1|2 -> change the plane type", 6, SCREEN_HEIGHT + 5);
    drawXYText("set powerup|colors yes|no -> change the powerup/colors", 6, SCREEN_HEIGHT + 6);
    drawXYText("set name your_name -> change the name", 6, SCREEN_HEIGHT + 7);
    drawXYText("run -> run the game", 6, SCREEN_HEIGHT + 8);
    drawXYText("quit -> quit the game", 6, SCREEN_HEIGHT + 9);
    drawXYText("help -> show/hide this help", 6, SCREEN_HEIGHT + 10);
}

void displayMenu(soptions* options) {
    struct s_image image;

    do {
        clearScreen();

        resetCursorColorsAndType();
        resetCursorPosition();

        drawXYRectangle(SCREEN_WIDTH, SCREEN_HEIGHT, BORDER_CHAR, 1, 1);

        image = readImage(LOGO_FILE);
        changeCursorType("blink");
        drawXYImage(image, (SCREEN_WIDTH/2)-(image.width/2), 2, 0);

        resetCursorColorsAndType();

        displayDifficultyOption(options->difficulty, image.height + 6);
        displayPlaneTypeOption(options->planeType, image.height + 8);
        displayPowerupOption(options->powerup, image.height + 10);
        displayColorsOption(options->colors, image.height + 12);
        displayNameOption(options->name, image.height + 14);

        if(options->help == 1) displayHelp();

        drawXYText("Enter a command > ", 3, SCREEN_HEIGHT-1);

        char userCommand[MAX_STRING_SIZE];
        fgets (userCommand, MAX_STRING_SIZE, stdin);

        parseUserCommand(userCommand, options);
    } while(options->run == 0 && options->quit == 0);
}