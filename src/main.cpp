#include "setup.h"
#include <cstdlib>
#include <ncurses.h>
#include <time.h>

int main(void) {
  if (screen_setup() != 0) {
    return 1;
  }

  // Seed random map generation
  // Figure out how to do this the c++ way
  srand((unsigned)time(NULL));

  // ---------- GAME LOOP ---------- //
  bool game_running = true;

  while (game_running) {
    // Do stuff here

    int ch = getch();
  }

  endwin();
  return 0;
}
