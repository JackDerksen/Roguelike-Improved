#include "map.h"
#include "setup.h"
#include <cstdlib>
#include <ctime>

int main(void) {
  if (screen_setup() != 0) {
    return 1;
  }

  // Seed random map generation the C++ way
  srand(static_cast<unsigned>(time(nullptr)));

  // Create and generate the map
  Map map;
  map.generate();

  // ---------- GAME LOOP ---------- //
  bool game_running = true;

  while (game_running) {
    // Clear the screen
    clear();

    // Render the map
    map.render();

    // Refresh the screen to show the updated map
    refresh();

    // Handle user input
    int ch = getch();
    if (ch == 'q') { // Example: Press 'q' to quit the game loop
      game_running = false;
    }
  }

  endwin();
  return 0;
}

