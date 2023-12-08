// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main
#include "Drawing.h"

void clearScreen() {
    printf("\x1b[2J");
}

void setCursorPosition (int x, int y) {
    printf("\x1b[%d;%dH", y, x);
}

void resetCursorPosition() {
    setCursorPosition(0,0);
}

void resetCursorColorsAndType() {
    changeCursorType("reset");
    changeCursorBackgroundColor("black");
    changeCursorForegroundColor("white");
}

void changeCursorForegroundColor (char* color) {
    int foregroundValue = -1;

    if(strcasecmp(color, "black") == 0) {
        foregroundValue = 30;
    } else if(strcasecmp(color, "red") == 0) {
        foregroundValue = 31;
    } else if(strcasecmp(color, "green") == 0) {
        foregroundValue = 32;
    } else if(strcasecmp(color, "yellow") == 0) {
        foregroundValue = 33;
    } else if(strcasecmp(color, "blue") == 0) {
        foregroundValue = 34;
    } else if(strcasecmp(color, "magenta") == 0) {
        foregroundValue = 35;
    } else if(strcasecmp(color, "cyan") == 0) {
        foregroundValue = 36;
    } else if(strcasecmp(color, "white") == 0) {
        foregroundValue = 37;
    }

    printf ("\x1b[%dm", foregroundValue);
}

void changeCursorBackgroundColor (char* color) {
    int backgroundValue = -1;

    if(strcasecmp(color, "black") == 0) {
        backgroundValue = 40;
    } else if(strcasecmp(color, "red") == 0) {
        backgroundValue = 41;
    } else if(strcasecmp(color, "green") == 0) {
        backgroundValue = 42;
    } else if(strcasecmp(color, "yellow") == 0) {
        backgroundValue = 43;
    } else if(strcasecmp(color, "blue") == 0) {
        backgroundValue = 44;
    } else if(strcasecmp(color, "magenta") == 0) {
        backgroundValue = 45;
    } else if(strcasecmp(color, "cyan") == 0) {
        backgroundValue = 46;
    } else if(strcasecmp(color, "white") == 0) {
        backgroundValue = 47;
    }

    printf ("\x1b[%dm", backgroundValue);
}

void changeCursorType(char* type) {
    int cursor = -1;

    if(strcasecmp(type, "reset") == 0) {
        cursor = 0;
    } else if(strcasecmp(type, "bright") == 0) {
        cursor = 1;
    } else if(strcasecmp(type, "dim") == 0) {
        cursor = 2;
    } else if(strcasecmp(type, "underscore") == 0) {
        cursor = 4;
    } else if(strcasecmp(type, "blink") == 0) {
        cursor = 5;
    } else if(strcasecmp(type, "reverse") == 0) {
        cursor = 7;
    } else if(strcasecmp(type, "hidder") == 0) {
        cursor = 8;
    }

    printf ("\x1b[%dm", cursor);
}

void drawXYRectangle(int width, int height, char symbol, int x, int y) {
    int w;
    int h;

    //TOP
    setCursorPosition(x, y);
    for(int i = 0; i < width; i++) {
        printf("%c", symbol);
    }
    printf("\n");

    // MIDDLE
    for (h = 1; h <= height - 2; h++) {
        setCursorPosition(x, y+h);
        printf("%c", symbol);
        for (w = 2; w <= width - 1; w++) {
            printf(" ");
        }
        printf("%c\n", symbol);
    }

    // BOTTOM
    setCursorPosition(x, y+h);
    for(int i = 0; i < width; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

void drawText(char* text) {
    printf("%s", text);
}

void drawXYText(char* text, int x, int y) {
    setCursorPosition(x, y);
    drawText(text);
}

void drawXYImage(simage image, int x, int y, int empty) {
    int h, w;

    for(h = 0; h < image.height; h++) {
        setCursorPosition(x, y + h);
        for(w = 0; w < image.width; w++) {
            if(empty == 1) {
                printf(" ");
            } else {
                printf("%c", image.data[h][w]);
            }
        }
    }
}

void drawXYHistogram(shistogram histogram, int x, int y) {
    int binSize;
    int bin;
    int element;

    binSize = (SCREEN_WIDTH - 2) / histogram.numberOfBins;

    for (bin = 0; bin < histogram.numberOfBins; bin++) {
        for (element = histogram.bins[bin]; element > 0; element--) {
            drawXYRectangle(binSize, BOX_HEIGHT, histogram.displayCharacter, (x + binSize * bin), (y - element * BOX_HEIGHT));
        }
    }
}

int getCenteredTextStart(char* text) {
    return (SCREEN_WIDTH/2)-(strlen(text)/2);
}

int drawCenteredText(char* text, int y) {
    drawXYText(text, getCenteredTextStart(text), y);
}