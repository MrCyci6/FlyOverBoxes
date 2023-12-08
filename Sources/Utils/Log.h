// Projet: FlyOverBoxes
// Author: Cyriac Lenoir : cyriac.lenoir@isen-ouest.yncrea.fr
// Creation date: 06/12/2023
// Modification date: 06/12/2023
// Role: Main

#ifndef LOG_H
#define LOG_H

#include "../Includes.h"

typedef enum e_logType {
    MESSAGE,
    WARNING,
    ERROR,
    CRITICAL,
    FATAL
} elogType;

#endif