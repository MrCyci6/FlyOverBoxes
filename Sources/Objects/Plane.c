// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main
#include "Plane.h"

void drawPlane(splane plane, int clear, soptions options) {
    if(options.colors == 1) changeCursorBackgroundColor("blue");
    drawXYImage(plane.image, plane.x, plane.y, clear);
}

void updatePlanePosition (splane* plane) {
    plane->x = plane->x + plane->orientation * plane->speed;
    if(plane->x >= (SCREEN_WIDTH - 1 - plane->image.width) || plane->x <= 2) {
        plane->y = plane->y + 2;
        plane->orientation = -1 * plane->orientation;
        flipImage(&plane->image);
    }
}

splane initializePlane(soptions options, int level) {
    splane plane;
    simage image;

    if(options.planeType == 1)
        image = readImage(PLANE1_FILE);
    else
        image = readImage(PLANE2_FILE);

    flipImage(&image);

    plane.x = PLANE_X;
    plane.y = PLANE_Y;
    plane.orientation = 1;
    plane.speed = 1 + ((float) level / 2);

    return plane;
}