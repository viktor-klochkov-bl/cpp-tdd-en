//
// Created by Viktor on 14.07.25.
//

#include "Game.h"

#include <iostream>

namespace adv_sk {

  namespace detail {
    std::string read_from_cin() {
      std::string result;
      std::cin >> result;
      return result;
    }
  }

  void Game::handle_user_action() { //NOLINT(misc-no-recursion)
    auto action = detail::read_from_cin();

    if (action == "move") {
      std::cout << "Where do you want to go?" << std::endl;
      auto directions = get_available_directions();
      std::cout << "Available directions: \n";
      for (const auto& direction : directions) {
        std::cout << direction_to_string(direction) << "\n";
      }
      std::string direction_string;
      std::cin >> direction_string;
      move(string_to_direction(direction_string));
      handle_user_action();
    }
    else if (action == "quit") {
      exit(EXIT_SUCCESS);
    }
  }

  void Game::start() {
    init();
    update_message();

    if (false){
      handle_user_action();
    }
  }

  void Game::move(Direction direction) {

    const auto next_room = _map->nextRoom(_player.get_current_room(), direction);
    if (next_room.has_value()) {
      _player.change_room(next_room.value());
    }
    update_message();
  }

  std::vector<Direction> Game::get_available_directions() const {
    std::vector<Direction> result;
    for (auto direction : {Direction::North, Direction::South, Direction::East, Direction::West}) {
      auto room = _map->nextRoom(_player.get_current_room(), direction);
      if (room.has_value()) {
        result.push_back(direction);
      }
    }
    return result;
  }

  void Game::print_message() const {
     std::cout << _current_message << std::endl;
  }

  void Game::init() {
    // default map
    if (_map == nullptr) {
      _map = std::make_unique<Map>(
        std::unordered_map<Room, RoomConnections>{
            {Room::GrandHall, RoomConnections{Direction::North, Room::Armoury}},
            {Room::Armoury, RoomConnections{Direction::South, Room::GrandHall}},
          }
        );
    }

    _player.change_room(Room::GrandHall);
  }

  void Game::update_message() {
    if (_player.get_current_room() == Room::GrandHall) {
      _current_message = "You are in the Grand Hall. It is a vast, echoing chamber.";
    }
    else if (_player.get_current_room() == Room::Armoury) {
      _current_message = "You are in the Armoury. Racks of dusty weapons line the walls.";
    }
    print_message();
  }
}
