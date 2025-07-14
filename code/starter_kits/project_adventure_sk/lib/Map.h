//
// Created by Viktor on 14.07.25.
//

#pragma once
#include <array>
#include <optional>
#include <unordered_map>
#include <utility>

namespace adv_sk {

  enum class Direction {
    North,
    South,
    East,
    West,
  };

  std::string direction_to_string(Direction direction);

  Direction string_to_direction(const std::string& direction);

  enum class Room {
    Armoury,
    GrandHall,
  };

  struct RoomConnections {
    RoomConnections(Direction direction, Room root) {
      connections.emplace(direction, root);
    }

    [[nodiscard]] std::optional<Room> get_connection(Direction direction) const;

    std::unordered_map<Direction, Room> connections{};
  };

  class Map {
  public:
    explicit Map(std::unordered_map<Room, RoomConnections> map) : _map(std::move(map)) {}

    std::optional<Room> nextRoom(Room current_room, Direction direction);

  private:
    std::unordered_map<Room, RoomConnections> _map{};
  };
}
