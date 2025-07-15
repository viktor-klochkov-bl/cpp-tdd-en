//
// Created by Viktor on 14.07.25.
//
#pragma once

#include "Map.h"

#include <string>
#include <vector>

namespace adv_sk {

  struct Inventory {
    std::string name{};
  };


  class Player {
  public:
    [[nodiscard]] std::vector<Inventory> get_inventory() const {
      return _inventory;
    }

    [[nodiscard]] Room get_current_room() const {
      return _current_room;
    }

    void change_room(Room room) {
      _current_room = room;
    }

  private:
    Room _current_room{};
    std::vector <Inventory> _inventory{};


  };
}
