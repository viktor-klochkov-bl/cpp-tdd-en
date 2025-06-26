// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#include "fizz_buzz.h"

std::string fizz_buzz_string(int n) {
  if (n % 15 == 0) {
    return"FizzBuzz";
  }
  if (n % 5 == 0) {
    return"Buzz";
  }
  if (n % 3 == 0) {
    return"Fizz";
  }
  return std::to_string(n);
 }

std::vector<std::string> fizz_buzz_vector(int n) {
  std::vector<std::string> result;
  result.reserve(n);
  for (int i = 1; i <= n; i++) {
    result.emplace_back(fizz_buzz_string(i));
  }
  return result;
}

void fizz_buzz(int n, std::ostream &os) {
  for (const auto& s : fizz_buzz_vector(n)) {
    os << s << "\n";
  }
}

