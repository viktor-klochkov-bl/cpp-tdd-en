// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#include "order.h"
#include "item.h"

#include <catch2/catch_test_macros.hpp>

#include <sstream>

TEST_CASE("Order test") {

  SECTION("Constructed correctly") {
    const std::initializer_list orders{Item{"item1", 30}, Item{"item2", -10}};
    Order order{orders};
    CHECK(order.items() == std::vector<Item>{orders});
  }

  SECTION("Total price calculated correctly") {
    const std::initializer_list orders{Item{"item1", 30}, Item{"item2", -10}};
    Order order{orders};
    CHECK(order.total_price() == 40);
  }

  SECTION("AddItem works correctly") {
    Item item{"item1", 30};
    Order order;

    order.add_item(item);
    CHECK(order.items() == std::vector<Item>{item});
    CHECK(order.total_price() == 30);

    order.add_item("item2", -20);
    CHECK(order.items() == std::vector<Item>{item, Item{"item2", -20}});
    CHECK(order.total_price() == 50);
  }
}