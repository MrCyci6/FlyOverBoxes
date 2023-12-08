// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main

#ifndef IMAGE_H
#define IMAGE_H

#include "../Utils/Log.h"
#include "../Includes.h"

typedef struct s_image {
  int width;
  int height;
  char** data;
} simage;

char mirrorChar(char character);
void flipImage (struct s_image* image);
struct s_image readImage(char* filename);
void deleteImage(struct s_image image);

#endif