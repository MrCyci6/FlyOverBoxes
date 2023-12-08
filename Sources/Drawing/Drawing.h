// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main

#ifndef DRAWING_H
#define DRAWING_H

#include "../Objects/Histogram.h"
#include "../Objects/Image.h"
#include "../Utils/Log.h"
#include "../Includes.h"

void clearScreen();
void setCursorPosition(int x, int y);
void resetCursorPosition();
void resetCursorColorsAndType();
void changeCursorType(char* type);
void changeCursorForegroundColor(char* color);
void changeCursorBackgroundColor(char* color);
void drawXYRectangle(int width, int height, char symbol, int x, int y);
void drawText(char* text);
void drawXYText(char* text, int x, int y);
void drawXYImage(struct s_image image, int x, int y, int empty);
void drawXYHistogram(struct s_histogram histogram, int x, int y);
int getCenteredTextStart(char* text);
int drawCenteredText(char* text, int y);

#endif