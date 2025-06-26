// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#include "fizz_buzz.h"

#include <catch2/catch_test_macros.hpp>

TEST_CASE("fizz_buzz_string()") {
  SECTION("fizz_buzz_string of 1 returns 1") {
    std::string expected{"1"};
    CHECK(fizz_buzz_string(1) == expected);
  }
  SECTION("fizz_buzz_string of 2 returns 2") {
    std::string expected{"2"};
    CHECK(fizz_buzz_string(2) == expected);
  }
  SECTION("fizz_buzz_string of 3 returns Fizz") {
    std::string expected{"Fizz"};
    CHECK(fizz_buzz_string(3) == expected);
  }
  SECTION("fizz_buzz_string of 5 returns Buzz") {
    std::string expected {"Buzz"};
    CHECK(fizz_buzz_string(5) == expected);
  }
  SECTION("fizz_buzz_string of 15 returns FizzBuzz") {
    std::string expected {"FizzBuzz"};
    CHECK(fizz_buzz_string(15) == expected);
  }
}

TEST_CASE("fizz_buzz_vector()") {
  SECTION("fizz_buzz_vector of 1 returns 1") {
    std::vector<std::string> expected {"1"};
    CHECK(fizz_buzz_vector(1) == expected);
  }
  SECTION("fizz_buzz_vector of 15 returns correct answer") {
    std::vector<std::string> expected {"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz", "11", "Fizz", "13", "14", "FizzBuzz"};
    CHECK(fizz_buzz_vector(15) == expected);
  }
}

TEST_CASE("fizz_buzz()") {
  SECTION("fizz_buzz of 15 prints correct output") {
    std::string expected {"1\n2\nFizz\n4\nBuzz\nFizz\n7\n8\nFizz\nBuzz\n11\nFizz\n13\n14\nFizzBuzz\n"};
    std::ostringstream os;
    fizz_buzz(15, os);
    CHECK(os.str() == expected);
  }
}