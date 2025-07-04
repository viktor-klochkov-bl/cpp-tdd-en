//
// Created by Viktor on 03.07.25.
//

#include "Inventory.h"

namespace london_vending{

  void Inventory::add_item(const Item &item) {
    _items.emplace(item.name, item);
  }

  int Inventory::get_item_count(const std::string &name) const {
    return _items.at(name).current_stock;
  }

  Item Inventory::get_item(const std::string &name) const {
    return _items.at(name);
  }

  void Inventory::restock_item(const std::string &name) {
    _items.at(name).current_stock = _items.at(name).capacity;
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
