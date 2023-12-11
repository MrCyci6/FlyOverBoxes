// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023
#include "Image.h"

char mirrorChar(char character) {
    switch (character) {
        case '/':
            return '\\';
        case '\\':
            return '/';
        case '<':
            return '>';
        case '>':
            return '<';
        case '(':
            return ')';
        case ')':
            return '(';
        case '[':
            return ']';
        case ']':
            return '[';
        default:
            return character;
    }
}

void flipImage (struct s_image* image) {
    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width/2; j++) {
            char temp = image->data[i][j];
            image->data[i][j] = image->data[i][image->width - j - 1];
            image->data[i][image->width - j - 1] = temp;
        }
    }

    for(int i = 0; i < image->height; i++) {
        for(int j = 0; j < image->width; j++) {
            image->data[i][j] = mirrorChar(image->data[i][j]);
        }
    }
}

void drawXYImage(struct s_image image, int x, int y, int empty) {
    int h, w;

    for(h = 0; h < image.height; h++) {
        for(w = 0; w < image.width; w++) {
            if(empty) {
                drawXYText(" ", w + x, h + y);
            } else {
                drawXYText(&image.data[h][w], w + x, h + y);
            }
        }
    }
}

struct s_image readImage(char* filename) {
    struct s_image image;
    int x;
    int y;
    FILE* file;

    file = fopen(filename, "r");
    fscanf (file, "%d %d\n", &image.width, &image.height);
    image.data = (char**)malloc (image.height*sizeof (char*));

    for (y = 0; y < image.height; y++)
    {
        image.data[y] = (char*)malloc (image.width*sizeof (char));
        for (x = 0; x < image.width; x++)
        {
            fscanf (file, "%c", &image.data[y][x]);
            if (image.data[y][x] == '@')
                image.data[y][x] = ' ';
        }
        fscanf (file, "\n");
    }

    fclose (file);

    return image;
}

void deleteImage(struct s_image* image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
}