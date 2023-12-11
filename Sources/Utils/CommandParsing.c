// Projet: FlyOverBoxes
// Author: MrCyci6
// Creation date: 06/12/2023
// Modification date: 06/12/2023
#include "CommandParsing.h"

int getNextWord (char* userCommand, char* word) {
    int index1;
    int index2;

    index1 = 0;
    while (userCommand[index1] == ' ')
        index1++;

    index2 = 0;
    while (userCommand[index1] != '\0')
    {
        if (userCommand[index1] == ' ')
            break;
        else
            word[index2] = userCommand[index1];
        index1++;
        index2++;
    }
    word[index2] = '\0';
    return index1;
}

void replaceNewLineByEndLine (char* userCommand) {
    int i;

    for (i = 0; i < strlen (userCommand); i++)
        if (userCommand[i] == '\n')
            userCommand[i] = '\0';
}

void parseUserCommand(char* userCommand, soptions* options) {
    char word[MAX_STRING_SIZE];
    int nextWordPosition;
    int length;
    int value;
    replaceNewLineByEndLine (userCommand);
    length = getNextWord (userCommand, word);
    userCommand += length;

    if (strcasecmp (word, "set") == 0)
    {

        length = getNextWord (userCommand, word);
        userCommand += length;

        if (strcasecmp (word, "difficulty") == 0)
        {

            getNextWord (userCommand, word);
            value = atoi (word);
            if (value >=1 && value <= 3)
                options->difficulty = value;
        }

        if (strcasecmp (word, "planetype") == 0)
        {

            getNextWord (userCommand, word);
            value = atoi (word);
            if (value >=1 && value <= 3)
                options->planeType = value;
        }

        if (strcasecmp (word, "powerup") == 0)
        {

            getNextWord (userCommand, word);
            if (strcasecmp (word, "yes") == 0)
                options->powerup = 1;
            if (strcasecmp (word, "no") == 0)
                options->powerup = 0;
        }

        if (strcasecmp (word, "colors") == 0)
        {

            getNextWord (userCommand, word);
            if (strcasecmp (word, "yes") == 0)
                options->colors = 1;
            if (strcasecmp (word, "no") == 0)
                options->colors = 0;
        }

        if (strcasecmp (word, "name") == 0)
        {

            getNextWord (userCommand, word);
            strcpy (options->name, word);
        }
    }

    if (strcasecmp (word, "run") == 0)
        options->run = 1;

    if (strcasecmp (word, "quit") == 0)
        options->quit = 1;

    if (strcasecmp (word, "help") == 0)
        options->help = !options->help;
}