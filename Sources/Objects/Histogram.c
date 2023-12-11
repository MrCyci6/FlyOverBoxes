// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023
#include "Histogram.h"

void decrementBin(int binNumber, int value, shistogram* histogram) {
    histogram->bins[binNumber] = (histogram->bins[binNumber] - value) < 0 ? 0 : histogram->bins[binNumber] - value;
}

void clearBin(int binNumber, shistogram* histogram) {
    histogram->bins[binNumber] = 0;
}

int isEmpty(shistogram histogram) {
    for(int i = 0; i < histogram.numberOfBins; i++) {
        if(histogram.bins[i] != 0) {
            return 0;
        }
    }
    return 1;
}

shistogram generateHistogram(int numberOfBins, int maxValue, char displayCharacter) {
    shistogram histogram;

    histogram.numberOfBins = numberOfBins;
    histogram.displayCharacter = displayCharacter;
    histogram.bins = malloc(rand()/maxValue);
    for(int i = 1; i < numberOfBins - 1; i++) {
        histogram.bins[i] = rand() % maxValue;
    }
    histogram.bins[0] = 0;
    histogram.bins[numberOfBins - 1] = 0;

    return histogram;
}

void deleteHistogram(shistogram histogram) {
    free(histogram.bins);
}

int XYIntersectHistogram(int x, int y, shistogram histogram) {
    int bin;
    int binSize;

    binSize = (SCREEN_WIDTH - 2)/histogram.numberOfBins;

    bin = (x - 2)/binSize;
    if ((SCREEN_HEIGHT - histogram.bins[bin]*BOX_HEIGHT) <= y)
        return bin;
    else
        return -1;
}
