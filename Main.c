// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main

#include "Sources/Drawing/Drawing.h"
#include "Sources/Menu/Menu.h"

int main() {

    struct s_options options;

    options = getDefaultOptions();

    do
    {
        displayMenu(&options);
        if (options.run)
            runGame(options);
    }
    while (!options.quit);

    return 0;

};