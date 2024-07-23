#ifndef MAP_H
#define MAP_H

#include "setup.h"
#include <cstdlib>
#include <ctime> // For random seeding
#include <ncurses.h>
#include <vector>

#define ROOM_MIN_SIZE 5
#define ROOM_MAX_SIZE 15
#define MAP_WIDTH 80
#define MAP_HEIGHT 25
#define MAX_ROOMS 15
#define MAX_CHESTS 5

class Room {
public:
  int x, y;          ///< X and Y coordinates of the room's top-left corner.
  int width, height; ///< Width and height of the room.
};

class Map {
public:
  char tiles[MAP_HEIGHT][MAP_WIDTH]; ///< 2D array of map tiles.
  std::vector<Room> rooms;           ///< Vector of rooms on the map.

  void initialize();
  Room create_random_room();
  bool place_room(const Room &room);
  void connect_rooms(const Room &room1, const Room &room2);
  void generate();
  void render() const;
  void clear_dialogue() const;
};

#endif // MAP_H
