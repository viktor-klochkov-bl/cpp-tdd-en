//
// Created by Viktor on 14.07.25.
//

#include "Map.h"

#include <optional>
#include <string>
#include <unordered_map>

namespace adv_sk {
  std::string direction_to_string(Direction direction) {
    switch (direction) {
      case Direction::North:
        return "North";
      case Direction::South:
        return "South";
      case Direction::East:
        return "East";
      case Direction::West:
        return "West";
    }
    throw std::runtime_error("Unknown direction");
  }

  Direction string_to_direction(const std::string &direction) {
    if (direction == "North") {
      return Direction::North;
    }
    if (direction == "South") {
      return Direction::South;
    }
    if (direction == "East") {
      return Direction::East;
    }
    if (direction == "West") {
      return Direction::West;
    }
    throw std::runtime_error("Unknown direction");
  }

  std::optional<Room> RoomConnections::get_connection(Direction direction) const {
    const auto it = connections.find(direction);
    if (it == connections.end()) {
      return std::nullopt;
    }
    return it->second;
  }

  std::optional<Room> Map::nextRoom(Room current_room, Direction direction) {
    auto current_root_it = _map.find(current_room);
    if (current_root_it == _map.end()) {
      return std::nullopt;
    }
    return current_root_it->second.get_connection(direction);
  }
}
