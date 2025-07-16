#pragma once

#include <string>

namespace adv_sk
{

enum class Direction
{
    North,
    South,
    East,
    West,
};

std::string direction_to_string(Direction direction);

Direction string_to_direction(const std::string& direction);

} // namespace adv_sk
