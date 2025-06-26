// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#include "prime_factors.h"

#include <iostream>
#include <sstream>

namespace prime_factors_sk {

  std::vector<long> compute_prime_factors(long number) {
    std::vector<long> result;

    for (long factor{2}; factor <= number; factor++) {
      while (number % factor == 0) {
        result.push_back(factor);
        number /= factor;
      }
    }
    return result;
  }

  void format_primes(const std::vector<long> &primes, std::ostream &os) {
    std::string prefix{""};
    for (auto& prime : primes) {
      os << prefix << prime;
      prefix = ", ";
    }
  }

  void compute_and_write_prime(long number, std::ostream &os) {
    const auto primes = compute_prime_factors(number);
    os << "The primes of " << number << " are: ";
    format_primes(primes, os);
  }

}
