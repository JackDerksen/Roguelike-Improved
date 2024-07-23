#ifndef SETUP_H
#define SETUP_H

#include <ncurses.h>

// Entity colour pairs
#define COLOR_PAIR_PLAYER 1
#define COLOR_PAIR_ORC 2
#define COLOR_PAIR_CHEST 3
#define COLOR_PAIR_EXIT 4
#define COLOR_PAIR_HEALTH 5
#define COLOR_PAIR_ARMOUR 6

// Tile colour pairs
#define COLOR_PAIR_WALLS 7
#define COLOR_PAIR_FLOORS 8
#define COLOR_PAIR_GAME_TEXT 9

// Basic colour pairs
#define COLOR_PAIR_BLUE 10
#define COLOR_PAIR_RED 11
#define COLOR_PAIR_GREEN 12

int screen_setup(void);

#endif // SETUP_H
