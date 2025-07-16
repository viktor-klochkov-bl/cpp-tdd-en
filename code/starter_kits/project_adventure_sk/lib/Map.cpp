//
// Created by Viktor on 14.07.25.
//

#include "Map.h"
#include "Room.h"
#include "Direction.h"

#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace adv_sk
{


Map::Map(std::vector<Room> rooms,
         std::unordered_map<RoomName, RoomConnections> connections)
{
    for (const auto& room : rooms)
    {
        _rooms.emplace(room.get_name(), room);
    }
    for (auto [room_name, connection] : connections)
    {
        //_rooms[room_name].add_connection(connection);
        //     _rooms[room_name].add_connection(connection);
    }
}

std::optional<RoomName> Map::nextRoom(RoomName current_room, Direction direction)
{
    auto current_root_it = _connections.find(current_room);
    if (current_root_it == _connections.end())
    {
        return std::nullopt;
    }
    return current_root_it->second.get_connection(direction);
}

std::string Map::get_welcome_message(RoomName room)
{
    return _rooms.find(room)->second.get_message();
}

std::unique_ptr<adv_sk::Map> create_map()
{
  auto map = std::make_unique<Map>(std::vector<RoomName>{ "GrandHall" , "Armoury" }, std::unordered_map<RoomName, RoomConnections>{ "GrandHall", RoomConnections{Direction::North, "Armoury"} });

    //return std::make_unique<Map>(std::unordered_map<RoomName, RoomConnections>{
    //    {"GrandHall", RoomConnections{Direction::North, "Armoury"}},
    //    {"Armoury", RoomConnections{Direction::South, "GrandHall"}},
    //});
}

} // namespace adv_sk
