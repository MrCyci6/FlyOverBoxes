// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#ifndef HISTOGRAM_H
#define HISTOGRAM_H

#include "../Utils/Log.h"
#include "../Includes.h"

typedef struct s_histogram {
    int numberOfBins;
    int* bins;
    char displayCharacter;
} shistogram;

void decrementBin(int binNumber, int value, struct s_histogram* histogram);
void clearBin(int binNumber, struct s_histogram* histogram);
int isEmpty(struct s_histogram histogram);
struct s_histogram generateHistogram(int numberOfBins, int maxValue, char displayCharacter);
void deleteHistogram(struct s_histogram histogram);
int XYIntersectHistogram(int x, int y, struct s_histogram histogram);

#endif