//
// Created by Viktor on 03.07.25.
//

#ifndef INVERTORY_H
#define INVERTORY_H

#include "item.h"

#include <string>
#include <unordered_map>

namespace london_vending{
class Inventory {
  std::unordered_map<std::string, Item> _items;
public:
  void add_item(const Item& item);

  [[nodiscard]] int get_item_count(const std::string& name) const;

  [[nodiscard]] Item get_item(const std::string& name) const;

  void restock_item(const std::string& name);

  void sell_item(const std::string& name, int amount = 1);

  [[nodiscard]] auto begin() const { return _items.begin(); }
  [[nodiscard]] auto end()   const { return _items.end(); }

};


}

#endif //INVERTORY_H
