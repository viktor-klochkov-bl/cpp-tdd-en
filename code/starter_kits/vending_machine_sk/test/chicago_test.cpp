// Copyright (c) 2025 Dr. Matthias Hölzl. All rights reserved.

#include "chicago/vending_machine.h"
#include "chicago/order.h"
#include "chicago/OrderStrategy.h"

#include <catch2/catch_test_macros.hpp>

using namespace chicago_vending;

TEST_CASE("Check that Chicago-style tests are executed")
{
    CHECK(chicago_vending::isolation() == "Chicago");
}

TEST_CASE("Test Vending Machine") {

    SECTION("Test add product") {
        VendingMachine testMachine;
        testMachine.addProduct("Coffee", 3);

        REQUIRE(testMachine.getInventoryItem("Coffee").capacity == 3);
        REQUIRE(testMachine.getInventoryItem("Coffee").current_stock == 3);
    }

    SECTION("Test sell product") {
        VendingMachine testMachine;
        testMachine.addProduct("Coffee", 3);
        testMachine.sellProduct("Coffee", 3);

        REQUIRE(testMachine.getInventoryCount("Coffee") == 0);
    }

    SECTION("Test restoke product") {
        VendingMachine testMachine;
        testMachine.addProduct("Coffee", 3);
        testMachine.sellProduct("Coffee", 3);

        testMachine.check_and_restock();

        REQUIRE(testMachine.getInventoryCount("Coffee") == 3);
    }
}

TEST_CASE("Test ordering strategy") {
    SECTION("Test empty order") {
        Inventory inventory;
        inventory.add_item({ "Tee", 4, 5 });

        OrderStrategy strategy;
        const Order order = strategy.compute_order(inventory, 0.25);\

        REQUIRE(order.empty());
    }

    SECTION("Test that order is correct") {
        Inventory inventory;

        inventory.add_item({ "Coffee", 1, 5 });
        inventory.add_item({ "Tee", 4, 5 });
        inventory.add_item({ "Lion", 1, 10 });

        OrderStrategy strategy;
        const Order order = strategy.compute_order(inventory, 0.25);

        REQUIRE(order.size() == 2);
        REQUIRE(order.find("Coffee")->second == 4);
        REQUIRE(order.find("Lion")->second == 9);

    }
}
