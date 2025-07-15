//
// Created by Viktor on 14.07.25.
//

#pragma once

#include <string>
#include <vector>

#include "Map.h"
#include "Player.h"

namespace adv_sk {

  class IInputHandler {
  };

  class Game {
  public:

    Game() = default;
    explicit Game(std::unique_ptr<Map> map) : _map(std::move(map)) {}

    void handle_user_action();

    void start();

   [[nodiscard]] std::string get_current_message() const {
      return _current_message;
    }

    void move(Direction direction);

    [[nodiscard]] Room get_current_location() const {
      return _player.get_current_room();
    }

    [[nodiscard]] std::vector<Direction> get_available_directions() const;

  private:
    void print_message() const;

    void init();

    void update_message();

    std::unique_ptr<Map> _map{};

    // current state
    Player _player{};

    std::string _current_message{};
//    Room _current_room{};
  };
}
