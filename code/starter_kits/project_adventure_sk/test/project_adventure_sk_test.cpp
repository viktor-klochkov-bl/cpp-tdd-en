    // Copyright (c) 2025 Dr. Matthias Hölzl. All rights reserved.

    #include "project_adventure_sk.h"

    #include <catch2/catch_test_macros.hpp>

    #include "Game.h"

    using namespace adv_sk;

    TEST_CASE("Check that tests are executed")
    {
        SECTION("Check that the game is started") {
            Game game{};
            game.start();
            CHECK(game.get_current_message() == "You are in the Grand Hall. It is a vast, echoing chamber.");
            CHECK(game.get_current_location() == Room::GrandHall);
        }

        SECTION("Check that I can move North") {
            Game game{};
            game.start();
            game.move(Direction::North);
            CHECK(game.get_current_message() == "You are in the Armoury. Racks of dusty weapons line the walls.");
            CHECK(game.get_current_location() == Room::Armoury);

        }

        SECTION("Check that I can move South") {
            Game game{};
            game.start();
            game.move(Direction::North);
            game.move(Direction::South);
            CHECK(game.get_current_message() == "You are in the Grand Hall. It is a vast, echoing chamber.");
            CHECK(game.get_current_location() == Room::GrandHall);
        }

        SECTION("Check that list of available directions works")
        {
            Game game{};
            game.start();
            auto list = game.get_available_directions();
            CHECK(list.size() == 1);
            CHECK(list[0] == Direction::North);

            game.move(Direction::North);
            list = game.get_available_directions();
            CHECK(list.size() == 1);
            CHECK(list[0] == Direction::South);
        }
    }
