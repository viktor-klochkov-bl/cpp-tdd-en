#pragma once

#include "Direction.h"
#include "Inventory.h"

#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

namespace adv_sk
{

using RoomName = std::string;

struct RoomConnections
{
    void add(Direction direction, RoomName room)
    {
        connections.emplace(direction, room);
    }

    [[nodiscard]] std::optional<RoomName> get_connection(
        Direction direction) const;

    std::unordered_map<Direction, RoomName> connections{};
};

class Room
{
public:
    Room(RoomName name) : _name(name)
    {
    }

    Room(const RoomName& _name, const std::string& _message,
         const std::vector<Inventory>& _inventory,
         const RoomConnections& _connections) :
        _name(_name), _message(_message), _inventory(_inventory),
        _connections(_connections)
    {
    }

    [[nodiscard]] std::string get_message() const
    {
        return _message;
    }

    [[nodiscard]] std::string get_name() const
    {
        return _name;
    }

    void add_connection(Direction direction, RoomName room)
    {
        _connections.add(direction, room);
    }

private:
    RoomName _name;
    std::string _message{};

    std::vector<Inventory> _inventory{};
    RoomConnections _connections{};
};

} // namespace adv_sk
