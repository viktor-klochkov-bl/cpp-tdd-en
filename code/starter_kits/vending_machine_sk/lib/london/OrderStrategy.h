//
// Created by Viktor on 03.07.25.
//

#ifndef ORDERSTRATEGY_H
#define ORDERSTRATEGY_H

#include "order.h"

namespace london_vending {
  class Inventory;

  class OrderStrategy {
  public:
    Order compute_order(const Inventory& inventory, double threshold);
  };
}

#endif //ORDERSTRATEGY_H
