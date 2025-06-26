// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#include "prime_factors.h"
#include "../../completed/prime_factors/prime_factors.h"

#include <catch2/catch_test_macros.hpp>

#include <sstream>

using namespace prime_factors_sk;

TEST_CASE ("compute_prime_factors()")
{
  SECTION("Compute prime factors of 1 return []") {
    std::vector<long> expected{};
    CHECK(compute_prime_factors(1) == expected);
  }

  SECTION("Compute prime factors of 2 return [2]") {
    std::vector expected{2L};
    CHECK(compute_prime_factors(2L) == expected);
  }

  SECTION("Compute prime factors of 3 return [3]") {
    std::vector expected{3L};
    CHECK(compute_prime_factors(3L) == expected);
  }

  SECTION("Compute prime factors of 4 return [2, 2]") {
    std::vector expected{2L, 2L};
    CHECK(compute_prime_factors(4L) == expected);
  }

  SECTION("Compute prime factors of 5 return [5]") {
    std::vector expected{5L};
    CHECK(compute_prime_factors(5L) == expected);
  }

  SECTION("Compute prime factors of 6 return [2, 3]") {
    std::vector expected{2L, 3L};
    CHECK(compute_prime_factors(6L) == expected);
  }
}

TEST_CASE("Format primes") {
  SECTION("formats an empty vector correctly") {
    std::vector<long> primes{};
    std::string expected{""};
    std::stringstream os;
    format_primes(primes, os);
    CHECK(os.str() == expected);
  }

  SECTION("formats a vector with one element correctly") {
    std::vector primes{2L};
    std::string expected{"2"};
    std::stringstream os;
    format_primes(primes, os);
    CHECK(os.str() == expected);
  }

  SECTION("formats a vector with two elements correctly") {
    std::vector primes{2L, 3L};
    std::string expected{"2, 3"};
    std::stringstream os;
    format_primes(primes, os);
    CHECK(os.str() == expected);
  }

  SECTION("formats a vector with 5 elements correctly") {
    std::vector primes{2L, 3L, 5L, 7L, 11L};
    std::string expected{"2, 3, 5, 7, 11"};
    std::stringstream os;
    format_primes(primes, os);
    CHECK(os.str() == expected);
  }
}

TEST_CASE("Compute and write prime") {
  SECTION("print the correct output for 100") {
    std::stringstream os;
    std::string expected{"The primes of 100 are: 2, 2, 5, 5"};
    compute_and_write_prime(100, os);
    CHECK(os.str() == expected);
  }
}
