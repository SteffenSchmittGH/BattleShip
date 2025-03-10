/*
 * OwnGrid.h
 *
 *  Created on: 11.12.2024
 *      Author: schmi
 */

#ifndef OWNGRID_H_
#define OWNGRID_H_
#include "Ship.h"
#include "Shot.h"
#include <map>
#include <vector>
#define MAX_OWN_SHIPS 10
class OwnGrid {
private:
	int m_rows;
	///< The number of rows on the #Owngrid.

	int m_cols;
	///< The number of columns on the #Owngrid.

	std::vector<Ship> m_ownShips;
	///< A std::vector of all the ships were placed successfully on #Owngrid.

	std::map<int,int> m_trackNumberOfPlacedShips;
	///< A std::map of all lengths #Ship and quantity available to the user.

	std::set<GridPosition> m_shotAt;
	///< A std::set of all the #GridPosition of Shots that were fired.
	int countHITs;
	///< counts Hits of Ships to determine Sunken Ship.
public:
	/**
	 * @brief Constructor for the OwnGrid class.
	 *
	 * @param rows Number of rows in the grid.
	 * @param cols Number of columns in the grid.
	 * Initializes the grid dimensions and tracks the available ships of various
	 * lengths.
	 */
	OwnGrid(int rows, int cols);

	/**
	 * @brief Destructor for the OwnGrid class.
	 *
	 * Currently, no specific cleanup is needed.
	 */
	virtual ~OwnGrid();

	/**
	 * @brief Gets the number of rows in the OwnGrid.
	 *
	 * @return The number of rows.
	 */
	int getRows();

	/**
	 * @brief Gets the number of columns in the OwnGrid.
	 *
	 * @return The number of columns.
	 */
	int getColumns();

	/**
	 * @brief Retrieves the positions of all shots fired at the player's grid.
	 *
	 * @return A set of GridPosition objects representing the locations of shots
	 */
	std::set<GridPosition> getShots();

	/**
	 * @brief Attempts to place a ship on the grid.
	 *
	 * @param addShip The ship to be added.
	 * @return True if the ship is successfully placed; false otherwise.
	 *
	 * Ensures that the ship is valid, does not overlap with other ships,
	 * and that the total number of allowed ships is not exceeded.
	 */
	bool placeShip(const Ship& addShip);

	/**
	 * @brief Retrieves the ships currently placed on the grid.
	 *
	 * @return A vector of Ship objects representing the ships on the grid.
	 */
	const std::vector<Ship> getShips();

	/**
	 * @brief Processes a shot fired at the player's grid and determines its
	 * impact.
	 *
	 * @param shot The Shot object containing the target position.
	 * @return The impact of the shot (HIT, SUNKEN, or NONE).
	 *
	 * Updates the grid to reflect the shot and tracks sunken ships.
	 * Ensures the list of remaining ships is updated accordingly.
	 */
	Shot::impact takeBlow(const Shot& shot);
};

#endif /* OWNGRID_H_ */
