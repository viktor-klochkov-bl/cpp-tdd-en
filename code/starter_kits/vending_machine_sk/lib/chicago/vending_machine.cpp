// Copyright (c) 2025 Dr. Matthias Hölzl. All rights reserved.

#include <iostream>

#include "vending_machine.h"

#include "OrderStrategy.h"


namespace chicago_vending
{
  void VendingMachine::addProduct(const std::string &name, int capacity) {
    _inventory.add_item({name, capacity, capacity});
  }

  void VendingMachine::check_and_restock() {
    OrderStrategy strategy;
    if (const Order order = strategy.compute_order(_inventory, _threshold); !order.empty()) {
      if (_order_service.place_order(order)) {
        _inventory.executeOrder(order);
      }
    }
  }

  void VendingMachine::sellProduct(const std::string &name, int amount) {
    _inventory.sell_item(name, amount);
  }

  int VendingMachine::getInventoryCount(const std::string &name) const {
    return _inventory.get_item_count(name);
  }

  Item VendingMachine::getInventoryItem(const std::string &name) const {
    return _inventory.get_item(name);
  }
} // namespace chicago_vending
