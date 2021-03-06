﻿/****************************************************************************
 * This file is part of the "Introduction to programming" course. FMI 2019/20
 *****************************************************************************/

 /**
  * @file   solutions_01-02.cpp
  * @author Ivan Filipov
  * @author Kristian Krastev
  * @author Vasilena Peycheva
  * @date   01.2020
  * @brief  Solution for recursion tasks from practice 12.
  */

#include <iostream>
#include <cmath>

const int MAX = 12;

/*************** Task 1 ***************/
unsigned int factorial(unsigned int number) {
	//limit
	if (number > MAX)
		return 0;
	if (number == 0 || number == 1)
		return 1;
	return number * factorial(number - 1);
}

/*************** Task 2 ***************/
// main logic
bool is_prime_rec(unsigned int number, unsigned int stop, unsigned int i) {

	if (number == 1 || number == 2)
		return true;
	if (number % i == 0)
		return false;
	if (i == stop)
		return true;

	return is_prime_rec(number, stop, i + 1);
}

// "wrapper function" is a function which wraps another function (in our example the recursive one).
// It's essentially another function which calls the actual function.
bool is_prime(unsigned int number) {

	return is_prime_rec(number, std::sqrt(number), 2);
}

int main() {
	unsigned int number;

	// task_01
	std::cout << "n = ";
	std::cin >> number;
	std::cout << number << "! = "
	          << factorial(number)
	          << std::endl;

	// task_02
	std::cout << "n = ";
	std::cin >> number;
	std::cout << "Is prime? - "
	          << std::boolalpha
	          << is_prime(number)
	          << std::endl;

	return 0;
}
