//
// Created by Viktor on 03.07.25.
//

#include "OrderStrategy.h"

#include <cassert>

#include "Inventory.h"

namespace chicago_vending {
  Order OrderStrategy::compute_order(const Inventory &inventory, double threshold) {
    assert(threshold > 0 && threshold < 1);
    Order order{};
    for (const auto& [name, item] : inventory) {
      if ( static_cast<double>(item.current_stock)/item.capacity < threshold) {
        order.emplace(name, item.capacity - item.current_stock);
      }
    }
    return order;
  }
}
