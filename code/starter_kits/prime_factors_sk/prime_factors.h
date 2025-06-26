// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#pragma once

#include <iostream>
#include <vector>

namespace prime_factors_sk {
  /**
   * Computes the prime factors for the specified number.
   *
   * This function identifies and returns all prime factors of the given integer.
   *
   * @param number The integer number for which prime factors are to be computed.
   *               It should be a positive number greater than or equal to 1.
   * @return A vector containing the prime factors of the input number in ascending order.
   *         If the number is 1, an empty vector is returned as 1 has no prime factors.
   */
  std::vector<long> compute_prime_factors(long number);

  /**
   * Formats a list of prime numbers and writes them to the specified output stream.
   *
   * This function takes a vector of prime numbers and writes them to the provided
   * output stream. The prime numbers are formatted as a comma-separated string.
   * An empty vector results in no output being written to the stream.
   *
   * @param primes The vector containing prime numbers to be formatted.
   *               It can be an empty vector, in which case no output is written.
   * @param os The output stream to which the formatted primes will be written.
   *           Typically, this would be `std::cout` or a file-based output stream.
   */
  void format_primes(const std::vector<long>& primes, std::ostream& os);

  /**
   * Computes the prime factors of a given number and writes them to the specified output stream.
   *
   * This function calculates all prime factors of the provided number, formats them as a comma-separated
   * string, and outputs the result to the specified stream. If the number is 1 or has no prime factors,
   * no output is written.
   *
   * @param number The positive integer for which prime factors should be computed.
   *               It should be greater than or equal to 1.
   * @param os The output stream where the formatted prime factors will be written.
   *           Defaults to `std::cout` if no stream is provided.
   */
  void compute_and_write_prime(long number, std::ostream &os = std::cout);

}
