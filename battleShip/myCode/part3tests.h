/*
 * part3tests.h
 *
 *  Created on: 08.01.2025
 *      Author: schmi
 */

#ifndef PART3TESTS_H_
#define PART3TESTS_H_
#include <string>
#include "ConsoleView.h"

/**
 * Outputs the failedMessage on the console if the condition is false.
 *
 * @param condition Boolean condition to be checked.
 * @param failedMessage Message to display if the condition is false.
 */
void assertTrue3(bool condition, std::string failedMessage);


/**
 * @brief Verifies whether the shot successfully hit a target or not.
 *
 * This function checks the result of a shot, verifying if it is either a hit
 * or a sunken ship,
 * and compares the result with the expected outcome (success or failure).
 * If `success` is true, it asserts the result using `assertTrue3`.
 *
 * @param result The result of the shot, represented by `Shot::impact` enum.
 *               Possible values are `HIT`, `NONE`, or `SUNKEN`.
 * @param str A descriptive string for the assertion, used for debugging/logging
 * purposes.
 * @param success A boolean indicating whether the test expects a successful hit
 *                If true, the function will assert if the shot was successful.
 */
void checkResult_hit(Shot::impact shotR, std::string str, bool STRisTrue);

/**
 * @brief Verifies whether a ship was sunken by the shot.
 *
 * This function checks if the shot resulted in a sunken ship. It compares the
 * result
 * with the expected outcome of a sunken ship (either `true` or `false`).
 * If `success` is true, it asserts the result using `assertTrue3`.
 *
 * @param result The result of the shot, represented by `Shot::impact` enum.
 *               Possible values are `HIT`, `NONE`, or `SUNKEN`.
 * @param str A descriptive string for the assertion, used for debugging/logging
 * purposes.
 * @param success A boolean indicating whether the test expects a sunken ship.
 *                If true, the function will assert if the shot sunken the ship.
 */
void checkResult_sunken(Shot::impact shotR, std::string str, bool STRisTrue);

/**
 * Runs a series of tests to validate the functionality of the `Board` class.
 *
 * This function tests the following:
 * - The results of firing shots at various positions on the board
 * - Verifies whether hits, misses,
 * 	 and sunken ship statuses are correctly determined.
 * - Simulates opponent grid shot results and verifies correct responses.
 *
 * @param board A pointer to the `Board` instance to be tested.
 */
void part3tests(Board* board);

#endif /* PART3TESTS_H_ */
