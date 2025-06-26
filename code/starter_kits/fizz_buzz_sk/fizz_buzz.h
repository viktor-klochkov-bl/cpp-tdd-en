// Copyright (c) 2024 Dr. Matthias Hölzl. All rights reserved.

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
 * Generates a string corresponding to the "FizzBuzz" logic based on the input number.
 * If the number is divisible by 15, returns "FizzBuzz".
 * If the number is divisible by 5 but not 15, returns "Buzz".
 * If the number is divisible by 3 but not 15, returns "Fizz".
 * If the number is not divisible by 3 or 5, returns the number itself as a string.
 *
 * @param n The input integer to evaluate.
 * @return A string representing "Fizz", "Buzz", "FizzBuzz", or the number itself.
 */
std::string fizz_buzz_string(int n);

/**
 * Generates a vector of strings corresponding to the "FizzBuzz" logic for a range of numbers from 1 to n.
 * For each number in the range:
 * - If the number is divisible by 15, includes "FizzBuzz".
 * - If the number is divisible by 5 but not 15, includes "Buzz".
 * - If the number is divisible by 3 but not 15, includes "Fizz".
 * - Otherwise, includes the number itself as a string.
 *
 * @param n The upper bound of the range (inclusive) for generating "FizzBuzz" strings.
 * @return A vector of strings representing the "FizzBuzz" values for the range 1 to n.
 */
std::vector<std::string> fizz_buzz_vector(int n);

/**
 * Outputs the "FizzBuzz" sequence up to the given number to the specified output stream.
 * For each integer from 1 to n, prints "Fizz" for multiples of 3, "Buzz" for multiples of 5,
 * "FizzBuzz" for multiples of both 3 and 5, and the number itself otherwise.
 *
 * @param n The upper limit of the sequence, inclusive.
 * @param os The output stream where the "FizzBuzz" sequence will be written; defaults to std::cout.
 */
void fizz_buzz(int n, std::ostream& os = std::cout);
