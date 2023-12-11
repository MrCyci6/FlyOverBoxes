// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#ifndef PLANE_H
#define PLANE_H

#include "Image.h"
#include "../Drawing/Drawing.h"
#include "../Utils/Log.h"
#include "../Utils/Options.h"
#include "../Includes.h"

struct s_plane {
    float x;
    float y;
    int orientation;
    float speed;
    struct s_image image;
};

void drawPlane(struct s_plane plane, int clear, struct s_options options);
void updatePlanePosition (struct s_plane* plane);
struct s_plane initializePlane(struct s_options options, int level);

#endif