/*
 * Ship.h
 *
 *  Created on: 10.12.2024
 *      Author: schmi
 */

#ifndef SHIP_H_
#define SHIP_H_
#include "GridPosition.h"
#include <set>
class Ship
{
private:
	GridPosition m_bow;
	///< #GridPosition of the start of the ship.

	GridPosition m_stern;
	///< #GridPosition of the end of the ship.

public:
	/**
	 * @brief Default constructor for the Ship class.
	 *
	 * Initializes a ship with default bow and stern GridPositions.
	 */
	Ship();

	/**
	 * @brief Parameterized constructor for the Ship class.
	 *
	 * @param bow The GridPosition of the ship's bow.
	 * @param stern The GridPosition of the ship's stern.
	 * Initializes a ship with the given bow and stern positions.
	 */
	Ship(const GridPosition& bow, const GridPosition& stern);

	/**
	 * @brief Destructor for the Ship class.
	 *
	 * Currently, no specific cleanup is required.
	 */
	virtual ~Ship();

	/**
	 * @brief Checks if the ship's configuration is valid.
	 *
	 * @return True if the ship's configuration satisfies all the following
	 * conditions:
	 * - Both bow and stern positions are valid.
	 * - The ship is aligned either horizontally or vertically (not diagonally).
	 * - The ship's length is between 2 and 5 (inclusive).
	 */
	bool isValid() const;

	/**
	 * @brief Retrieves the bow position of the ship.
	 *
	 * @return The GridPosition representing the ship's bow.
	 */
	GridPosition getBow() const;

	/**
	 * @brief Retrieves the stern position of the ship.
	 *
	 * @return The GridPosition representing the ship's stern.
	 */
	GridPosition getStern() const ;

	/**
	 * @brief Calculates the length of the ship.
	 *
	 * @return The length of the ship as an integer.
	 *
	 * This method determines the number of grid cells the ship occupies,
	 * depending on whether it is horizontally or vertically aligned.
	 */
	int length() const;

	/**
	 * @brief Determines the occupied area of the ship on the grid.
	 *
	 * @return A set of GridPosition objects representing all grid cells
	 * occupied by the ship.
	 *
	 * This method iterates over the grid cells between the bow and stern,
	 * inclusive, and returns them as part of the ship's occupied area.
	 */
	std::set<GridPosition> occupiedArea() const;

	/**
	 * @brief Determines the blocked area around the ship.
	 *
	 * @return A set of GridPosition objects representing all grid cells
	 * adjacent to the ship.
	 *
	 * This method calculates the "blocked area" around the ship to prevent
	 * overlapping or touching ships.
	 * It considers the following cases:
	 * - Cells adjacent to the top, bottom, left, and right of the ship.
	 * - Cells at the diagonal corners of the ship.
	 * - Edge cases for ships at the boundaries of the grid
	 * (e.g., top row, bottom row, leftmost column, rightmost column).
	 */
	std::set<GridPosition> blockedArea() const;
};

#endif /* SHIP_H_ */
