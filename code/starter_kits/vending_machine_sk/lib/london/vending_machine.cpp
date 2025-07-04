// Copyright (c) 2025 Dr. Matthias Hölzl. All rights reserved.

#include <iostream>

#include "vending_machine.h"

namespace london_vending {

  void VendingMachine::addProduct(const std::string &name, int capacity) {
    _inventory.add_item({name, capacity, capacity});
  }

  void VendingMachine::restockProduct(const std::string &name) {
    _inventory.restock_item(name);
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
} // namespace london_vending
