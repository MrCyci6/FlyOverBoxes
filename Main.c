// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#include "Sources/Drawing/Drawing.h"
#include "Sources/Utils/Options.h"
#include "Sources/Game/Game.h"
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