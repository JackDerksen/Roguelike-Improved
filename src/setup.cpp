#include "setup.h"

int screen_setup(void) {
  initscr();

  if (has_colors()) {
    start_color();

    // Initialize entity colour pairs here
    init_pair(COLOR_PAIR_PLAYER, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_PAIR_ORC, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_PAIR_CHEST, COLOR_BLACK, COLOR_YELLOW);
    init_pair(COLOR_PAIR_EXIT, COLOR_BLACK, COLOR_GREEN);
    init_pair(COLOR_PAIR_HEALTH, COLOR_RED, COLOR_RED);
    init_pair(COLOR_PAIR_ARMOUR, COLOR_GREEN, COLOR_GREEN);

    // Initialize tile colour pairs
    init_pair(COLOR_PAIR_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_PAIR_RED, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_PAIR_GREEN, COLOR_GREEN, COLOR_BLACK);

    init_pair(COLOR_PAIR_WALLS, COLOR_WHITE, COLOR_WHITE);
    init_pair(COLOR_PAIR_FLOORS, COLOR_BLACK, COLOR_BLACK);
    init_pair(COLOR_PAIR_GAME_TEXT, COLOR_BLACK, COLOR_WHITE);
  }

  noecho();
  curs_set(0);

  refresh();

  return 0;
}
