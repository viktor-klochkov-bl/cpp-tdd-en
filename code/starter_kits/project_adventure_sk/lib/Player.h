//
// Created by Viktor on 14.07.25.
//
#pragma once

#include "Inventory.h"
#include "Map.h"
#include "Room.h"

#include <string>
#include <vector>

namespace adv_sk
{

class Player
{
public:
    [[nodiscard]] std::vector<Inventory> get_inventory() const
    {
        return _inventory;
    }

    [[nodiscard]] RoomName get_current_room() const
    {
        return _current_room;
    }

    void change_room(RoomName room)
    {
        _current_room = room;
    }

private:
    RoomName _current_room{};
    std::vector<Inventory> _inventory{};
};
} // namespace adv_sk
