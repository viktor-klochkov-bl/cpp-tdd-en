// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#include "item.h"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Item constructed correctly") {
  SECTION("when price is non-negative") {
    const Item item1{"item1", 30};
    CHECK(item1.get_name() == "item1");
    CHECK(item1.get_price() == 30);
  }
  SECTION("when price is negative") {
    const Item item1{"item2", -30};
    CHECK(item1.get_name() == "item2");
    CHECK(item1.get_price() == 30);
  }
}

TEST_CASE("Items compared correctly") {
  CHECK(Item{"item", 100} == Item{"item", 100});
  CHECK(Item{"item", 100} == Item{"item", -100});

  CHECK_FALSE(Item{"item", 100} == Item{"item1", 100});
  CHECK_FALSE(Item{"item", 100} == Item{"item", 10});
}