#include "setup.h"
#include <ncurses.h>

int screen_setup(void) {
  initscr();

  if (has_colors()) {
    start_color();
    // Initialize color pairs here
  }

  noecho();
  curs_set(0);

  refresh();
  return 0;
}
