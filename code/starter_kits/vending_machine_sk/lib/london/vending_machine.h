// Copyright (c) 2025 Dr. Matthias Hölzl. All rights reserved.

#pragma once
#ifndef LIB_LONDON_VENDING_MACHINE_H
#define LIB_LONDON_VENDING_MACHINE_H

#include <string>

#include "Inventory.h"
#include "item.h"

namespace london_vending
{
    inline std::string isolation()
    {
        return "London";
    }

    class VendingMachine
    {
    public:
        void addProduct(const std::string& name, int capacity);
        void sellProduct(const std::string& name, int amount = 1);
        void restockProduct(const std::string &name);

        [[nodiscard]] int getInventoryCount(const std::string& name) const;
        [[nodiscard]] Item getInventoryItem(const std::string& name) const;
    private:

        Inventory _inventory{};
    };
} // namespace london_vending
#endif // LIB_LONDON_VENDING_MACHINE_H
