// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main
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

void flipImage (simage* image) {
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

simage readImage(char* filename) {
    simage image;
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

void deleteImage(simage image) {
    for (int i = 0; i < image.height; i++) {
        free(image.data[i]);
    }
    free(image.data);
}