// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#include "Plane.h"

void drawPlane(struct s_plane plane, int clear, struct s_options options) {
    if(options.colors) changeCursorForegroundColor("blue");
    drawXYImage(plane.image, plane.x, plane.y, clear);
    resetCursorColorsAndType();
}

void updatePlanePosition (struct s_plane* plane) {
    plane->x += plane->orientation * plane->speed;
    if(plane->x >= (SCREEN_WIDTH - 1 - plane->image.width) || plane->x <= 2) {
        plane->y += 2;
        plane->orientation = -1 * plane->orientation;
        flipImage(&plane->image);
    }
}

struct s_plane initializePlane(struct s_options options, int level) {
    struct s_plane plane;

    if(options.planeType == 1) {
        plane.image = readImage(PLANE1_FILE);
    } else {
        plane.image = readImage(PLANE2_FILE);
    }

    flipImage(&plane.image);

    plane.x = PLANE_X;
    plane.y = PLANE_Y;
    plane.orientation = 1;
    plane.speed = 1. + ((float) level / 2);

    return plane;
}