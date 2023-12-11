// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023

#ifndef COMMANDPARSING_H
#define COMMANDPARSING_H

#include "../Utils/Log.h"
#include "../Utils/Options.h"
#include "../Includes.h"

int getNextWord(char* userCommand, char* word);
void replaceNewLineByEndLine(char* userCommand);
void parseUserCommand(char* userCommand, struct s_options* options);

#endif