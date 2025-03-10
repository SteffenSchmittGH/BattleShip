/*
 * OpponentGrid.h
 *
 *  Created on: 12.12.2024
 *      Author: schmi
 */

#ifndef OPPONENTGRID_H_
#define OPPONENTGRID_H_
#include "Ship.h"
#include "Shot.h"
#include <map>
#include <vector>
class OpponentGrid
{
private:
	int m_rows;
	///< The number of rows on #OpponentGrid.

	int m_columns;
	///< The number of columns on #OpponentGrid.

	std::vector<Ship> m_sunkenShips;
	///< Holds the Sunken Ships of opponent Grid.

	std::map<GridPosition,Shot::impact> m_shots;
	///< A map with the #GridPosition of #Shot and their Shot::Impact.
public:
	/**
	 * @brief Constructor for the OpponentGrid class.
	 *
	 * @param rows Number of rows in the grid.
	 * @param columns Number of columns in the grid.
	 */
	OpponentGrid();

	/**
	 * @brief Parametrized Constructro.
	 *
	 * @param rows Number of rows in the grid.
	 * @param columns Number of columns in the grid.
	 */
	OpponentGrid(int rows, int columns);

	/**
	 * @brief Destructor for the OpponentGrid class.
	 */
	virtual ~OpponentGrid();

	/**
	 * @brief Gets the number of rows in the OpponentGrid.
	 *
	 * @return Number of rows.
	 */
	int getRows();

	/**
	 * @brief Gets the number of columns in the OpponentGrid.
	 *
	 * @return Number of columns.
	 */
	int getColumns();

	/**
	 * @brief Updates the grid with the result of a shot.
	 *
	 * @param result The impact of the shot (e.g., HIT, MISS, SUNKEN).
	 * @param shot The Shot object containing the target position.
	 */
	void shotResult(Shot::impact const result, Shot shot);

	/**
	 * @brief Retrieves the list of sunken ships on the opponent's grid.
	 *
	 * @return Vector of Ship objects representing the sunken ships.
	 */
	std::vector<Ship> getSunkenShips();

	/**
	 * @brief Retrieves the map of all shots and their impacts on the opponent's
	 * grid.
	 *
	 * @return Map of GridPosition to Shot::impact.
	 */
	std::map<GridPosition,Shot::impact> getShotMap();
};

#endif /* OPPONENTGRID_H_ */
