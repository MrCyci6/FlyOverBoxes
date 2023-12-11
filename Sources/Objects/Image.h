// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#ifndef IMAGE_H
#define IMAGE_H

#include "../Utils/Log.h"
#include "../Includes.h"
#include "../Drawing/Drawing.h"

struct s_image {
  int width;
  int height;
  char** data;
};

char mirrorChar(char character);
void flipImage (struct s_image* image);
void drawXYImage(struct s_image image, int x, int y, int empty);
struct s_image readImage(char* filename);
void deleteImage(struct s_image* image);

#endif