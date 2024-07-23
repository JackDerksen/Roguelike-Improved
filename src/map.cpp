#include "map.h"

void Map::initialize() {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      tiles[y][x] = '#'; // Default to a wall tile
    }
  }
  rooms.clear(); // Reset room count
}

Room Map::create_random_room() {
  Room room;
  room.width = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
  room.height = rand() % (ROOM_MAX_SIZE - ROOM_MIN_SIZE + 1) + ROOM_MIN_SIZE;
  room.x = rand() % (MAP_WIDTH - room.width - 1) + 1;
  room.y = rand() % (MAP_HEIGHT - room.height - 1) + 1;
  return room;
}

bool Map::place_room(const Room &room) {
  for (const Room &existing : rooms) {
    if (!(room.x + room.width < existing.x ||
          room.x > existing.x + existing.width ||
          room.y + room.height < existing.y ||
          room.y > existing.y + existing.height)) {
      return false; // Room overlaps, cannot place
    }
  }

  for (int y = room.y; y < room.y + room.height; y++) {
    for (int x = room.x; x < room.x + room.width; x++) {
      tiles[y][x] = '.'; // Set floor
    }
  }

  rooms.push_back(room); // Add room to the map's room list
  return true;
}

void Map::connect_rooms(const Room &room1, const Room &room2) {
  int center1_x = room1.x + room1.width / 2;
  int center1_y = room1.y + room1.height / 2;
  int center2_x = room2.x + room2.width / 2;
  int center2_y = room2.y + room2.height / 2;

  if (rand() % 2) {
    for (int x = std::min(center1_x, center2_x);
         x <= std::max(center1_x, center2_x); x++) {
      tiles[center1_y][x] = '.';
    }
    for (int y = std::min(center1_y, center2_y);
         y <= std::max(center1_y, center2_y); y++) {
      tiles[y][center2_x] = '.';
    }
  } else {
    for (int y = std::min(center1_y, center2_y);
         y <= std::max(center1_y, center2_y); y++) {
      tiles[y][center1_x] = '.';
    }
    for (int x = std::min(center1_x, center2_x);
         x <= std::max(center1_x, center2_x); x++) {
      tiles[center2_y][x] = '.';
    }
  }
}

void Map::generate() {
  srand(time(NULL)); // Seed random number generator
  initialize();

  for (int i = 0; i < MAX_ROOMS; i++) {
    Room new_room = create_random_room();
    if (place_room(new_room)) {
      if (rooms.size() > 1) {
        connect_rooms(rooms[rooms.size() - 2], new_room);
      }
    }
  }
}

void Map::render() const {
  for (int y = 0; y < MAP_HEIGHT; y++) {
    for (int x = 0; x < MAP_WIDTH; x++) {
      char display_char = tiles[y][x];
      if (display_char == '#') {
        attron(COLOR_PAIR(COLOR_PAIR_WALLS));
        mvprintw(y, x, "#");
        attroff(COLOR_PAIR(COLOR_PAIR_WALLS));
      } else if (display_char == '.') {
        attron(COLOR_PAIR(COLOR_PAIR_FLOORS));
        mvprintw(y, x, ".");
        attroff(COLOR_PAIR(COLOR_PAIR_FLOORS));
      }
    }
  }
}

void Map::clear_dialogue() const {
  move(MAP_HEIGHT, 2);
  clrtoeol();
}
