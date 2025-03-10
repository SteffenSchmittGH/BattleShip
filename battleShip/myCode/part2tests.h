/*
 * part2tests.h
 *
 *  Created on: 08.01.2025
 *      Author: schmi
 */

#ifndef PART2TESTS_H_
#define PART2TESTS_H_

#include <iostream>
#include "ConsoleView.h"
#include <string>

/**
 * Outputs the failedMessage on the console if condition is false.
 *
 * @param condition the condition
 * @param failedMessage the message
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * Runs a series of tests for the `GridPosition` and `Ship` classes.
 *
 * This function tests the constructors, getters, setters, and comparison
 * operators for the `GridPosition` class. Additionally, it validates the
 * functionality of the `Ship` class, including its constructor,
 * `isValid` method, length calculation, and occupied area.
 */
void part1tests();

/**
 * Runs a series of tests on the `Board` class.
 *
 * This function tests ship placement functionality for the `Board` class,
 * including checking whether diagonal ships can be placed, ensuring ships do
 * not overlap or align, and verifying rules for the maximum number and
 * size of ships.
 *
 * @param board A pointer to the `Board` instance to be tested.
 */
void part2test(Board* board);
#endif /* PART2TESTS_H_ */
