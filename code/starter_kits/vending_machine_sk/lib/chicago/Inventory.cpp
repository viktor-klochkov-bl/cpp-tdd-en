//
// Created by Viktor on 03.07.25.
//

#include "Inventory.h"

namespace chicago_vending{

  void Inventory::add_item(const Item &item) {
    _items.emplace(item.name, item);
  }

  int Inventory::get_item_count(const std::string &name) const {
    return _items.at(name).current_stock;
  }

  Item Inventory::get_item(const std::string &name) const {
    return _items.at(name);
  }

  void Inventory::restock_item(const std::string &name, int amount) {
    if (_items.at(name).current_stock + amount <= _items.at(name).capacity) {
      _items.at(name).current_stock += amount;
    }
    else {
      throw std::runtime_error("Not enough capacity");
    }
  }

  void Inventory::executeOrder(const Order &order) {
    for (const auto& [name, amount] : order) {
      restock_item(name, amount);
    }
  }

  void Inventory::sell_item(const std::string &name, int amount) {
    if (_items.at(name).current_stock >= amount){
      _items.at(name).current_stock -= amount;
    }
    else {
      throw std::runtime_error("Not enough stock");
    }
  }
}
