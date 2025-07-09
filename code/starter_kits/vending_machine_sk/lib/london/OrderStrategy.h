//
// Created by Viktor on 03.07.25.
//

#pragma once

#include "order.h"

namespace london_vending
{
    class Inventory;

    class OrderStrategy
    {
    public:
        Order compute_order(const Inventory& inventory, double threshold);
    };
} // namespace london_vending
