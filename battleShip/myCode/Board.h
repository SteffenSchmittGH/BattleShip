/*
 * Board.h
 *
 *  Created on: 12.12.2024
 *      Author: schmi
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "OwnGrid.h"
#include "OpponentGrid.h"
class Board
{
private:
	OwnGrid m_ownGrid;
	///< The Own Grid of the whole #Board.
	OpponentGrid m_oppGrid;
	///< The opponents Board.
public:
	/**
	 * @brief Constructor for the Board class.
	 *
	 * @param rows The number of rows in the board.
	 * @param cols The number of columns in the board.
	 */
	Board(int rows, int cols);
	/**
	 * @brief Destructor for the Board class.
	 */
	virtual ~Board();
	/**
	 * @brief Get the number of rows in the board.
	 *
	 * @return The number of rows.
	 */
	int getRows();
	/**
	 * @brief Get the number of columns in the board.
	 *
	 * @return The number of columns.
	 */
	int getColumns();
	/**
	 * @brief Get a reference to the player's own grid.
	 *
	 * @return A reference to the OwnGrid object.
	 */
	OwnGrid& getOwnGrid();
	/**
	 * @brief Get a reference to the opponent's grid.
	 *
	 * @return A reference to the OpponentGrid object.
	 */
	OpponentGrid& getOppGrid();
};

#endif /* BOARD_H_ */
