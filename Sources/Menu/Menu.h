// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#ifndef MENU_H
#define MENU_H

#include "../Drawing/Drawing.h"
#include "../Objects/Image.h"
#include "../Utils/CommandParsing.h"
#include "../Utils/Log.h"
#include "../Utils/Options.h"
#include "../Includes.h"

void displayDifficultyOption(int difficulty, int y);
void displayPlaneTypeOption(int planeType, int y);
void displayPowerupOption(int powerup, int y);
void displayColorsOption(int colors, int y);
void displayNameOption(char* name, int y);
void displayHelp();
void displayMenu(struct s_options* options);

#endif