//
// Created by Viktor on 04.07.25.
//

#pragma once

#include "order.h"

namespace london_vending
{

    class IOrderService
    {
    public:
        virtual ~IOrderService() = default;
        virtual bool place_order(const Order& order) = 0;
    };

    class OrderService : public IOrderService
    {
    public:
        bool place_order(const Order& order) override;
    };

} // namespace london_vending
