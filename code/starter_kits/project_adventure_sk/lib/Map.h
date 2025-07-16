//
// Created by Viktor on 14.07.25.
//

#pragma once

#include "Inventory.h"
#include "Room.h"

#include <array>
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <utility>

namespace adv_sk
{


class Map
{
public:
    explicit Map(std::unordered_map<RoomName, RoomConnections> map) :
        _connections(std::move(map))
    {
    }

    Map(std::vector<Room> rooms,
        std::unordered_map<RoomName, RoomConnections> map);

    std::optional<RoomName> nextRoom(RoomName current_room, Direction direction);

    std::string get_welcome_message(RoomName room);

private:
    std::unordered_map<RoomName, RoomConnections> _connections{};
    std::unordered_map<RoomName, Room> _rooms{};
};

std::unique_ptr<Map> create_map();

} // namespace adv_sk
